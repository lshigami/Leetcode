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
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            if (cur.size() == nums.size()) {
                ans.push_back(cur);
            }
            else backtrack(nums, cur, ans, used);
            used[i] = false;
            cur.pop_back();
        }
    }
};
