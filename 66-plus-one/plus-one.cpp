class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        int d=0;
        digits[digits.size()-1]+=1;
        for(int i=digits.size()-1;i>0;i--){
            if(digits[i]==10) {
                s="0"+s;
                digits[i-1]+=1;
            }
            else{
                s=to_string(digits[i])+s;
            }
        }
        if(digits[0]==10){
            s="0"+s;
            s="1"+s;
        }else{
             s=to_string(digits[0])+s;
        }
        cout<<s<<" ";
        vector<int>v;
        string c;
        for(auto x:s){
            c=string(1,x);
            v.push_back(stoi(c));
        }
        return v;
    }
};