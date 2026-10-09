class Solution {
public:
    int minInsertions(string s) {
        int back = 0;
        int front = 0;
        int front2 = 0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                front++;
            }
            else
            {
                if(i<s.size()-1 && s[i+1]==')')
                {
                    i++;
                }
                else
                {
                    back++;
                }
                if(front>0) front--;
                else front2++;
            }
        }
        return back + front*2 + front2;
    }
};