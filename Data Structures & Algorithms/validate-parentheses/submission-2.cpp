class Solution {
public:
    bool isValid(string s) {

        //Use stack
        stack <char> st;
        for(char c: s)
        {
            if(c=='(' || c=='[' || c=='{')
            {
                st.push(c);
            }

            else
            {
                if(c ==')' && !st.empty() && st.top()=='(')
                {
                    st.pop();
                }

                else if(c ==']' && !st.empty() && st.top()=='[')
                {
                    st.pop();
                }

                else if(c =='}' && !st.empty() && st.top()=='{')
                {
                    st.pop();
                }

                else
                {
                    return false;
                }
            }
        }

        if(!st.empty())
        {
            return false;
        }

        return true;

    }
};
