class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> x;
        for(int i = 0;i<arr.size();i++)
        {
            x.push_back(arr[i]-(i+1));
        }
        int l = 0;
        int h = arr.size()-1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(x[mid]<k) l = mid+1;
            else h = mid-1;
        }
        cout<<l;
        return k+h+1;
    }
};