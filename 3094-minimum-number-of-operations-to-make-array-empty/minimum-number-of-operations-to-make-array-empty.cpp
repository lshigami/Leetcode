class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        int ans=0;
        for(auto x:m){
            if(x.second==1) return -1;
            int g= x.second/3;
            int d=x.second%3;
            if(d>0) ans+=g+1;
            else ans+=g;
        }
        return ans;
    }
};