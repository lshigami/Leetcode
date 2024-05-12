class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>res;
        vector<int>v;
        for(int i=0;i<grid.size()-2;i++){
            vector<int>v;
            for(int j=0;j<grid[0].size()-2;j++){
                int m=INT_MIN;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        m=max(m,grid[x][y]);
                    }
                }
                v.push_back(m);
            }
            res.push_back(v);
        }
        return res;
    }
};