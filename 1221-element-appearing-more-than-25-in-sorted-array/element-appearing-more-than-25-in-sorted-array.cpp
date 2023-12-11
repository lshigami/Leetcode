class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        int per=arr.size()*0.25;
        for(auto x:m){
            if(x.second>per) return x.first;
        }
        return -1;
    }
};