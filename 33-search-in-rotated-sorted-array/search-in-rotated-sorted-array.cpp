class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target<=nums[nums.size()-1] && nums[mid]<=nums[nums.size()-1]){
                if(nums[mid]<target){
                    left=mid+1;
                }
                else if(nums[mid]>target){
                    right=mid-1;
                }
                else return mid;
            }
            else if(target<=nums[nums.size()-1] && nums[mid]>nums[nums.size()-1]){
                left=mid+1;
            }
            else if(target>nums[nums.size()-1] && nums[mid]<=nums[nums.size()-1]){
                right=mid-1;
            }else {
                if(nums[mid]<target){
                    left=mid+1;
                }
                else if(nums[mid]>target){
                    right=mid-1;
                }
                else return mid;
            }
        }
        return -1;
    }
};