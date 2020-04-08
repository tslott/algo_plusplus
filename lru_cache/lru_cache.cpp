#include <iostream>
#include "lru_cache.h"

lru_cache::lru_cache(int n)
{
    size = 0;
    cache_size = n;
}

lru_cache::~lru_cache(){}

void lru_cache::set(string key, int value)
{
    // Check if value already exists
    if (key_mapping.find(key) != key_mapping.end())  // Value already exists
    {
        (*key_mapping[key]).value = value;
        cache_container.move_node_to_front(key_mapping[key]);
    }
    else  // Value does not exists
    {
        if (size == cache_size)
        {
            // Remove least used node from cache container and key map
            string old_key = cache_container.get_tail_key();
            key_mapping.erase(old_key);
            cache_container.remove_back_node();
            size--;  // Decrease cache size
        }

        node* new_item = cache_container.add_node_to_front(key, value);
        key_mapping[key] = new_item;
        size++;  // Increment cache size
    }
}

int lru_cache::get(string key)
{
    // Check if value exists
    if (key_mapping.find(key) != key_mapping.end())
    {
        cache_container.move_node_to_front(key_mapping[key]);
        return (*key_mapping[key]).value;
    }

    return -1;
}

void lru_cache::print()
{
    cache_container.print();
}

// https://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/
