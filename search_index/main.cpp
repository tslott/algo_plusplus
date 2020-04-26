#include <iostream>
#include "inverted_index.h"

using std::cout, std::cin;

int main()
{
    inverted_index search_index("txt_data");

    string search_word;
    string exit_term = "$";

    do
    {
        cout << "Please enter search word (exit with '" << exit_term << "'): ";
        cin >> search_word;
        search_index.search(search_word);
    }
    while (search_word != exit_term);

    // search_index.print();

    return 0;
}
