#ifndef LRU_CACHE_GUARD
#define LRU_CACHE_GUARD
#include <string>
#include <unordered_map>
#include "linked_list.hpp"

using std::string;

class lru_cache
{
private:
    int size, cache_size;
    linked_list cache_container;
    std::unordered_map<string, node*> key_mapping;
public:
    lru_cache(int n);
    ~lru_cache();
    void lru_cache::set(std::string key, int value);
};

#endif
