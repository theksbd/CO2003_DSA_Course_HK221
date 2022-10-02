#include <iostream>
#include <sstream>

using namespace std;

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node *head;
    Node *tail;
    int count;

public:
    IntSLinkedList() : head(nullptr), tail(nullptr), count(0) {};

    void add(int element) {
        Node *newNode = new Node(element);
        if (this->count == 0) {
            this->head = newNode;
        }
        else {
            this->tail->next = newNode;
        }
        this->tail = newNode;
        this->count++;
    }

    void add(int index, int element) {
        if (index < 0 || index > this->count)
            throw std::out_of_range("Index is out of range");
        Node *newNode = new Node(element);
        if (index == 0) {
            if (this->count == 0) {
                this->head = this->tail = newNode;
            }
            else {
                newNode->next = this->head;
                this->head = newNode;
            }
        }
        else if (index == this->count) {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        else {
            Node *prevNode = this->head;
            for (int i = 0; i < index - 1; i++) {
                prevNode = prevNode->next;
            }
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
        this->count++;
    }

    int removeAt(int index) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("Index is out of range");
        Node *deletedNode = this->head;
        if (index == 0) {
            if (this->count == 1) {
                this->head = this->tail = nullptr;
            }
            else {
                this->head = this->head->next;
            }
        }
        else {
            Node *prevNode = deletedNode;
            for (int i = 0; i < index; i++) {
                prevNode = deletedNode;
                deletedNode = deletedNode->next;
            }
            prevNode->next = deletedNode->next;
            if (prevNode->next == nullptr)
                this->tail = prevNode;
        }
        int deletedData = deletedNode->data;
        delete deletedNode;
        this->count--;
        return deletedData;
    }

    bool removeItem(int item) {
        if (this->count == 0)
            return false;
        Node *deletedNode = this->head;
        if (this->head->data == item) {
            this->head = this->head->next;
            if (this->head == nullptr)
                this->tail = nullptr;
            delete deletedNode;
            this->count--;
            return true;
        }
        else {
            Node *prevNode = deletedNode;
            deletedNode = deletedNode->next;
            if (deletedNode == nullptr)
                return false;
            for (int i = 0; i < this->count - 1; i++) {
                if (deletedNode->data == item) {
                    prevNode->next = deletedNode->next;
                    if (prevNode->next == nullptr)
                        this->tail = prevNode;
                    delete deletedNode;
                    this->count--;
                    return true;
                }
                prevNode = deletedNode;
                deletedNode = deletedNode->next;
            }
        }
        return false;
    }

    bool empty() {
        return (this->count == 0);
    }

    int size() {
        return this->count;
    }

    int get(int index) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("Index is out of range");
        if (index == 0)
            return this->head->data;
        else if (index == this->count - 1)
            return this->tail->data;
        Node *currentNode = this->head->next;
        for (int i = 1; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }

    void set(int index, int element) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("Index is out of range");
        if (index == 0)
            this->head->data = element;
        else if (index == this->count - 1)
            this->tail->data = element;
        else {
            Node *currentNode = this->head->next;
            for (int i = 1; i < index; i++)
                currentNode = currentNode->next;
            currentNode->data = element;
        }
    }

    int indexOf(int item) {
        if (this->count == 0)
            return -1;
        Node *currentNode = this->head;
        for (int i = 0; i < this->count; i++) {
            if (currentNode->data == item)
                return i;
            currentNode = currentNode->next;
        }
        return -1;
    }

    bool contains(int item) {
        return (this->indexOf(item) != -1);
    }

    void clear() {
        while (this->head != nullptr) {
            Node *deletedNode = this->head;
            this->head = this->head->next;
            delete deletedNode;
            this->count--;
        }
        this->tail = nullptr;
    }

    string toString() {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail) {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        return ss.str();
    }

    ~IntSLinkedList() {
        this->clear();
        delete this->head;
        delete this->tail;
    }

public:
    class Node {
    public:
        int data;
        Node *next;

    public:
        Node() : next(nullptr) {};

        Node(int data) : data(data), next(nullptr) {};
    };
};

int main() {
    IntSLinkedList list;
    int values[] = {10, 15, 2, 6, 4, 2, 40, 8};
    int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    for (int idx = 0; idx < 8; idx++) {
        list.add(index[idx], values[idx]);
    }

    bool removed = list.removeItem(41);
    cout << removed << endl;

    cout << list.toString();
    /*int size = 10;
    for (int index = 0; index < size; index++) {
        list.add(index);
    }
    cout << list.toString() << "\nSize: " << list.size() << endl;
    int a = list.removeAt(0);
    int b = list.removeAt(5);
    cout << a << " " << b << endl;
    cout << list.toString() << "\nSize: " << list.size() << endl;
    bool t = list.removeItem(6);
    cout << t << endl;;
    cout << list.toString() << "\nSize: " << list.size() << endl;
    t = list.removeItem(7);
    cout << t << endl;;
    cout << list.toString() << "\nSize: " << list.size() << endl;
    t = list.removeItem(9);
    cout << t << endl;;
    cout << list.toString() << "\nSize: " << list.size() << endl;*/
    return 0;
}
