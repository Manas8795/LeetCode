class LFUCache {
public:
    unordered_map<int, pair<int, int>> k;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
    int mini = 1;
    int capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(k.find(key) != k.end()) 
        {
            int a = k[key].second++;
            int b = a + 1;
            
            freq[a].erase(iter[key]);
            
            if(freq[a].empty() && mini == a) mini++;
            
            freq[b].push_front(key);
            iter[key] = freq[b].begin();
            
            return k[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;

        if(k.find(key) != k.end())
        {
            get(key);
            k[key].first = value;
        }
        else
        {
            if(k.size() == capacity)
            {
                int evictKey = freq[mini].back();
                freq[mini].pop_back();
                
                if(freq[mini].empty()) {
                    freq.erase(mini);
                }
                
                k.erase(evictKey);
                iter.erase(evictKey);
            }
            
            k[key].first = value;
            k[key].second = 1;
            
            freq[1].push_front(key);
            iter[key] = freq[1].begin();
            mini = 1;
        }
    }
};