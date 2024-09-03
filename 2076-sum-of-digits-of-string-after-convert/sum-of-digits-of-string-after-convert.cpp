class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        int sum;
        for(int i=1;i<=k;i++){
            sum=0;
            if(res==""){
                for(auto x:s){
                int con=x-'a'+1;
                res+=to_string(con);
            }
            }
            cout<<res<<" ";
            for(auto x:res){
                sum+=x-'0';
            }
            cout<<sum<<endl;
            res=to_string(sum);
        }
        return sum;
    }
    
};