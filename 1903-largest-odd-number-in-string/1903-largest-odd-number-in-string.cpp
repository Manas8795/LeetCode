class Solution {
public:
    string largestOddNumber(string num) {
        // int n = stoi(num);
        int x = -1;
        for(int i = num.size()-1;i>=0;i--)
        {
            if(((int)(num[i]) - '0')%2!=0)
            {
                x = i;
                break;
            }
        }
        string st = "";
        for(int i = 0;i<=x;i++)
        {
            st += num[i];
        }
        return st;
    }
};