class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        if (a.size() < 3 || a[1] < a[0])
            return false;
        bool peek = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < a[i - 1])
                peek = true;
            else if (a[i] == a[i - 1])
                return false;
            if (peek == true) {
                if (a[i] > a[i - 1])
                    return false;
            }
        }
        return peek;
    }
};