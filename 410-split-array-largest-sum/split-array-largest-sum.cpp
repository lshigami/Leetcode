class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxSum) {
    int currentSum = 0, splits = 1;
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            currentSum = num;
            splits++;
            if (splits > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

};