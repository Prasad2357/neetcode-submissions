class Solution {
public:
    bool isAnagram(string s, string t) {

        // Brute Force:

        // int n = s.size();
        // int m = t.size();

        // if(n != m)  //size not matching
        // {
        //     return false;
        // }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for (int i=0; i<n; i++)
        // {
        //     if(s[i]!=t[i])
        //     {
        //         return false;
        //     }
        // }

        // return true;


        // Optimal:

        int n = s.size();
        int m = t.size();

        if(n != m)  //size not matching
        {
            return false;
        }

        // put them in unordered frequency map
        unordered_map <char,int> mpp1;
        unordered_map <char,int> mpp2;

        for (int i=0; i<n; i++)
        {
            mpp1[s[i]]++;    // counting the freq
            mpp2[t[i]]++;
        }

        if(mpp1 != mpp2)
        {
            return false;
        }
        return true;
   
    }
};
