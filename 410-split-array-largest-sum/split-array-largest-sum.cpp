class Solution {
public:
    bool valid(int maxSum, vector<int> nums, int k) {
        int currentSum = 0, splits = 1;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                currentSum = num;
                splits++;
                if (splits > k)
                    return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(),0);
        int sum = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, nums, k)) {
                sum = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return sum;
    }
};