class Solution {
public:
    string removeOccurrences(string s, string part) {
        int k=part.size();
        auto find=s.find(part);
        while(find!=string::npos){
            s.erase(find,k);
            find=s.find(part);
        }
        return s;
    }
};