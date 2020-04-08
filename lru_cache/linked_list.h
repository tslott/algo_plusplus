#ifndef LINKED_LIST_GUARD
#define LINKED_LIST_GUARD
#include <string>

using std::string;

struct node
{
    string key;
    int value;
    node *next;
    node *prev;
};

class linked_list
{
private:
    int size;
    node *head, *tail;
public:
    linked_list();
    ~linked_list();
    void add_node_to_back(string key, int value);
    node* add_node_to_front(string key, int value);
    void remove_back_node();
    void move_node_to_front(node *n);
    string get_tail_key();
    void print();
};

#endif
