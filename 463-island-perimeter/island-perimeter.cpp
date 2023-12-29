class Solution {
public:
    int islandPerimeter(vector<vector<int>>& v) {
        int ans=0;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j]==1){
                    ans+=4;
                    if(i>0 && v[i-1][j]==1) ans-=2;
                    if(j>0 && v[i][j-1]==1) ans-=2;
                }
            }
        }
        return ans;
    }
};