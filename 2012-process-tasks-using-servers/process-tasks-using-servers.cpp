class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            server_w_i;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<long long, int>>>
            busy_t_i;
        long long time = 0;
        int i = 0;
        vector<int> res;
        for (int i = 0; i < servers.size(); i++)
            server_w_i.push({servers[i], i});
        while (res.size() < tasks.size()) {
            while (!busy_t_i.empty() && busy_t_i.top().first <= time) {
                server_w_i.push(
                    {servers[busy_t_i.top().second], busy_t_i.top().second});
                busy_t_i.pop();
            }
            if (server_w_i.size()) {
                auto ser = server_w_i.top();
                server_w_i.pop();
                res.push_back(ser.second);
                busy_t_i.push({time + tasks[i], ser.second});
                i += 1;
                time = max(time, 1ll * i);
            } else
                time = busy_t_i.top().first;
        }
        return res;
    }
};