class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>m;
        for(auto x:nums){
            for(auto i:x){
                m[i]+=1;
            }
        }
        vector<int>res;
        for(auto x:m){
            if(x.second==nums.size()){
                res.push_back(x.first);
            }
        }
        return res;
    }
};