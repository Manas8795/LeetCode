class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 1;
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, start, max_len);
            expand(s, i, i + 1, start, max_len);
        }
        return s.substr(start, max_len);
    }

private:
    void expand(string& s, int left, int right, int& start, int& max_len) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        int current_len = right - left - 1;
        if (current_len > max_len) {
            max_len = current_len;
            start = left + 1;
        }
    }
};
