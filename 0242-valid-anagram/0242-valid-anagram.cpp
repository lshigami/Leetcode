class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m1,m2;
        for(auto x:s){
            m1[x]+=1;
        }
        for(auto x:t){
            m2[x]+=1;
        }
        for(auto x:m1){
            if(m2[x.first]!=x.second) return false;
        }
        for(auto x:m2){
            if(m1[x.first]!=x.second) return false;
        }
        return s.size()==t.size();
    }
};