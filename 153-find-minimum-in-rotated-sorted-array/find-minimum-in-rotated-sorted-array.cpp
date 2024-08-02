class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((mid==left || nums[mid-1]>nums[mid]) && (mid==right || nums[mid+1]>nums[mid])){
                return nums[mid];
            }
            if(nums[mid]>nums[nums.size()-1]) {
                left=mid+1;
            }
            else right=mid-1;
        }
        return -1;
    }
};