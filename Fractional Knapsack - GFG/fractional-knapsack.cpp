//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
   static bool compareInterval(pair<int, double> p1,  pair<int, double> p2)
    {
        return (p1.second > p2.second);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
       
        vector<pair<int,double>> v1(n,{0,0});
        for(int i=0;i<n;i++)
        {
            v1[i] = {i,(double)arr[i].value/arr[i].weight};
        }
        
        sort(v1.begin(),v1.end(),compareInterval);
        
        double sumV=0,sumW=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(sumW<W)
            {
                sumW += arr[v1[i].first].weight;
                sumV += arr[v1[i].first].value;
            }
            else
                break;
        }
        if(i==n && sumW <= W)
        {
            return sumV;         
        }
        if(sumW==W)
            return sumV;
        else
        {
            i--;
            sumW -= arr[v1[i].first].weight;
            sumV -= arr[v1[i].first].value;
            
            double frac = (double)(W-sumW)/arr[v1[i].first].weight;
            
            sumV += frac * arr[v1[i].first].value;
        }
        return sumV;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends