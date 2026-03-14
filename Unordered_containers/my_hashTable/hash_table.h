#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

template <typename K, typename V>
class my_hashTable {
private:
    struct Entry {
        K key;
        V value;
        Entry(const K& k, const V& v) : key(k), value(v) {}
    };

    std::vector<std::list<Entry>> buckets;
    size_t count;
    size_t bucket_count;
    float max_load_factor;

    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % bucket_count;
    }

    void rehash(size_t new_bucket_count) {
        std::vector<std::list<Entry>> new_buckets(new_bucket_count);
        for (auto& bucket : buckets) {
            for (auto& entry : bucket) {
                size_t idx = std::hash<K>{}(entry.key) % new_bucket_count;
                new_buckets[idx].emplace_back(entry.key, entry.value);
            }
        }
        buckets = std::move(new_buckets);
        bucket_count = new_bucket_count;
    }

public:
    explicit my_hashTable(size_t initial_buckets = 16, float load_factor = 0.75f)
        : buckets(initial_buckets), count(0),
          bucket_count(initial_buckets), max_load_factor(load_factor) {}

    // Insert or update
    void insert(const K& key, const V& value) {
        if (load_factor() >= max_load_factor)
            rehash(bucket_count * 2);

        size_t idx = hash(key);
        for (auto& entry : buckets[idx]) {
            if (entry.key == key) {
                entry.value = value;  // update
                return;
            }
        }
        buckets[idx].emplace_back(key, value);
        ++count;
    }

    // Access by key (throws if missing)
    V& at(const K& key) {
        size_t idx = hash(key);
        for (auto& entry : buckets[idx])
            if (entry.key == key) return entry.value;
        throw std::out_of_range("Key not found");
    }

    const V& at(const K& key) const {
        size_t idx = hash(key);
        for (const auto& entry : buckets[idx])
            if (entry.key == key) return entry.value;
        throw std::out_of_range("Key not found");
    }

    // operator[] — inserts default if missing
    V& operator[](const K& key) {
        if (load_factor() >= max_load_factor)
            rehash(bucket_count * 2);

        size_t idx = hash(key);
        for (auto& entry : buckets[idx])
            if (entry.key == key) return entry.value;

        buckets[idx].emplace_back(key, V{});
        ++count;
        return buckets[idx].back().value;
    }

    // Remove a key
    bool erase(const K& key) {
        size_t idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --count;
                return true;
            }
        }
        return false;
    }

    bool contains(const K& key) const {
        size_t idx = hash(key);
        for (const auto& entry : buckets[idx])
            if (entry.key == key) return true;
        return false;
    }

    size_t size()        const { return count; }
    bool   empty()       const { return count == 0; }
    float  load_factor() const { return static_cast<float>(count) / bucket_count; }

    void clear() {
        for (auto& bucket : buckets) bucket.clear();
        count = 0;
    }

    void print() const {
        for (size_t i = 0; i < bucket_count; ++i) {
            if (buckets[i].empty()) continue;
            std::cout << "[" << i << "]: ";
            for (const auto& entry : buckets[i])
                std::cout << "{" << entry.key << " -> " << entry.value << "} ";
            std::cout << "\n";
        }
    }
};



#endif //HASH_TABLE_H
