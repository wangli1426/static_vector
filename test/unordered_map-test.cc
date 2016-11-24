#include "gtest/gtest.h"
#include "lib/static_unordered_map.h"

TEST(STATIC_UNORDERED_MAP, CONTAINS) {
  static_unordered_map<int, int, 10> m;
  m.insert(100,1);
  EXPECT_EQ(m.contains(100), true);
}

TEST(STATIC_UNORDERED_MAP, ACCESS) {
  static_unordered_map<int, int, 10> m;
  m.insert(100, 1);
  EXPECT_EQ(m[100], 1);
}

TEST(STATIC_UNORDERED_MAP, MULTIPLEINSERTION) {
  static_unordered_map<int, int, 10> m;
  m.insert(100, 100);
  m.insert(101, 101);
  m.insert(102, 102);
  EXPECT_EQ(m[100], 100);
  EXPECT_EQ(m[101], 101);
  EXPECT_EQ(m[102], 102);
}

TEST(STATIC_UNORDERED_MAP, DUPLICATEDKEYS) {
  static_unordered_map<int, int, 1> m;
  m.insert(1, 100);
  m.insert(1, 102);
  EXPECT_EQ(m[1], 102);
}

TEST(STATIC_UNORDERED_MAP, STAITCREFERENCE) {
  static_unordered_map<int, int, 1> m;
  m.insert(1, 100);
  const int value = m[1];
  EXPECT_EQ(value, 100);
}

TEST(STATIC_UNORDERED_MAP, SIZE) {
  static_unordered_map<int, int, 1> m;
  EXPECT_EQ(m.size(), 0);
  m.insert(1, 100);
  EXPECT_EQ(m.size(), 1);
}  
