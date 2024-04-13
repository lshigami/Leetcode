class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<mat.size();i++){
            int counter=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) counter+=1;
            }
            m[i]=counter;
        }
        vector<pair<int,int>>v;
        for(auto x:m){
            cout<<x.first<<" "<<x.second<<endl;
            v.push_back({x.first,x.second});
        }
    
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b)->bool{
            if(a.second!=b.second) return a.second<b.second;
            else return a.first<b.first;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};