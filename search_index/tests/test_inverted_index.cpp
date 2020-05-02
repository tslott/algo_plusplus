#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "inverted_index.h"

using std::string;
using std::vector;

TEST(ConstructInvertedIndexTest, IsConstructibleFromSingleFile) {
  inverted_index search_index;
  EXPECT_EQ(search_index.get_word_count(), 0);

  search_index.insert_document("test_data/sample_1.txt");
  EXPECT_EQ(search_index.get_word_count(), 13);
}

TEST(ConstructInvertedIndexTest, IsConstructibleFromFolderDirectory) {
  inverted_index search_index;
  EXPECT_EQ(search_index.get_word_count(), 0);

  search_index.insert_multiple_documents("test_data");
  EXPECT_TRUE(search_index.get_word_count() > 0);
}

TEST(ConstructInvertedIndexTest, ContainsAllDocuments) {
  inverted_index search_index;
  EXPECT_EQ(search_index.get_doc_count(), 0);

  search_index.insert_multiple_documents("test_data");
  EXPECT_EQ(search_index.get_doc_count(), 2);
}
