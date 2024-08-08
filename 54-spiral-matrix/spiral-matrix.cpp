class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();
        vector<int> res;
        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = m - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                res.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            if (rowBegin > rowEnd) break;
            
            for (int i = rowBegin; i <= rowEnd; i++) {
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if (colBegin > colEnd) break;
            
            for (int i = colEnd; i >= colBegin; i--) {
                res.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            if (rowBegin > rowEnd) break;
            
            for (int i = rowEnd; i >= rowBegin; i--) {
                res.push_back(matrix[i][colBegin]);
            }
            colBegin++;
        }
        
        return res;
    }
};