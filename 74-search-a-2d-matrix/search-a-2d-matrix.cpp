class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left <= right){
            int mid = (left+right) / 2;
            int mid_value = matrix[mid / n][mid % n];
            if(mid_value == target){
                return true;
            }else if(mid_value < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};
