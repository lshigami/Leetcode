class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        vector<int>res(nums.size());
        int index=nums.size()-1;
        for(auto&x:nums) x=abs(x);
        while(left<=right){
            if(nums[left]<=nums[right]){
                res[index--]=nums[right--];
            }else{
                res[index--]=nums[left++];
            }
        }
        for(auto &x:res){
            x=x*x;
        }
        return res;
    }
};