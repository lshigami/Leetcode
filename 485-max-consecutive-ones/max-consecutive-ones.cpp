class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int MAX=0;
        int index=0;
        int cur=0;
        while(index<nums.size()){
            if(nums[index]==1){
                cur+=1;
            }else{
                MAX=max(MAX,cur);
                cur=0;
            }
            index+=1;
        }
        return max(MAX,cur);
    }
};