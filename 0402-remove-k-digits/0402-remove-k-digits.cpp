class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        if(k == num.size()) return "0";
        for(char i:num)
        {
            if(s.empty()) s.push(i);
            else
            {
                while(k!=0 && !s.empty() && (int)(s.top())>(int)(i))
                {
                    cout<<s.top()<<" ";
                    s.pop();
                    k--;
                }
                s.push(i);
            }
        }
        while(k!=0 && !s.empty())
        {
            s.pop();
            k--;
        }
        string fin="";
        while(!s.empty())
        {
            fin+=s.top();
            s.pop();
        }
        reverse(fin.begin(),fin.end());
        int x= 0;
        while(fin[x]=='0')
        {
            x++;
        }
        fin = fin.substr(x);
        if(fin =="") return "0";
        return fin;
    }
};