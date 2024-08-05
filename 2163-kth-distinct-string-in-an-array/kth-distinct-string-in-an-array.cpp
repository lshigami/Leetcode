class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        for(auto x:arr){
            m[x]+=1;
        }
        vector<string>res;
        for(auto x:arr){
            if(m[x]==1) res.push_back(x);
        }
        return ((res.empty()||k-1>res.size()) ? "": res[k-1]);
    }
};