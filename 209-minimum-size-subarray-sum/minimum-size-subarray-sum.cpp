class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int Min = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                Min = min(Min, right - left + 1);
                cout<<Min<<" ";
                sum -= nums[left++];
            }
        }
        return Min == INT_MAX ? 0 : Min;
    }
};