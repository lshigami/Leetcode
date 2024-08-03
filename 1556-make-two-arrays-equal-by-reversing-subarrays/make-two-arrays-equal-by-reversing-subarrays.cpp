class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>m1;
        for(auto x:target){
            m1[x]++;
        }
        map<int,int>m2;
        for(auto x:arr){
            m2[x]++;
        }
        for(auto x:m1){
            if(x.second!=m2[x.first]) return false;
        }
        return true;
    }
};