class StockSpanner {
public:
    // stack<int> s;
    vector<int> l;
    vector<int> ans;
    int pos;
    StockSpanner() {
        pos = 0;
        ans.push_back(NULL);
    }
    int next(int price) {
        l.push_back(price);stack<int> s;
        int count = 0;
        for(int i = l.size()-1;i>=0;i--)
        {
            if(l[i]<=price) count++;
            else break;
        }
        ans.push_back(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */