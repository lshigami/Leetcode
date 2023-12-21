class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>ans;
        for(auto x: points){
            ans.push_back(x[0]);
        }
        sort(ans.begin(),ans.end());
        int widest=0;
        for(int i=0;i<ans.size()-1;i++){
            widest=max(widest,ans[i+1]-ans[i]);
        }
        return widest;
    }
};