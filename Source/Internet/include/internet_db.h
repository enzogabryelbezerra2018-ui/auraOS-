// include/internet_db.h
#ifndef INTERNET_DB_H
#define INTERNET_DB_H

#include <string>

// Salva página no cache / histórico
void cache_page(const std::string& url, const std::string& html_data);

#endif // INTERNET_DB_H
