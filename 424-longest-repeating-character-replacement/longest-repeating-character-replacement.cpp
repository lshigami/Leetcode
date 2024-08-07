class Solution {
public:
    // B A A A B C  : k=2
    bool valid(unordered_map<char,int>m,int k){
        bool isOk=true;
        int maxFrequency=INT_MIN;
        int charMax;
        for(auto x:m){
            if(x.second>maxFrequency){
                charMax=x.first;
                maxFrequency=x.second;
            }
        }
        for(auto x:m){
            if(k<0) return false;
            if(x.second==maxFrequency && isOk){
                isOk=false;
                continue;
            }
            else{
                k-=x.second;
            }
        }
        return k>=0;
    }
    int characterReplacement(string s, int k) {
        int left=0;
        int maxSize=1;
        unordered_map<char,int>m;
        for(int right=0;right<s.size();right+=1){
            m[s[right]]+=1;
            while(m.size()>1 && !valid(m,k)){
                if(m[s[left]]==1) m.erase(s[left]);
                else m[s[left]]-=1;
                left+=1;
            }
            maxSize=max(maxSize,right-left+1);
        }
        return maxSize;
    }
};