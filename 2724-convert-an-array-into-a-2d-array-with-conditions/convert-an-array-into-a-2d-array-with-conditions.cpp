class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>m;
        int end=INT_MIN;
        for(auto x:nums){
            m[x]++;
            end=max(end,m[x]);
        }
        vector<vector<int>>ans;
        int flag=0;
        while(flag!=end){
            vector<int>temp;
            vector<bool>visited(nums.size()+1,false);            
            for(int i=0;i<nums.size();i++){
                if(!visited[nums[i]] && m[nums[i]]){
                    temp.push_back(nums[i]);
                    m[nums[i]]--;
                    visited[nums[i]]=true;
                }
            }
            ans.push_back(temp);
            flag++;
        }
        return ans;
    }
};