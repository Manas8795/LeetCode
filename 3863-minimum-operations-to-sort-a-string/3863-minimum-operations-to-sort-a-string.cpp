class Solution {
public:
    int minOperations(string s) {
       int n = s.size();
       string sorted = s;
       sort(sorted.begin(),sorted.end());
       if(sorted == s ) return 0;
       if(n == 2 && sorted!=s) return -1;
       int mini =0;
       int maxi = 0;
       for(int i = 0;i<n;i++)
       {
            if(s[i]<s[mini]) mini = i;
            if(s[i]>=s[maxi]) maxi = i;
       }
       if(mini == 0 || maxi == n-1) return 1;
       else if(mini == n-1 && maxi == 0)return 3;
       else return 2;
    }
};