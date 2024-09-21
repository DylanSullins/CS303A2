#pragma once
#include <stdexcept>

template <typename T>
class LinkedList 
{
    struct Node {
        T data;
        Node* next;

        Node(const T& item, Node* nextNode = nullptr) : data(item), next(nextNode)
        {}
    };
    protected: 
        Node* head;
        Node* tail;
        size_t numItems;
    
    public:
        LinkedList(T data)
        {
            head = new Node(data);
            tail = head;
            numItems = 1;
        }
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
            numItems = 0;
        }
        LinkedList(const LinkedList& other)
        {
            if (other.empty())
            {
                head = nullptr;
                tail = nullptr;
                numItems = 0;
            }
            else
            {
                head = new Node(other.getHead()->data);

                Node* currentNewNode = head;
                Node* currentOtherNode = other.getHead()->next;

                while (currentOtherNode != nullptr)
                {
                    Node* newNode = new Node(currentOtherNode->data);

                    currentNewNode->next = newNode;
                    currentNewNode = newNode;
                    currentOtherNode = currentOtherNode->next;
                }
                tail = currentNewNode;
                numItems = other.getNumItems();
            }
        }
        ~LinkedList()
        {
            if (empty()){
                return;
            }
            Node* delNode = head;
            while (head != nullptr)
            {
                head = head->next;
                delete delNode;
                delNode = head;
            }
            tail = nullptr;
            numItems = 0;
        }

        const Node* getHead() const{return head;}
        	/*
            Returns head node pointer
            Parameters:
                None

            Returns:
                Node* head
            */
        const Node* getTail() const{return tail;}
            /*
            Returns tail node pointer
            Parameters:

            Returns:
                Node* tail
            */
        const size_t getNumItems() const{return numItems;}
            /*
            Returns number of items
            Parameters:

            Returns:
                size_t numItems
            */

        void setHead(Node* newHead){head = newHead;}
            /*
            Set head pointer to new node pointer
            Parameters:
                Node* newHead: new head pointer

            Returns:
                None
            */
        void setTail(Node* newTail){tail = newTail;}
            /*
            Set tail pointer to new node pointer
            Parameters:
                Node* newHead: new head pointer

            Returns:
                None
            */

        const bool empty() const{return head == nullptr;}
            /*
            Check for empty list
            Parameters:
                None

            Returns:
                bool 
            */
        void push_front(T item)
            /*
            Push new item to front of list
            Parameters:
                T item: new type T item to add 

            Returns:
                None
            */
        {
            Node* addNode = new Node(item, head);
            if (empty()){
                setHead(addNode);
                setTail(addNode);
                ++numItems;
                return;
            }
            setHead(addNode);
            ++numItems;
            return;
        }
        void push_back(T item)
            /*
            Push new item to back of list
            Parameters:
                T item: new type T item to add 

            Returns:
                None
            */
        {
            Node* addNode = new Node(item);
            if (empty()){
                setHead(addNode);
                setTail(addNode);
                ++numItems;
                return;
            }
            tail->next = addNode;
            setTail(addNode);
            ++numItems;
            return;
        }
        void pop_front()
            /*
            Pop item from front of list
            Parameters:
                None

            Returns:
                None
            */
        {
            if (empty())
                throw std::runtime_error("Attempting to delete from empty list.");
            Node* delNode = head;
            setHead(head->next);
            delete delNode;
            if (empty())
                setTail(nullptr);
            --numItems;
        }
        void pop_back()
            /*
            Pop item from back of list
            Parameters:
                None

            Returns:
                None
            */
        {
            if (empty())
                throw std::runtime_error("Attempting to delete from empty list.");
            Node* delNode = tail;
            Node* currentNode = head;
            if (currentNode == delNode)
            {
                setHead(nullptr);
                setTail(nullptr);
                delete delNode;
                --numItems;
                return;
            }
            
            while (currentNode->next != delNode)
            {
                currentNode = currentNode->next;
            }
            setTail(currentNode);
            currentNode->next = nullptr;
            delete delNode;
            --numItems;
        }
        T& front(){return head->data;}
            /*
            Returns first piece of data in list
            Parameters:
                None

            Returns:
                T head->data
            */
        T& back(){return tail->data;}
            /*
            Returns last piece of data in list
            Parameters:
                None 

            Returns:
                T tail->data
            */

        class iterator 
        {
            public:
                Node* current;
                iterator(typename LinkedList<T>::Node* position) : current(position) {}

                T& operator*() const 
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempting to dereference end()");
                    return current->data;
                }
                T* operator->() const 
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempt to dereference end()");
                    return &(current->data);
                }
                iterator& operator++() 
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempt to advance past end()");
                    current = current->next;
                    return *this;
                }
                iterator operator++(int) 
                {
                    iterator returnValue = *this;
                    ++(*this);
                    return returnValue;
                }
                bool operator==(const iterator& other) const
                {
                    return current == other.current;
                }
                bool operator!=(const iterator& other) const
                {
                    return current != other.current;
                }
        };

        void insert(size_t index, const T value)
            /*
            Insert value at given index. Not efficient.
            Parameters:
                size_t index: Index to insert at
                T value: new type T item to add 

            Returns:
                None
            */
        {
            if (index >= numItems) 
            {
                push_back(value);
                return;
            }
            if (index == 0)
            {
                push_front(value);
                return;
            }
            size_t count = 0;
            iterator itr(head);
            iterator prevItr = itr;

            while (count < index)
            {
                prevItr = itr;
                ++itr;
                ++count;
            }
            
            Node* newNext = itr.current;
            Node* addNode = new Node(value, newNext);
            prevItr.current->next = addNode;
            ++numItems;
        }
        bool remove(size_t index)
            /*
            Remove item at given index
            Parameters:
                size_t index: Index to remove

            Returns:
                None
            */
        {
            if (index >= numItems)
                throw std::out_of_range("Index out of range");
            if (index == 0)
            {
                pop_front();
                return true;
            }
            
            size_t count = 0;
            iterator itr(head);
            iterator prevItr = itr;
            
            while (count < index) 
            {
                prevItr = itr;
                ++itr;
                ++count;
            }
            Node* delNode = itr.current;
            prevItr.current->next = delNode->next;
            if (delNode == tail)
            {
                setTail(prevItr.current);
            }
            delete delNode;
            --numItems;
            return true;
        }
        
        size_t find(const T& value) 
            /*
            Linear search through list from head-tail for value
            Parameters:
                T value: Value to find in list

            Returns:
                size_t index of found item
            */
        {
            if (empty())
                throw std::runtime_error("Attempting to search an empty list.");
            if (head->data == value)
                return 0;
            size_t index = 0;
            for (iterator itr = begin(); itr != end(); ++itr, ++index)
            {
                if (*itr == value)
                {
                    return index;
                }
            }
            return numItems;
        }

        iterator begin() {return iterator(head);}
        iterator end() {return iterator(nullptr);}

        void print() 
            /*
            Print list with "==>" between each node
            Parameters:
                None

            Returns:
                None
            */
        {
            for (iterator i = begin(); i != end(); ++i)
            {
                std::cout << *i;
                if (i.current->next != nullptr) std::cout << " ==> ";
                else std::cout << std::endl;
            }
        }
};