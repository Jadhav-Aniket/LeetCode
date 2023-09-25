//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> edges) 
    {
        //code here
          vector<int> adj[n];
          int indegree[n]={0};
          for(int i=0;i<edges.size();i++)
          {
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
          }
        
          queue<int> Q;
          vector<int> ans;
          int vis=0;
          for(int i=0;i<n;i++)
          {
            if(indegree[i]==0)
              Q.push(i);
          }
          while(!Q.empty())
          {
            int curr = Q.front();
            Q.pop();
            vis++;
            ans.push_back(curr);
            for(auto temp:adj[curr])
            {
              indegree[temp]--;
              if(indegree[temp]==0)
                Q.push(temp);
            }
          }
          if(vis==n)
            return ans;
          return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends