class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // // Brute Force - 3 nested loops

        // set <vector<int>> st;
        // int n = nums.size();

        // for(int i=0; i<n-2 ; i++)
        // {
        //     for(int j=i+1; j<n-1; j++)
        //     {
        //         for(int k=j+1; k<n; k++)
        //         {   
        //             if (nums[i]+ nums[j]+ nums[k]==0)
        //             {
        //                 // put ele in vector and sort them to remove duplicates
        //                 vector <int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector <vector<int>> ans (st.begin(), st.end());
        // return ans;
        

        // Optimal - Two Pointers

        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i=0; i<n-2; i++)
        {
            //skip duplicates
            if(i> 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int j = i+1;
            int k = n-1;

            int target = -nums[i];
            
            while(j<k)
            {
                int sum = nums[j] + nums[k];
                if(sum<target)
                {
                    j++;
                }

                else if (sum>target)
                {
                    k--;
                }

                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    //skip duplicate
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }

                    while(j<k && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                }
            }
        }

        return ans;


    }
};
