class Solution {
public:
    int distance(vector<int>a,vector<int>b){
        return abs(a[1]-b[1]) + abs(a[0]-b[0]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,int>>adj[points.size()];
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int w = (distance(points[i],points[j]));
                adj[i].push_back({w,j});
                adj[j].push_back({w,i});
            }
        }
        map<int,bool>visited;
        for(int i=0;i<points.size();i++){
            visited[i]=false;
        }
        int minpath=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto x:adj[0]){ // Sửa lỗi ở đây
            pq.push(x);
        }
        visited[0]=true;
        while(!pq.empty()){
            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(visited[u]==false){
                minpath+=w;
                visited[u]=true;
                for(auto x:adj[u]){
                    if(visited[x.second]==false){
                        pq.push(x);
                    }
                }
            }
        }
        return minpath;
    }
};
