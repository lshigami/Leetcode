class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>v(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) v[j]=1;
                else v[j]=ans[i-1][j-1] +ans[i-1][j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};