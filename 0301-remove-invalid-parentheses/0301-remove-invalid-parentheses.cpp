class Solution {
public:
    void re(int index, const string &s, int l_rem, int r_rem, int open_cnt, string &x, unordered_set<string> &fin) 
    {
        if (index == s.size()) 
        {
            if (l_rem == 0 && r_rem == 0 && open_cnt == 0)
            {
                fin.insert(x);
            }
            return;
        }
        
        if (l_rem < 0 || r_rem < 0 || open_cnt < 0) return;
        
        char c = s[index];
        
        if (c != '(' && c != ')')
        {
            x += c;
            re(index + 1, s, l_rem, r_rem, open_cnt, x, fin);
            x.pop_back();
            return;
        }
        
        if (c == '(' && l_rem > 0) {
            re(index + 1, s, l_rem - 1, r_rem, open_cnt, x, fin);
        }
        if (c == ')' && r_rem > 0) {
            re(index + 1, s, l_rem, r_rem - 1, open_cnt, x, fin);
        }
        
        int next_open = open_cnt + (c == '(' ? 1 : -1);
        x += c;
        re(index + 1, s, l_rem, r_rem, next_open, x, fin);
        x.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int l_rem = 0, r_rem = 0;
        
        for (char c : s) 
        {
            if (c == '(') 
            {
                l_rem++;
            }
            else if (c == ')') 
            {
                if (l_rem > 0) 
                {
                    l_rem--;
                } 
                else 
                {
                    r_rem++;
                }
            }
        }
        
        unordered_set<string> fin;
        string x = "";
        
        re(0, s, l_rem, r_rem, 0, x, fin);
        
        return vector<string>(fin.begin(), fin.end());
    }
};