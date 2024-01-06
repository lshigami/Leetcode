class Solution {
public:
    void moveZeroes(vector<int>& v) {
    int l = 0;
    int r = 0;
    while (r < v.size()) {
        if (v[r] != 0) {
            swap(v[l], v[r]);
            l++;
        }
        r++;
    }
}

};