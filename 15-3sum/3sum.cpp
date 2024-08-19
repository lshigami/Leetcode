class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++){
            if(k>0 && nums[k]==nums[k-1]) continue;
            int left=k+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[k]+nums[left]+nums[right];
                if(sum==0){
                    res.push_back({nums[k], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if(sum<0){
                    left+=1;
                }
                else {
                    right-=1;
                }
            }
        }
        return res;
    }
};