class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, cur, ans, used);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, vector<bool>& used) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Nếu phần tử đã được sử dụng, bỏ qua.
            if (used[i]) continue;

            // Bỏ qua các phần tử trùng lặp nếu phần tử trước đó giống hệt và chưa được sử dụng.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            // Đánh dấu phần tử hiện tại là đã sử dụng.
            used[i] = true;
            cur.push_back(nums[i]);

            // Gọi đệ quy với trạng thái mới.
            backtrack(nums, cur, ans, used);

            // Hoàn tác thay đổi.
            used[i] = false;
            cur.pop_back();
        }
    }
};
