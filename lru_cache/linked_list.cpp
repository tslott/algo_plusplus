#include <iostream>
#include "linked_list.h"

linked_list::linked_list()
{
    size = 0;
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

    size++;
}

node* linked_list::add_node_to_front(int value)
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

    size++;

    return new_node;
}

void linked_list::remove_back_node()
{
    if (size == 0) return;
    if (size == 1)
    {
        node *n = head;
        head = NULL;
        tail = NULL;
        delete n;

        size--;
    }
    else
    {
        node *n = tail;
        tail = (*n).prev;
        (*tail).next = NULL;
        delete n;

        size--;
    }
}

void linked_list::move_node_to_front(node *n)
{
    // Remove node from place in linked list and connect adjacent nodes
    node *prev = (*n).prev;
    node *next = (*n).next;
    (*prev).next = next;
    (*next).prev = prev;

    // Set n as new head
    node *head_next = (*head).next;
    (*n).prev = NULL;
    (*n).next = head_next;
    head = n;
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
