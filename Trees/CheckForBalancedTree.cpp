//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    private:
    // first to check balanced or not and second for height
    pair<bool , int> solve(Node* root){
        if(root == NULL){
            pair<bool , int>p = make_pair(true , 0);
            return p;
        }
        
        pair<int , int> left = solve(root -> left);
        pair<int , int> right = solve(root -> right);
        
        bool ansLeft = left.first;
        bool ansRight = right.first;
        bool diff = abs(left.second - right.second) <= 1;   // if height is > 1 than false 
        pair<bool , int> ans;
        ans.second = max(left.second , right.second) + 1;   // add height 
        if(ansLeft && ansRight && diff){
            ans.first = true;   // if all true then true
        }
        else{
            ans.second = false; // else false
        }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        pair<bool , int> ans = solve(root);
        return ans.first;
    }
};


class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int solve(Node *root , bool &ans , int &height){
        if(!root)
            return 0;
        
        int left = solve(root -> left , ans , height);
        int right = solve(root -> right , ans , height);
        height = max(left , right) + 1;
        if(abs(left - right) > 1)
            ans = false;
        return height; 
    }
    bool isBalanced(Node *root)
    {
        bool ans = true;
        int h = 0;
        int height = solve(root , ans , h);
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends