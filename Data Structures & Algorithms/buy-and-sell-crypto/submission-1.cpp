class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // // Brute Force: Nested Loop

        // int profit = 0;
        // int max_profit = 0;
        // int n = prices.size();

        // for(int i=0; i<n-1; i++)
        // {
        //     for(int j=i+1; j<n; j++)
        //     {
        //         profit = prices[j] - prices[i];
        //         max_profit = max(profit, max_profit);
        //     }
        // }

        // return max_profit;


        // Optimal: Sliding Window

        int left = 0;
        int n = prices.size();
        int right = left+1;

        int profit = 0;
        int max_profit = 0;

        while(right<n)
        {   
            if(prices[right] > prices[left])
            {
                profit = prices[right] - prices[left];
                max_profit = max(profit, max_profit);
            }
            else
            {
                left=right;
            }
            right++;
        }

        return max_profit;      
    }
};
