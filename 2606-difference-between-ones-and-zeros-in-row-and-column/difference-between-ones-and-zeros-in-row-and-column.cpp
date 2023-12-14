class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        map<int,int>row;
        map<int,int>col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1) row[i]++;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(v[i][j]==1) col[j]++;
            }
        }
        vector<vector<int>>diff(m,v[0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=row[i] + col[j] - (n-row[i]) -(m-col[j]);
            }
        }
        return diff;
    }
};