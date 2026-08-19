class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return temp(n);
    }
    vector<string> temp(int n)
    {
        if(n == 0) return {""};
        vector<string> res;
        for(int i = 0;i<n;i++)
        {
            vector<string> inside = temp(n-i-1);
            vector<string> outside = temp(i);
            for(string in :inside)
            {
                for(string out : outside )
                {
                    res.push_back("("+in+")"+out);
                }
            }
        }
        return res;
    }
};