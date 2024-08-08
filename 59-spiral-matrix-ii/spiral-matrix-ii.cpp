class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int cnt=1;
        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                matrix[rowBegin][i]=cnt++;
            }
            rowBegin++;
            if (rowBegin > rowEnd) break;
            
            for (int i = rowBegin; i <= rowEnd; i++) {
                matrix[i][colEnd]=cnt++;
            }
            colEnd--;
            if (colBegin > colEnd) break;
            
            for (int i = colEnd; i >= colBegin; i--) {
                matrix[rowEnd][i]=cnt++;
            }
            rowEnd--;
            if (rowBegin > rowEnd) break;
            
            for (int i = rowEnd; i >= rowBegin; i--) {
                matrix[i][colBegin]=cnt++;
            }
            colBegin++;
        }
        
        return matrix;
    }
};