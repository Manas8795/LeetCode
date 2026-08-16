class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s)
        {
            freq[c]++;
        }
        vector<pair<char,int>> x(freq.begin(),freq.end());
        vector<pair<int,char>> fin;
        for(int i = 0;i<x.size();i++)
        {
            fin.push_back({x[i].second,x[i].first});
        }
        sort(fin.begin(),fin.end());     
        string finn = "";
        for(int i = fin.size()-1;i>-1;i--)
        {
            for(int j = 0;j<fin[i].first;j++)
            {
                finn += fin[i].second;
            }
        }
        return finn;
    }
};