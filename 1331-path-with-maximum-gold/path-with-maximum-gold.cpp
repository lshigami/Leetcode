class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};
    vector<int>res;
    void backtrack(int i,int j,int n,int m,int &sum,vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;
        sum += grid[i][j];
        int local = sum;
        for(int k=0;k<4;k++){
            int in=i+p[k].first;
            int jn=j+p[k].second;
            if(in>=0 && jn>=0 && in<n && jn<m && grid[in][jn] && !visited[in][jn]){
                backtrack(in,jn,n,m,sum,grid,visited);
                sum = local;
            }
        }
        res.push_back(sum);
        visited[i][j] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                if(grid[i][j]){
                    backtrack(i,j,n,m,sum,grid,visited);
                }
            }
        }
        res.push_back(0);
        return *max_element(res.begin(),res.end());
    }
};
