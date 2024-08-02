class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v = {-1, -1};
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) return v;
        v[0] = it - nums.begin();
        auto eit = upper_bound(it, nums.end(), target);
        v[1] = eit - nums.begin() - 1;
        return v;
    }
};