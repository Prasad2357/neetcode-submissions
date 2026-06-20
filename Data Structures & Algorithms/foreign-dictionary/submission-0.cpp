class Solution {
private:
    vector<int> topoSort(int v, vector<int> adj[]){
        vector<int> indegree(v, 0);
        //calculate indegree
        for(int i=0; i<v; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        //push into queue whose indegree is 0
        queue <int> q;
        for(int i=0; i<v; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            //reduce ele from indegree
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] ==0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }


public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        string ans;

        vector<bool> exists(26, false);

        //unique char
        for(auto word : words)
        {
            for(char ch : word)
            {
                exists[ch - 'a'] = true;
            }
        }

        //adj list
        vector<int> adj[26];

        //compare
        for(int i=0; i<n-1; i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            bool check = false;

            int len = min(s1.size(), s2.size());
            for(int j=0; j<len; j++)
            {
                if(s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');   //pushing numbers instead of char
                    check = true;
                    break;
                }
            }
            if(check == false && s1.size()> s2.size())   //edge case   s1=abcd  s2=abc
            {
                return "";
            }

        }

        vector <int> topo = topoSort(26,adj);

        //finding cycles
        int uniqueChars = 0;
        for(bool x : exists)
        {
            if(x) uniqueChars++;
        }

        int topoChars = 0;
        for(auto node : topo)
        {
            if(exists[node])
            {
                topoChars++;
            }
        }

        if(topoChars < uniqueChars)
        {
            return "";
        }


        for(auto it: topo)
        {
            if(exists[it])
            {
                ans = ans + char(it + 'a');
            }
        } 
        return ans;

    }
};
