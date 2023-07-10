#pragma once

template<class T>
class Deque {
private:
    int _capacity = 10;
    T* _arr = new T[_capacity];
    int _front = -1;
    int _rear = -1;
    int _size = 0;

public:
    Deque() = default;

    T getFront() const;
    T getRear() const;
    void push_front(T key);
    void push_rear(T key);
    void pop_front();
    void pop_rear();
    bool isEmpty() const;
    bool isFull() const;


    template<class T>
    friend ostream& operator<<(ostream& print, const Deque<T>& queue);

    ~Deque();
};

template<class T>
bool Deque<T>::isFull() const {
    if (_front == 0 && _rear == _capacity - 1) {
        return true;
    }
    if (_front == _rear + 1) {
        return true;
    }
    return false;
}

template<class T>
bool Deque<T>::isEmpty() const {
    return (_front == -1);
}

template<class T>
T Deque<T>::getFront() const {
    if (isEmpty()) {
        assert(!"Deque is Empty!");
    }
    return _arr[_front];
}

template<class T>
T Deque<T>::getRear() const {
    if (isEmpty()) {
        assert(!"Deque is Empty!");
    }
    return _arr[_rear];
}

template<class T>
void Deque<T>::push_front(T key) {
    if (isFull()) {
        assert(!"Deque is Full!");
        return;
    }
    if (_front == -1) {
        _front = 0;
        _rear = 0;
    }
    else if (_front == 0)
        _front = _capacity - 1;
    else
        _front = _front - 1;

    _arr[_front] = key;
    _size++;
}

template<class T>
void Deque<T>::push_rear(T key) {
    if (isFull()) {
        assert(!"Deque is Full!");
        return;
    }

    if (_front == -1) {
        _front = 0;
        _rear = 0;
    }
    else if (_rear == _capacity - 1)
        _rear = 0;
    else
        _rear = _rear + 1;

    _arr[_rear] = key;
    _size++;
}

template<class T>
void Deque<T>::pop_front() {
    if (isEmpty()) {
        assert(!"Deque is Empty!");
        return;
    }

    if (_front == _rear) {
        _front = -1;
        _rear = -1;
    }
    else if (_front == _capacity - 1)
        _front = 0;

    else
        _front = _front + 1;
    _size--;
}

template<class T>
void Deque<T>::pop_rear() {
    if (isEmpty()) {
        assert(!"Deque is Empty!");
        return;
    }

    if (_front == _rear) {
        _front = -1;
        _rear = -1;
    }
    else if (_rear == 0)
        _rear = _capacity - 1;
    else
        _rear = _rear - 1;
    _size--;
}

template<class T>
ostream& operator<<(ostream& print, const Deque<T>& queue) {
    if (queue.isEmpty()) {
        print << "Queue is Empty.";
        return print;
    }
    int i;
    cout << "[";
    for (i = queue._front; i != queue._rear; i = (i + 1) % queue._capacity) {
        print << queue._arr[i] << ", ";
    }
    print << queue._arr[queue._rear] << "]" << endl;
    return print;
}

template<class T>
Deque<T>::~Deque() {
    delete[] _arr;
}