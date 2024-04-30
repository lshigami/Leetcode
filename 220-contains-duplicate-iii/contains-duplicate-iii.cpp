class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int z) {
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // Remove numbers out of range k
            // -z <= x - nums[i] <= z; so nums[i] - z <= x <= nums[i] + z;
            auto it = window.lower_bound((long long) nums[i] - z);
            if (it != window.end() && *it <= ((long long) nums[i] + z))
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
