// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template <typename T>
class TPQueue {
private:
   T *arr;
   int size;
   int begin, end;
   int count;
public:
   TQueue(int =100);
   ~TPQueue();
   void push(const T &);
   T pop();
   T get() const;
   bool isEmpty() const;
   bool isFull() const;
};
template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0) {
      arr = new T[size + 1];
    }
template<typename T>
TPQueue<T>::~TPQueue() {
  delete [] arr;
}
template <typename T>
void TPQueue<T>::push(const T & item) {
  assert(count < size);
  int prior = 0;
  int beginC = begin;
  int inPlace = 0;
  bool flag = 0;
  T trans, trans2;
  if (beginC != end) {
    while (beginC != end) {
        if (!(arr[beginC].prior < item.prior)) {
          beginC++;
          if (beginC == size)
            beginC = 0;
        } else {
          trans = arr[beginC];
          arr[beginC] = item;
          inPlace = beginC + 1;
          end++;
          count++;
          flag = 1;
          break;
        }
    }
    beginC = inPlace;
    if (flag) {
        while (beginC != end) {
          trans2 = arr[beginC];
          arr[beginC] = trans;
          trans = trans2;
          beginC++;
            if (beginC == size)
              beginC = 0;
        }
    }
    if (!flag) {
      arr[end++] = item;
      inPlace = end;
      count++;
    }
  } else {
    arr[begin] = item;
    count++;
    end++;
  }
  if (end > size)
    end -= size + 1;
}
template<typename T>
T TPQueue<T>::pop() {
  assert(count > 0);
  T item = arr[begin++];
  count--;
  if (begin > size)
    begin -= size + 1;
  return item;
}
template<typename T>
T TPQueue<T>::get() const {
  assert(count > 0);
  return arr[begin];
}
template<typename T>
bool TPQueue<T>::isEmpty() const {
  return count == 0;
}
template<typename T>
bool TPQueue<T>::isFull() const {
  return count == size;
}
struct SYM {
  char ch;
  int  prior;
};
#endif // INCLUDE_TPQUEUE_H_
