//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/
class Solution{
  public:
    // Function to get the height of a node
    int height(struct Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    
    // Function to perform right rotation
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
    
        // Perform rotation
        x->right = y;
        y->left = T2;
    
        // Update heights
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;
    
        return x;
    }
    
    // Function to perform left rotation
    Node *leftRotate(struct Node *x)
    {
        struct Node *y = x->right;
        struct Node *T2 = y->left;
    
        // Perform rotation
        y->left = x;
        x->right = T2;
    
        // Update heights
        x->height = max(height(x->left), height(x->right))+1;
        y->height = max(height(y->left), height(y->right))+1;
    
        return y;
    }
    
    // Function to get the balance factor of a node
    int getBalance(struct Node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    
    // Function to check if a tree is height-balanced
    bool __getBalance__(struct Node *root)
    {
        int lh; // for height of left subtree
        int rh; // for height of right subtree 
        
        // If tree is empty, return true
        if(root == NULL)
            return 1; 
    
        // Get the height of left and right subtrees
        lh = height(root->left);
        rh = height(root->right);
    
        // Check if the difference in heights is <= 1
        // and recursively check for all nodes in the tree
        if( abs(lh-rh) <= 1 &&
            __getBalance__(root->left) &&
            __getBalance__(root->right))
         return 1;
    
         // If we reach here, the tree is not height-balanced
        return 0;
    }
    
    // Function to insert a new node into an AVL tree
    Node* insertToAVL(Node* node, int data)
    {   
        // If the node is null, create a new node with the data
        if (node == NULL)
            return new Node(data);
    
        // If the data is less than the current node's data,
        // insert it into the left subtree
        if (data < node->data)
            node->left = insertToAVL(node->left, data);
        // If the data is greater than the current node's data,
        // insert it into the right subtree
        else if(data > node->data)
            node->right = insertToAVL(node->right, data);
       // If the data is equal to the current node's data,
       // return the node (no insertion needed)
       else
           return node;
    
        // Update the height of the current node
        node->height = max(height(node->left), height(node->right)) + 1;
    
        // Check the balance factor of the current node
        int balance = getBalance(node);
    
        // Perform rotations based on the balance factor
        
        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);
    
       // Right Right Case
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);
    
        // Left Right Case
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    
        // Right Left Case
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends