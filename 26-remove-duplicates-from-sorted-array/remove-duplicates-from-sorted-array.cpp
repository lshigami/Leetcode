class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int slow = 0; 
        int fast = 1; 
        
        while(fast<nums.size()){
            if(nums[fast]==nums[slow]){
                fast++;
            }
            else{
                slow+=1;
                swap(nums[fast],nums[slow]);
                fast+=1;
            }
        }
        return slow+1;
    }
};
