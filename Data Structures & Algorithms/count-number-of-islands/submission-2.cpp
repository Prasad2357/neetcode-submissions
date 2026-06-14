// class Solution {
// private:

//     void bfs(int i, int j, vector <vector<int>> &visited, vector<vector<char>>& grid ){
//         visited[i][j] = 1;
//         queue<pair<int,int>> q;
//         q.push({i,j});

//         int n = grid.size();
//         int m = grid[0].size();

//         while(!q.empty())
//         {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             //traverse
//             int delrow[] = {-1, 0, 1, 0};
//             int delcol[] = {0, 1, 0, -1};

//             for(int k=0; k<4; k++)
//             {     
//                 int nrow = row+delrow[k];
//                 int ncol = col+delcol[k];

//                 //boundary constraint and 'land' in the grid and not visited as well
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol])
//                 {
//                     visited[nrow][ncol] = 1;  //mark visited
//                     q.push({nrow, ncol});     //push into queue
//                 }
//             }
//         }
//     }
    
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector <vector<int>> visited(n, vector<int> (m,0));
//         int count = 0;

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(!visited[i][j] && grid[i][j]=='1')
//                 {
//                     count++;
//                     bfs(i,j,visited, grid);
//                 }
//             }
//         }
//         return count;
        
//     }
// };



//DFS


class Solution {
private:
    //  directions[4][2] = {  up,   right,  left,  down }
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    void dfs( vector<vector<char>>& grid, int i, int j){
        //all the constraint conditions
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
        {
            return; //base case
        }

        //mark visited
        grid[i][j] ='0';

        //explore in four directions
        for(int k=0; k<4; k++)
        {
            dfs(grid,i+directions[k][0], j+directions[k][1]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};
