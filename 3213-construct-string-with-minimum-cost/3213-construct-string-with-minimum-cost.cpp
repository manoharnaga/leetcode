class TrieNode {
public:
    TrieNode* children[26];
    int cost;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        cost = INT_MAX;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word, int cost) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->cost = min(node->cost, cost); // Update cost if smaller
    }
    
    int search(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx])
                return INT_MAX; // No matching prefix found
            node = node->children[idx];
        }
        return node->cost;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.insert(words[i], costs[i]);
        }
        
        int targetLength = target.size();
        vector<int> dp(targetLength + 1, INT_MAX);
        dp[0] = 0; 
        for (int i = 0; i < targetLength; ++i) {
            if (dp[i] == INT_MAX)
                continue; 
            TrieNode* node = trie.root;
            for (int j = i; j < targetLength; ++j) {
                int idx = target[j] - 'a';
                if (!node->children[idx])
                    break;  

                node = node->children[idx];
                if (node->cost != INT_MAX) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + node->cost);
                }
            }
        }
        
        return dp[targetLength] == INT_MAX ? -1 : dp[targetLength];
    }
};
