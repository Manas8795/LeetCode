class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(c == ')')
            {
                string temp = "";
                while(!st.empty() && st.top()!='(')
                {
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                for(char x : temp)
                {
                    st.push(x);
                }
            }
            else
            {
                st.push(c);
            }
        }
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};