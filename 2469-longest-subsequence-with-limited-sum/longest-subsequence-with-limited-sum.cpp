class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto x:queries){
            int sum=0;
            int MAX=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum<=x){
                    MAX=max(MAX,i+1);
                }
            }
            ans.push_back(MAX);
        }
        return ans;
    }
};