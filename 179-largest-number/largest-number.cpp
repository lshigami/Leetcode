class Solution {
public: 
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto x:nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),[](string a,string b)->bool{
            return a+b>b+a;
        });
        string ans="";
        for(auto x:v){
            ans+=x;
        }
        return ans[0]=='0' ? "0" : ans;
    }
};