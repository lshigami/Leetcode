class Solution {
public:
    vector<string> Neibourhoods(string& s) {
        vector<string> ans;
        for (int i = 0; i < 4; ++i) {
            string t = s;
            string z = s;
            t[i] = t[i] == '9' ? '0' : t[i] + 1;
            ans.push_back(t);
            z[i] = z[i] == '0' ? '9' : z[i] - 1;
            ans.push_back(z);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        int step = 0;
        string start = "0000";
        queue<string> q;
        q.push("0000");
        set<string> deadNotes(deadends.begin(), deadends.end());
        if (deadNotes.count("0000")) return -1;
        while (!q.empty()) {
            for (int i =q.size(); i >0; i--) {
                string top = q.front();
                q.pop();
                if (top == target)
                    return step;
                vector<string>neis=Neibourhoods(top);
                for(auto x:neis){
                    if(deadNotes.count(x)) continue;
                    deadNotes.insert(x);
                    q.push(x);
                }
            }
            step+=1;
        }
        return -1;
    }
};