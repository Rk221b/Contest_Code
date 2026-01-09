#include <bits/stdc++.h>
using namespace std;

class EvictionPolicy {
public:
    // Notify policy that a key was accessed
    virtual void keyAccessed(int key) = 0;

    // Decide which key to evict
    virtual int evictKey() = 0;

    // Virtual destructor for polymorphism
    virtual ~EvictionPolicy() {}
};

class LRUEvictionPolicy : public EvictionPolicy {
private:
    // Front = most recently used
    list<int> order;

    // Key -> iterator in list
    unordered_map<int, list<int>::iterator> pos;

public:
    void keyAccessed(int key) override {
        // Remove old position if key already exists
        if (pos.count(key)) {
            order.erase(pos[key]);
        }

        // Insert at front
        order.push_front(key);
        pos[key] = order.begin();
    }

    int evictKey() override {
        // Least recently used key
        int key = order.back();
        order.pop_back();
        pos.erase(key);
        return key;
    }
};

class Cache {
private:
    int capacity;

    // Actual key-value storage
    unordered_map<int, string> data;

    // Eviction strategy
    unique_ptr<EvictionPolicy> policy;

public:
    Cache(int cap, unique_ptr<EvictionPolicy> p)
        : capacity(cap), policy(move(p)) {}

    bool get(int key, string& value) {
        if (!data.count(key))
            return false;

        value = data[key];

        // Inform eviction policy
        policy->keyAccessed(key);
        return true;
    }

    void put(int key, const string& value) {
        // Evict only if new key and capacity full
        if (data.size() == capacity && !data.count(key)) {
            int evict = policy->evictKey();
            data.erase(evict);
        }

        data[key] = value;

        // Inform eviction policy
        policy->keyAccessed(key);
    }

    void display() const {
        cout << "Cache contents: ";
        for (auto& [k, v] : data) {
            cout << "(" << k << "," << v << ") ";
        }
        cout << endl;
    }
};


int main() {
    // Choose eviction policy at runtime
    unique_ptr<EvictionPolicy> policy =
        make_unique<LRUEvictionPolicy>();

    Cache cache(2, move(policy));

    cache.put(1, "A");
    cache.put(2, "B");

    string value;
    cache.get(1, value);    // Access key 1

    cache.put(3, "C");      // Evicts key 2 (LRU)

    cache.display();        // (1,A) (3,C)

    return 0;
}
