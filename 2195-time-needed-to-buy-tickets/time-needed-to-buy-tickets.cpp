class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int count=0;
        int i=0;
        while(v[k]){
            if(v[i]==0) {
                i+=1;
                i=i%v.size();
                 continue;
            }
            else {
                v[i]-=1;
                count+=1;
            }
            i+=1;
            i=i%v.size();
        }
        return count;
    }
};