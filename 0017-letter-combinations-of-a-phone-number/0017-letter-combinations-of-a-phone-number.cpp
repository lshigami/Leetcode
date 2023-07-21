class Solution {
public:
    vector<string> letterCombinations(string s) {
        string phone[10];
        phone[2]="abc";
        phone[3]="def";
        phone[4]="ghi";
        phone[5]="jkl";
        phone[6]="mno";
        phone[7]="pqrs";
        phone[8]="tuv";
        phone[9]="wxyz";
        string ans="";
        vector<string>v;
        Try(s,0,ans,v,phone);
        return v;
    }
    
    void Try(string s, int pos, string& ans, vector<string>&v, string phone[10]){
       for(int j=0;j<phone[s[pos]-'0'].size();j++){
           ans+=phone[s[pos]-'0'][j];
           if(ans.size()==s.size()){
               v.push_back(ans);
           }
           else Try(s,pos+1,ans,v,phone);
           ans.pop_back();
       }
    }
    
};