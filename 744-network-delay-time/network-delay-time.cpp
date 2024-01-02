class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+100];
        for(auto x:times){
            adj[x[0]].push_back({x[2],x[1]});
        }
        vector<int>dis(n+10,INT_MAX);
        vector<bool>visited(n+10,false);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            int dinh=top.second;
            if(!visited[dinh]){
                visited[dinh]=true;
                for(auto x:adj[dinh]){
                    int dk=x.second;
                    int w=x.first;
                    if(dis[dk]>dis[dinh]+w){
                        dis[dk]=dis[dinh]+w;
                        pq.push({dis[dk],dk});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]) return -1;
        }
        int ans=-1;
        for(auto x:dis){
            if(x!=INT_MAX){
                ans=max(ans,x);
            }
        }
        return ans;

    }
};