class Solution {
public:
    void Backtrack(vector<vector<int>>&ans,vector<int>temp,vector<int>& nums,int idx,int last){
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            last+=1;
            if(last!=(int)pow(2,nums.size())) Backtrack(ans,temp,nums,i+1,last);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        ans.push_back({});
        Backtrack(ans,temp,nums,0,1);
        return ans;
    }
};