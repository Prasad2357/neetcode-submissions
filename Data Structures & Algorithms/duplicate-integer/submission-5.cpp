class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        // // Brute Force 1:

        // int n = nums.size();
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=i+1; j<n; j++)
        //     {
        //         if (nums[i]== nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;



        // // Brute Force 2:

        // int n = nums.size();

        // sort(nums.begin(), nums.end());
        // for (int i=0; i<n-1; i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     {
        //         return true;
        //     }
        // }
        // return false;


        // // Optimal 1; Using hashmap (frequency):

        // int n = nums.size();
        // unordered_map <int,int> mpp;
        // for(int i=0; i<n; i++)
        // {
        //     mpp[nums[i]]++; //store the frequency in the map
        // }

        // // traverse the map
        // for(auto it: mpp)
        // {
        //     if(it.second > 1)  //if the frequency is greater than 1
        //     {
        //         return true;
        //     }
        // }

        // return false;


        // // Optimal 2:
        // int n = nums.size();
        // unordered_map <int,int> mpp;

        // for(int i =0; i<n; i++)
        // {
        //     if(mpp[nums[i]] > 0)  //If nums[i] is not in the map: It gets created automatically with value 0
        //     {
        //         return true;
        //     }
        //     mpp[nums[i]]++;
        // }

        // return false;



        // Optimal 3: Using set:
        int n = nums.size();
        unordered_set <int> st;

        for(int num: nums)
        {
            if(st.count(num))   //count function returns true if the number is present
            {
                return true;
            }
            st.insert(num);
        }

        return false;

    }
};