class Solution {
public:
    string reverseWords(string s) {
        vector<string> st;
        string temp = "";
        for(char c:s)
        {   
            if(c==' ')
            {
                if(temp=="") {
                    // cout<<"0 ";
                    continue;
                }
                st.push_back(temp);
                temp ="";
                // cout<<"1 ";
            }
            else
            {
                temp+=c;
                // cout<<"2 ";
            }
        }
        if(temp!="")st.push_back(temp);
        
        // for(int i = 0;i<st.size();i++)
        // {
        //     st[i] = reverse(st[i].begin(),st[i].end());
        // }
        string fin ="";
        for(string t : st)
        {
            cout<<t<<"";
        }
        for(int i = st.size()-1;i>0;i--)
        {
            fin += st[i];
            fin += ' ';
        }
        // cout<<st[0];
        fin+=st[0];
        return fin;

    }
};