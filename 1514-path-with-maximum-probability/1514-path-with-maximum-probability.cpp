class Solution {
public:
    vector<double> dijkstra(int V, vector<int> adj[],map<pair<int,int>,double>& edge_prob, int s)
    {
        vector<double> dist(V,0.0);
        priority_queue<pair<double,int>> pq;
        dist[s] = 1.0;
        pq.push({1.0,s});
        for(int i=0;i<V;i++){
            if(i!=s) pq.push({0.0,i});
        }
        vector<int> setmst(V,0);
        while(!pq.empty()){
            auto it = pq.top();
            double x = it.first;
            int at = it.second;
            setmst[at] = 1;
            pq.pop();
            for(auto it: adj[at]){
                if(dist[it] < (x*edge_prob[{at,it}]) && !setmst[it]){
                    dist[it] = x*edge_prob[{at,it}];
                    pq.push({x*edge_prob[{at,it}],it});
                }
            }
        }
        return dist;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<int> adj[n];
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        map<pair<int,int>,double> edge_prob;
        for(int i=0;i<edges.size();i++){
            edge_prob[{edges[i][0],edges[i][1]}] = succProb[i];
            edge_prob[{edges[i][1],edges[i][0]}] = succProb[i];
        }
        vector<bool> visited(n,false);
        vector<double> dist = dijkstra(n,adj,edge_prob,start_node);
        return dist[end_node];
    }
};