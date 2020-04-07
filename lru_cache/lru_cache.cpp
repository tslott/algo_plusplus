#include "lru_cache.h"

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
        // Check if value already exists
        if (key_mapping.find(key) != key_mapping.end())  // Value already exists
        {
            (*key_mapping[key]).value = value;
            cache_container.move_node_to_front(key_mapping[key]);
        }
        else  // Value does not exists
        {
            node* new_item = cache_container.add_node_to_front(value);
            key_mapping[key] = new_item;
        }

        // Increment cache size
        size++;
    }
    else
    {
        // Check if value already exists
        if (key_mapping.find(key) != key_mapping.end())  // Value already exists
        {
            (*key_mapping[key]).value = value;
            cache_container.move_node_to_front(key_mapping[key]);
        }
        else  // Value does not exists
        {
            cache_container.remove_back_node();

            node* new_item = cache_container.add_node_to_front(value);
            key_mapping[key] = new_item;
        }
    }
}

int lru_cache::get(string key)
{
    return -1;
}

// https://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/
