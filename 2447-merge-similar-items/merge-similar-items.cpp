class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        map<int,int>m;
        for(auto x:v1){
            m[x[0]]=x[1];
        }
        for(auto x:v2){
            if(m.find(x[0])!=m.end()){
                m[x[0]]+=x[1];
            }
            else m[x[0]]=x[1];
        }
        vector<vector<int>>ans;
        for(auto x:m){
            vector<int>temp;
            temp.push_back(x.first);
            temp.push_back(x.second);
            ans.push_back(temp);
        }
        return ans;
    }
};