#ifndef LRU_CACHE_GUARD
#define LRU_CACHE_GUARD
#include <string>
#include <unordered_map>
#include "linked_list.h"

using std::string;
using std::unordered_map;

template <class K, class V>
class lru_cache
{
private:
    int size, cache_size;
    linked_list<K,V> cache_container;
    unordered_map<K, node<K,V>*> key_mapping;
public:
    lru_cache(int n);
    ~lru_cache();
    void set(K key, V value);
    V get(K key);
    void print();
};

#endif
