#include "Trie.h"

TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;

    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index])
            current->children[index] = new TrieNode();

        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void Trie::dfs(TrieNode* node, std::string current, std::vector<std::string>& result) {
    if (node->isEndOfWord)
        result.push_back(current);

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            dfs(node->children[i],
                current + char(i + 'a'),
                result);
        }
    }
}

std::vector<std::string> Trie::prefixSearch(const std::string& prefix) {
    TrieNode* current = root;

    for (char c : prefix) {
        int index = c - 'a';
        if (!current->children[index])
            return {};
        current = current->children[index];
    }

    std::vector<std::string> result;
    dfs(current, prefix, result);
    return result;
}
