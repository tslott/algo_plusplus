#include <iostream>
#include "linked_list.h"
#include "lru_cache.h"

int main()
{
    linked_list my_list;

    my_list.add_node_to_back(2);
    my_list.add_node_to_back(3);
    my_list.add_node_to_back(20);
    my_list.add_node_to_front(10);
    my_list.add_node_to_back(2);
    my_list.remove_back_node();
    my_list.add_node_to_back(3);

    std::cout << "Printing linked list...\n";
    my_list.print();

    lru_cache my_cache(4);
    my_cache.set("fisk", 2);
    std::cout << my_cache.get("fisk") << std::endl;
    std::cout << my_cache.get("morten") << std::endl;

    return 0;
}
