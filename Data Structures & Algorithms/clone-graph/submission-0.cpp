/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mpp;

    Node* dfs(Node* node) {
    // If already cloned, return the clone
    if(mpp.find(node)!= mpp.end())
    {
        return mpp[node];
    }

    //create a new node
    Node *clone = new Node(node->val);   //1----> 1'

    //push back to hashmap
    //original -->clone
    mpp[node] = clone;

    //clone for all neighbors
    for(auto neighbor: node->neighbors)
    {
        Node *clonedNeighbor = dfs(neighbor);
        clone->neighbors.push_back(clonedNeighbor);
    }
    return clone;
}

public:
    Node* cloneGraph(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    return dfs(node);      
    }
};
