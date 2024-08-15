class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>m;
        for(auto x:bills){
            if(x==10){
                if(m[5]<=0) return false;
                m[5]-=1;
            }
            else if(x==20){
                
                if(m[5]>=1 && m[10]>=1) {
                    m[5]-=1;
                    m[10]-=1;
                }else if(m[5]>=3) m[5]-=3;
                else return false;
            }
            m[x]+=1;
        }
        return true;
    }
};