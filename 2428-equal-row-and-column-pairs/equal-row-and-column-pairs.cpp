class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>row;
        string temp;
        for(int i=0;i<grid.size();i++){
            temp="";
            for(int j=0;j<grid[0].size();j++){
                temp+=to_string(grid[i][j]);
                temp+=" ";
            }
            row[temp]+=1;
        }
        int ans=0;
        for(auto x:row){
            cout<<x.first<<" ";
        }
        cout<<endl;
        for(int i=0;i<grid.size();++i){
            temp="";
            for(int j=0;j<grid[0].size();j++){
                temp+=to_string(grid[j][i]);
                temp+=" ";
            }
            cout<<temp<<" ";
            if(row[temp]) ans+=row[temp];
        }
        return ans;
    }
};