class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //Brute Force: Nested Loops

        // vector <int> tar;
        // int n = nums.size();
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=i+1; j<n; j++)
        //     {
        //         if(target == nums[i]+nums[j])
        //         {
        //             tar.push_back(i);
        //             tar.push_back(j);

        //             return tar;
        //         }
        //     }  
        // }
        // return tar;


        // Optimal : hashmap and diff

        unordered_map <int,int> mpp; //value: index format
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int diff = target - nums[i];

            if( mpp.find(diff) != mpp.end())   //found the complement
            {
                return {mpp[diff], i};   //find the key and return the index ( it = mpp.find(diff) it->second & i)
            }

            mpp[nums[i]]=i;   // if no complement is found store in value: index format
        }

        return {};
    }
};

