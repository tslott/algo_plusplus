#include <iostream>
#include "linked_list.h"
#include "linked_list.cpp"
#include "lru_cache.h"
#include "lru_cache.cpp"

int main()
{
    // linked_list<string,int> my_list;

    // my_list.add_node_to_back("", 2);
    // my_list.add_node_to_back("", 3);
    // my_list.add_node_to_back("", 20);
    // my_list.add_node_to_front("", 10);
    // my_list.add_node_to_back("", 2);
    // my_list.remove_back_node();
    // my_list.add_node_to_back("", 3);

    // std::cout << "Printing linked list...\n";
    // my_list.print();

    lru_cache<string,int> my_cache(4);
    my_cache.set("fisk", 2);
    my_cache.print();
    std::cout << my_cache.get("fisk") << std::endl;
    my_cache.set("fisk", 7);
    my_cache.print();
    my_cache.set("what", 24);
    my_cache.print();
    my_cache.set("morten", 34);
    my_cache.print();
    my_cache.set("what2", 25);
    my_cache.print();
    my_cache.set("what3", 26);
    my_cache.print();
    my_cache.set("what8", 60);
    my_cache.print();
    std::cout << my_cache.get("what2") << std::endl;
    std::cout << my_cache.get("fisk") << std::endl;
    my_cache.set("what4", 27);
    my_cache.print();
    my_cache.set("what7", 50);
    my_cache.print();
    my_cache.set("what3", 28);
    my_cache.print();
    std::cout << my_cache.get("what8") << std::endl;
    std::cout << my_cache.get("what2") << std::endl;
    my_cache.set("what9", 527);
    my_cache.print();

    return 0;
}
