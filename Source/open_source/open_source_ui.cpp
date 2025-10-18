// Source/open_source/open_source_ui.cpp
// Console UI simples para gerenciar arquivos dentro do open_source_root.
// Compile com -std=c++17
#include "open_source.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string root_display = OpenSource::get_root_path();

static void print_header() {
    cout << "=== AuraOS Open Source Manager ===" << endl;
    cout << "Root: " << root_display << endl;
    cout << "Comandos: ls [path], cat path, edit path, rm path, mkdir path, mv old new, touch path, exit" << endl;
}

static string prompt() {
    cout << "> ";
    string line;
    getline(cin, line);
    return line;
}

static void cmd_ls(const string &arg) {
    auto list = OpenSource::list_directory(arg);
    for (auto &f : list) {
        cout << (f.is_dir ? "[DIR] " : "      ") << f.name << "\t" << f.size << " bytes\t" << f.modified << endl;
    }
}

static void cmd_cat(const string &arg) {
    string content, err;
    if (OpenSource::read_file(arg, content, err)) {
        cout << content << endl;
    } else {
        cerr << "Erro: " << err << endl;
    }
}

static void cmd_edit(const string &arg) {
    cout << "Abrindo em modo de edição simples. Digite o novo conteúdo. Fim com uma linha contendo somente '.save'" << endl;
    string line, all;
    while (true) {
        getline(cin, line);
        if (line == ".save") break;
        all += line + "\n";
    }
    string err;
    if (OpenSource::write_file(arg, all, err)) {
        cout << "Arquivo salvo: " << arg << endl;
    } else {
        cerr << "Erro salvando: " << err << endl;
    }
}

static void cmd_rm(const string &arg) {
    cout << "Tem certeza que quer REMOVER '" << arg << "' ? (sim/nao): ";
    string ans; getline(cin, ans);
    if (ans == "sim" || ans == "s") {
        string err;
        if (OpenSource::remove_path(arg, err)) cout << "Removido." << endl;
        else cerr << "Erro: " << err << endl;
    } else cout << "Cancelado." << endl;
}

static void cmd_mkdir(const string &arg) {
    string err;
    if (OpenSource::create_directory(arg, err)) cout << "Diretório criado." << endl;
    else cerr << "Erro: " << err << endl;
}

static void cmd_mv(const string &oldp, const string &newp) {
    string err;
    if (OpenSource::rename_path(oldp, newp, err)) cout << "Renomeado/movido." << endl;
    else cerr << "Erro: " << err << endl;
}

static void cmd_touch(const string &arg) {
    string err;
    if (OpenSource::write_file(arg, "", err)) cout << "Arquivo criado (vazio)." << endl;
    else cerr << "Erro: " << err << endl;
}

int main_open_source_console() {
    print_header();
    while (true) {
        string line = prompt();
        if (line.empty()) continue;
        // split
        vector<string> parts;
        {
            std::istringstream iss(line);
            string token;
            while (iss >> token) parts.push_back(token);
        }
        string cmd = parts[0];
        if (cmd == "exit") break;
        if (cmd == "ls") {
            string arg = (parts.size()>1? parts[1] : "");
            cmd_ls(arg);
            continue;
        }
        if (cmd == "cat" && parts.size()>1) { cmd_cat(parts[1]); continue; }
        if (cmd == "edit" && parts.size()>1) { cmd_edit(parts[1]); continue; }
        if (cmd == "rm" && parts.size()>1) { cmd_rm(parts[1]); continue; }
        if (cmd == "mkdir" && parts.size()>1) { cmd_mkdir(parts[1]); continue; }
        if (cmd == "mv" && parts.size()>2) { cmd_mv(parts[1], parts[2]); continue; }
        if (cmd == "touch" && parts.size()>1) { cmd_touch(parts[1]); continue; }

        cout << "Comando inválido ou parâmetros faltando." << endl;
    }
    cout << "Saindo do Open Source Manager." << endl;
    return 0;
}
