class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string fin="";
        int count = 0;
        for(char c:s)
        {
            if(c == '(') count++;
            if(c == ')')
            {
                if(count>1) {fin+=c; cout<<c;}
                count--;
            } 
            if(count>1 && c == '(') {
                cout<<c;
                fin+=c;
            }
            cout<<count<<" ";
        }
        return fin;
    }
};