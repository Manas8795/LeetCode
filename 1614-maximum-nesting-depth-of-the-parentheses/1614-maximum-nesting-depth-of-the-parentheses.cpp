class Solution {
public:
    int maxDepth(string s) {
        int countmax = 0;
        int count = 0;
        for(char c : s)
        {
            if(c == '(') count++;
            if(c == ')') count--;
            countmax = max(countmax,count);
        }
        return countmax;
    }
};