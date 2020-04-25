#include <iostream>
#include "inverted_index.h"

using std::cout, std::cin;

int main()
{
    // string search_word;
    // string exit_term = "$";

    // do
    // {
    //     cout << "Please enter search word (exit with '" << exit_term << "'): ";
    //     cin >> search_word;
    //     cout << search_word << "\n";
    // }
    // while (search_word != exit_term);

    // file.open("txt_data/fffcd4b4f4e89c84d865aef16b051d162f27d40f.txt");

    inverted_index search_index("txt_data");

    search_index.insert_document("txt_data/fffcd4b4f4e89c84d865aef16b051d162f27d40f.txt");
    search_index.insert_document("txt_data/ffda4b565052650f13871b577db7aef4ecef7821.txt");

    search_index.print();

    return 0;
}
