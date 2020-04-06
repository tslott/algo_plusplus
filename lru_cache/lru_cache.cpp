#include "lru_cache.hpp"

lru_cache::lru_cache(int n)
{
    size = 0;
    cache_size = n;
}

lru_cache::~lru_cache(){}

void lru_cache::set(string key, int value)
{
    if (size < cache_size)
    {
        key_mapping.at(key);
        cache_container.add_node_to_front(value);

        size++;
    }
    else
    {
        /* code */
    }
}

// lru_cache::get()

// https://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/
