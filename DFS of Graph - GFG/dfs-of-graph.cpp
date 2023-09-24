//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void sol(int curr, int V, vector<int> adj[],vector<int>& ans, vector<int>& vis)
    {
        // if(vis[curr] == 1)
        //     return;
        for(int i=0;i<adj[curr].size();i++)
        {
            int temp = adj[curr][i];
            if(vis[temp] == 0)
            {
                vis[temp] = 1;
                ans.push_back(temp);
                sol(temp,V,adj,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                ans.push_back(i);
                sol(i,V,adj,ans,vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends