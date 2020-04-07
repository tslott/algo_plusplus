#ifndef LRU_CACHE_GUARD
#define LRU_CACHE_GUARD
#include <string>
#include <unordered_map>
#include "linked_list.h"

using std::string;
using std::unordered_map;

class lru_cache
{
private:
    int size, cache_size;
    linked_list cache_container;
    unordered_map<string, node*> key_mapping;
public:
    lru_cache(int n);
    ~lru_cache();
    void set(string key, int value);
    int get(string key);
};

#endif
