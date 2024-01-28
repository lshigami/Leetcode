class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = build(nums, l, m - 1);
        node->right = build(nums, m + 1, r);
        return node;
    }
};
