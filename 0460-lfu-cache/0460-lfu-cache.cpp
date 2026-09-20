class LFUCache {
public:
    unordered_map<int,pair<int,int>> k;
    unordered_map<int,vector<int>> freq;
    int mini = 1;
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(k.find(key)!=k.end()) 
        {
            int a = k[key].second++;
            int b = a + 1;
            
            for(int i = 0;i<freq[a].size();i++)
            {
                if(freq[a][i] == key) freq[a].erase(freq[a].begin() + i);
            }
            if(freq[a].empty() && mini == a) mini++;
            freq[b].push_back(key);
            return k[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(k.find(key)!=k.end())
        {

            get(key);
            k[key].first = value;
        }
        else
        {
            if(k.size() == capacity)
            {
                int a = freq[mini][0];
                freq[mini].erase(freq[mini].begin());
                k.erase(a);

            }
            k[key].first = value;
            k[key].second = 1;
            freq[1].push_back(key);
            mini = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */