class Solution {
public:
    string largestGoodInteger(string num) {
        map<string,int>m;
        for(int i=0;i<num.size()-2;i++){
            string now=string(1,num[i])+string(1,num[i+1])+string(1,num[i+2]);
            if(num[i]==num[i+1] && num[i]==num[i+2]) m[now]++;
        }
        string MAX="";
        for(auto x:m){
            cout<<x.first<<" ";
            MAX=max(MAX,x.first);
        }
        return MAX;
    }
};