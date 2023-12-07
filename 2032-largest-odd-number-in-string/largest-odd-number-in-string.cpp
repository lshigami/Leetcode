class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        for(int i=0;i<num.size();i++){
            if (int((num[i] - '0'))%2!=0) idx=i; 
        }
        if(idx==-1) return "";
        string x="";
        for(int i=0;i<=idx;i++){
            x+=string(1,num[i]);
        }
        return x;
    }
};