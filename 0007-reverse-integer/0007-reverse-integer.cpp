#include <algorithm>
using namespace std;
class Solution {
public:
    int reverse(int n) {
       if(n>=0){
        string s= to_string(n);
       std::reverse(s.begin(),s.end());
        string lim= to_string(INT_MAX);
        if(s.size() >lim.size() || (s.size()==lim.size() && s>lim)) return 0;
        else return stoi(s);
    }
    else {
        string s= to_string(n);
       std::reverse(s.begin(),s.end());
        s.pop_back();
        s="-"+s;
        string lim= to_string(INT_MIN);
        if(s.size() >lim.size() || (s.size()==lim.size() && s>lim)) return 0;
        else return stoi(s);
    }
    }
};