class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        if(n<=999) return 0;
        else
        {
            for(int i = 1000;i<=n;i++)
            {
                count++;
            }
        }
        return count;
        // string s = to_string(n);
        // int l = s.length();
        // int count = 0;
        // x(l,count);
        // return count;
    }
    // void x(int l,int& count)
    // {
    //     if(l<=3) return;
    //     else
    //     {
    //         count++;
    //         x(l-3,count);
    //     }
    // }
};