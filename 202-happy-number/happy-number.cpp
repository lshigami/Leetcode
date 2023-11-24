class Solution {
public:
    bool isHappy(int n) {

        map<int,int> m;
        string str;

        while(m[n] < 1)
        {
            m[n] = m[n] + 1;
            str = to_string(n);
            n = 0;

            for(int i=0; i<str.size(); ++i)
            {
                n+= int(str[i] - '0') * int(str[i] - '0');
            }

            if(n==1)
                return true;
        }

        return false;
    }
};