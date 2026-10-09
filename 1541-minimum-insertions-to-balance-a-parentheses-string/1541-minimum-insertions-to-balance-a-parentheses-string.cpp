class Solution {
public:
    int minInsertions(string s) {
        string test = "";
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==')' && i == s.size()-1) 
            {
                count++;
                test+=')';
                break;
            }
            else if(s[i]==')' && s[i+1] ==')')
            {
                test+=s[i];
                i++;
            }
            else if(s[i]==')' && s[i+1]!=')') 
            {
                count++;
                test+=')';
            }
            else
            {
                test+=s[i];
            }
        }
        cout<<test<<endl;
        stack<char> st;
        for(int i = 0;i<test.size();i++)
        {
            if(test[i]=='(') 
            {
                st.push(test[i]);
                cout<<"a";
            }
            if(test[i]==')') 
            {
                if(!st.empty() && st.top() =='(')
                {
                    st.pop();
                    cout<<"b";
                }
                else
                {
                    st.push(test[i]);
                    cout<<"c";
                }
            }
        }
        while(!st.empty())
        {
            char x = st.top();
            if(x == '(') count+=2;
            else count++;
            st.pop();
            // cout<<x<<" ";
        }
        // for(int i = 0;i<test.size();i++)
        // {
        //     if(test[i] == '(')fcount++;
        //     if(test[i]==')')bcount++;
        //     if(bcount>fcount) count++;
        // }
        return count;
    }
};