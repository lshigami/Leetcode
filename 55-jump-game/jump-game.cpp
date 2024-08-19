class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canMove=0;
        int lastIndex=0;
        for(int i=0;i<nums.size();i++){
            if(i<=lastIndex){
                canMove=max(canMove,i+nums[i]);
                lastIndex=canMove;
            }
        }
        return canMove>=nums.size()-1;
    }
};