class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUnique=1;
        for(int i=1;i<nums.size();i++){
            if(nums[lastUnique-1]!=nums[i]){
                swap(nums[i],nums[lastUnique]);
                lastUnique+=1;
            }
        }
        return lastUnique;
    }
};