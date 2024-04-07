class Solution {
public:
    int Merge(vector<int>&nums,int l,int mid,int r){
        // 1. count
        int j = mid + 1;
        int reverse_pairs = 0;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2ll * nums[j]) {
                j++;
            }            
            reverse_pairs += (j - 1 - mid);
        }

        // 2. merge
        vector< int > merge;
        int i = l;
        j = mid + 1;
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

        return reverse_pairs;
    }
    int Count(vector<int>&v, int l,int r){
        if(l==r) return 0;
        int m=(l+r)/2;
        int left=Count(v,l,m);
        int right=Count(v,m+1,r);
        return left+right+Merge(v,l,m,r);
    }
    int reversePairs(vector<int>& nums) {
        int x=Count(nums,0,nums.size()-1);
        return x;
    }
};