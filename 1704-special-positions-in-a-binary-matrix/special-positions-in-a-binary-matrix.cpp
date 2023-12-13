class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        map<int,int>row;
        map<int,int>col;
        for(int i=0;i<v.size();i++){
            int cnt=0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1) cnt++;
            }
            row[i]=cnt;
        }
        for(int j=0;j<v[0].size();j++){
            int cnt=0;
            for(int i=0;i<v.size();i++){
                if(v[i][j]==1) cnt++;
            }
            col[j]=cnt;
        }

        int cnt=0;

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1 && row[i]==1 && col[j]==1) cnt++;
            }
        }
        return cnt;
    }
};