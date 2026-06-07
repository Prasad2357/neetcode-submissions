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

class Codec {
public:

    string serialize(TreeNode* root) {

        if(root == nullptr)
            return "N,";

        string ans = to_string(root->val) + ",";
        ans += serialize(root->left);
        ans += serialize(root->right);

        return ans;
    }

    TreeNode* build(vector<string>& nodes, int& idx)
    {
        if(nodes[idx] == "N")
        {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++;

        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp;

        for(char c : data)
        {
            if(c == ',')
            {
                nodes.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(c);
            }
        }

        int idx = 0;
        return build(nodes, idx);
    }
};
