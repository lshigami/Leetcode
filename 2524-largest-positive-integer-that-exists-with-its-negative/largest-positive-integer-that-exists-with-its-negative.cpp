class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxPositive = -1;
        unordered_map<int, int> m;
        for (auto x : nums) {
            m[x]=1;
        }
        for(auto x:nums){
            if(x>0 && m[-x]) maxPositive=max(maxPositive,x);
        }
        return maxPositive;
    }
};