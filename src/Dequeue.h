#pragma once
namespace My
{
  template <class T>
  class Dequeue
  {
  public:
    Dequeue() :m_size(0), m_queue(nullptr) {};
    Dequeue(const Dequeue<T>&);
    Dequeue(Dequeue<T>&&);

    Dequeue<T>& operator=(const Dequeue<T>& src);
    Dequeue<T>& operator=(Dequeue<T>&& src);

    void push_back(const T&);
    void push_front(const T&);
    void push_back(T&&);
    void push_front(T&&);

    const T& front() { return m_queue->data; };
    const T& back() { return m_queue->prev->data; };
    void clear();
    T poll_first();
    T poll_last();
    int size() { return m_size; }

  private:
    typedef struct Node
    {
      Node* prev;
      Node* next;
      T data;
    }Node;

    Node* m_queue;
    unsigned int m_size;
  };

  template <class T>
  void Dequeue<T>::push_back(const T& elem)
  {
    if (m_queue == nullptr)
    {
      m_queue = new Node;
      m_queue->data = elem;
      m_queue->next = m_queue;
      m_queue->prev = m_queue;
      m_size = 1;
      return;
    }

    Node* newNode = new Node;
    newNode->data = elem;

    newNode->next = m_queue;
    m_queue->prev->next = newNode;
    newNode->prev = m_queue->prev;
    m_queue->prev = newNode;
    m_size++;
  }

  template <class T>
  void Dequeue<T>::push_front(const T& elem)
  {
    push_back(elem);
    m_queue = m_queue->prev;
  }

  template <class T>
  void Dequeue<T>::clear()
  {
    Node* tmp = m_queue;
    Node* next;
    while (m_size != 0)
    {
      next = tmp->next;
      delete tmp;
      tmp = next;
      m_size--;
    }
  }

  template <class T>
  T Dequeue<T>::poll_first()
  {
    if (m_size)
    {
      T data = m_queue->data;
      Node* tmp = m_queue;

      m_queue = m_queue->next;
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      m_size--;
      delete tmp;
      if (m_size == 0)
        m_queue = nullptr;

      return data;
    }
    else
      throw std::logic_error("deleting from empty queue");
  }

  template <class T>
  T Dequeue<T>::poll_last()
  {
    if (m_size)
    {
      T data = m_queue->data;
      Node* tmp = m_queue->prev;

      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      m_size--;
      delete tmp;
      if (m_size == 0)
        m_queue = nullptr;

      return data;
    }
    else
      throw std::logic_error("deleting from empty queue");
  }

  template <class T>
  void Dequeue<T>::push_back(T&& data)
  {
    if (m_queue == nullptr)
    {
      m_queue = new Node;
      m_queue->data = std::move(data);
      m_queue->next = m_queue;
      m_queue->prev = m_queue;
      m_size = 1;
      return;
    }

    Node* newNode = new Node;
    newNode->data = std::move(data);

    newNode->next = m_queue;
    m_queue->prev->next = newNode;
    newNode->prev = m_queue->prev;
    m_queue->prev = newNode;
    m_size++;

  }

  template <class T>
  void Dequeue<T>::push_front(T&& data)
  {
    if (m_queue == nullptr)
    {
      m_queue = new Node;
      m_queue->data = std::move(data);
      m_queue->next = m_queue;
      m_queue->prev = m_queue;
      m_size = 1;
      return;
    }

    Node* newNode = new Node;
    newNode->data = std::move(data);

    newNode->next = m_queue;
    m_queue->prev->next = newNode;
    newNode->prev = m_queue->prev;
    m_queue->prev = newNode;
    m_size++;
    m_queue = m_queue->prev;
  }

  template <class T>
  Dequeue<T>::Dequeue(const Dequeue& cls) :m_queue(nullptr), m_size(0)
  {
    Node* tmp = cls.m_queue;
    while (m_size != cls.m_size)
    {
      push_back(tmp->data);
      tmp = tmp->next;
    }
  }

  template <class T>
  Dequeue<T>::Dequeue(Dequeue&& cls)
  {
    m_size = cls.m_size;
    m_queue = cls.m_queue;
    cls.m_queue = 0;
    cls.m_size = 0;
  }

  template <class T>
  Dequeue<T>& Dequeue<T>::operator=(const Dequeue& src)
  {
    clear();
    Node* tmp = cls.queue;
    while (m_size != cls.size)
    {
      push_back(tmp->data);
      tmp = tmp->next;
    }
  }

  template <class T>
  Dequeue<T>& Dequeue<T>::operator=(Dequeue<T>&& src)
  {
    clear();
    m_size = src.m_size;
    m_queue = src.m_queue;
    src.m_queue = nullptr;
    src.m_size = 0;
  }
}
