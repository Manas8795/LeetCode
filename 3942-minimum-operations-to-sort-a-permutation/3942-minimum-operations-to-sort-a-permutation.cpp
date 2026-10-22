class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == 0){
                zero = i;
                break;
            }
        }
        bool isIncreasingRight = true;
        for (int i = 0; i < n - 1; i++) {
            int curr = (zero + i) % n;
            int next = (zero + i + 1) % n;
            if (nums[curr] > nums[next]) {
                isIncreasingRight = false;
                break;
            }
        }
        bool isIncreasingLeft = true;
        for (int i = 0; i < n - 1; i++) {
            int curr = (zero - i + n) % n;
            int next = (zero - (i + 1) + n) % n;
            if (nums[curr] > nums[next]) {
                isIncreasingLeft = false;
                break;
            }
        }
        if(!isIncreasingLeft && !isIncreasingRight) return -1;
        int r = INT_MAX;
        if(isIncreasingRight)
        {
            r = min(zero,r);
            r = min(r,n-zero+2);
        }
        if(isIncreasingLeft)
        {
            r = min(zero+2,r);
            r = min(n-zero,r);
        }
        return r;

    }
};