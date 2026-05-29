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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        //subroot is non null
        if(root == nullptr)
        {
            return false;
        }

        if(isSameTree(root,subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
        
    }

private:
    bool isSameTree(TreeNode *p, TreeNode *q){

        if(p== nullptr && q!= nullptr || p!=nullptr && q==nullptr)
        {
            return false;
        }

        else if (p==nullptr && q==nullptr)
        {
            return true;
        }

        else if (p->val != q->val)
        {
            return false;
        }

        bool l_tree = isSameTree(p->left, q->left);
        bool r_tree = isSameTree(p->right, q->right);

        return l_tree && r_tree;
    }
};
