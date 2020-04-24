#include <iostream>
#include "inverted_index.h"

using std::cout, std::cin;

int main()
{
    string search_word;
    string exit_term = "$";

    do
    {
        cout << "Please enter search word (exit with '" << exit_term << "'): ";
        cin >> search_word;
        cout << search_word << "\n";
    }
    while (search_word != exit_term);

    return 0;
}
