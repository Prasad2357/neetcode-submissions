class Solution {
public:
    int rows, cols;
    vector<vector<bool>> visited;

    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int idx)
    {
        //base case
        if(idx == word.length())
        {
            return true;
        }

        if(i< 0 || i>=rows || j<0 || j>=cols || visited[i][j] ||  board[i][j]!=word[idx])
        {
            return false;
        }

        //make choice
        visited[i][j] = true;

        //explore(recurse)

        bool found =
            solve(board, word, i + 1, j, idx + 1) || // down
            solve(board, word, i - 1, j, idx + 1) || // up
            solve(board, word, i, j + 1, idx + 1) || // right
            solve(board, word, i, j - 1, idx + 1);   // left


        //undo choice
        visited[i][j] = false;
        
        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        visited.assign(rows, vector<bool>(cols, false));

        // Try every cell as a starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
        
    }
};
