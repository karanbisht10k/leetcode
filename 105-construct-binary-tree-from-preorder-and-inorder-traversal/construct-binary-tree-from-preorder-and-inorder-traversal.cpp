class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, int inorderStart, int inorderEnd) {

        if (inorderStart > inorderEnd)
            return NULL;
 
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];
        root->left = solve(preorder, inorderStart,pos - 1);
        root->right = solve(preorder, pos + 1,inorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,  vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        preIndex = 0;
        return solve(preorder, 0, inorder.size() - 1);
    }
};