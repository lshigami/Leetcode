class Solution {
public:
    int numIdenticalPairs(vector<int>& v) {
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            m[i]=v[i];
        }
        int cnt=0;
        for(int i=0;i<v.size()-1;i++){
            int j=v.size()-1;
            while(j!=i){
                if(m[i]==v[j]) cnt++;
                j--;
            }
        }
        return cnt;
    }
};