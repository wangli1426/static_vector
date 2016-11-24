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

TEST(STATIC_UNORDERED_MAP, REMOVAL) {
  static_unordered_map<int, int, 10> m;
  m.insert(100, 1);
  m.remove(100);
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.contains(100), false);
}

class A {
  public:
  int a;
  A(int _a): a(_a) {};
  A(): a(0) {};
  bool operator== (const A& a) const {
    return a.a == this->a;
  }
};  
template<>
unsigned long h<A>(A t) {
  return 0;
}

TEST(STATIC_UNORDERED_MAP, CUSTOM_DATATYPE) {
  static_unordered_map<A, A, 10> m;
  A a;
  a.a = 100;
  m.insert(a, a);
  EXPECT_EQ(m.size(), 1);
  EXPECT_EQ(m[a].a, 100);
}

TEST(STATIC_UNORDERED_MAP, DELETE_OVERFLOW_MID) {
  static_unordered_map<A, int, 10> m;
  m.insert(A(0), 0);
  m.insert(A(1), 1);
  m.insert(A(2), 2);
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m[A(0)], 0);
  EXPECT_EQ(m[A(1)], 1);
  m.remove(A(1));
  EXPECT_EQ(m.contains(A(1)), false);
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m[A(0)], 0);
  EXPECT_EQ(m[A(2)], 2);
}

