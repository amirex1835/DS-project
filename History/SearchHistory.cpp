#include "SearchHistory.h"

void SearchHistory::addSearch(const string& term) {
    if (history.size() == MAX_SIZE) {
        history.pop(); // حذف قدیمی‌ترین
    }
    history.push(term);
}

vector<string> SearchHistory::getHistory() const {
    queue<string> temp = history;
    vector<string> result;

    while (!temp.empty()) {
        result.push_back(temp.front());
        temp.pop();
    }
    return result;
}

bool SearchHistory::empty() const {
    return history.empty();
}
