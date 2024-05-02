class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int left=0;
        int ans=1;
        for(int right=0;right<s.size();right+=1){
            m[s[right]]+=1;
            while(!canBeReplace(m,left,right,k)){
                m[s[left++]]-=1;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
    bool canBeReplace(map<char,int>m,int l,int r,int k){
        int MAX=0;
        for(auto x:m){
            MAX=max(MAX,x.second);
        }
        return r-l+1-MAX<=k;
    }
};