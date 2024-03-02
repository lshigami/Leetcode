class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0, j = n - 1, k = n - 1;
        
        while(i <= j){
            int square;
            if(abs(nums[i]) > abs(nums[j])){
                square = nums[i] * nums[i];
                i++;
            } else {
                square = nums[j] * nums[j];
                j--;
            }
            res[k--] = square;
        }
        return res;
    }
};