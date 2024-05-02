class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size()>s.size()) return false;
        map<char,int>m;
        for(auto x:p) m[x]+=1;
        int k=p.size(); // size of window
        vector<int>ans;
        map<char,int>temp;
        int left=0;
        for(int i=0;i<k;i++){
            temp[s[i]]+=1;
        }
        if(m==temp) return true;
        for(int i=k;i<s.size();i++){
           temp[s[i]]+=1;
           if(temp[s[left]]==1) temp.erase(s[left++]);
           else temp[s[left++]]-=1;
           if(temp==m) return true;
        }
        return false;
    }
};