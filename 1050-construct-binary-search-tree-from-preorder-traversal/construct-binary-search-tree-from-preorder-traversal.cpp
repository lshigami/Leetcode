class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& v) {
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(v[0]);
        st.push(root);
        for(int i = 1; i < v.size(); i++){
            TreeNode* node = new TreeNode(v[i]);
            if(v[i] < st.top()->val){
                st.top()->left = node;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();
                while(!st.empty() && v[i] > st.top()->val){
                    temp = st.top();
                    st.pop();
                }
                temp->right = node;
            }
            st.push(node);
        }
        return root;
    }
};
