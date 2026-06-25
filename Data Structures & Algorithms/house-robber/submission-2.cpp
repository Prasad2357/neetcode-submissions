class Solution {
private:
    int solve(vector <int>&nums, int i, vector<int> &dp){
        //base case
        if(i>= nums.size())
        {
            return 0;
        }

        //use the precomputed value
        if(dp[i] != -1)
        {
            return dp[i];
        }

        int take = nums[i] + solve(nums, i+2, dp);
        int skip = solve(nums, i+1, dp);

        //store the compuhted result
        return dp[i] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        //declare the dp vector
        vector <int> dp(nums.size()+1, -1); 
        return solve(nums, 0, dp);
        
    }
};
