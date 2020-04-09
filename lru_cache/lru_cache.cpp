#include <iostream>
#include "lru_cache.h"

template <class K, class V>
lru_cache<K,V>::lru_cache(int n)
{
    size = 0;
    cache_size = n;
}

template <class K, class V>
lru_cache<K,V>::~lru_cache(){}

template <class K, class V>
void lru_cache<K,V>::set(K key, V value)
{
    // // Check if value already exists
    if (key_mapping.find(key) == key_mapping.end())  // Value does not exist
    {
        if (size == cache_size)
        {
            // Remove least used node from cache container and key map
            K old_key = cache_container.get_tail_key();
            key_mapping.erase(old_key);
            cache_container.remove_back_node();

            size--;  // Decrease cache size
        }

        node<K,V>* new_item = cache_container.add_node_to_front(key, value);
        key_mapping[key] = new_item;
        size++;  // Increment cache size
    }
    else  // Value already exists
    {
        (*key_mapping[key]).value = value;
        cache_container.move_node_to_front(key_mapping[key]);
    }
}

template <class K, class V>
V lru_cache<K,V>::get(K key)
{
    // Check if value exists
    if (key_mapping.find(key) != key_mapping.end())
    {
        cache_container.move_node_to_front(key_mapping[key]);
        return (*key_mapping[key]).value;
    }

    // Return "default" value if key does not exist
    V obj = V();
    return obj;
}

template <class K, class V>
void lru_cache<K,V>::print()
{
    cache_container.print();
}
