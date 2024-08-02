class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        vector<int>cur;
        vector<vector<int>>ans;
        backtrack(nums,cur,ans,0);
        for(auto x:ans){
            int temp_sum=0;
            for(auto e:x){
                temp_sum=temp_sum^e;
            }
            sum+=temp_sum;
        }
        return sum;
    }
    void backtrack(vector<int>nums,vector<int>cur,vector<vector<int>>&ans,int start){
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            ans.push_back(cur);
            backtrack(nums,cur,ans,i+1);
            cur.pop_back();
        }
    }
};