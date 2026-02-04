#pragma once
#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, std::string current, std::vector<std::string>& result);

public:
    Trie();

    void insert(const std::string& word);
    std::vector<std::string> prefixSearch(const std::string& prefix);
};

#endif
