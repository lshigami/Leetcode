class Solution {
public:
    //1 5 13 26
    bool valid(int size, vector<long long> prefix, int k, vector<int> nums) {
        for (int i = size - 1; i < prefix.size(); ++i) {
            long long sum = prefix[i]-((i>=size ? prefix[i-size] : 0));
            long long needed = (long long) nums[i] * size - sum;
            if (needed <= k) {
                return true;
            }
        }
        return false;
    }

    int maxFrequency(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int left = 1;
        int right = n;
        int result = 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, prefix, k, nums)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
