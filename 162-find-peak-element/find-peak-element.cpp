class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int result = -1; // Initialize result to store the peak index
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0 || nums[mid] > nums[mid - 1]) {  // Edge case when mid is at the start
                if (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) {  // Edge case when mid is at the end
                    result = mid;  // Found the peak
                    break;
                } else {
                    l = mid + 1;  // Move right
                }
            } else {
                r = mid - 1;  // Move left
            }
        }
        
        return result;
    }
};
