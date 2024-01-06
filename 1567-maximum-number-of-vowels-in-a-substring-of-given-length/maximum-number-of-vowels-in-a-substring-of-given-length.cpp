class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }
        int ans=count;
        for(int i=k;i<s.size();i++){
            if(isVowel(s[i-k])) count--;
            if(isVowel(s[i])) count++;
            ans=max(ans,count);
        }
        return ans;
    }
    bool isVowel(char a){
        return a=='u' || a=='e'|| a=='o'|| a=='a'|| a=='i';
    }
};