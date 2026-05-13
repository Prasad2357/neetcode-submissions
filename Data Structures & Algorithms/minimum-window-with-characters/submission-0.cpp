class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int min_len = 0;
        string ans = "";

        if(m > n)
        {
            return "";
        }

        unordered_map <char,int> tmpp;
        
        for(char c: t)
        {
            tmpp[c]++;
        }

        for(int i=0; i<n; i++)
        {
            unordered_map <char,int> submpp; 
            for(int j=i; j<n; j++)
            {
                submpp[s[j]]++;
                bool valid = true;

                for(auto it: tmpp)   //comparing both tmpp and submpp
                {
                    char ch = it.first;
                    int freq = it.second;  

                    if(submpp[ch] < freq)
                    {
                        valid = false;
                        break;
                    } 
                }

                if (valid)
                {
                    string curr = s.substr(i, j-i+1);
                    if (ans=="" || curr.size()< ans.size())
                    {
                        ans = curr;
                    }
                }
            }
        }
        return ans;
        
    }
};
