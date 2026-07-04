class Solution {
private:
    int solve(vector<int> &nums, int i, vector<int> &dp){
        if(i>=nums.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int take = nums[i] + solve(nums, i+2, dp); 
        int skip = solve(nums,i+1, dp);

        return dp[i] = max(skip, take);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        {
            return nums[0];
        }

        //first house to the second-to-last house
        vector<int> nums1 (nums.begin(),nums.end()-1);

        //second house to the last house
        vector<int> nums2 (nums.begin()+1,nums.end());

        //dp vector
        vector<int> dp1(nums.size()+1, -1);
        int ans1 = solve(nums1, 0, dp1);

        //reinitialize dp vector
        vector<int> dp2(nums.size()+1, -1);
        int ans2 = solve(nums2, 0, dp2);

        return max(ans1, ans2);
    }

};
