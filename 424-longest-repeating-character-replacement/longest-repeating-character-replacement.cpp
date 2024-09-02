class Solution {
public:
    bool valid(map<char,int>&m,int k){
        int maxChar;
        int maxFre=INT_MIN;
        for(auto x:m){
            if(x.second>maxFre){
                maxFre=x.second;
                maxChar=x.first;
            }
        }
        for(auto x:m){
            if(x.first==maxChar) continue;
            else k-=x.second;
            if(k<0) return false;
        }
        return true;
    }
    int characterReplacement(string s, int k) {
        int left=0;
        int MAX=1;
        map<char,int>m;
        for(int right=0;right<s.size();right+=1){
            m[s[right]]+=1;
            if(m.size()>1){
                while(!valid(m,k)){
                    if(m[s[left]]==1) m.erase(s[left]);
                    else m[s[left]]-=1;
                    left+=1;
                }
            }
            MAX=max(MAX,right-left+1);
        }
        return MAX;
    }
};