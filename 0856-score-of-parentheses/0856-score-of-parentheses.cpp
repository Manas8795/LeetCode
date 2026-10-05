class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        unordered_map<int,int> freq;
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(') 
            {
                count++;
                freq[i] = count;
            }
            if(s[i] == ')') 
            {
                count--;
                freq[i] = -1;
            }
            
        }
        vector<int> a;
        for(int i = 0;i<freq.size();i++)
        {
            if(freq[i]!=-1) a.push_back(freq[i]);
            // cout<<freq[i]<<" ";
        }
        // for(int i : a)
        // {
        //     cout<<i<<" ";
        // }
        int sum = 0;
        for(int i = 0;i<a.size()-1;i++)
        {
            if(a[i+1]<=a[i])
            {
                sum += pow(2,(a[i]-1));
            }
        }
        sum +=pow(2,(a[a.size()-1]-1));
        return sum;
    }
};