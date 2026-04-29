class Solution {
public:

    string encode(vector<string>& strs) {
        
        string result="";
        for(string s: strs)
        {
            result += to_string(s.size())+ "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Step 1: read length
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            // Step 2: move to string start
            j++;

            // Step 3: extract string of length 'len'
            string word = s.substr(j, len);
            result.push_back(word);

            // Step 4: move pointer
            i = j + len;
        }

        return result;
    }
};
