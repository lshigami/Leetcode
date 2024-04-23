class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minSize = nums.size() + 1;
        while (right < nums.size() && sum<target ) {
            sum += nums[right];

            if (sum >= target) {
                while (sum >= target) {
                    sum -= nums[left];
                    minSize = min(minSize, right - left + 1);
                    left++;
                }
            }
            right += 1;
        }
        return minSize == nums.size() + 1 ? 0 : minSize;
    }
};