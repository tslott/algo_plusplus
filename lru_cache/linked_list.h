#ifndef LINKED_LIST_GUARD
#define LINKED_LIST_GUARD

struct node
{
    int value;
    node *next;
    node *prev;
};

class linked_list
{
private:
    node *head, *tail;
public:
    linked_list();
    ~linked_list();
    void add_node_to_back(int value);
    void add_node_to_front(int value);
    void print();
};

#endif
