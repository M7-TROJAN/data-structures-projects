#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

void PrintNodeDetails(clsDblLinkedList<int>::Node *node)
{
    if (node->prev != nullptr)
    {
        cout << node->prev->value;
    }
    else
    {
        cout << "NULL";
    }

    cout << " <--> " << node->value << " <--> ";

    if (node->next != nullptr)
    {
        cout << node->next->value << "\n";
    }
    else
    {
        cout << "NULL\n";
    }
}

int main()
{
    clsDblLinkedList<int> MyDblLinkedList;

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    cout << "\nLinked List Content:\n";
    MyDblLinkedList.PrintList();

    clsDblLinkedList<int>::Node *N1 = MyDblLinkedList.Find(2);

    if (N1 != NULL)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not found :-(\n";

    MyDblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    MyDblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    clsDblLinkedList<int>::Node *N2 = MyDblLinkedList.Find(4);
    MyDblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    MyDblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    cout << "\nAfter Deleting Last Node:\n";
    MyDblLinkedList.DeleteLastNode();
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    cout << "\nAfter Deleting The Node with value 500:\n";
    MyDblLinkedList.DeleteNodeWithValue(500);
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    MyDblLinkedList.Clear();
    MyDblLinkedList.PrintList();
    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    MyDblLinkedList.InsertAtBeginning(20);

    MyDblLinkedList.PrintList();
    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";

    MyDblLinkedList.Reverse();

    MyDblLinkedList.PrintList();
    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << "\n";
    MyDblLinkedList.PrintList();

    clsDblLinkedList<int>::Node *N3 = MyDblLinkedList.GetNode(0);

    if(N3)
        cout << N3->value << endl;

    MyDblLinkedList.InsertAtBeginning(1);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(4);

    MyDblLinkedList.PrintList();

    MyDblLinkedList.UpdateItems(2,780);
    MyDblLinkedList.PrintList();

    // PrintNodeDetails(N3);
}