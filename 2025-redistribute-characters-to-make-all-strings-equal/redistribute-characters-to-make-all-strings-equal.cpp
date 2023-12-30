class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1) return true;
        map<char,int>m;
        for(auto x:words){
            for(auto c:x){
                m[c]++;
            }
        }
        for(auto x:m){
            if(x.second%words.size()!=0) return false;
        }
        return true;
    }
};