class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        map<int,int>m;
        int smaller=0;
        for(auto x:nums){
            if(x<target) smaller+=1;
            if(x==target) m[x]+=1;
        }
        vector<int>res;
        if(m.find(target)==m.end()) return {-1,-1};
        res.push_back(smaller);
        res.push_back(smaller+m[target]-1);   
        return res;
    }
};