class LFUCache {
public:
    int cap;
    int minFreq;
    unordered_map<int,pair<int,int>> keyInfo;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator>keyIter;
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }
    int get(int key) {
        if (keyInfo.find(key)==keyInfo.end()) return -1;
        int val=keyInfo[key].first;
        int freq=keyInfo[key].second;
        freqList[freq].erase(keyIter[key]);
        if(freq==minFreq&&freqList[freq].empty()) minFreq++;
        freq++;
        keyInfo[key].second=freq;
        freqList[freq].push_front(key);
        keyIter[key]=freqList[freq].begin();
        return val;
    }
    void put(int key, int value) {
        if(cap==0) return;
        if(keyInfo.find(key)!=keyInfo.end()) {
            keyInfo[key].first=value;
            get(key);
            return;
        }
        if(keyInfo.size()==cap) {
            int evictKey=freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyInfo.erase(evictKey);
            keyIter.erase(evictKey);
        }
        keyInfo[key]={value,1};
        freqList[1].push_front(key);
        keyIter[key]=freqList[1].begin();
        minFreq=1;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */