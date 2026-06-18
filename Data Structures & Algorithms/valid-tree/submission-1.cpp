class Solution {
private:
    bool dfs(int node,int parent, vector<int> &visited, vector<int> adj[]){
        //mark visited
        visited[node] =1;

        for(auto neigh: adj[node])
        {
            if(!visited[neigh])
            {
                if(!dfs(neigh,node, visited, adj))
                {
                    return false;
                }
            }

            else if(neigh!=parent)
            {
                // visited neighbor that isn't parent, cycle found
                return false;
            }
        }
        return true;
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
        //detect cycle
        if(!dfs(0,-1, visited, adj))
        {
            return false;
        }

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
