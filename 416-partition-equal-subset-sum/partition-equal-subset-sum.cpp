class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (totalSum % 2 != 0) {
            return false;
        }
        int halfSum = totalSum / 2;
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = halfSum; j >= nums[i]; j--) {
                if (dp[j - nums[i]])
                    dp[j] = true;
            }
        }
        return dp[halfSum];
    }
};
