//PrefixTree_Tree
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():num(0),isWordEndFlag(false){
        for(int i=0;i<26;i++)
            next[i] = NULL;
    }
    void insert(string word){
         if(word.empty())
            return;
         num++;
         if(next[word[0]-'a']){
            if(word.size()==1)
                next[word[0]-'a']->isWordEndFlag = true;
            next[word[0]-'a']->insert(word.substr(1));
         }else{
            next[word[0]-'a'] = new TrieNode();
            if(word.size()==1)
                next[word[0]-'a']->isWordEndFlag = true;
            next[word[0]-'a']->insert(word.substr(1));
         }
    }
    bool search(string word){
        if(word.empty())
            return true;
        if(next[word[0]-'a']){
            if(word.size()==1)
                return next[word[0]-'a']->isWordEndFlag;
            return next[word[0]-'a']->search(word.substr(1));
        }else
            return false;
    }
    
    bool find(string word){
        if(word.empty())
            return true;
        if(next[word[0]-'a']){
            return next[word[0]-'a']->find(word.substr(1));
        }else
            return false;
    }

        bool isWordEndFlag;
        int num;//record the number of word that pass this letters;
        TrieNode* next[26];//there could be 26 branches of this node;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word.empty())
            return;
        // root->NumAddOne();
        root->num++;
        if(root->next[word[0]-'a']){
            if(word.size()==1)
                root->next[word[0]-'a']->isWordEndFlag = true;
            root->next[word[0]-'a']->insert(word.substr(1));
        }else{
            root->next[word[0]-'a']=new TrieNode();
            if(word.size()==1)
                root->next[word[0]-'a']->isWordEndFlag = true;
            root->next[word[0]-'a']->insert(word.substr(1));
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
         if(word.empty())
            return false;
         if(root->next[word[0]-'a']){
            if(word.size()==1){
                return root->next[word[0]-'a']->isWordEndFlag;
            }
            return root->next[word[0]-'a']->search(word.substr(1));
         }else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
         if(prefix.empty())
            return true;
         
         return root->find(prefix);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
