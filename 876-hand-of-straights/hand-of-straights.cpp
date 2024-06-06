class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k) return false;
        multiset<int>s;
        for(auto x:hand) s.insert(x);
        unordered_map<int,int>m;
        for(auto x:hand){
            m[x]+=1;
        }
        //  2 3 4 6 7 8
        int step=hand.size()/k;
        while(step){   //            9/3 = 3 step
            vector<int>temp;   //    1 2 3
            temp.push_back(*s.begin());
            s.erase(s.begin());
            for(int i=0;i<k-1 && i< temp.size();i++){
                auto it=s.lower_bound(temp[i]+1);
                if(it!=s.end() && *it==temp[i]+1){
                    temp.push_back(*it);
                    s.erase(it);
                }else{
                    return false;
                }
            }
            step-=1;
        }
        return true;
    }
};