class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute Force:

        // int n = nums.size();
        // vector <int> output;

        // for(int i=0;i<n;i++)
        // {
        //     int product = 1;
        //     for(int j=0;j<n; j++)
        //     {
        //         if(i==j)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             product*=nums[j];
        //         }
               
        //     }
        //     output.push_back(product);
        // }


        // return output;


        // Optimal: using prefix and suffix array

        int n = nums.size();
        vector <int> prefix(n,1);
        vector <int> suffix(n,1);
        int product = 1;

        for(int i=1; i<n; i++)
        {
            product *= nums[i-1];
            prefix[i] = product;
        }

        product = 1;
        for(int i=n-2; i>=0; i--)
        {
            product *= nums[i+1];
            suffix[i] = product;
        }

        // multiply both the numbers
        for(int i=0; i<n; i++)
        {
            prefix[i] = prefix[i]*suffix[i];
        }

        return prefix;
    }
};

