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

    int kthSmallest(TreeNode* root, int k) {

        //inorder traversal  left root right
        vector <int> nums;
        InOrder(root, nums);

        return nums[k-1];
     
    }

    void InOrder(TreeNode *root, vector<int> &nums)
    {
        if(root == nullptr)
        {
            return;
        }   

        InOrder(root->left, nums);
        nums.push_back(root->val);
        InOrder(root->right, nums);
    }
};
