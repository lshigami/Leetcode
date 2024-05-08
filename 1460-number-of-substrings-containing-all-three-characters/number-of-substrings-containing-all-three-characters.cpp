class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int left=0;
        map<char,int>m;
        for(int right=0;right<s.size();right++){
            m[s[right]]+=1;
            while(m['a']  && m['b'] && m['c'] ){
                count+=s.size()-right;
                m[s[left++]]-=1;

            }
        }
        return count;
    }
};