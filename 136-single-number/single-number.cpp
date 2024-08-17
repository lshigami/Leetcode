class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int last=0;
        for(auto x:nums) last^=x;
        return last;
    }
};