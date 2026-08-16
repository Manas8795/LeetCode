class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> p;
        unordered_map<char,char> q;
        for(int i = 0;i<s.size();i++)
        {
            if(p.count(s[i]) && p[s[i]] != t[i]) return false;
            if(q.count(t[i]) && q[t[i]] != s[i]) return false;
            p[s[i]] = t[i];
            q[t[i]] = s[i];
        }
        return true;
    }
};