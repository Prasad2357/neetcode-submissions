class Solution {
public:
    bool isPalindrome(string s) {

        // // Brute Force: reverse and compare string
        // string s_clean = "";
        // for(char c: s)
        // {
        //     if(isalnum(c))
        //     {
        //         s_clean+=tolower(c);
        //     }
        // }

        // string rev = s_clean;
        // reverse(rev.begin(), rev.end());
        // for(int i=0; i<s_clean.size(); i++)
        // {
        //     if(s_clean[i] != rev[i])
        //     {
        //         return false;
        //     }
        // }

        // return true;


        // Optimal: Two pointers

        int left = 0, right = s.size()-1;

        while(left< right)  //not used <= because for odd len string the palindrome condition wouldn't match
        {
            while(left< right && !isalnum(s[left]))
            {
                left++;
            }

            while(left< right && !isalnum(s[right]))
            {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
