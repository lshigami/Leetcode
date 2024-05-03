class Solution {
public:
    int cmp(string x, string y) {
        int a=stoi(x);
        int b=stoi(y);
        if (a < b)
            return -1;
        if (a > b)
            return 1;
        return 0;
    }
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        stringstream s2(version2);
        vector<string> ans1, ans2;
        string temp;
        while (getline(s1, temp, '.')) {
            int num = stoi(temp);
            ans1.push_back(to_string(num));
        }
        while (getline(s2, temp, '.')) {
            int num = stoi(temp);
            ans2.push_back(to_string(num));
        }
        for (auto x : ans1)
            cout << x << " ";
        cout << endl;
        for (auto x : ans2)
            cout << x << " ";

        for (int i = 0; i < min(ans1.size(), ans2.size()); i++) {
            int res = cmp(ans1[i], ans2[i]);
            if (res != 0)
                return res;
        }
        if (ans1.size() > ans2.size()) {
            while (ans1.size() > ans2.size() && ans1.back() == "0")
                ans1.pop_back();
            if (ans1.size() > ans2.size())
                return 1;
        } else if (ans1.size() == ans2.size())
            return 0;
        else {
            while (ans2.size() > ans1.size() && ans2.back() == "0")
                ans2.pop_back();
            if (ans2.size() > ans1.size())
                return -1;
        }
        return 0;
    }
};