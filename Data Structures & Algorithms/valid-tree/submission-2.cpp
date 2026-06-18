class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<int> adj[])
    {
        visited[node] = 1;

        for(auto neigh : adj[node])
        {
            if(!visited[neigh])
            {
                dfs(neigh, visited, adj);
            }
        }
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) { 

        if(n-1 != edges.size())
        {
            return false;
        }

        //create adj list
        vector<int> adj[n];
        for(auto &p: edges)
        {
            int a = p[0];
            int b = p[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector <int> visited(n,0); 
        dfs(0, visited, adj);

        //connected
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }

        return true;

    }
};
