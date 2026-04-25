class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector <int> tar;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(target == nums[i]+nums[j])
                {
                    tar.push_back(i);
                    tar.push_back(j);

                    return tar;
                }
            }
            
        }

        return tar;
     
    }
};
