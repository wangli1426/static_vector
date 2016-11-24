#ifndef __STATIC_UNORDERED_MAP__
#define __STATIC_UNORDERED_MAP__
#include <assert.h>

template<class K>
unsigned long h(K key) {
  return (unsigned long) key;
}

template<class K, class V, size_t L>
class static_unordered_map {
  class entry {
    public:
      entry(K k, V v): key(k), value(v) {};
      entry():valid(false) {};

    K key;
    V value;
    bool valid;
  };
  
  public:
    static_unordered_map():size_(0) {  
    }
    void insert(K key, V value) {
      size_t index1 = hash1(key);
      size_t attempts = 0;
      while (slots_[index1].valid && slots_[index1].key != key) {
        index1 = (index1 + 1) % L;
        if(attempts++ == L)
          assert(false); // A larger L is required.
      }
      
      if (slots_[index1].key != key) 
        size_++;
      slots_[index1].key = key;
      slots_[index1].value = value;
      slots_[index1].valid = true;
    }

    bool contains(K key) {
      size_t index1 = hash1(key);
      while(slots_[index1].valid) {
        if(slots_[index1].key == key) 
          return true;
        index1 = (index1 + 1) % L;
      }
      return false;
    }
    
    V& operator[] (const K& key) {
      size_t index1 = hash1(key);
      while(slots_[index1].valid) {
        if(slots_[index1].key == key)
          return slots_[index1].value;
        index1 = (index1 + 1) % L;
      }
      assert(false); // key is not in the map.
      // unreachable code
      return slots_[0].value;      
    }     
  
    const V& operator[] (const K& key) const {
      size_t index1 = hash1(key);
      while(slots_[index1].valid) {
        if(slots_[index1].key == key)
          return slots_[index1].value;
        index1 = (index1 + 1) % L;
      }
      assert(false); // key is not in the map.
      // unreachable code.
      return slots_[0].value;
    }

    size_t size() const {
      return size_;
    } 
  private:
    size_t hash1(K key) {
      return (h<K>(key) + 16127) * 16273 % L;
    }

    size_t hash2(K key) {
      return (h<K>(key) + 15671) * 15671 % L;
    }  
  
  private:
    entry slots_[L];
    size_t size_;
};

#endif
