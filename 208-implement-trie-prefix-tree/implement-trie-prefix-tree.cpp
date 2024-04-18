class TrieNode{
public:
    map<char, TrieNode*> child;
    bool endOfWord;
    TrieNode(){
        endOfWord=false;
    }
};

class Trie {
    TrieNode*root;
public:
    Trie() {
        this->root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*node=root;
        for(auto c:word){
            if(node->child.count(c)==0){
                node->child[c]=new TrieNode();
            }
            node=node->child[c];
        }
        node->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode*node=root;
        for(auto c:word){
            if(node->child.count(c)==0) return false;
            node=node->child[c];
        }
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode*node=root;
        for(auto c:prefix){
            if(node->child.count(c)==0) return false;
            node=node->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */