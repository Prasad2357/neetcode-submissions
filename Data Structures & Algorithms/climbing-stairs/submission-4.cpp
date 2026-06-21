class Solution {
private:
    int solve(int n, vector <int> &dp){
        //base case
        if(n==1 || n==2)
        {
            return n;
        }

        //use precomputed value if already calculated
        if(dp[n] != -1)
        {
            return dp[n];
        }

        //store ans of subproblem
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

public:
    int climbStairs(int n) {

        //intialize dp
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};
