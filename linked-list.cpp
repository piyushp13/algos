#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* head;
    Node* tail;
    Node(int x)
    {
        data = x;
        next = NULL;
        head = this;
        tail = this;
    }

    void insertAtBegining(int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int newData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newData;
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
        node->next = newNode;
    }

    void printList()
    {
        Node *headRef = head;
        while (headRef != NULL)
        {
            cout << headRef->data << endl;
            headRef = headRef->next;
        }
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
    myList->printList();
    return 0;
}