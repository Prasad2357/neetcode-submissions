class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // // Brute Force
        // int max_product = INT_MIN;
        // int n = nums.size();

        // for(int i=0; i<n; i++)
        // {
        //     int product = 1;
        //     for(int j=i; j<n; j++)
        //     {
        //         product *= nums[j];
        //         max_product = max(product, max_product);
        //     }
        // }

        // return max_product;  

        // Prefix and suffix

        int n = nums.size();
        int res = nums[0];

        int prefix=0; int suffix=0;

        for(int i=0; i<n; i++)
        {
            //from left side, reset at 0 start new subarray
            prefix = nums[i] * (prefix==0 ? 1 : prefix); 

            //from right side     
            suffix = nums[n-1-i] * (suffix==0 ? 1 : suffix);  
            res = max(res, max(prefix, suffix));
        } 
        return res;
    }
};
