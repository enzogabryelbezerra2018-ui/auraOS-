#include "internet_db.h"
#include <vector>
#include <string>

struct PageRecord {
    std::string url;
    std::string html_data;
};

static std::vector<PageRecord> history;

void cache_page(const std::string& url, const std::string& html_data) {
    history.push_back({url, html_data});
}
