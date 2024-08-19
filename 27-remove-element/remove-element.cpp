class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(nums[right]==val) right-=1;
            else if(nums[left]!=val) left+=1;
            else swap(nums[left],nums[right]);

        }
        return right+1;
    }
};