class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        vector<int>ans(v.size());
        int pos=0;
        int nev=1;
        for(auto x:v){
            if(x>0) {
                ans[pos]=x;
                pos+=2;
            }
            else{
                ans[nev]=x;
                nev+=2;
            }
        }
        return ans;
    }
};