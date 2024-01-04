class Graph {
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int u, int v) {
        int n=adj.size();
        vector<int>dis(n+10,INT_MAX);
        vector<int>visited(n+10,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[u]=0;
        pq.push({0,u});
        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            int d=top.second;
            if(!visited[d]){
                visited[d]=true;
                for(auto x:adj[d]){
                    int dk=x.first;
                    int w=x.second;
                    if(dis[dk]>dis[d]+w){
                        dis[dk]=dis[d]+w;
                        pq.push({dis[dk],dk});
                    }
                }
            }
        }
        if(!visited[v]) return -1;
        else return dis[v];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */