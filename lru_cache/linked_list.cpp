#include <iostream>
#include "linked_list.h"

template <class K, class V>
linked_list<K,V>::linked_list()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class K, class V>
linked_list<K,V>::~linked_list(){}

template <class K, class V>
void linked_list<K,V>::add_node_to_back(K key, V value)
{
    node<K,V> *new_node = new node<K,V>;
    (*new_node).key = key;
    (*new_node).value = value;
    (*new_node).next = nullptr;
    (*new_node).prev = nullptr;

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        (*tail).next = new_node;
        (*new_node).prev = tail;
        tail = new_node;
    }

    size++;
}

template <class K, class V>
node<K,V>* linked_list<K,V>::add_node_to_front(K key, V value)
{
    node<K,V> *new_node = new node<K,V>;
    (*new_node).key = key;
    (*new_node).value = value;
    (*new_node).next = nullptr;
    (*new_node).prev = nullptr;

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        (*head).prev = new_node;
        (*new_node).next = head;
        head = new_node;
    }

    size++;

    return new_node;
}

template <class K, class V>
void linked_list<K,V>::remove_back_node()
{
    if (size == 0) return;
    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        size--;
    }
    else
    {
        node<K,V> *old_tail = tail;
        tail = (*tail).prev;
        (*tail).next = nullptr;
        delete old_tail;

        size--;
    }
}

template <class K, class V>
void linked_list<K,V>::move_node_to_front(node<K,V> *n)
{
    if (n == head) return;

    if (n == tail)
    {
        // Remove n from tail and set new tail
        tail = (*tail).prev;
        (*tail).next = nullptr;
    }
    else
    {
        // Remove n from place in linked list and connect adjacent nodes
        node<K,V> *prev = (*n).prev;
        node<K,V> *next = (*n).next;
        (*prev).next = next;
        (*next).prev = prev;
    }

    // Set n as new heads
    (*n).next = head;
    (*n).prev = nullptr;
    (*head).prev = n;
    head = n;
}

template <class K, class V>
K linked_list<K,V>::get_tail_key()
{
    return (*tail).key;
}

template <class K, class V>
void linked_list<K,V>::print()
{
    node<K,V> *iter = head;
    while (iter != nullptr)
    {
        std::cout << (*iter).key << ":" << (*iter).value << " ";
        iter = (*iter).next;
    }
    std::cout << std::endl;
}
