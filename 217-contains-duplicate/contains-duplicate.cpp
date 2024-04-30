class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums){
            if(m[x]==1) return true;
            else m[x]=1;
        }
        return false;
    }
};