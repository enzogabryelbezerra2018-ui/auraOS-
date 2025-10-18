import os
import time

# Pasta que será testada
SOURCE_DIR = "Source"

# Lista de arquivos encontrados
files = []

# Cores ANSI para logs
class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

# Função para listar arquivos
def list_source_files(path):
    global files
    try:
        files = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    except Exception as e:
        print(f"{Colors.FAIL}Erro ao acessar a pasta {path}: {e}{Colors.ENDC}")

# Função para simular execução de cada módulo
def run_modules():
    for idx, f in enumerate(files, 1):
        print(f"{Colors.OKBLUE}[{idx}] Executando módulo: {f}{Colors.ENDC}")
        time.sleep(0.3)  # Simula execução
        print(f"{Colors.OKGREEN}Módulo {f} executado com sucesso.{Colors.ENDC}\n")

if __name__ == "__main__":
    print(f"{Colors.HEADER}===== Testando todos os arquivos da pasta Source ====={Colors.ENDC}\n")
    
    list_source_files(SOURCE_DIR)
    
    print(f"Arquivos encontrados ({len(files)}):")
    for idx, f in enumerate(files, 1):
        print(f"[{idx}] {f}")
    
    print("\nIniciando execução simulada dos módulos...\n")
    run_modules()
    
    print(f"{Colors.HEADER}===== Teste concluído ====={Colors.ENDC}")
