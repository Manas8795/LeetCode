class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = strs[0].size();
        if(strs.size() == 1) return strs[0];
        for(string str : strs)
        {
            mini = min(mini,(int)str.size());
        } 
        string s="";
        int i = 0;
        while(i<mini)
        {
            int count = 0;
            for(int j = 0;j<strs.size()-1;j++)
            {
                if(strs[j][i] == strs[j+1][i]) count++;
            }
            if(count==strs.size()-1)
            {
                s+=strs[0][i++];
            }
            else
            {
                break;
            }
        }
        return s;
    }
};