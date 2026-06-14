class Solution {
private:

    void bfs(int i, int j, vector <vector<int>> &visited, vector<vector<char>>& grid ){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int k=0; k<4; k++)
            {     
                int nrow = row+delrow[k];
                int ncol = col+delcol[k];

                //boundary constraint and 'land' in the grid and not visited as well
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol])
                {
                    visited[nrow][ncol] = 1;  //mark visited
                    q.push({nrow, ncol});     //push into queue
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> visited(n, vector<int> (m,0));
        int count = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,visited, grid);
                }
            }
        }
        return count;
        
    }
};
