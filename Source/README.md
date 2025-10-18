<p align="center">
  <pre style="color:#00FFFF; background-color:#000000; border-radius:10px; padding:10px;">
     ___                       ___   _____
    /   |  ____ ___  ____ ___ /   | /  _  \
   / /| | / __ `__ \/ __ `__ \/ /| |/  /_\  \
  / ___ |/ / / / / / / / / / / ___ /    |    \
 /_/  |_/_/ /_/ /_/_/ /_/ /_/_/  |_|\____|__  /
                                           \/ 
  </pre>
</p>

<p align="center">
  <img src="boot/logo.PNG" alt="AuraOS Logo" width="300" style="border-radius: 10px; background-color: #000000;" />
</p>

<h1 align="center">🌌 <span style="color:#FF0000;">A</span><span style="color:#FF7F00;">u</span><span style="color:#FFFF00;">r</span><span style="color:#00FF00;">a</span><span style="color:#0000FF;">O</span><span style="color:#4B0082;">S</span></h1>

<p align="center" style="color:#FFFFFF;">
  <b>O melhor sistema operacional baseado em BSD e Linux — moderno, rápido e open source.</b>
</p>

---

## 📂 Estrutura de Pastas

### 🔴 arm64/
Contém código em **assembly** para inicialização da arquitetura ARM64:
- `cpu_init.S` → Inicializa CPU, registradores, stack e MMU.
- `stack_init.S` → Configura stack pointer do kernel.
- `memory_init.S` → Inicializa memória, MMU e cache.
- `exception_vector.S` → Vetores de exceção ARM64.
- `boot_entry.S` → Ponto de entrada `_start`, chama CPU, vetores e bootloader.

### 🟠 automation_testing/
Scripts e código para **testes automáticos** do sistema.

### 🟡 bootloader/
Arquivos responsáveis pelo **boot do sistema** e seleção de modo de inicialização.

### 🟢 debug_mode/
Modo de debug, mostrando todos os logs do sistema e permitindo testes avançados.

### 🔵 seven_ui/
Interface **Seven UI** do AuraOS:
- `logic/` → Lógica da UI.
- `widgets/` → Componentes visuais.
- `input/` → Gerencia entradas do usuário.

### 🟣 NFC/
Integração com hardware NFC.

### 🟤 pico_tts/
Módulo TTS (Text-to-Speech) para AuraOS.

### ⚫ kernel/
Código do kernel, incluindo:
- `BSD/` → Componentes baseados em BSD.
- `panic/` → Kernel panic com cores RGB.
- `logUI/` → Exibe todos os logs do kernel.

### ⚪ open_source/
Exibe código aberto do AuraOS para usuários.

### 🔵 reboot/
Reinicia o sistema.

### 🟢 recovery/
Modo recovery com múltiplas opções para manutenção.

### 🟡 alert_system/
Sistema de alertas do governo com cores e animações RGB.

### 🔴 no_main/
Fallback do sistema quando o `main` não funciona.

### 🟠 main/
Contém `main.c` e `main.cpp`, ponto de compilação principal do AuraOS, que integra todos os módulos da pasta `Source`.

### 🟣 vendor/
Código de fornecedores e bibliotecas de terceiros.

---

## 📌 Observações

- Todos os arquivos estão **modulares**, permitindo atualização e manutenção fácil.  
- O **bootloader** chama `_start` em `boot_entry.S`, que inicializa CPU, memória, vetores de exceção e finalmente o kernel.  
- Os módulos podem ser ativados ou desativados via `sys_config_factory.cfg`.

---

## ⚡ Links úteis

<p align="center">
  <a href="https://github.com/enzogabryelbezerra2018-ui/auraOS-" target="_blank">
    <img src="https://img.shields.io/badge/🌐_Repositório-AuraOS-0A0A0A?style=for-the-badge&logo=github&logoColor=white" />
  </a>
  <a href="https://github.com/enzogabryelbezerra2018-ui/auraOS-/tree/main/Source" target="_blank">
    <img src="https://img.shields.io/badge/📂_Código_Fonte-Source-111111?style=for-the-badge&logo=codeium&logoColor=00FFFF" />
  </a>
  <a href="https://github.com/enzogabryelbezerra2018-ui/auraOS-/releases" target="_blank">
    <img src="https://img.shields.io/badge/⬇️_Baixar_Versão-Latest-1A1A1A?style=for-the-badge&logo=download&logoColor=00FF88" />
  </a>
  <a href="https://github.com/enzogabryelbezerra2018-ui/auraOS-/wiki" target="_blank">
    <img src="https://img.shields.io/badge/📖_Documentação-Wiki-111111?style=for-the-badge&logo=readthedocs&logoColor=00CFFF" />
  </a>
  <a href="https://github.com/enzogabryelbezerra2018-ui/auraOS-/issues" target="_blank">
    <img src="https://img.shields.io/badge/🐞_Reportar_Bug-Issues-1A1A1A?style=for-the-badge&logo=bugsnag&logoColor=FF3366" />
  </a>
  <a href="https://github.com/enzogabryelbezerra2018-ui" target="_blank">
    <img src="https://img.shields.io/badge/👨‍💻_Desenvolvedor-Enzo_Gabriel-000000?style=for-the-badge&logo=github&logoColor=FFFFFF" />
  </a>
</p>

---

## 📝 Créditos e Licença

- Desenvolvido por **Gabriel / Enzo**  
- Licenciado sob **MIT / BSD / Open Source**  
- Respeita licenças de código de terceiros presentes na pasta `vendor/`  
- Todos os módulos são de código aberto e podem ser modificados e redistribuídos conforme licenças.

---

<p align="center">
  <span style="color:#FF0000;">🌟</span>
  <span style="color:#FF7F00;">🌟</span>
  <span style="color:#FFFF00;">🌟</span>
  <span style="color:#00FF00;">🌟</span>
  <span style="color:#0000FF;">🌟</span>
  <span style="color:#4B0082;">🌟</span>
</p>

**Sistema:** AuraOS – Open Source, modular e para aprendizado.
