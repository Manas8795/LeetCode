class Solution {
public:
    bool isPalindrome(string s)
    {
        for(int i = 0;i<(s.size()+1)/2;i++)
        {
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    void x(string s,int index,vector<string>& l,vector<vector<string>>& ans)
    {   
        if(index == s.size()) 
        {
            ans.push_back(l);
            return;
        }
        for(int i = index;i<s.size();i++)
        {
            if(isPalindrome(s.substr(index,i+1-index)))
            {
                l.push_back(s.substr(index,i-index+1));
                x(s,i+1,l,ans);
                l.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string st="";
        vector<string> l;
        x(s,0,l,ans);
        return ans;
    }
};