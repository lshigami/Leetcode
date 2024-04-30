class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int z) {
        set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]);
            auto it = window.lower_bound( nums[i] - z);
            if (it != window.end() && *it <= ( nums[i] + z))
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
