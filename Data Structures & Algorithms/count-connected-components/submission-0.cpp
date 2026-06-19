class Solution {
private:
    void dfs(int node, vector<int> &visited, vector<int> adj[]){
        //mark visited
        visited[node] = 1;

        //explore the directions
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                dfs(it, visited, adj);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //create adj list
        vector<int> adj[n];

        for(auto &e: edges)
        {
            int a = e[0];
            int b = e[1];

            adj[a].push_back(b);
            adj[b].push_back(a);

        }
        //visited array
        vector<int> visited(n,0);

        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,visited, adj);
            }
        }

        return count;

    }
};
