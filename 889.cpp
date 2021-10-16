/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int x = 0,y=0;
    TreeNode* secondFunc(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root;
    if(x==preorder.size()|| y== postorder.size()){
        return NULL;
    }
    if (preorder.at(x) != postorder.at(y)) {
        root = new TreeNode(preorder.at(x++), secondFunc(preorder, postorder),
                            NULL);
    }else     if (preorder.at(x) == postorder.at(y)) {
        root = new TreeNode(preorder.at(x++));
    }
    if(x==preorder.size()|| y== postorder.size()){
        return root;
    }

    if(root->val!=postorder.at(y++)){
        y--;
        root->right = secondFunc(preorder,postorder);
        y++;

    }
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode * root;
    root = secondFunc(preorder, postorder);
        return root;
    }
};
