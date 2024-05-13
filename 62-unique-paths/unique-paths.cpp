class Solution {
public:
    vector<vector<int>>dp;
    int countUniquePaths(int x,int y,int m,int n){
        if(dp[x][y]!=-1) return dp[x][y];
        if(x==m-1 && y==n-1) return dp[x][y]=1;
        int count=0;
        if(x<m-1)  count+=countUniquePaths(x+1,y,m,n);
        if(y<n-1)  count+=countUniquePaths(x,y+1,m,n);
        return dp[x][y]=count;
    }
    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        return countUniquePaths(0,0,m,n);
    }
};