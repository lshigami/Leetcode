class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mapP;
        map<char,int>mapS;
        int k=p.size();
        for(auto x:p) mapP[x]+=1;
        int left=0;
        for(int right=0;right<k;right++){
            mapS[s[right]]+=1;
        }
        vector<int>ans;
        if(mapS==mapP) ans.push_back(left);
        for(int right=k;right<s.size();right+=1){
            mapS[s[right]]+=1;
            if(mapS[s[left]]==1) mapS.erase(s[left]);
            else mapS[s[left]]-=1;
            left+=1;
            if(mapS==mapP) ans.push_back(left);
        }
        return ans;
    }
};