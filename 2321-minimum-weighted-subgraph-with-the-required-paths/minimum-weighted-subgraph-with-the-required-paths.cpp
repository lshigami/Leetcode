class Solution {
public:

    vector<long long> Dijkstra(vector<pair<int,int>>adj[],int n, int u){
        vector<long long>dis(n+100,1e18);
        vector<bool>visited(n+100,false);
        dis[u]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,u});
        while(!pq.empty()){
            pair<long long,int>top=pq.top();
            int d=top.second;
            pq.pop();
            if(!visited[d]){
                visited[d]=true;
                for(auto x:adj[d]){
                    int dk=x.second;
                    long long w=x.first;
                    if(dis[dk]>dis[d]+w){
                        dis[dk]=dis[d]+w;
                        pq.push({dis[dk],dk});
                    }
                }
            }
        }
        return dis;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<int,int>>adj[n+100];
        vector<pair<int,int>>rev[n+100];

        for(auto x:edges){
            adj[x[0]].push_back({x[2],x[1]});
            rev[x[1]].push_back({x[2],x[0]});

        }
        vector<long long> dist_from_src1 = Dijkstra(adj,n, src1);
		vector<long long> dist_from_src2 = Dijkstra(adj,n, src2);
		vector<long long> dist_to_dest   = Dijkstra(rev,n, dest);
        long long ans = 1e18;
        for(int i=0;i<n;i++){
			ans = min(ans, dist_from_src1[i] + dist_from_src2[i] + dist_to_dest[i]);
        }
        return ans==1e18 ? -1 : ans;
    }
};