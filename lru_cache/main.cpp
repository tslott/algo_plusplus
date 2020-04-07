#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list my_list;

    my_list.add_node_to_back(2);
    my_list.add_node_to_back(3);
    my_list.add_node_to_back(20);
    my_list.add_node_to_front(10);
    my_list.add_node_to_back(2);

    std::cout << "Printing linked list...\n";

    my_list.print();

    return 0;
}
