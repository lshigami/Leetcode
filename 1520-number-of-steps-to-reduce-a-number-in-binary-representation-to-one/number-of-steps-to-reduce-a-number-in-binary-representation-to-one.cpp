class Solution {
public:
    void divideTwo(string &s) { s.pop_back(); }
    string plusOne(const string& binary) {
        string result = binary;
        int carry = 1; 
        for (int i = binary.size() - 1; i >= 0; --i) {
            if (binary[i] == '0' && carry == 1) {
                result[i] ='1';   
                carry = 0; 
            } else if (binary[i] == '1' && carry == 1) {
                result[i] = '0'; 
            }
        }
        if (carry == 1) {
            result = '1' + result; 
        }
        return result;
    }
    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            if(s[s.size()-1]=='0') divideTwo(s);
            else s=plusOne(s);
            cnt+=1;
        }
        return cnt;
    }
};