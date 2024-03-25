class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
    for (int i = 0; i < nums.size(); i++) {
        int n = std::abs(nums[i]);
        if (nums[n - 1] < 0) {
            duplicates.push_back(n);
        } else {
            nums[n - 1] *= -1;
        }
    }
    return duplicates;
    }
};