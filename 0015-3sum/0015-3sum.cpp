class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        set<vector<int>>se;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(v[i]+v[j]+v[k]==0) {
                    se.insert({v[i],v[j],v[k]});
                    j++;
                    k--;
                }
                else if(v[i]+v[j]+v[k]<0) j++;
                else k--;
            }
        }
        vector<vector<int>>ans(se.begin(),se.end());
        return ans;
    }
  
};