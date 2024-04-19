class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};
    void flooding(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            int x=i+p[k].first;
            int y=j+p[k].second;
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1'){
                flooding(grid,x,y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans+=1;
                    flooding(grid,i,j);
                }
            }
        }
        return ans;
    }
};