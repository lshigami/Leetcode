class Solution {
public:
    int buyChoco(vector<int>& v, int money) {
        sort(v.begin(),v.end());
        return (money-v[0]-v[1] >=0) ? (money-v[0]-v[1]) : money;
    }
};