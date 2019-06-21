#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *head;
    Node *tail;
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
        }
        else
        {
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
            cout << headRef->data << " ";
            headRef = headRef->next;
        }
        cout << endl;
    }

    void reverseList()
    {
        // Your code here
        Node* prevEle = NULL;
        Node* curr = head;
        while(curr != NULL) {
            head = curr->next;
            curr->next = prevEle;
            prevEle = curr;
            curr = head;
        }
        head = prevEle;
    }

    void deleteNode(int k) {
        Node* headRef = head;
        int index = k;
        while(--k > 1) {
            head = head->next;
        }
        Node* temp = head->next;
        if (temp != NULL) {
            head->next = temp->next;
            if (index == 1) {
                head->data = temp->data;
            }
            free(temp);
            head = headRef;
        } else {
            head = NULL;
        }
        return;
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
    // myList->reverseList();
    // myList->printList();
    int k;
    cin >> k;
    myList->deleteNode(k);
    myList->printList();
    return 0;
}