class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen=1;   //for single string char
        int start=0;

        //DP array
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++)
        {
            //all len(1) substrings are palindrome
            dp[i][i] = true;
        }

        for(int length=2; length<=n; length++)
        {
            for(int i=0; i+length-1 <n; i++)
            {
                int j = i+ length-1;
                //check if the string is palindrome
                if(s[i] == s[j])
                {
                    if(j-i+1 <=2)
                    {
                        dp[i][j]= true;
                    }
                    else
                    {
                        if(dp[i+1][j-1])
                        {
                            dp[i][j] = true;    
                        }
                    }   

                    if(dp[i][j] && j-i+1> maxlen)
                    {
                        maxlen = j-i+1;
                        start = i;
                    }   
                }
            }
        }
        return s.substr(start,maxlen);
        
    }
};
