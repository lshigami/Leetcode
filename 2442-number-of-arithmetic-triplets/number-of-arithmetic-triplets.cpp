class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        int cnt=0;
        for(auto x:nums){
            if(m[diff+x] && m[diff+x+diff]) cnt++;
        }
        return cnt;
    }

};