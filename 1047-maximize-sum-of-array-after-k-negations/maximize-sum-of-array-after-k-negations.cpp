class Solution {
public:
    int largestSumAfterKNegations(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        for(int i=0;i<v.size() && v[i]<0 && k>0 ;i++){
            v[i]*=-1;
            k--;
        }
        int min=INT_MAX;
        int sum=0;
        for(int i=0;i<v.size();i++){
            min=std::min(min,v[i]);
            sum+=v[i];
        }
        if(k%2!=0) sum-=min*2;
        return sum;
    }
};