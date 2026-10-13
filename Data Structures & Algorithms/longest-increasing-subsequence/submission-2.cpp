class Solution {

private:
    int dfs(vector<int> &nums, int i, int prev, vector<vector<int>> &dp ) {

        //base condition
        if(i == nums.size())
        {
            return 0;
        }

        int curr = i;
        int take = 0;

        if(dp[i][prev +1] != -1)
        {
            return dp[i][prev +1];
        }

        // take or skip
        if(prev ==-1 || nums[i]> nums[prev])
        {
            take = 1 + dfs(nums, i+1, i, dp);
        }
        
        int skip = dfs(nums, i+1, prev, dp);

        return dp[i][prev +1] = max(take, skip);
 
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int length = 0;
        int max_length = 0;
        int n = nums.size();

        //dp array
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));

        length = dfs(nums, 0, -1, dp);
        max_length = max(length, max_length);
    
        return max_length;
        
    }
};
