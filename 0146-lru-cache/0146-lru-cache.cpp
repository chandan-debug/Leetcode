
class LRUCache {
    // Data members
    map<int, int> m;               // Map to store key-value pairs
    map<int, list<int>::iterator> address; // Map to store iterators to the linked list nodes
    list<int> l;                   // Doubly linked list to maintain the order of keys
    int cap;                       // Maximum capacity of the cache
    int size;                      // Current number of elements in the cache

public:
    // Constructor to initialize the cache
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    // Method to get the value for a given key
    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        // Move the key to the front of the list (most recently used)
        list<int>::iterator it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();

        return m[key];
    }

    // Method to put a key-value pair into the cache
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Key already exists, remove old entry
            l.erase(address[key]);
            address.erase(key);
            m.erase(key);
            size--;
        }
        if (size == cap) {
            // Cache is full, remove the least recently used element
            int k = l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        // Add the new key-value pair to the cache
        size++;
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
    }

    // Public method to get the value for a given key
    int getValue(int key) {
        return get(key);
    }
};