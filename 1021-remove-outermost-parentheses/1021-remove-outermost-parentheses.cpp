class Solution {
public:
    string removeOuterParentheses(string s) {
        string fin = "";
        int count = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (count > 0) fin += c;
                count++;
            } else {
                count--;
                if (count > 0) fin += c;
            }
        }
        
        return fin;
    }
};