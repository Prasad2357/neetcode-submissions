class Solution {
    //we go from outside to inside (ocean to cell)

    vector<vector<int>> ans;
    // vector<int> intermediate;
    int row, col;
    vector<vector<bool>> pac;
    vector<vector<bool>> atl;

private:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;

        int dir[4][2] ={{1,0}, {-1,0}, {0,-1}, {0,1}};

        for(auto &it: dir)
        {
            int nr= i+it[0];
            int nc= j+it[1];

            //base cases
            if(nr<0 || nc<0 || nr>=row || nc>=col)
            {
                continue;
            }

            if(visited[nr][nc])
            {
                continue;
            }

            if(heights[nr][nc] < heights[i][j])
            {
                continue;
            }

            dfs(heights, nr, nc, visited );
        }

    }




public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty())
        return {};
        
        row= heights.size();
        col= heights[0].size();

        pac = vector<vector<bool>> (row, vector<bool> (col, false));
        atl = vector<vector<bool>> (row, vector<bool> (col, false));

        for(int i=0; i<row; i++)
        {
            for(int j=0;j<col; j++)
            {
                //pacific ocean
                if(i == 0 || j== 0 && !pac[i][j])
                {
                    dfs(heights, i, j, pac);
                }

                //atlantic ocean
                if(i== row-1 || j==col-1 && !atl[i][j])
                {
                    dfs(heights, i, j, atl);
                } 
            }   
        }


        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(atl[i][j] && pac[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;  
    }
};
