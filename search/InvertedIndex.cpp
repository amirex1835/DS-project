#include "InvertedIndex.h"
#include <sstream>
#include <algorithm>

vector<string> InvertedIndex::tokenize(const string& text) const {
    vector<string> words;
    string word;
    stringstream ss(text);

    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    return words;
}

void InvertedIndex::addPost(int postId, const string& content) {
    vector<string> words = tokenize(content);

    for (const string& w : words) {
        index[w].insert(postId);
    }
}

unordered_set<int> InvertedIndex::search(const string& word) const {
    string w = word;
    transform(w.begin(), w.end(), w.begin(), ::tolower);

    if (index.find(w) == index.end())
        return {};

    return index.at(w);
}
