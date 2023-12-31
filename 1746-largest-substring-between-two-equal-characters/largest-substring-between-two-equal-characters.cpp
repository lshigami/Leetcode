class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int>m;
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()) m[s[i]]=i;
            else ans=max(ans,i-m[s[i]]-1);
        }
        return ans;
    }
};
