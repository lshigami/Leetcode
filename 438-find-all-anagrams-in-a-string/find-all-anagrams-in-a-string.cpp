class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m;
        for(auto x:p) m[x]+=1;
        int k=p.size(); // size of window
        vector<int>ans;
        map<char,int>temp;
        int left=0;
        for(int i=0;i<k;i++){
            temp[s[i]]+=1;
        }
        if(m==temp) ans.push_back(0);
        for(int i=k;i<s.size();i++){
           temp[s[i]]+=1;
           if(temp[s[left]]==1) temp.erase(s[left++]);
           else temp[s[left++]]-=1;
           if(temp==m) ans.push_back(left);
        }
        return ans;
    }
};