#pragma once
#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class InvertedIndex {
private:
    unordered_map<string, unordered_set<int>> index;

    vector<string> tokenize(const string& text) const;

public:
    void addPost(int postId, const string& content);
    unordered_set<int> search(const string& word) const;
};

#endif
