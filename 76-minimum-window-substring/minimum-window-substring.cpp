class Solution {
public:
    bool isGreaterOrEqual(unordered_map<char,int>&m1,unordered_map<char,int>&m2){
        for(auto x:m2){
            if(m1.find(x.first)==m1.end() || m1[x.first]<x.second) return false; 
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>m1,m2;
        for(auto x:t) m2[x]+=1;
        int minimumSize=INT_MAX;
        int left=0;
        int i=0,j=0;
        for(int right=0;right<s.size();right+=1){
            m1[s[right]]+=1;
            while(isGreaterOrEqual(m1,m2)){
                if(right-left+1<minimumSize){
                    minimumSize=right-left+1;
                    i=left;
                    j=right;
                }
                m1[s[left++]]-=1;
            }
        }
        if(minimumSize==INT_MAX) return "";
        else return s.substr(i,j-i+1);
    }
};