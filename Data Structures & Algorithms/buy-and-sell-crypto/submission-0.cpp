class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Brute Force: Nested Loop

        int profit = 0;
        int max_profit = 0;
        int n = prices.size();

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                profit = prices[j] - prices[i];
                max_profit = max(profit, max_profit);
            }
        }

        return max_profit;
        
        
    }
};
