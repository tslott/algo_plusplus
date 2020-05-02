#include "gtest/gtest.h"
#include "inverted_index.h"

// TEST(ConstructInvertedIndexTest, IsConstructibleFromFolderDirectory) {
//   inverted_index search_index;
//   EXPECT_EQ(search_index.get_word_count(), 0);

//   search_index.insert_document("test_data/");
//   EXPECT_EQ(search_index.get_word_count(), 5);
// }

TEST(ConstructInvertedIndexTest, IsConstructibleFromFolderDirectory) {
  inverted_index search_index;
  search_index.insert_multiple_documents("test_data");

  EXPECT_TRUE(search_index.get_word_count() > 0);
}
