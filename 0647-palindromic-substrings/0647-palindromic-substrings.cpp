class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            
            count += expand(i, i, s);
            count += expand(i, i + 1, s);
        }

        return count;
    }

    int expand(int l, int r, const string& s) {
        int count = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;

            l--;
            r++;
        }

        return count;
    }
};