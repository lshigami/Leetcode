class Solution {
public:
    int largestSumAfterKNegations(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        for(auto x:v) cout<<x<<" ";
        for(int i=0;i<v.size();i++){
            if(k==0) break;
            if(v[i]<=0){
                v[i]*=-1;
                k--;
            }
            else{
               if(k%2==0) return accumulate(v.begin(),v.end(),0);
               else{
                   sort(v.begin(),v.end());
                   v[0]*=-1;
                   return accumulate(v.begin(),v.end(),0);
               }
            }
        }
        if(k!=0){
sort(v.begin(),v.end());
                   v[0]*=-1;
                
        }
        return accumulate(v.begin(),v.end(),0);
    }
};