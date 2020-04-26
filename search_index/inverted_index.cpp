#include "inverted_index.h"

inverted_index::inverted_index(const string &documents_folder){
    // Build index from all documents
    // Use multithreading

    // Loop files in directory of documents
    for(auto& p: std::filesystem::directory_iterator(documents_folder))
        insert_document(p.path().string());
}

inverted_index::~inverted_index(){}

void inverted_index::insert_document(const string &file_name)
{
    // Extract document id from file name
    string doc_id = file_name.substr(0, file_name.size()-4);  // Remove ".txt"
    doc_id = doc_id.substr(9, doc_id.size());  // Remove "txt_data/"

    // Open txt file and stream words in document one by one, document is split on whitespace.
    std::ifstream file;
    file.open(file_name);
    string word;
    while (file >> word)
    {
        clean_word(word);

        // Convert string to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Insert word into inverted index
        index[word][doc_id].push_back(0);
    }
}

void inverted_index::clean_word(string &word)
{
    // Clean word for all non-alpha characters
    word.erase(
        std::remove_if(
            word.begin(),
            word.end(),
            [](unsigned char c) { return !std::isalpha(c); }
        ),
        word.end()
    );
}

void inverted_index::search(const string &search_word)
{
    if (index.find(search_word) != index.end())
    {
        // Extract inner map from index
        map<string, vector<int> > doc_ids = index.find(search_word)->second;

        // Print keys/doc_ids from inner map
        for (map<string, vector<int> >::iterator it = doc_ids.begin(); it != doc_ids.end(); ++it)
        {
            cout << it->first << "\n";
        }
    }
}

void inverted_index::print()
{
    for (const auto &[word, doc_map] : index)
    {
        cout << word << "\n";
        for (const auto &[doc_id, v] : doc_map)
            cout << "\t" << doc_id << "\n";
        cout << "\n";
    }
}
