#include <stdio.h>

bool write_file(const char* path, const char* data){
    FILE *f = fopen(path, "w");
    if(!f) return false;
    fprintf(f, "%s", data);
    fclose(f);
    return true;
}

bool read_file(const char* path, char* buffer, int max_len){
    FILE *f = fopen(path, "r");
    if(!f) return false;
    fgets(buffer, max_len, f);
    fclose(f);
    return true;
}
