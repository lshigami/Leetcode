class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>m;
        int i=97;
        for(auto x:key){
            if(x==' '){
                continue;
            }
            if(m[x]==0) m[x]=(i++);
        }
        string decoded="";
        for(auto x:message){
            if(x==' ') decoded+=" ";
            else decoded+=m[x];
            
        }
        return decoded;
    }
};