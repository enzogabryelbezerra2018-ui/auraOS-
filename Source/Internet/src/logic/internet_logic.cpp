#include "internet_logic.h"
#include "internet_db.h"
#include "../network/http_client.h"
#include <string>

void navigate_to(const std::string& url) {
    std::string html_data = http_download(url);
    cache_page(url, html_data);             // salva no banco
    html_interpret(html_data);              // envia para interpretador Java
}
