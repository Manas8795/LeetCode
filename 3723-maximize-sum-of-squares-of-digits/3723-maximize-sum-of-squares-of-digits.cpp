class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";
        if(sum > num * 9) return "";
        while(sum>9)
        {
            if(result.length() == num) break;
            result+=char(57);
            sum -= 9;
        }
        if(result.length() == num && sum>0) return "";
        cout<<sum<<endl;
        result+=char(48+sum);
        while(result.length()<num)
        {
            result +='0';
        }
        cout<<int('0');
        return result;
    }
};