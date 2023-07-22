class Solution {
public: 
    vector<vector<int>> fourSum(vector<int>& v, int target) {
       sort(v.begin(),v.end());
        set<vector<int>>se;
        int n=v.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1;
                int w=n-1;
                while(k<w){
                    long long sum = static_cast<long long>(v[i]) + v[j] + v[k] + v[w];

                    if(sum==target){
                        se.insert({v[i],v[j],v[k],v[w]});
                        k++;
                        w--;
                    }
                    else if(sum<target) k++;
                    else w--;
                }
            }
        }
        vector<vector<int>>ans(se.begin(),se.end());
        return ans;
    }
};
