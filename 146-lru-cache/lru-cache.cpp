class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int x) : value(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    Node* LRU;
    Node* MRU;
    unordered_map<int, Node*> m;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        LRU = MRU = new Node(-1);
        LRU->next = MRU;
        MRU->prev = LRU;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        Node* cur = m[key];
        remove(cur);
        insert(cur);
        return cur->value;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* cur = m[key];
            cur->value = value;
            remove(cur);
            insert(cur);
        } else {
            Node* newNode = new Node(value);
            insert(newNode);
            m[key] = newNode;
            if (m.size() > capacity) {
                Node* leastUsed = LRU->next;
                remove(leastUsed);
                auto it = find_if(m.begin(), m.end(), 
                    [leastUsed](const auto& pair) { return pair.second == leastUsed; });
                if (it != m.end()) {
                    m.erase(it);
                }
                delete leastUsed;
            }
        }
    }

    void insert(Node* node) {
        Node* previousEnd = MRU->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = MRU;
        MRU->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};