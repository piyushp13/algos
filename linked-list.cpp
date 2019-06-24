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

    void printList(Node* head) {
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
        Node *prevEle = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            head = curr->next;
            curr->next = prevEle;
            prevEle = curr;
            curr = head;
        }
        head = prevEle;
    }

    void deleteNode(int k)
    {
        Node *headRef = head;
        int index = k;
        while (--k > 1)
        {
            head = head->next;
        }
        Node *temp = head->next;
        if (temp != NULL)
        {
            head->next = temp->next;
            if (index == 1)
            {
                head->data = temp->data;
            }
            free(temp);
            head = headRef;
        }
        else
        {
            head = NULL;
        }
        return;
    }

    Node* sortedMerge(Node *head2)
    {
        Node* curr = (Node*)malloc(sizeof(Node));
        if (head->data < head2->data) {
            curr->data = head->data;
            head = head->next;
        } else {
            curr->data = head2->data;
            head2 = head2->next;
        }
        Node* newHead = curr;
        while (head != NULL && head2 != NULL)
        {
            if (head->data < head2->data)
            {
                curr->next = head;
                head = head->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        if (head != NULL) {
            curr->next = head;
        } else if (head2 != NULL) {
            curr->next = head2;
        }
        head = newHead;
        return newHead;
    }
};

int main()
{
    cout << "Enter n and m" << endl;
    int n, m;
    cin >> n >> m;
    cout << "Enter first list" << endl;
    int firstElement;
    cin >> firstElement;
    Node *myList1 = new Node(firstElement);
    for (int i = 0; i < n - 1; i++)
    {
        int num;
        cin >> num;
        myList1->insertAtEnd(num);
    }
    cout << "Enter second list" << endl;
    cin >> firstElement;
    Node *myList2 = new Node(firstElement);
    for (int i = 0; i < m - 1; i++)
    {
        int num;
        cin >> num;
        myList2->insertAtEnd(num);
    }
    myList1->printList();
    myList2->printList();
    myList1->sortedMerge(myList2->head);
    myList1->printList();
    // myList1->reverseList();
    // myList1->printList();
    // int k;
    // cin >> k;
    // myList1->deleteNode(k);
    // myList1->printList();
    return 0;
}