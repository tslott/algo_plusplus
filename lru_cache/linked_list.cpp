#include <iostream>
#include "linked_list.h"

template <class K, class V>
linked_list<K,V>::linked_list()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

template <class K, class V>
linked_list<K,V>::~linked_list(){}

template <class K, class V>
void linked_list<K,V>::add_node_to_back(K key, V value)
{
    node<K,V> *new_node = new node<K,V>;
    (*new_node).key = key;
    (*new_node).value = value;
    (*new_node).next = NULL;
    (*new_node).prev = NULL;

    if (head == NULL)
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
    (*new_node).next = NULL;
    (*new_node).prev = NULL;

    if (head == NULL)
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
        node<K,V> *n = head;
        head = NULL;
        tail = NULL;
        delete n;

        size--;
    }
    else
    {
        node<K,V> *n = tail;
        tail = (*n).prev;
        (*tail).next = NULL;
        delete n;

        size--;
    }
}

template <class K, class V>
void linked_list<K,V>::move_node_to_front(node<K,V> *n)
{
    if (head == tail || n == head) return;

    if (n == tail)
    {
        // Remove n from tail and set new tail
        node<K,V> *new_tail = (*tail).prev;
        (*new_tail).next = (*tail).next;
        tail = new_tail;
    }
    else
    {
        // Remove n from place in linked list and connect adjacent nodes
        node<K,V> *prev = (*n).prev;
        node<K,V> *next = (*n).next;
        (*prev).next = next;
        (*next).prev = prev;
    }

    // Set n as new head
    node<K,V> *current_head = head;
    (*n).prev = NULL;
    (*n).next = current_head;
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
    while (iter != NULL)
    {
        std::cout << (*iter).value << " ";
        iter = (*iter).next;
    }
    std::cout << std::endl;
}
