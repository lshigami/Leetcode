class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        map<int,int>dong;
        map<int,int>cot;
        for(int i=0;i<v.size();i++){
            int cnt=0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1) cnt++;
            }
            dong[i]=cnt;
        }
        for(int j=0;j<v[0].size();j++){
            int cnt=0;
            for(int i=0;i<v.size();i++){
                if(v[i][j]==1) cnt++;
            }
            cot[j]=cnt;
        }

        int cnt=0;

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1 && dong[i]==1 && cot[j]==1) cnt++;
            }
        }
        return cnt;
    }
};