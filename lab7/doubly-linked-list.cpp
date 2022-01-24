#include <iostream>
using namespace std;

// special cases = empty list, one node list, operation on first(head) node when
// nodes > 1 case too, operation on last node case ( but this doesnot occur for
// insertAtBegin function for example )

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head = NULL;

// corner cases are: empty list, insertion at end
// but generally cross check for : empty list, 1 node list, insertion at beginning(not possible here),
// insertion at end, other cases according to problem.
void insertAfterGivenNode(int givenData, int reqData)
{
    if (head == NULL)
    {
        cout << "Error: No node exists so \"insert after given node\" function cannot work." << endl;
        return;
    }
    Node *temp = head;
    while (temp->data != givenData)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Error: Done linear searching of the given node data but not found." << endl;
            return;
        }
    }
    Node *newNode = new Node;
    newNode->data = reqData;
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void insertBeforeGivenNode(int givenData, int reqData)
{
    if (head == NULL)
    {
        // empty list case.
        cout << "Error: No node exists so \"insert after given node\" function cannot work." << endl;
        return;
    }
    Node *newNode = new Node;
    newNode->data = reqData;
    if (head->data == givenData)
    {
        // case when we want to insert at beginning.
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node *temp = head;

    while (temp->data != givenData)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Error: Done linear searching of the given node data but not found." << endl;
            return;
        }
    }
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}
void insertAtBegin(int data)
{
    Node *temp = new Node;
    temp->prev = NULL;
    temp->next = head;
    temp->data = data;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}
void insertAtEnd(int data)
{
    if (head == NULL)
    {
        insertAtBegin(data);
        return;
    }
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    Node *movingPtr = head;
    while (movingPtr->next != NULL)
    {
        movingPtr = movingPtr->next;
    }
    temp->prev = movingPtr;
    movingPtr->next = temp;
}
void printList()
{
    cout << "The list printed in forward order is: " << endl;
    Node *temp = head;
    if (head == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }
    while (temp != NULL)
    {
        // this ifelse is just for printing way ( i.e. not related to linked list )
        if (temp->next == NULL)
            cout << temp->data;
        else
            cout << temp->data << "<--->";
        temp = temp->next;
    }
    cout << endl;
}
void printReverseOrder()
{
    cout << "Printing In Reverse order: " << endl;
    if (head == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    Node *temp = head;
    // reaching last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // traversing back from last node using prev pointer
    while (temp->prev != NULL)
    {
        cout << temp->data << "<--->";
        temp = temp->prev;
    }
    cout << temp->data << endl;
    ;
}
void deleteANode(int index)
{
    // index is the node position where 0 == first(head) node

    // case for empty list
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        // for only one node case
        if (index == 0)
        {
            delete head;
            head = NULL;
        }
        return;
    }

    // case for index = 0 when we need to manipulate head pointer too.
    if (index == 0)
    {
        Node *temp = head;
        head->next->prev = NULL;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL or temp->next == NULL)
        {
            // case when input index is greater than numberofnodes-1
            return;
        }
    }
    Node *tempPtr = temp->next;
    temp->next = temp->next->next;
    if (tempPtr->next == NULL)
    {
        // this block executes if we try to delete the "last node",after
        // which there is no next node whose "prev" pointer we can modify.
    }
    else
    {
        tempPtr->next->prev = tempPtr->prev;
    }
    delete tempPtr;
}
    
void insertAtNthPos(int index, int data)
{

    if (index == 0)
    {
        insertAtBegin(data);
    }

    Node *newNode = new Node;
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        if (temp == NULL)
        {
            // case when given input index is more than number of nodes
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        insertAtEnd(data);
    }
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
}

int main()
{
    cout << "Welcome to doubly linked list" << endl;
    int num, size;
    char ch = 'y';
    cout << "Enter size of the list: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter data[" << i << "]: ";
        cin >> num;
        insertAtEnd(num);
    }
    printList();

    cout << "Want to insert at beginning? (y/n)" << endl;
    cin >> ch;
    while (ch == 'y')
    {
        cout << "Insert a node at beginning: (Enter data) " << endl;
        cin >> num;
        insertAtBegin(num);
        cout << "Again? (y/n)" << endl;
        cin >> ch;
    }
    printList();
    printReverseOrder();

    cout << "Want to delete a node ? (y/n)" << endl;
    cin >> ch;
    int index;
    while (ch == 'y')
    {
        cout << "Delete a node: (Enter index, 0 = first (head node) and so on )" << endl;
        cin >> index;
        deleteANode(index);
        printList();
        cout << "Again? (y/n)" << endl;
        cin >> ch;
    }
    cout << "Want to insert at any position? (y/n)" << endl;
    cin >> ch;
    int data;
    while (ch == 'y')
    {
        cout << "Insert a node and data at an index : (where 0 = new node will be at first node and so on ) " << endl;
        cin >> index >> data;
        insertAtNthPos(index, data);
        printList();
        cout << "Again? (y/n)" << endl;
        cin >> ch;
    }

    return 0;
}
