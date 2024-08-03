class Solution {
public:
     bool valid(int fre, std::vector<int> nums, int k) {
        int n = nums.size();
        long long total = 0;
        int left = 0;
        long long cost = 0;

        for (int right = 0; right < n; ++right) {
            total += nums[right];
            if (right - left + 1 > fre) {
                total -= nums[left];
                ++left;
            }
            cost = 1LL * nums[right] * (right - left + 1) - total;
            if (right - left + 1 == fre && cost <= k) {
                return true;
            }
        }

        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=1;
        int right=nums.size();
        int fre=1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(valid(mid,nums,k)){
                fre=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return fre;
    }
};