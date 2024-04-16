
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            root = newnode;
            return root;
        }
        int count=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            count+=1;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*top=q.front();
                q.pop();
                if(count==depth-1){
                    TreeNode*leftNode= new TreeNode(val,top->left,NULL);
                    TreeNode*rightNode= new TreeNode(val,NULL,top->right);
                    top->left=leftNode;
                    top->right=rightNode;
                }else{
                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }

            }
        }
        return root;
    }
};
 