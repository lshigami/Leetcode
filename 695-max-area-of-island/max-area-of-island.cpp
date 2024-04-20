class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};
    void flooding(vector<vector<int>>& grid,int i,int j,int &count){
        if(count==0) count=1;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int in=i+p[k].first;
            int jn=j+p[k].second;
            if(in>=0 && jn>=0 && in<grid.size() && jn<grid[0].size() && grid[in][jn]){
                count+=1;
                flooding(grid,in,jn,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int count=0;
                if(grid[i][j]){
                    flooding(grid,i,j,count);
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};