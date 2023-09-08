//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef pair<int,pair<int,int>> p1;
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        
        priority_queue<p1> maxq;
        set<p1> set1;
    	sort(a.begin(),a.end(),greater<int>());
    	sort(b.begin(),b.end(),greater<int>());
    
    	maxq.push({a[0]+b[0],{0,0}});
    	set1.insert({a[0]+b[0],{0,0}});
    	vector<int> ans;
    	while(k>0)
    	{
    		p1 pair1 = maxq.top();
    		ans.push_back(pair1.first);
    		int i = pair1.second.first;
    		int j = pair1.second.second;
    		maxq.pop();
    		if(j<n-1)
    		{
    		    if(set1.find({a[i]+b[j+1],{i,j+1}}) == set1.end())
    		    {
    		        set1.insert({a[i]+b[j+1],{i,j+1}});
    		        maxq.push({a[i]+b[j+1],{i,j+1}});
    		    }
    			    
    		}
    		if(i<n-1)
    		{
    		    if(set1.find({a[i+1]+b[j],{i+1,j}}) == set1.end())
    		    {
    		        set1.insert({a[i+1]+b[j],{i+1,j}});
    		        maxq.push({a[i+1]+b[j],{i+1,j}});
    		    }
    			    
    		}
    		k--;
    	}
    	
    	return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends