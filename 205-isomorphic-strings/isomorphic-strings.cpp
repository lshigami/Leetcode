class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,int>s1,t1;    
       for(int i=0;i<s.size();i++) s1[s[i]]=0;
        for(int i=0;i<s.size();i++) t1[t[i]]=0;

       for(int i=0;i<s.size();i++){
            if(s1[s[i]]!=t1[t[i]]) return false;
            s1[s[i]]=i+1;
            t1[t[i]]=i+1;
       }
       return true;
    }
};