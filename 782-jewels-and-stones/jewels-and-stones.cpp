class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>m1,m2;
        for(auto x:jewels){
            m1[x]++;
        }
        for(auto x:stones){
            m2[x]++;
        }
        int cnt=0;
        for(auto x: m1){
            if(m2[x.first]) cnt+=m2[x.first];
        }
        return cnt;
    }
};