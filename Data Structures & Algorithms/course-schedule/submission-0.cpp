class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int> adj[]){

        vis[node] =1; // currently in recursion stack

        for(auto it: adj[node])
        {
            if(vis[it] ==1)
            {
                return false;
            }

            if(vis[it] ==0)
            {
                if(!dfs(it, vis, adj))
                {
                    return false;
                }
            }
        }
        vis[node] =2;   // completely processed

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        bool ans;
        
        //adj list
        vector<int> adj[numCourses+1];
        for(auto &p: prerequisites)
        {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        //visited array
        vector<int> vis(numCourses, 0);

        for(int i=0; i<numCourses; i++)
        {
             if(!dfs(i, vis, adj))
            {
                return false;
            }
        }

        return true;
        
    }
};
