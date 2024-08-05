class Solution {
public:
    int lowerBound(vector<int>nums,int value){
        int left=0;
        int right=nums.size()-1;
        int ans=nums.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=value){
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int index=lowerBound(ans,nums[i]);
            if(index==ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};