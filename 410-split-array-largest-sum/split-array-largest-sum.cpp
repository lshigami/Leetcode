class Solution {
public:
    bool valid(int maxSum, vector<int> nums, int k) {
/*
Nó kêu mình split k cái, nhưng nếu giả sử chỉ split k-1 thì cũng ok ( vì càng split càng ok)
*/      
        int curSum=0,split=1;
        for(auto x:nums){
            curSum+=x;
            if(curSum>maxSum){
                curSum=x;
                if(curSum>maxSum) return false;
                split+=1;
            }
        }
        return split<=k;

    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(),0);
        int sum = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, nums, k)) {
                sum = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return sum;
    }
};