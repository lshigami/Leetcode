class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
                for(int j=0;j<grid[0].size();j++){
                    grid[i][j]= (grid[i][j]) ? 0 : 1;
                }
            }
        }
        for(int j=0;j<grid[0].size();j++){
            int countZero=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0) countZero+=1; 
            }
            if(grid.size()-countZero>countZero) continue;
            for(int i=0;i<grid.size();i++){
                grid[i][j]= (grid[i][j]) ? 0 : 1;
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int row=0;
            int k=grid[0].size()-1;
            for(int j=0;j<grid[0].size();j++){
                row += grid[i][j] * pow(2, k--);
            }
            ans+=row;
        }
        return ans;
    }
};