class TrieNode {
public:
    TrieNode *children [26];
    string word;

    //constructor
    TrieNode(){
        for(int i=0; i<26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode *root;
    vector<string> ans;
    int rows, cols;
    vector<vector<bool>> visited;

    Solution(){
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *curr = root;

        for(char c: word)
        {
            if(curr->children[c- 'a'] == nullptr)
            {
                TrieNode *newNode = new TrieNode();   //new node
                curr->children[c -'a'] = newNode;     //reference, connect parent to newly created node
            }
            curr = curr->children[c-'a'];  //move pointer
        }  
        curr->word = word;
    }

    void solve(vector<vector<char>>& board, int i, int j, TrieNode *node)
    {
        //boundary checks constraints
        if(i<0 || i>=rows || j<0 ||j>=cols || visited[i][j])
        {
            return;
        }

        char ch = board[i][j];
        if(node->children[ch- 'a']== nullptr)
        {
            return; //prune
        }

        //child exists
        node = node->children[ch- 'a'];

        if(node->word != "")
        {
            ans.push_back(node->word);
            node->word ="";
        }
        visited[i][j] = true;

        //explore (recurse)
        solve(board, i+1, j, node);  //down
        solve(board, i-1,j, node);  //up
        solve(board, i, j+1, node);  //right
        solve(board, i, j-1, node);  //left

        //undo choice
        visited[i][j] = false;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(int i=0; i<words.size(); i++)
        {
            insert(words[i]);  //sending string at a time
        }

        // if(board.empty())
        // {
        //     return {};
        // }

        //traversing the grid
        rows = board.size();
        cols = board[0].size();

        visited = vector<vector<bool>>(rows,
                               vector<bool>(cols,false));

        for(int i=0; i<rows; i++)
        {
            for(int j=0;j< cols; j++)
            {
                solve(board, i, j, root);
            }
        }

        return ans;
    }
};
