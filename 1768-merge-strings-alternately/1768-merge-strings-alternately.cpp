class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string sex="";
        int i=0;
        int j=0;
        while(i<s1.size() && j<s2.size()){
           sex+=s1[i++];
            sex+=s2[j++];
        }
        while(i<s1.size()){
            sex+=s1[i++];
        }
        while(j<s2.size()){
            sex+=s2[j++];
        }
        return sex;
    }
};