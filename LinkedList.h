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
            if (other.isEmpty())
            {
                head = nullptr;
                tail = nullptr;
                numItems = 0;
            }
            else
            {
                head = new Node(other.head->data);

                Node* currentNewNode = head;
                Node* currentOtherNode = other.head->next;

                while (currentOtherNode != nullptr)
                {
                    Node* newNode = new Node(currentOtherNode->data);

                    currentNewNode->next = newNode;
                    currentNewNode = newNode;
                    currentOtherNode = currentOtherNode->next;
                }
                tail = currentNewNode;
                numItems = other.numItems;
            }
        }
        ~LinkedList()
        {
            if (isEmpty()){
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

        const Node* getHead(){return head;}
        const Node* getTail(){return tail;}
        const int getNumItems(){return numItems;}

        void setHead(Node* newHead){head = newHead;}
        void setTail(Node* newTail){tail = newTail;}

        const bool isEmpty(){return head == nullptr;}
        void push_front(T item)
        {
            Node* addNode = new Node(item, head);
            if (isEmpty()){
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
        {
            Node* addNode = new Node(item);
            if (isEmpty()){
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
        {
            if (isEmpty())
                throw std::runtime_error("Attempting to delete from empty list.");
            Node* delNode = head;
            setHead(head->next);
            delete delNode;
            if (isEmpty())
                setTail(nullptr);
            --numItems;
        }
        void pop_back()
        {
            if (isEmpty())
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
            delete delNode;
            --numItems;
        }
        T& front(){return head->data;}
        T& back(){return tail->data;}
        void insert(size_t index, const T value)
        {
            if (index >= numItems) 
            {
                push_back(value);
                return;
            }
            
        }
        //bool remove(size_t index);
        /*size_t find(const T& value) 
        {
            if (isEmpty())
                throw std::runtime_error("Attempting to search an empty list.");
            if (head->data == value)
                return 0;
            if (tail->data == value){}
        }*/

};

template <typename T>
class iterator 
{
    friend class LinkedList<T>;
    private:
        LinkedList<T>* parent;
        LinkedList<T>::Node* current;
        iterator(LinkedList<T>* newParent, Node* position) :
            parent(newParent), current(position) {}
        
        T& operator*() const 
        {
            if (current == nullptr)
                throw std::runtime_error("Attempting to dereference end()");
            return current->data;
        }
};