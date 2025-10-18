#ifndef OPEN_SOURCE_H
#define OPEN_SOURCE_H

#include <string>
#include <vector>

struct FileInfo {
    std::string name;
    bool is_dir;
    uint64_t size;
    std::string modified;
};

namespace OpenSource {
    std::vector<FileInfo> list_directory(const std::string &relative_path);
    bool read_file(const std::string &relative_path, std::string &out_content, std::string &out_err);
    bool write_file(const std::string &relative_path, const std::string &content, std::string &out_err);
    bool create_directory(const std::string &relative_path, std::string &out_err);
    bool remove_path(const std::string &relative_path, std::string &out_err);
    bool rename_path(const std::string &old_relative, const std::string &new_relative, std::string &out_err);
    bool exists(const std::string &relative_path, bool &out_is_dir);
    std::string get_root_path();
}

#endif
