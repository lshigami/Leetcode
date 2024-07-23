class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=1;
        int left=0;
        unordered_map<char,int>m;
        for(int right=0;right<s.size();right+=1){
            m[s[right]]+=1;
            while(m[s[right]]>1){
                m[s[left]]-=1;
                if(m[s[left]]==0) m.erase(s[left]);
                left+=1;
            }
            ans=max(ans,(int)m.size());
        }
        return ans;
    }
};