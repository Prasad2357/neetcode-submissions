class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Solution 1: Freq 

        // unordered_map <string, vector<string>> mpp;

        // for(string s: strs)
        // {
        //     vector <int> freq(26,0);
        //     for (char c: s)
        //     {
        //         freq[c - 'a']++;   //count freq 
        //     }

        //     //convert freq to string
        //     // map cannot hash the vector so we convert it to string
        //     // or it could have been unordered_map <vector <int> , vector<string>> mpp;

        //     string key="";
        //     for(int i=0; i<26; i++)
        //     {
        //         key+= to_string(freq[i])+"#";
        //     }

        //     mpp[key].push_back(s);   //push back the string to the group


        // }

        // vector <vector<string>> result;
        // for (auto it: mpp)
        // {
        //     result.push_back(it.second);
        // }

        // return result;
        




        // Solution 2: Sort

        unordered_map <string, vector<string>> mpp;  // key: sorted substring, value: original substrings (anagrams) 

        for (string s: strs)
        {     
            
            string original_key = s;
            for(char c: s)   //loop over char in substring
            {
                //sort the substring    
                sort(s.begin(), s.end());
            }
            //push back the sorted substring as key and original as value
            mpp[s].push_back(original_key);
        }

        vector <vector<string>> result;

        for(auto it: mpp)
        {
            result.push_back(it.second);
        }

        return result;

    }
};
