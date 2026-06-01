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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //greater values go right
        if(p->val > root->val &&  q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        //smaller values go left
        else if (p->val < root->val &&  q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q); 
        }

        //split
        else if (p->val < root->val && q->val > root->val ||
                 p->val > root->val && q->val < root->val)
        {   
            return root;
        }

        //one node is parent of another
        else if (p->val == root->val || q->val == root->val)
        {
            return root;
        }

        return nullptr;
        
    }
    
};
