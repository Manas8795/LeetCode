class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> freq;
        int left = 0;
        int max1 = 0; 
        for(int right = 0;right<s.length();right++)
        {
            freq[s[right]]++;
            while(freq[s[right]]>2)
            {
                freq[s[left]]--;
                left++;
            }
            max1 = max(max1,right-left+1);
        }
        return max1;
    }
};