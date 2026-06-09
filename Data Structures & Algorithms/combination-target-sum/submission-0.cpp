class Solution {
public:

    void solve(int idx, int remaining, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){

        if(remaining == 0)
        {
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<nums.size(); i++)
        {
            //make choice
            if(remaining - nums[i]>= 0)
            {
                curr.push_back(nums[i]);
            
                //explore(recurse)
                solve(i,remaining-nums[i], nums, curr, ans);   //same number

                //undo choice
                curr.pop_back();
            }

        }


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector <vector<int>> ans;
        vector<int> curr;

        solve(0, target, nums, curr, ans);        

        return ans;
        
    }
};
