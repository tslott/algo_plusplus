#ifndef IVERTED_INDEX_GUARD
#define IVERTED_INDEX_GUARD
#include <iostream>
#include <string>
#include <string_view>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <thread>

using std::string;
using std::map;
using std::cout;
using std::vector;
using std::thread;

class inverted_index
{
private:
    map<string, map<string, vector<int> > > index;
    int doc_count;
    void clean_word(string &word);
public:
    inverted_index();
    ~inverted_index();
    void insert_document(const string &file_name);
    void insert_multiple_documents(const string &documents_folder);
    map<string, vector<int> >* search(const string &search_word);
    void search_print(const string &search_word);
    void print();
    int get_word_count();
    int get_doc_count();
};

#endif
