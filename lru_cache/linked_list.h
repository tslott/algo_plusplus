#ifndef LINKED_LIST_GUARD
#define LINKED_LIST_GUARD
#include <string>

using std::string;

template <class K, class V>
struct node
{
    K key;
    V value;
    node *next;
    node *prev;
};

template <class K, class V>
class linked_list
{
private:
    int size;
    node<K,V> *head, *tail;
public:
    linked_list();
    ~linked_list();
    void add_node_to_back(K key, V value);
    node<K,V>* add_node_to_front(K key, V value);
    void remove_back_node();
    void move_node_to_front(node<K,V> *n);
    K get_tail_key();
    void print();
};

#endif
