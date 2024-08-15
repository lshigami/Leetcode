class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target);
        // if(it==nums.end()) return nums.size();
        return it-nums.begin();
    }
};