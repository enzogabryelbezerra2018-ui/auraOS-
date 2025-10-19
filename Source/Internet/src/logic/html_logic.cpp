#include "html_logic.h"
#include <vector>
#include <string>
#include "internet_db.h"
#include "../network/http_client.h"

struct HtmlChar {
    char ch;
    uint32_t color;
};

std::vector<HtmlChar> html_buffer;

void navigate_to(const std::string& url) {
    std::string html_data = http_download(url);
    cache_page(url, html_data);

    // Parse usando interpretador Java (pseudo-call)
    // Aqui você precisa do bridge Java↔C++ real
    html_buffer.clear();
    // Simplificando: converte cada linha em HtmlChar
    for(char c: html_data){
        html_buffer.push_back({c, 0xFFFFFF});
    }
}

const std::vector<HtmlChar>& get_html_buffer() {
    return html_buffer;
}
