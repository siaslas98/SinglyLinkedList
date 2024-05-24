#include <gtest/gtest.h>
#include "../SLinkedList.h"

// Test fixture for SLinkedList
class SLinkedListTest : public ::testing::Test {
protected:
    SLinkedList<int> list;

    void SetUp() override {
        list.insertAtHead(1);
        list.insertAtHead(2);
        list.insertAtHead(3);
    }
};

// Test case for insertAtHead
TEST_F(SLinkedListTest, InsertAtHead) {
list.insertAtHead(4);
}

// Test case for insertAtTail
TEST_F(SLinkedListTest, InsertAtTail) {
list.insertAtTail(0);
}

// Test case for remove
TEST_F(SLinkedListTest, Remove) {
bool removed = list.remove(2);
EXPECT_TRUE(removed);
}

// Test case for remove non-existent element
TEST_F(SLinkedListTest, RemoveNonExistent) {
bool removed = list.remove(99);
EXPECT_FALSE(removed);
}

// Test case for getSize
TEST_F(SLinkedListTest, GetSize) {
}

// Test case for printList
TEST_F(SLinkedListTest, PrintList) {
// You can redirect the output to a stringstream and check its content
std::ostringstream oss;
std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());
list.printList();
std::cout.rdbuf(oldCoutBuffer);
EXPECT_EQ(oss.str(), "3 -> 2 -> 1 -> nullptr\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
