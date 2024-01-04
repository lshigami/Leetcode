class Solution {
public:
    string sortSentence(string s) {
        map<int,string>m;
        string temp;
        stringstream ss(s);
        string rm;
        while(ss>>temp){
            rm=temp;
            temp.pop_back();
            m[rm[rm.size()-1]-'0']=temp;
        }
        temp="";
        for(auto x:m){
            temp+=x.second;
            temp+=" ";
        }
        temp.pop_back();
        return temp;
    }
};