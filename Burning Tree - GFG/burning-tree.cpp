//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void traverse(Node* root, int dist, int *ans)
    {
        if(!root)
        {
            return ;
        }

        *ans = max(dist,*ans);
        
        if(!(root->left) && !(root->right))
            return ;

        if(root->left)
            traverse(root->left,dist+1,ans);
        
        if(root->right)
            traverse(root->right,dist+1,ans);

    }

    int minTime(Node* root, int start) 
    {
        // Your code goes here
        
         unordered_map<Node*, Node*> mpp;
        int ans = INT_MIN;
        queue<Node*> Q;
        Node *curr = root, *parent,*child,*target;
        Q.push(root);
        mpp[curr] = nullptr;
        while(!Q.empty())
        {
            int size = Q.size();
            for(int i=0;i<size;i++)
            {
                curr = Q.front();
                Q.pop();
                //cout<<curr->data<<" ";
                if(curr->data == start)
                    target = curr;
                
                if(curr->left)
                {
                    Q.push(curr->left);
                    mpp[curr->left] = curr;
                }
                if(curr->right)
                {
                    Q.push(curr->right);
                    mpp[curr->right] = curr;
                }
            }
        }

        //cout<<start<<" ";
        //cout<<target->data;
        traverse(target,0,&ans);
        child = target;
        int k = 0;
        while(child)
        {
            //cout<<1111;
           
            parent = mpp[child];
            if(parent && parent->right == child)
                traverse(parent->left,k+2,&ans);
            else if(parent && parent->left == child)
                traverse(parent->right,k+2,&ans);
            
            child = parent;

            ans = max(k,ans);
            k++;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends