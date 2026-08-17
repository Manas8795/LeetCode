class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int sum = 0;
        for(int i = 0;i<s.size()-1;i++)
        {
            if(m[s[i+1]]>m[s[i]])
            {
                sum -= m[s[i]];
            }
            else
            {
                sum += m[s[i]];
            }
        }
        sum += m[s[s.size()-1]];
        return sum;
    }
};