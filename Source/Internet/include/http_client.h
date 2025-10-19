// include/http_client.h
#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>

// Baixa página HTML de uma URL (HTTP/HTTPS)
std::string http_download(const std::string& url);

#endif // HTTP_CLIENT_H
