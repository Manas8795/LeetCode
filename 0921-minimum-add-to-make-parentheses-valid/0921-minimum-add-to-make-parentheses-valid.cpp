class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int z = 0;
        for(char x : s)
        {
            if(x == '(' ) count++;
            else if(count == 0 && x ==')') z++;
            else count--;
        }
        return abs(count) + abs(z);
    }
};