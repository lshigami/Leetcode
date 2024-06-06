class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k) return false;
        multiset<int>s;
        for(auto x:hand) s.insert(x);
        int step=hand.size()/k;
        while(step){   
            vector<int>temp;  
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