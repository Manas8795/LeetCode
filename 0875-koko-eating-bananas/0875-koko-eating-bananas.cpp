class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for(int n:piles)
        {
            if(n>max)
            {
                max = n;
            }
        }
        // cout<<max;
        int low = 1;
        int high = max;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            cout<<mid<<",";
            long long hours = 0;
            for(int n:piles)
            {
                hours += (n+mid-1)/mid;
            }
            cout<<hours<<" ";
            if(hours>h) low = mid+1;
            else high = mid-1;
        }
        return low;
        

    }
};