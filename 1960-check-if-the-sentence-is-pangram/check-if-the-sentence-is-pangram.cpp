class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>m;
        for(auto x:sentence){
            m[x]++;
        }
        for(char x='a';x<='z';x++){
            if(!m[x]) return false;
        }
        return true;
    }
};