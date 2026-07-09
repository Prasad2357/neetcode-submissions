class Solution {

public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++)
        {
            dp[i][i] = true;
            count++;
        }

        for(int length =2; length<=n; length++)
        {
            for(int i=0; i+length-1<n; i++)
            {
                int j = i+length-1;

                //check if string is palindrome
                if(s[i]==s[j])
                {
                    if(j-i+1<=2)
                    {
                        dp[i][j] = true;
                        count++;
                    }
                    else
                    {
                        if(dp[i+1][j-1])
                        {
                            dp[i][j] =true;
                            count++;
                        }
                    }
                }

            }
        }
        return count;
        
    }
};
