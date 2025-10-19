from PIL import Image
import zipfile
import os

# Configurações
ZIP_PATH = 'font_images.zip'       # caminho para seu zip de imagens
OUTPUT_INC = 'system_font_data.inc'  # arquivo .inc gerado
CHAR_WIDTH = 8
CHAR_HEIGHT = 16
START_ASCII = 32
END_ASCII = 127

# Pasta temporária para extrair imagens
EXTRACT_DIR = 'temp_font'
os.makedirs(EXTRACT_DIR, exist_ok=True)

# Extrai o zip
with zipfile.ZipFile(ZIP_PATH, 'r') as zip_ref:
    zip_ref.extractall(EXTRACT_DIR)

# Abre o arquivo .inc para escrever
with open(OUTPUT_INC, 'w') as f:
    f.write("// Arquivo gerado automaticamente do zip de imagens\n")
    f.write("const uint8_t g_system_font_data[96][16] = {\n")

    for ascii_code in range(START_ASCII, END_ASCII + 1):
        img_path = os.path.join(EXTRACT_DIR, f'ASCII_{ascii_code}.png')
        im = Image.open(img_path).convert('1')  # 1-bit
        f.write("  { ")
        for y in range(CHAR_HEIGHT):
            byte = 0
            for x in range(CHAR_WIDTH):
                pixel = im.getpixel((x, y))
                byte |= (1 if pixel else 0) << (7-x)
            f.write(f"0x{byte:02X}, ")
        f.write("}, // ASCII {}\n".format(ascii_code))
    
    f.write("};\n")

print(f"Arquivo gerado: {OUTPUT_INC}")
