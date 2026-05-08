class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Brute Force - 3 nested loops

        set <vector<int>> st;
        int n = nums.size();

        for(int i=0; i<n-2 ; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {   
                    if (nums[i]+ nums[j]+ nums[k]==0)
                    {
                        // put ele in vector and sort them to remove duplicates
                        vector <int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector <vector<int>> ans (st.begin(), st.end());
        return ans;
        
    }
};
