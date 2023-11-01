//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[],vector<int>& vist,int at){
        vist[at]=1;
        for(auto i: adj[at]){
            if(!vist[i]){
                dfs(adj,vist,i);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vist(V,0);
	    int mother = 0;
	    for(int i=0;i<V;i++){
	        if(!vist[i]){
	            mother = i;
	            dfs(adj,vist,i);
	        }
	    }
	    vector<int> c(V,0);
	    dfs(adj,c,mother);
	    for(int i=0;i<V;i++){
	        if(!c[i]) return -1;
	    }
	    return mother;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends