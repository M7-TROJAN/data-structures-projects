#pragma once
#include <iostream>

template <class T>
class clsDblLinkedList
{

protected:
    int _Size = 0;

public:
    class Node
    {
    public:
        T value;
        Node *next;
        Node *prev;
    };

    Node *head = nullptr;

    void InsertAtBeginning(int value)
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;

        _Size++;
    }

    // Function to insert a node at the end of the linked list
    void InsertAtEnd(T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        // If the list is empty, set the new node as the head
        if (head == nullptr)
        {
            head = newNode;
            _Size++;
            return;
        }

        Node *lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
        newNode->prev = lastNode;

        _Size++;
    }

    // Insert a node after a given node
    void InsertAfter(Node *current, T value)
    {
        if (current == nullptr)
        {
            return;
        }

        // Allocate memory for the new node
        Node *new_node = new Node();

        new_node->value = value;
        new_node->next = current->next;
        new_node->prev = current;

        if (current->next != nullptr)
        {
            current->next->prev = new_node;
        }
        current->next = new_node;

        _Size++;
    }

    Node *Find(T target)
    {
        Node *Current = head;
        while (Current != nullptr)
        {
            if (Current->value == target)
            {
                return Current;
            }

            Current = Current->next;
        }

        return nullptr;
    }

    // Delete a specific node
    void DeleteNode(Node *&NodeToDelete)
    {
        if (head == nullptr || NodeToDelete == nullptr)
            return;

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != nullptr)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != nullptr)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;

        _Size--;
    }

    // Delete a node with a specific value
    void DeleteNodeWithValue(int value)
    {
        if (head == nullptr)
            return;

        if (head->value == value)
        {
            Node *nodeToDelete = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete nodeToDelete;
            _Size--;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->value != value)
        {
            currentNode = currentNode->next;
        }

        if (currentNode->next != nullptr)
        {
            Node *nodeToDelete = currentNode->next;
            currentNode->next = nodeToDelete->next;
            if (nodeToDelete->next != nullptr)
            {
                nodeToDelete->next->prev = currentNode;
            }
            delete nodeToDelete;
            _Size--;
        }
    }

    // Delete the first node of the linked list
    void DeleteFirstNode()
    {
        if (head == nullptr)
        {
            return; // Linked list is empty, nothing to delete
        }

        Node *nodeToDelete = head;

        if (head->next != nullptr)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
        {
            head = nullptr; // Linked list had only one node, set head to nullptr
        }

        delete nodeToDelete;

        _Size--;
    }

    // Delete the Last node of the linked list
    void DeleteLastNode()
    {
        if (head == nullptr)
            return; // Linked list is empty, nothing to delete

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            _Size--;
            return; // Linked list had only one node, set head to nullptr
        }

        Node *prevNode = head;
        Node *LastNode = head;

        while (LastNode->next != nullptr)
        {
            prevNode = LastNode;
            LastNode = LastNode->next;
        }
        //                 1   2   3   4
        // LastNode                    |
        // prevNode                |

        prevNode->next = nullptr;

        delete LastNode;

        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return head == nullptr;
        // or
        return _Size == 0;
    }

    // Clear the entire linked list
    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    // Reverse the order of the list
    void Reverse()
    {
        // Start from the head node
        Node *current = head;
        Node *temp = nullptr;

        // Traverse through the linked list
        while (current != nullptr)
        {
            // Store the previous node address (before modification)
            temp = current->prev;

            // Reverse the prev and next pointers of the current node
            current->prev = current->next;
            current->next = temp;

            // Move to the previous node (prepare for the next step)
            current = current->prev;
        }

        // After the loop, if temp is not nullptr,
        // update the head pointer to the new head of the reversed list
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    Node *GetNode(const int &index)
    {
        int counter = 0;

        // Check if the index is out of range
        if (index < 0 || index >= _Size)
        {
            return nullptr;
        }

        Node *current = head;

        // Traverse through the linked list to find the node at the specified index
        while (current != nullptr && counter < index)
        {
            current = current->next;
            counter++;
        }

        return current;
    }


    T GetItem(int Index)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;
    }

    bool UpdateItem(const int &index, T newValue)
    {
        // Get the target node at the specified index
        Node *targetNode = GetNode(index);

        // If the target node exists, update its value
        if (targetNode != nullptr)
        {
            targetNode->value = newValue;
            return true;
        }

        return false;
    }

    // Insert a node after a node at a specific index
    bool InsertAfter(const int &index, T value)
    {
        // Get the target node at the specified index
        Node *targetNode = GetNode(index);

        // check If the target node exists
        if (targetNode != nullptr)
        {
            InsertAfter(targetNode, value);
            return true;
        }
        return false;
    }

    // Print the linked list
    void PrintList()

    {
        Node *Current = head;

        while (Current != NULL)
        {
            std::cout << Current->value << " ";
            Current = Current->next;
        }
        std::cout << "\n";

        // no need to delete 'current' cause it is in stack not heap
        // delete Current;
    }
};
