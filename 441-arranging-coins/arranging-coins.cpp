class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1;
        long long right = (-1 + sqrt(1 + 8 * (long long)n)) / 2;
        int ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long value = mid * (mid + 1) / 2;
            if (value <= n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
