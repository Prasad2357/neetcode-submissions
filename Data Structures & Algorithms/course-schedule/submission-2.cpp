// class Solution {
// private:
//     bool dfs(int node, vector<int>& vis, vector<int> adj[]){

//         vis[node] =1; // currently in recursion stack

//         for(auto it: adj[node])
//         {
//             if(vis[it] ==1)
//             {
//                 return false;
//             }

//             if(vis[it] ==0)
//             {
//                 if(!dfs(it, vis, adj))
//                 {
//                     return false;
//                 }
//             }
//         }
//         vis[node] =2;   // completely processed

//         return true;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
//         //adj list
//         vector<int> adj[numCourses+1];
//         for(auto &p: prerequisites)
//         {
//             int a = p[0];
//             int b = p[1];
//             adj[b].push_back(a);
//         }

//         //visited array
//         vector<int> vis(numCourses, 0);

//         for(int i=0; i<numCourses; i++)
//         {
//              if(!dfs(i, vis, adj))
//             {
//                 return false;
//             }
//         }

//         return true;
        
//     }
// };




// Kahn's Algo (BFS)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        //adj list
        vector<vector<int>> adj(numCourses);
        for(auto &p: prerequisites)
        {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        //indegree calculation
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        //push the ele whose indegree=0
        queue <int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] ==0)
            {
                q.push(i);
            }
        }

        int count =0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            //reduce the indegree
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] ==0)
                {
                    q.push(it);
                }
            }
        }

        return count== numCourses;
        
    }
};

