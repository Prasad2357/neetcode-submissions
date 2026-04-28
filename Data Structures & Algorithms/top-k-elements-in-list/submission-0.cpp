class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Brute Force : Using Hash Map

        unordered_map <int, int> freq;  //element: freq

        for(int num: nums)
        {
            freq[num]++;  //increase the freq
        }

        //sorting the map, for that first convert map to vector
        //sort on the basis of freq (value not key)
        vector <pair<int,int>> vec (freq.begin(), freq.end());

        //custom comparator
        sort(vec.begin(),vec.end(), [](auto &a, auto &b)   //sort(start, end, comparator)
        {
            return a.second > b.second; //descending 
        });

        vector <int> ans;  //top k elements
        for(int i=0; i<k; i++)
        {
            ans.push_back(vec[i].first);  
        } 

        return ans;
        
    }
};
