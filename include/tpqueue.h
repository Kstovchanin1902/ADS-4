// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  private:
    T *arr;          // массив с данными
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;       // счетчик элементов
public:
    TPQueue(int =100);          // конструктор по умолчанию
    ~TPQueue();                 // деструктор
 
    void push(const T &); // добавить элемент в очередь
    T pop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
};
// конструктор по умолчанию
template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), end(0), count(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new T[size + 1];
}

// деструктор класса Queue
template<typename T>
TPQueue<T>::~TPQueue()
{
    delete [] arr;
}


// функция добавления элемента в очередь
template<typename T>
void TPQueue<T>::push(const T & item)
{
     // проверяем, ести ли свободное место в очереди
    assert( count < size ); 
    int prior = 0;
    int beginC = begin;
    int inPlace = 0;
    bool flag = 0;
    T trans, trans2;
    std::cout << "1" << std::endl;
    std::cout << "begin = " << begin << " end = " << end << std::endl;
    if (beginC != end)
    {
        while (beginC != end)
        {
            std::cout << "jkAl" << std::endl;
            std::cout << "count = " << count << std::endl;
            if (!(arr[beginC].prior < item.prior))
            {
                beginC++;
                if (beginC == size)
                    beginC = 0;
            }
            else
            {
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
        if (flag)
        {
            while (beginC != end)
            {
                trans2 = arr[beginC];
                arr[beginC] = trans;
                trans = trans2;
                beginC++;
                if (beginC == size)
                    beginC = 0;

            }
        }
        if (!flag)
        {
            arr[end++] = item;
            inPlace = end;
            count++;
        }
    }
    else
    {
        arr[begin] = item;
        count++;
        end++;
    }
 
    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}

// функция удаления элемента из очереди
template<typename T>
T TPQueue<T>::pop()
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
 
    T item = arr[begin++];
    count--;
 
    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди
 
    return item;
}

// функция чтения элемента на первой позиции
template<typename T>
T TPQueue<T>::get() const 
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TPQueue<T>::isEmpty() const
{
  return count==0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TPQueue<T>::isFull() const
{
  return count==size;
}


struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
