class Solution {
private:
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        //base case
        if(amount ==0)
        {
            return 0;
        }  
        int mini =INT_MAX;

        for(int coin: coins)
        {
            if(coin<= amount)
            {
                if(dp[amount]!= -1)
                {
                    return dp[amount];
                }
                int ans = solve(coins, amount - coin, dp);

                // Only update if the remaining amount was possible
                if(ans != INT_MAX)
                {
                    mini = min(mini, ans+1);    //best and for remaining amt + current coin
                }
            }
            
        }
        return dp[amount] = mini;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);

        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};
