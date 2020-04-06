#include <iostream>
#include "linked_list.hpp"

linked_list::linked_list()
{
    head = NULL;
    tail = NULL;
}
linked_list::~linked_list(){}

void linked_list::add_node_to_back(int value)
{
    node *new_node = new node;
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
}

void linked_list::add_node_to_front(int value)
{
    node *new_node = new node;
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
}

void linked_list::print()
{
    node *iter = head;
    while (iter != NULL)
    {
        std::cout << (*iter).value << " ";
        iter = (*iter).next;
    }
    std::cout << std::endl;
}
