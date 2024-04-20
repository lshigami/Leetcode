class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};
    void flooding(vector<vector<int>>& land,int i,int j, int &f,int &l){
        land[i][j]=0;
        for(int k=0;k<4;k++){
            int in=i+p[k].first;
            int jn=j+p[k].second;
            if(in>=0 && jn>=0 && in<land.size() && jn<land[0].size() && land[in][jn]){
                f=max(f,in);
                l=max(l,jn);
                flooding(land,in,jn,f,l);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]){
                    int f=i,l=j;
                    flooding(land,i,j,f,l);
                    ans.push_back({i,j,f,l});
                }
            }
        }
        return ans;
    }
};