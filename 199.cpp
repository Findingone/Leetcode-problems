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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> roots;
        vector<int> level;
        vector<int> sol;
        roots.push_back(root);
        level.push_back(0);
        while(roots.size()!=0){
            TreeNode *current = roots.at(0);
            int clev = level.at(0);
            if(current==NULL){
                return sol;
            }
            if(current->left!=NULL){
                roots.push_back(current->left);
                level.push_back(clev+1);
           }
            if(current->right!=NULL){
                roots.push_back(current->right);
                level.push_back(clev+1);
            }
            if(level.size()==1 || level.at(1)>clev){
                sol.push_back(current->val);
            }
            level.erase(level.begin());
            roots.erase(roots.begin());
        }
        return sol;
    }
};
