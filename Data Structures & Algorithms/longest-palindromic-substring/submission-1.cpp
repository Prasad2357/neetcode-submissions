class Solution {

private:
    bool isPalindrome(string s, int left, int right, vector<vector<bool>> &dp){

        //check the dp array
        if(s[left] == s[right] && dp[left][right])
        {
            return true;       
        }

        while(left< right)
        {
            if(s[left]!= s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        //store the ans in DP array
        dp[left][right]=true;
        return true;
    }


public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen=0;
        int start=0;

        //DP array
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        //generate all the substrings
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                //check if the string is palindrome
                if(isPalindrome(s,i,j,dp))
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        start =i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
        
    }
};
