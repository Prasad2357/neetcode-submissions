class Solution {
public:
    int climbStairs(int n) {

        // //tabulation method
        // //base cases
        // if(n == 1) return 1;
        // if(n == 2) return 2;

        // //declare the dp array
        // vector<int> dp(n+1, -1);

        // //base values
        // dp[1] = 1;
        // dp[2] = 2;

        // //run loop except base cases
        // for(int i=3; i<=n; i++)
        // {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // return dp[n];


        //optimizing the tabulation method
        if(n == 1) return 1;
        if(n == 2) return 2;

        //declare the dp array
        vector<int> dp (n+1, -1);

        int curr;
        int prev = 2;
        int prev2 = 1;

        for(int i=3; i<=n; i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
 