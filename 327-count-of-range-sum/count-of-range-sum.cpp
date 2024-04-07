class Solution {
public:
    int count_merge(vector< long long > &nums, int l, int r, int mid, int lower, int upper) {
        // merge sort [l, mid], [mid + 1, r]
        // count reverse pairs of [l, mid], [mid + 1, r]
        // [l, mid] => sorted, [mid + 1, r] => sorted
        // number pairs of upper >= nums[j] - nums[i] >= lower
        // upper + nums[i] >= nums[j] >= lower + nums[i]

        // 1. count
        int lower_pos = mid + 1;
        int upper_pos = mid + 1;
        int range_count = 0;
        for (int i = l; i <= mid; i++) {
            while (lower_pos <= r && nums[lower_pos] < nums[i] + lower) {
                lower_pos++;
            }
            // nums[lower_pos] >= lower + nums[i]

            while (upper_pos <= r && nums[upper_pos] <= nums[i] + upper) {
                upper_pos++;
            }
            // nums[upper_pos] > upper + nums[i]
            // j in [lower_pos, upper_pos)
            
            range_count += (upper_pos - lower_pos);
        }

        // 2. merge
        vector< long long > merge;
        int i = l;
        int j = mid + 1;
        while (i <= mid || j <= r) {
            if (i > mid) {
                merge.push_back(nums[j++]);
                continue;
            }
            if (j > r) {
                merge.push_back(nums[i++]);
                continue;
            }

            if (nums[i] < nums[j]) {
                merge.push_back(nums[i++]);
            } else {
                merge.push_back(nums[j++]);
            }
        }


        for (int i = l; i <= r; i++) {
            nums[i] = merge[i - l];
        }

        return range_count;
    }

    int count(vector< long long > &nums, int l, int r, int lower, int upper) {
        if (l == r) {
            return 0;
        }

        // count then sort nums subarray from [l, r]
        int mid = (l + r) / 2;

        int count_left = count(nums, l, mid, lower, upper);
        int count_right = count(nums, mid + 1, r, lower, upper);
        int count_cross = count_merge(nums, l, r, mid, lower, upper);

        return count_left + count_right + count_cross;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector< long long > sums;
        long long sum = 0;
        sums.push_back(sum);
        for (int num : nums) {
            sum += num;
            sums.push_back(sum);
        }

        // i < j
        // count pairs (i, j) in sums when upper >= sums[j] - sums[i] >= lower
        // sum[i, j] = sums[j] - sums[i - 1]

        return count(sums, 0, sums.size() - 1, lower, upper);
    }
};