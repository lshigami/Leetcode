class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans="";
        set<string>s;
        for(auto x:words) s.insert(x);
        for(auto word:words){
            bool isGood=true;
            if(word.size()>ans.size() || (word.size()==ans.size() && ans>word) ){
                for(int k=1;k<word.size();k++){
                    if(!s.count(word.substr(0,k))){
                        isGood=false;
                        break;
                    }
                }
                if(isGood) ans=word;
            }
        }
        return ans;
    }
};