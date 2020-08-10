#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    int size();    
    void push(const T& obj);
    void pop();
    T&   front();
    T&   back();
    bool empty();

private:
    int n;
    T* arr;
};

template<typename T>
Queue<T>::Queue(): n(0), arr(NULL)
{}

template<typename T>
Queue<T>::~Queue()
{ 
    if (n == 0)
        delete arr;
    else
        delete[] arr; 
}

template<typename T>
int Queue<T>::size()
{
    return n;
}

template<typename T>
void Queue<T>::push(const T& obj)
{
    T* tmp_arr = new T[n+1];

    for (int i = 0; i < n; i++)
    {
        tmp_arr[i] = arr[i];    
    }
    tmp_arr[n] = obj;

    delete arr;
    
    arr = tmp_arr;
    n++;
}

template<typename T>
void Queue<T>::pop()
{
    /*удаляет последний элемент*/
    if (n > 0)
    {
        T* tmp_arr = new T[n-1];

        for (int i = 0; i < n-1; i++)
        {
            tmp_arr[i] = arr[i];    
        }

        delete arr;
        
        arr = tmp_arr;
        n--;
    }
    else
        cout << "queue empty!" << endl;
}

template<typename T>
T& Queue<T>::front()
{
    /*Возвращает первого элемента*/
    if (n > 0)
        return arr[0];
    throw 1;
}

template<typename T>
T& Queue<T>::back()
{
    /*Возвращает последний элемент и удаляет его*/
    if (n > 0)
        return arr[n-1];
    throw 1;
}

template<typename T>
bool Queue<T>::empty()
{
    return n == 0? true : false;
}

int main()
{
    Queue<int> roler;
    
    for (int i = 1; i <= 5; i++)
        roler.push(i);
    cout << "Size = " << roler.size() << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << roler.back() << ' ';
        roler.pop();
    }
    cout << endl;

    cout << "Size = " << roler.size() << endl;
    return 0;
}