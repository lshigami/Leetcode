class Solution {
public:
    bool valid(int size, const std::vector<long long>& prefix, int k, const std::vector<int>& nums) {
        for (int i = size - 1; i < prefix.size(); ++i) {
            long long sum = prefix[i];
            if (i >= size) {
                sum -= prefix[i - size];
            }

            // Calculate the required number of operations to make all elements in the window equal to nums[i]
            long long needed = (long long) nums[i] * size - sum;
            if (needed <= k) {
                return true;
            }
        }
        return false;
    }

    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<long long> prefix(n);
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
