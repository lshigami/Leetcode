class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> m; 
        for (auto x : nums) {
            m[x]++;
        }
        int cnt = 0;
        for (auto x : nums) {
            if (m[x] == 0) continue;
            if (m[x + k]) {
                cnt += m[x + k];
            }
            if (m[x - k]) {
                cnt += m[x - k];
            }
            m[x]--; // Giảm tần suất của x sau khi sử dụng
        }
        return cnt;
    }
};
