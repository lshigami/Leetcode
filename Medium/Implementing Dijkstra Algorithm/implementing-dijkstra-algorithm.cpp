//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dis(V+100,INT_MAX);
        vector<bool>visited(V+100,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            int dinh=top.second;
            if(!visited[dinh]){
                visited[dinh]=true;
                for(auto z:adj[dinh]){
                    int dinhke=z[0];
                    int w=z[1];
                    if(dis[dinhke]>dis[dinh]+w){
                       dis[dinhke]=dis[dinh]+w;
                       pq.push({dis[dinhke],dinhke});
                   }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            ans.push_back(dis[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends