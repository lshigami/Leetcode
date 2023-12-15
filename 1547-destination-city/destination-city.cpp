class Solution {
public:
    string destCity(vector<vector<string>>& v) {
        map<string,int>m;
        for(int i=0;i<v.size();i++){
            m[v[i][0]]++;
        }
        for(int i=0;i<v.size();i++){
            if(m[v[i][0]]==0) return v[i][0];
            if(m[v[i][1]]==0) return v[i][1];
        }
        return "ISHIGAMI";
    }
};