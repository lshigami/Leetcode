class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            //[3,3,7,7,10,11,11]
            // 0 1 2 3 4  5  6
            int mid=left+(right-left)/2;
            if(mid==0){
                if(nums[mid+1]==nums[mid]) left=mid+1;
                else return nums[mid];
            }
            if(mid==nums.size()-1){
                if(nums[mid-1]==nums[mid]) right=mid-1;
                else return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if((mid-1)%2==0) left=mid+1;
                else right=mid-1;
            }else if(nums[mid]==nums[mid+1]){
                if((mid)%2==0) left=mid+1;
                else right=mid-1;
            }
            else return nums[mid];
        }
        return -1;
    }
};