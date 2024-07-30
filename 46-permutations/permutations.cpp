class Solution {
private:
    unordered_map<int, bool> m;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>ans;
        backtracking(nums,cur,ans);
        return ans;
    }
    void backtracking(vector<int> nums, vector<int> cur,vector<vector<int>>& ans) {
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                cur.push_back(nums[i]);
                m[nums[i]]=1;
                if(cur.size()==nums.size()) {
                    ans.push_back(cur);
                }
                else{
                    backtracking(nums,cur,ans);
                }
                m[nums[i]]=0;
                cur.pop_back();
            }
        }
    }
};