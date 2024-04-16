using ll = long long;

class Solution {

public:

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // weight, id

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            free;

        int n = servers.size(), m = tasks.size();

        for (int i = 0; i < n; ++i) {

            free.emplace(servers[i], i);

        }

        // finish time, id

           priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        ll t = 0;

        vector<int> res;

        int i = 0;

        while (res.size() < m) {

            while (busy.size() && busy.top().first <= t) {

                int id = busy.top().second;

                busy.pop();

                free.emplace(servers[id], id);

            }

            if (free.size()) {

                int id = free.top().second;

                free.pop();

                res.push_back(id);

                busy.emplace((t + tasks[i]), id);

                i++;

                t = max(t, (ll) i);

            } else {

                t = busy.top().first;

            }

        }

        return res;

    }

};