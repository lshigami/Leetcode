class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    s.insert({nums[i],nums[j],nums[k]});
                    j+=1;
                }
                else if(sum>0){
                    k-=1;
                }
                else j+=1;
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};