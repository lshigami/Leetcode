class RandomizedCollection {
    unordered_map<int, vector<int>> m; 
    vector<int> v;
public:
    RandomizedCollection() {
        std::srand(std::time(nullptr));  
    }
    
    bool insert(int val) {
        bool result = m.find(val)==m.end();
        m[val].push_back(v.size());
        v.push_back(val);
        return result;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        int rmvIndex= m[val].back();
        int lastIndex= v.size()-1;
        if(rmvIndex==lastIndex){
            v.pop_back();
            removeBackFromMap(val);  
            return true;          
        }
        int lastVal=v[lastIndex];
        swap(v[rmvIndex],v[lastIndex]);

        removeBackFromMap(val);
        removeBackFromMap(lastVal);
        m[lastVal].push_back(rmvIndex);
        sort(m[lastVal].begin(),m[lastVal].end());

        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int i = std::rand() % n; 
        return v[i];
    }
    void removeBackFromMap(int val){
        m[val].pop_back();
        if(m[val].size()==0) m.erase(val);
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */