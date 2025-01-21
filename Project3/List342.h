#ifndef LIST342_H_
#define LIST342_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class List342 {
    private:
        struct Node {
            T *data;
            Node* next;
        };

        Node* head_;
    public:
        //Constructor & Destructor
        List342();
        List342(List342& list);
        List342(string fileName);
        ~List342();

        //Methods
        bool BuildList(string file_name);
        bool Insert(T* obj);
        bool Remove(T target, T& result);
        bool Peek(T target, T& result) const;
        int Size() const;
        void DeleteList();
        bool Merge(List342& list1);
        
        //Operator Overloads
        List342<T> operator+(const List342<T>& list);
        List342<T>& operator+=(const List342<T>& list);
        bool operator==(const List342<T>& list);
        bool operator!=(const List342<T>& list);
        List342<T>& operator=(const List342<T>& list);

        friend ostream& operator<< (ostream &ostream, const List342<T>& list){
            Node *current = list.head_;
            while(current != nullptr) {
                ostream << *current->data;
                current = current->next;
            }

            return ostream;
        }
};

// ------------------- Constructor/Destructor Definitions -------------------

template <class T>
List342<T>::List342() : head_(nullptr) {
    
}

template <class T>
List342<T>::List342(List342<T>& list) : head_(nullptr) {
    if (list.head_ == nullptr) {
        return;

    }

    Node* tempHead = list.head_;
    Node* tempDestination = nullptr;

    while (tempHead != nullptr) {
        T* newData = new T(*tempHead->data);
        Node* newNode = new Node;
        newNode->data = newData;

        if (head_ == nullptr) {
            head_ = newNode;
            tempDestination = head_;

        } else {
            tempDestination->next = newNode;
            tempDestination = newNode;

        }

        tempHead = tempHead->next;
    }
}


template <class T>
List342<T>::List342(string fileName) : head_(nullptr) {
    BuildList(fileName);

}

template <class T>
List342<T>::~List342() {
    DeleteList();

}

// ------------------- Method Definitions -------------------

template <class T>
bool List342<T>::BuildList(string filename) {
    ifstream infile(filename);

    if (!infile) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;

    }

    T item;
    while (infile >> item) {
        Insert(new T(item));

    }

    infile.close();
    return true;
}

template <class T>
bool List342<T>::Insert(T* obj) {
    if (obj == nullptr) {
        return false;

    }

    Node* newNode = new Node;
    newNode->data = obj;
    newNode->next = nullptr;

    if ((head_ == nullptr) || (*(newNode->data) < *(head_->data))) {
        newNode->next = head_;
        head_ = newNode;
        return true;

    }

    Node* current = head_;
    while ((current->next != nullptr) && (*(current->next->data) < *(newNode->data))) {
        current = current->next;

    }

    if ((current->next != nullptr) && (*(current->next->data) == *(newNode->data))) {
        delete newNode;
        return false;

    }

    newNode->next = current->next;
    current->next = newNode;
    return true;
}

template <class T>
bool List342<T>::Remove(T target, T& result) {
    if (head_ == nullptr) {
        return false;

    }

    Node* current = head_;
    Node* previous = nullptr;

    while (current && *(current->data) != target) {
        previous = current;
        current = current->next;

    }

    if (current == nullptr) {
        return false;

    }

    if (previous != nullptr) {
        previous->next = current->next;

    } else {
        head_ = current->next;

    }

    result = *(current->data);
    delete current->data;
    delete current;
    return true;
}

template <class T>
bool List342<T>::Peek(T target, T& result) const {
    Node* current = head_;

    while (current != nullptr) {
        if (*(current->data) == target) {
            result = *(current->data);
            return true;

        }
        current = current->next;
    }

    return false;
}

template <class T>
int List342<T>::Size() const {
    int count = 0;
    Node* current = head_;

    while (current) {
        ++count;
        current = current->next;

    }

    return count;
}

template <class T>
void List342<T>::DeleteList() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        
        delete temp;
    }
}

template <class T>
bool List342<T>::Merge(List342<T>& list) {
    if (this == &list) {
        return false;

    }

    Node* other = list.head_;
    while (other != nullptr) {
        Insert(new T(*other->data)); 
        other = other->next;

    }
    list.head_ = nullptr;
    return true;
}
// ------------------- Operator Overload Definitions -------------------

template <class T>
List342<T> List342<T>::operator+(const List342<T>& list) {
    List342<T> result(*this);
    result += list;
    return result;

}

template <class T>
List342<T>& List342<T>::operator+=(const List342<T>& list) {
    Node* current = list.head_;
    while (current != nullptr) {
        Insert(new T(*current->data));
        current = current->next;

    }
    return *this;
}

template <class T>
bool List342<T>::operator==(const List342<T>& list) {
    Node* Node1 = head_;
    Node* Node2 = list.head_;

    while ((Node1 != nullptr) && (Node2 != nullptr)) {
        if (*(Node1->data) != *(Node2->data)) {
            return false;

        }
        Node1 = Node1->next;
        Node2 = Node2->next;
    }

    return (Node1 == nullptr) && (Node2 == nullptr);
}

template <class T>
bool List342<T>::operator!=(const List342<T>& list) {
    return !(*this == list);

}

template <class T>
List342<T>& List342<T>::operator=(const List342<T>& list) {
    if (this != &list) {
        DeleteList();

        Node* tempHead = list.head_;
        Node* tempDestination = nullptr;

        while (tempHead != nullptr) {
            T* newData = new T(*tempHead->data);
            Node* newNode = new Node;

            newNode->data = newData;
            newNode->next = nullptr;

            if (head_ == nullptr) {
                head_ = newNode;
                tempDestination = head_;

            } else {
                tempDestination->next = newNode;
                tempDestination = newNode;

            }
            tempHead = tempHead->next;
        }
    }

    return *this;
}

#endif