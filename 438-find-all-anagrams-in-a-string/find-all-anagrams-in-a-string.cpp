class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m1,m2;
        for(auto x:p){
            m2[x]+=1;
        }
        int left=0;
        int k=p.size();
        vector<int>res;
        for(int right=0;right<s.size();right+=1){
            if(right>=k){
                if(m1[s[left]]==1) m1.erase(s[left]);
                else m1[s[left]]-=1;
                left+=1;
            }
            m1[s[right]]+=1;
            if(m1==m2){
                res.push_back(left);
            }
        }
        return res;
    }
};