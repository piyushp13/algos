#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* previous;
    Node* head;
    Node* tail;
    Node(int x)
    {
        data = x;
        next = NULL;
        previous = NULL;
        head = this;
        tail = this;
    }

    void insertAtBegining(int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        head->previous = newNode;
        newNode->data = newData;
        newNode->next = head;
        newNode->previous = NULL;
        head = newNode;
    }

    void insertAtEnd(int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->previous = tail;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void insertAfterNode(Node *node, int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = node->next;
        newNode->previous = node;
        node->next->previous = newNode;
        node->next = newNode;
    }

    void insertBeforeNode(Node *node, int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = node;
        newNode->previous = node->previous;
        node->previous->next = newNode;
        node->previous = newNode;
    }

    void printForward()
    {
        Node *headRef = head;
        while (headRef != NULL)
        {
            cout << headRef->data << " ";
            headRef = headRef->next;
        }
        cout << endl;
    }

    void printReverse()
    {
        Node *tailRef = tail;
        while (tailRef != NULL)
        {
            cout << tailRef->data << " ";
            tailRef = tailRef->previous;
        }
        cout << endl;
    }
};


int main()
{
    int n;
    cin >> n;
    int firstElement;
    cin >> firstElement;
    Node *myList = new Node(firstElement);
    for (int i = 0; i < n - 1; i++)
    {
        int num;
        cin >> num;
        myList->insertAtEnd(num);
    }
    myList->printForward();
    myList->printReverse();
    myList->insertBeforeNode(myList->tail->previous, 200);
    myList->insertBeforeNode(myList->tail, 100);
    myList->insertAfterNode(myList->head->next, 500);
    myList->printForward();
    return 0;
}