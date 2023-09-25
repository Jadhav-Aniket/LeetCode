//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        vector<int> adj[n];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<pair<int,int>> Q;
    vector<int> distarr(n,INT_MAX);
    distarr[src] = 0;
    Q.push({src,0});
    while(!Q.empty())
    {
        int curr = Q.front().first;
        int dist = Q.front().second;
        Q.pop();

        for(auto temp: adj[curr])
        {
            if(distarr[temp]>dist+1)
            {
                distarr[temp] = dist+1;
                Q.push({temp,dist+1});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(distarr[i]==INT_MAX)
            distarr[i] = -1;
    }
    return distarr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends