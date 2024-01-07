class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        set<int>s;
        for(auto x:m){
            s.insert(x.second);
        }
        return s.size()==m.size();
    }
};
