#pragma once
#include <queue>
#include <string>
#include <vector>

using namespace std;

class SearchHistory {
private:
    queue<string> history;
    static const int MAX_SIZE = 5;

public:
    void addSearch(const string& term);
    vector<string> getHistory() const;
    bool empty() const;
};
