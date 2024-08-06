class Solution {
public:
    bool valid(string s){
        int closeParentheses=0;
        for(auto x:s){
            if(x=='(') closeParentheses+=1;
            else closeParentheses-=1;
            if(closeParentheses<0) return false;
        }
        return closeParentheses==0;
    }
    vector<string> generateParenthesis(int n) {
        string base="()";
        string cur="";
        vector<string>res;
        generate(cur,res,base,n);
        return res;
    }
    void generate(string cur,vector<string>&res,string base,int n){
        for(auto x:base){
            cur.push_back(x);
            if(cur.size()==2*n ){
               if(valid(cur)) res.push_back(cur);
            }else{
                generate(cur,res,base,n);
            }
            cur.pop_back();
        }
    }
};