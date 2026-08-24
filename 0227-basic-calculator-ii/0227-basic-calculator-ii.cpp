class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num=0;
        char op='+';
        for(int i=0;i<s.length();i++)
        {
    
          

            if(s[i]>='0' && s[i]<='9')
            {
                num=num*10+(s[i]-'0');
            }
             if((s[i]!=' ' && !(s[i]>='0' && s[i]<='9')) || i==s.length()-1)
            {
                if(op=='+')
                st.push(num);
                else if(op=='-')
                st.push(-num);
                else if(op=='*')
                {
                    int n=st.top();
                    st.pop();
                    st.push(n*num);
                }
                else
                {
                    int n=st.top();
                    st.pop();
                    st.push(n/num);
                }
                num=0;
                op=s[i];
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};