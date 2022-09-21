#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;

class IntDLinkedList {
private:
    class Node;

private:
    Node *head;
    Node *tail;
    int count;
public:
    IntDLinkedList() : head(NULL), tail(NULL), count(0) {}

    ~IntDLinkedList() {
        this->clear();
    }

    void add(int element) {
        Node *newNode = new Node(element);
        if (this->count > 0) {
            this->tail->next = newNode;
            newNode->prev = this->tail;
        }
        else {
            this->head = newNode;
        }
        this->tail = newNode;
        this->count++;
    }

    void add(int index, int element) {
        if (index < 0 || index > this->count)
            throw std::out_of_range("The index is out of range!");
        if (index == 0) {
            Node *newNode = new Node(element);
            if (this->count == 0)
                this->head = this->tail = newNode;
            else {
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
            }
        }
        else if (index == this->count) {
            this->add(element);
            return;
        }
        else {
            Node *newNode = new Node(element, NULL, this->head);
            Node *prevNode = this->head;
            for (int i = 1; i < index; i++) {
                prevNode = prevNode->next;
            }
            newNode->prev = prevNode;
            newNode->next = prevNode->next;
            prevNode->next->prev = newNode;
            prevNode->next = newNode;
        }
        this->count++;
    }

    int removeAt(int index) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("The index is out of range!");
        Node *deleteNode = this->head;
        int value = deleteNode->value;
        if (index == 0) {
            if (this->count == 1)
                this->head = this->tail = NULL;
            else {
                this->head = this->head->next;
                this->head->prev = NULL;
            }
        }
        else if (index == this->count - 1) {
            deleteNode = this->tail;
            value = deleteNode->value;
            this->tail = this->tail->prev;
            this->tail->next = NULL;
        }
        else {
            Node *prevNode = this->head;
            deleteNode = deleteNode->next;
            for (int i = 1; i < index; i++) {
                prevNode = prevNode->next;
                deleteNode = deleteNode->next;
            }
            value = deleteNode->value;
            prevNode->next = deleteNode->next;
            deleteNode->next->prev = prevNode;
        }
        delete deleteNode;
        this->count--;
        return value;
    }

    bool removeItem(int element) {
        if (this->count == 0)
            return false;
        Node *deleteNode = this->head;
        if (this->head->value == element) {
            if (this->count == 1)
                this->head = this->tail = NULL;
            else {
                this->head = this->head->next;
                this->head->prev = NULL;
            }
            delete deleteNode;
            this->count--;
            return true;
        }
        else {
            Node *prevNode = this->head;
            deleteNode = deleteNode->next;
            for (int i = 1; i < this->count; i++) {
                if (deleteNode->value == element) {
                    if (deleteNode != this->tail) {
                        prevNode->next = deleteNode->next;
                        deleteNode->next->prev = prevNode;
                    }
                    else {
                        prevNode->next = NULL;
                        this->tail = prevNode;
                    }
                    delete deleteNode;
                    this->count--;
                    return true;
                }
                prevNode = prevNode->next;
                deleteNode = deleteNode->next;
            }
        }
        return false;
    }

    int get(int index) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("The index is out of range!");
        if (index == 0)
            return this->head->value;
        else if (index == this->count - 1)
            return this->tail->value;
        else {
            Node *gNode = this->head->next;
            for (int i = 1; i < index; i++)
                gNode = gNode->next;
            return gNode->value;
        }
    }

    void set(int index, int element) {
        if (index < 0 || index >= this->count)
            throw std::out_of_range("The index is out of range!");
        if (index == 0)
            this->head->value = element;
        else if (index == this->count - 1)
            this->tail->value = element;
        else {
            Node *sNode = this->head->next;
            for (int i = 1; i < index; i++)
                sNode = sNode->next;
            sNode->value = element;
        }
    }

    int indexOf(int element) {
        if (this->count == 0)
            return -1;
        if (this->head->value == element)
            return 0;
        else {
            Node *scanNode = this->head->next;
            for (int i = 1; i < this->count; i++) {
                if (scanNode->value == element)
                    return i;
                scanNode = scanNode->next;
            }
        }
        return -1;
    }

    bool contains(int element) {
        int checkContains = this->indexOf(element);
        if (checkContains == -1)
            return false;
        return true;
    }

    int size() {
        return this->count;
    }

    bool empty() {
        return (this->count == 0);
    }

    void clear() {
        if (this->count == 0)
            return;
        while (this->head != NULL) {
            Node *clearNode = this->head;
            this->head = this->head->next;
            delete clearNode;
            this->count--;
        }
        this->tail = NULL;
    }

    string toString() {
        std::stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail) {
            ss << ptr->value << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->value << "]";
        else
            ss << "]";
        return ss.str();
    }

    void dump() {
        if (this->count == 0) {
//            assert(this->head == NULL);
//            assert(this->tail == NULL);
            cout << "List: []" << endl;
            cout << "Reverse list: []" << endl;
            return;
        }

        cout << "List: [";
        Node *temp = this->head;
        while (temp != this->tail) {
            cout << temp->value << ",";
            temp = temp->next;
        }
        cout << temp->value << "]" << endl;
        cout << "Reverse list: [";
        temp = this->tail;
        while (temp != this->head) {
            cout << temp->value << ",";
            temp = temp->prev;
        }
        cout << temp->value << "]" << endl;
    }

private:
    class Node {
    public:
        int value;
        Node *prev;
        Node *next;

        Node(int value = 0, Node *prev = NULL, Node *next = NULL) : value(value), prev(prev), next(next) {}
    };
};


int main() {
    try {
        IntDLinkedList list;
        list.empty() ? cout << "List is currently empty" << endl : cout << "List is not currently empty" << endl;
        int size = 10;
        for (int idx = 0; idx < size; idx++)
            list.add(0, idx);
        list.dump();
//        cout << list.size() << endl;
//        list.add(5, 15);
//        cout << list.toString() << endl;
//        list.add(15, 101);
//        list.add(-1, 10);
//        cout << list.size() << endl;
//        list.empty() ? cout << "List is currently empty" << endl : cout << "List is not empty" << endl;
//        cout << list.toString() << endl;
//        cout << list.removeAt(1) << endl;
//        cout << list.removeAt(7) << endl;
//        cout << list.toString() << endl;
//        cout << list.removeItem(101) << endl;
//        cout << list.removeItem(15) << endl;
//        cout << list.toString() << endl;
//        cout << list.size() << endl;
//        cout << list.removeItem(9) << endl;
//        cout << list.toString() << endl;
    }
    catch (std::out_of_range &oor) {
        cerr << oor.what() << endl;
    }
    return 0;
}
