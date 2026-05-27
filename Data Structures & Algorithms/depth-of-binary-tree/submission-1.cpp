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
    int maxDepth(TreeNode* root) {
    
    //     DFS

    //     if(root == nullptr)
    //     {
    //         return 0;             //base case
    //     }

    //     int left_depth = maxDepth(root->left);
    //     int right_depth = maxDepth(root->right);

    //     return max(left_depth, right_depth)+1;
        

    //     BFS


    queue <TreeNode *> q;
    if(root != nullptr)
    {
        q.push(root);
    }

    int level = 0;
    while(!q.empty())
    {
        int n = q.size();
        for(int i =0; i<n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left != nullptr)
            {
                q.push(node->left);
            }

            if(node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        level++;
    }

    return level;
    }
  
};
