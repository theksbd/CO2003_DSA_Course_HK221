#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr){};
    Node(int data, Node *next = nullptr) : data(data), next(next){};
    int getData()
    {
        return this->data;
    }
    Node *getNext()
    {
        return this->next;
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
};

void reduceDuplicate(Node *root)
{
    if (root == nullptr)
        return;
    Node *previousNode = root;
    Node *currentNode = root->getNext();

    // Method 1: O(N^2)
    // while (currentNode != nullptr)
    // {
    //     while (previousNode->getData() == currentNode->getData())
    //         currentNode = currentNode->getNext();
    //     previousNode->setNext(currentNode);
    //     previousNode = previousNode->getNext();
    //     currentNode = previousNode->getNext();
    // }

    // Method 2: O(N)
    while (currentNode != nullptr)
    {
        if (previousNode->getData() == currentNode->getData())
        {
            previousNode->setNext(currentNode->getNext());
            currentNode = currentNode->getNext();
        }
        else
        {
            previousNode = previousNode->getNext();
            currentNode = previousNode->getNext();
        }
    }
}

void printList(Node *root)
{
    Node *currentNode = root;
    while (currentNode != nullptr)
    {
        cout << currentNode->getData() << " ";
        currentNode = currentNode->getNext();
    }
    cout << '\n';
}

int main()
{
    Node *root = new Node(1);
    Node *root1 = new Node(1);
    Node *root2 = new Node(2);
    Node *root3 = new Node(2);
    Node *root4 = new Node(2);
    Node *root5 = new Node(4);
    Node *root6 = new Node(5);
    Node *root7 = new Node(6);
    Node *root8 = new Node(7);
    Node *root9 = new Node(8);
    Node *root10 = new Node(8);
    Node *root11 = new Node(8);
    Node *root12 = new Node(2);

    root->setNext(root1);
    root1->setNext(root2);
    root2->setNext(root3);
    root3->setNext(root4);
    root4->setNext(root5);
    root5->setNext(root6);
    root6->setNext(root7);
    root7->setNext(root8);
    root8->setNext(root9);
    root9->setNext(root10);
    root10->setNext(root11);
    root11->setNext(root12);

    printList(root);
    reduceDuplicate(root);
    printList(root);

    return 0;
}