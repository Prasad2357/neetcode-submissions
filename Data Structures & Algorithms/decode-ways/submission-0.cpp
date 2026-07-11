class Solution {
private:
    int dfs(string &s, int i, vector<int> &dp){

        //reached the end of string
        if(i==s.length())
        {
            return 1; 
        }

        //base condition
        if(s[i]=='0')
        {
            return 0;
        }

        if(dp[i]!= -1)
        {
            return dp[i];
        }

        dp[i] = dfs(s, i+1,dp);

        if(i+1< s.length())
        {
            int num = (s[i]-'0')*10 + (s[i+1]-'0');   //26=2×10+6
            if(num>=10 && num<=26)
            {
                dp[i]+=dfs(s, i+2,dp);
            }
        }
        return dp[i];
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        return dfs(s,0, dp);
    }
};
