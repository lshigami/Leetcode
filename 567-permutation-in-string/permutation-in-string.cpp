class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1,m2;
        for(auto x:s1){
            m1[x]+=1;
        }
        int left=0;
        int k=s1.size();
        for(int i=0;i<min(k,(int)s2.size());i++){
            m2[s2[i]]+=1;
        }
        if(m1==m2) return true;
        for(int i=k;i<s2.size();i++){
            m2[s2[i]]+=1;
            if(m2[s2[left]]==1) m2.erase(s2[left++]);
            else m2[s2[left++]]-=1;
            if(m1==m2) return true;
        }
        return false;
    }
};