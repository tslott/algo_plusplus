#ifndef IVERTED_INDEX_GUARD
#define IVERTED_INDEX_GUARD
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>

using std::string;
using std::map;

class inverted_index
{
private:
    map<string, map<string, std::vector<int> > > index;
public:
    inverted_index(string documents_folder);
    ~inverted_index();
    void insert_document(string file_name);
    void search(string search_word);
    void print();
};

#endif
