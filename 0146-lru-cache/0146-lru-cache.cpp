class LRUCache {
public:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> um;
    list<pair<int,int>> dll;
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
        if(um.find(key)==um.end()) return -1;
        auto it=um[key];
        int val=it->second;
        dll.erase(it);
        dll.push_front({key,val});
        um[key]=dll.begin();
        return val;
    }
    void put(int key, int value) {
        if(um.find(key)!=um.end()) dll.erase(um[key]);
        else if (dll.size()==cap) {
            auto last=dll.back();
            um.erase(last.first);
            dll.pop_back();
        }
        dll.push_front({key,value});
        um[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */