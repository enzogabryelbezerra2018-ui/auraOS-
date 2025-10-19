#include "internet_logic.h"
#include "internet_db.h"
#include "../network/http_client.h"
#include "../html/html_interpreter.h"
#include <string>

void navigate_to(const std::string& url) {
    std::string html_data = http_download(url);  // baixa HTML
    cache_page(url, html_data);                   // salva cache
    render_page(html_data);                       // envia para interpretador
}

void render_page(const std::string& html_data) {
    parse_html(html_data);  // chama Java ou engine embutida
}
