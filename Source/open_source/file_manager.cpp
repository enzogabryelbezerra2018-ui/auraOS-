#include "open_source.h"
#include <filesystem>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace fs = std::filesystem;

namespace OpenSource {

    static const std::string open_source_root = "Source/open_source_repo";

    std::string get_root_path() {
        try {
            return fs::canonical(open_source_root).string();
        } catch(...) {
            fs::create_directories(open_source_root);
            return open_source_root;
        }
    }

    static bool resolve_and_check(const std::string &relative, fs::path &out_abs, std::string &out_err) {
        try {
            fs::path root = fs::path(get_root_path());
            fs::path candidate = root / relative;
            fs::path abs = fs::weakly_canonical(candidate);
            std::string abs_s = abs.string();
            std::string root_s = fs::weakly_canonical(root).string();
            if (abs_s.size() < root_s.size() || abs_s.rfind(root_s, 0) != 0) {
                out_err = "Path fora do diretório permitido.";
                return false;
            }
            out_abs = abs;
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro ao resolver path: ") + e.what();
            return false;
        }
    }

    std::vector<FileInfo> list_directory(const std::string &relative_path) {
        std::vector<FileInfo> list;
        std::string err;
        fs::path abs;
        if(!resolve_and_check(relative_path, abs, err)) return list;
        try {
            if(!fs::exists(abs)) return list;
            for (auto &entry : fs::directory_iterator(abs)) {
                FileInfo fi;
                fi.is_dir = entry.is_directory();
                fi.name = entry.path().filename().string();
                fi.size = fi.is_dir ? 0 : (uint64_t)fs::file_size(entry.path());
                auto ftime = fs::last_write_time(entry.path());
                auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                    ftime - fs::file_time_type::clock::now()
                    + std::chrono::system_clock::now()
                );
                std::time_t tt = std::chrono::system_clock::to_time_t(sctp);
                std::ostringstream ss;
                ss << std::put_time(std::localtime(&tt), "%Y-%m-%d %H:%M:%S");
                fi.modified = ss.str();
                list.push_back(fi);
            }
        } catch(...) {}
        return list;
    }

    bool read_file(const std::string &relative_path, std::string &out_content, std::string &out_err) {
        fs::path abs;
        if(!resolve_and_check(relative_path, abs, out_err)) return false;
        try {
            if(!fs::exists(abs)) { out_err = "Arquivo não existe."; return false; }
            if(fs::is_directory(abs)) { out_err = "Caminho é um diretório."; return false; }
            std::ifstream f(abs, std::ios::binary);
            if(!f) { out_err = "Falha ao abrir arquivo para leitura."; return false; }
            std::ostringstream ss;
            ss << f.rdbuf();
            out_content = ss.str();
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro leitura: ") + e.what();
            return false;
        }
    }

    bool write_file(const std::string &relative_path, const std::string &content, std::string &out_err) {
        fs::path abs;
        if(!resolve_and_check(relative_path, abs, out_err)) return false;
        try {
            if (abs.has_parent_path()) fs::create_directories(abs.parent_path());
            std::ofstream f(abs, std::ios::binary | std::ios::trunc);
            if(!f) { out_err = "Falha ao abrir arquivo para escrita."; return false; }
            f << content;
            f.close();
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro escrita: ") + e.what();
            return false;
        }
    }

    bool create_directory(const std::string &relative_path, std::string &out_err) {
        fs::path abs;
        if(!resolve_and_check(relative_path, abs, out_err)) return false;
        try {
            if(fs::exists(abs)) { out_err = "Já existe."; return false; }
            fs::create_directories(abs);
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro criação: ") + e.what();
            return false;
        }
    }

    bool remove_path(const std::string &relative_path, std::string &out_err) {
        fs::path abs;
        if(!resolve_and_check(relative_path, abs, out_err)) return false;
        try {
            fs::path root = fs::path(get_root_path());
            if (fs::equivalent(abs, root)) { out_err = "Remoção do diretório root proibida."; return false; }
            if(!fs::exists(abs)) { out_err = "Caminho não existe."; return false; }
            fs::remove_all(abs);
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro remoção: ") + e.what();
            return false;
        }
    }

    bool rename_path(const std::string &old_relative, const std::string &new_relative, std::string &out_err) {
        fs::path abs_old, abs_new;
        if(!resolve_and_check(old_relative, abs_old, out_err)) return false;
        if(!resolve_and_check(new_relative, abs_new, out_err)) return false;
        try {
            if(!fs::exists(abs_old)) { out_err = "Origem não existe."; return false; }
            if(abs_old == abs_new) { out_err = "Mesma path."; return false; }
            if (abs_new.has_parent_path()) fs::create_directories(abs_new.parent_path());
            fs::rename(abs_old, abs_new);
            return true;
        } catch (const std::exception &e) {
            out_err = std::string("Erro rename: ") + e.what();
            return false;
        }
    }

    bool exists(const std::string &relative_path, bool &out_is_dir) {
        fs::path abs;
        std::string err;
        if(!resolve_and_check(relative_path, abs, err)) return false;
        try {
            if(!fs::exists(abs)) return false;
            out_is_dir = fs::is_directory(abs);
            return true;
        } catch(...) { return false; }
    }
}
