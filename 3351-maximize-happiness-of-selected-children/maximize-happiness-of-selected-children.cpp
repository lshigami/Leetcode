class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long sum=0;
        sort(v.begin(),v.end());
        int x=0;
        for(int i=v.size()-1;i>=0 && k;i--,k--){
            sum+= v[i]-x>=0 ?  v[i]-x++ : 0;
        }
        return sum;
    }
};