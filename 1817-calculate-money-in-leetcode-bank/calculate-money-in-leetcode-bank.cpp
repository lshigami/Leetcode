class Solution {
public:
    int totalMoney(int n) {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7};
        int sum = 0;
        int i = 1;
        int stop = 0;
        while (i <= n) {
            sum += v[i - 1];
            if (i % 7 == 0) {
                int last = v.back();
                v.erase(v.begin());
                v.push_back(last + 1);
                i = 0;
        }
        i++;
        stop++;
        if (stop == n) break;
    }
    return sum;
    }
};