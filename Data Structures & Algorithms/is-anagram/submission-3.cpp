class Solution {
public:
    bool isAnagram(string s, string t) {

        // // Brute Force:

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


        // // Optimal 1:

        // int n = s.size();
        // int m = t.size();

        // if(n != m)  //size not matching
        // {
        //     return false;
        // }

        // // put them in unordered frequency map
        // unordered_map <char,int> mpp1;
        // unordered_map <char,int> mpp2;

        // for (int i=0; i<n; i++)
        // {
        //     mpp1[s[i]]++;    // counting the freq
        //     mpp2[t[i]]++;
        // }

        // if(mpp1 != mpp2)
        // {
        //     return false;
        // }
        // return true;


        // // Optimal 2:

        // int n = s.size();
        // int m = t.size();

        // if(n != m)  //size not matching
        // {
        //     return false;
        // }

        // // put them in unordered frequency map
        // unordered_map <char,int> mpp;

        // for(char c: s)
        // {
        //     mpp[c]++;   //add the freq
        // }

        // for(char c: t)
        // {
        //     mpp[c]--;   //cancel out the freq
        // }

        // for(auto it: mpp)   //check if the freq is greater than zero or not
        // {
        //     if(it.second!=0)
        //     {
        //         return false;
        //     }
        // }


        // return true;



        // Optimal 3: fixed vector size (26 for lower case):

        int n = s.size();
        int m = t.size();

        if(n != m)  //size not matching
        {
            return false;
        }

        vector <int> freq (26,0);

        for(char c: s)
        {
            freq[c - 'a']++;   //ASCII
        }

        for(char c: t)
        {
            freq[c - 'a']--;
        }

        for(int x: freq)
        {
            if(x!= 0)
            {
                return false;
            }
        }

        return true;
   
    }
};
