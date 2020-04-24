#ifndef IVERTED_INDEX_GUARD
#define IVERTED_INDEX_GUARD
#include <string>
#include <map>

using std::string;
using std::map;

class inverted_index
{
private:
    map<string,map<string,int> > index;
public:
    inverted_index(string documents_folder);
    ~inverted_index();
    void insert_document(string file_name);
    void search(string search_word);
};

#endif
