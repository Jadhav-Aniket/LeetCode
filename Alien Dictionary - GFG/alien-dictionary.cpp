//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dictionary[], int N, int n) {
        //code here
        string ans = "";
    unordered_set<int> adj[n];
    vector<int> indegree(n,0);
    for(int i=0; i<N-1;i++)
    {
        string str1 = dictionary[i];
        string str2 = dictionary[i+1];
        for(int j=0;j<str1.size()&&j<str2.size();j++)
        {
            if(str1[j]!=str2[j])
            {
                if(adj[str1[j]-'a'].find(str2[j]-'a') == adj[str1[j]-'a'].end())
                    adj[str1[j]-'a'].insert(str2[j]-'a');
                break;
            }
        }
    }

    for(auto list: adj)
    {
        for(auto temp: list)
        {
            indegree[temp]++;
        }
    }

          queue<int> Q;
          for(int i=0;i<n;i++)
          {
            if(indegree[i]==0)
              Q.push(i);
          }
          while(!Q.empty())
          {
            int curr = Q.front();
            Q.pop();
            ans += char(curr+'a');
            for(auto temp:adj[curr])
            {
              indegree[temp]--;
              if(indegree[temp]==0)
                Q.push(temp);
            }
          }
        //cout<<ans<<endl;
        return ans; 
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends