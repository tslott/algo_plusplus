#include "inverted_index.h"

inverted_index::inverted_index(string documents_folder){
    // Build index from all documents
    // Use multithreading
    std::cout << documents_folder << "\n";
}

inverted_index::~inverted_index(){}

void inverted_index::insert_document(string file_name)
{
    // Extract document id from file name
    string doc_id = file_name.substr(0, file_name.size()-4);
    doc_id = doc_id.substr(9, doc_id.size());

    // Open txt file and stream words in document one by one, document is split on whitespace.
    std::ifstream file;
    file.open(file_name);
    string word;
    while (file >> word)
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

        // Convert string to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Insert word into inverted index
        index[word][doc_id].push_back(0);
    }
}

void search(string search_word)
{

}

void inverted_index::print()
{
    for (const auto &[word, doc_map] : index)
    {
        std::cout << word << "\n";
        for (const auto &[doc_id, v] : doc_map)
            std::cout << "\t" << doc_id << "\n";
        std::cout << "\n";
    }
}
