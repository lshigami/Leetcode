class Solution {
public:
    int maxProduct(vector<int>& v) {
        auto it=max_element(v.begin(),v.end());
        int x=*it;
        v.erase(it);
        it=max_element(v.begin(),v.end());
        return (x-1)*(*it-1);
    }
};