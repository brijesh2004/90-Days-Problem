// https://leetcode.com/problems/lru-cache/description/



class LRUCache {
public:
    int capacity;
    list<pair<int, int>> items; // Stores (key, value) pairs
    unordered_map<int, list<pair<int, int>>::iterator> cache; // Maps keys to iterators in 'items'

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        // Move the accessed item to the back of the list (mark as most recently used)
        items.splice(items.end(), items, cache[key]);
        return cache[key]->second; // Return the value
    }

    void put(int key, int value) {
        // If the key exists, update its value and move it to the back of the list
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            items.splice(items.end(), items, cache[key]);
            return;
        }
        // If reaching capacity, remove the LRU item from the front of the list and the cache
        if (items.size() == capacity) {
            cache.erase(items.front().first);
            items.pop_front();
        }
        // Insert the new item as the most recently used
        items.push_back({key, value});
        cache[key] = --items.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */