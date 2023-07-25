class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // check null cases
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        
        // it : i_total
        int it = m + n - 1;
        int i1 = m - 1, i2 = n - 1;
        
        while (it >= 0) {
            if (i1 < 0) {
                nums1[it--] = nums2[i2--];
                continue;
            }
            if (i2 < 0) {
                break;
            }
            
            if (nums1[i1] > nums2[i2]) {
                nums1[it--] = nums1[i1--];
            } else {
                nums1[it--] = nums2[i2--];
            }
        }
    }
};
