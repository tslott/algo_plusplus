#ifndef IVERTED_INDEX_GUARD
#define IVERTED_INDEX_GUARD
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <filesystem>

using std::string;
using std::map;
using std::cout;
using std::vector;

class inverted_index
{
private:
    map<string, map<string, vector<int> > > index;
public:
    inverted_index(string documents_folder);
    ~inverted_index();
    void insert_document(string file_name);
    void search(string search_word);
    void print();
};

#endif
