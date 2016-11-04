#include "gtest/gtest.h"
#include "lib/static_vector.h"

TEST(STATIC_VECTOR, INIT) {
  s_vector<int, 10> v;
  EXPECT_EQ(v.size(),0);
}

TEST(STATIC_VECTOR, PUSH_BACK) {
  s_vector<int, 100> v;
  v.push_back(100);
  EXPECT_EQ(v.front(), 100);
}

TEST(STATIC_VECTOR, RANDOM_ACCESS) {
  s_vector<int, 1000> v;
  for(int i = 0; i < 1000; i++) {
    v.push_back(i);
  }
  for(int i = 0; i < 1000; i++ ) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(STATIC_VECTOR, RECURSIVE_DEFINE) {
  s_vector<s_vector<int, 16>, 20> s;
  for(int i = 0; i < 10; i++ ) {
    s_vector<int, 16> tmp_v;
    tmp_v.push_back(i);
    s.push_back(tmp_v);
  }
  EXPECT_EQ(s.size(), 10);
}  

