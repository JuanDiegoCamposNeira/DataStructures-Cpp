/*----------------------------------------------------------------------------------------------
---------------------------------------- LINKED LIST  ------------------------------------------
----------------------------------------------------------------------------------------------*/

/*
    Linked list: Is basically a data structure to store elements where an element represents a node
                    where every node has a value an a pointer to the next element. 
                    Thre are various types of linked lists:
                        -Single linked list: has a pointer to the next value.
                        -Double linked list: has a pointer to the next value and the previous value.
                        -Circular linked list: has a circular representation, that is: the last element points 
                                               to the head of the list. 
*/

#include <bits/stdc++.h>

using namespace std;

/*
    Struct for a single node
*/
typedef struct Node
{
    // Attributes of a single Node
    int value;
    Node *next;

    // Constructor of the node
    Node(int data) : value(data), next(NULL){};
} Node;

/*
    Struct for the linked list
*/
typedef struct Linked_list
{
    // Attributes of a linked list
    Node *head, *tail;

    // Constructor of the linked list
    Linked_list() : head(NULL), tail(NULL){};

    // Methods
    bool addNode(Node *new_node)
    {
        // Fisrt check if the head/tail is empty
        if (head == nullptr || tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return true;
        }

        // Add the new node to the tail and convert the new node into the new tail
        if (tail != NULL)
        {
            tail->next = new_node;
            tail = new_node;
            return true;
        }

        // If nothing matched to this point, the node will not be inserted into the linked list
        return false;
    }

    bool delete_all_nodes()
    {
        // Check if the head/tail is empty
        if (head == NULL && tail == NULL)
        {
            cout << "There's nothing to delete\n";
            return true;
        }

        // Traverse the list and delete each node
        Node *current = head, *next;
        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
        // Dereference the head and the tail of the linked list
        head = tail = NULL;

        // Return success as the list is completelly deleted
        return true;
    }

    bool delete_node(int node_to_delete)
    {
        // Check if the list is empty
        if (head == NULL && tail == NULL)
        {
            cout << "Nothing to delete, because the list is empty\n";
            return true;
        }

        // Traverse the list in order to find the first occurance of the value passed
        Node *previous, *current = head, *next;
        previous = next = NULL;
        while (current != NULL)
        {
            // If the node is founded
            if (current->value == node_to_delete)
            {
                // Check if the node is the head (NO PREVIOUS NODE)
                if (previous == NULL)
                {
                    // If there's only one node in the list
                    if (head == tail)
                    {
                        delete head;
                        delete tail;
                        head = head = NULL;
                        return true;
                    }
                    // Otherwise there are more than one node
                    else
                    {
                        head = current->next;
                        delete current;
                        return true;
                    }
                }
                // Check if the node is the tail (NO NEXT NODE)
                else if (next == NULL)
                {
                    tail = previous;   // Set the tail to the previous element in the list
                    delete current;    // Delete the current Node
                    tail->next = NULL; // After deleing the node, set the next to NULL
                    return true;       // Return true when deleted the node
                }
                // Otherwise, the node is somewhere in the middle of the list
                else
                {
                    previous->next = next; // Assosiate the previous with the next node
                    delete current;        // Delete the current node of the list
                    return true;           // Return true when deleted the node
                }
            }
            previous = current;
            current = current->next;
            // If current is not the end of the list
            if (current != NULL)
                next = current->next;
            // If it is the tail of the list
            else
                next = NULL;
        }

        // If the algorithim gets to this point, there is no such node with the value that the user enter
        cout << "No node was found with that value\n";
        return false;
    }

    bool generate_list(int number_of_nodes)
    {
        // If the number passed is less than or equal to cero
        if (number_of_nodes <= 0)
        {
            cout << "Number not accepted \n";
            cout << "Range (1, INF) \n";
            return false;
        }
        // Otherwise make an array of nodes
        srand(time(NULL));
        for (int i = 1; i <= number_of_nodes; i++)
        {
            int value = rand() % 100 + 1; // Random value between 1 and 100
            Node *new_node = new Node(value);
            addNode(new_node);
        }
    }

    void print()
    {
        // In case the head/tail is null
        if (head == NULL || tail == NULL)
        {
            cout << "The list is empty\n";
            return;
        }

        // Otherwise traverse thru all the nodes and print its values
        Node *iterator = head;
        while (iterator != NULL)
        {
            cout << iterator->value << " -> ";
            iterator = iterator->next;
            if (iterator == NULL)
                cout << "NULL \n";
        }
    }
} Linked_list;

int main()
{
    // Start the single Linked list
    Linked_list linked_list;

    // Ask the user fon an action
    bool quit = false;
    char option;
    int node_value;
    do
    {
        cout << "Choose an option\n";
        cout << "A -> Add a node into the list\n";
        cout << "D -> Delete all the nodes of the list\n";
        cout << "N -> Delete one node of the list\n";
        cout << "G -> Generate a list with random numbers\n";
        cout << "P -> Print the elements in the list\n";
        cout << "Q -> Quit\n";

        cout << "$ ";
        cin >> option;

        // Evaluate the option of the user
        switch (tolower(option))
        {
        case 'a':
            Node *new_node;
            cout << "Assign node value : ";
            cin >> node_value;
            new_node = new Node(node_value);
            // Add the node to the linked list
            if (linked_list.addNode(new_node))
                cout << "Succsesfully added\n";
            else
                cout << "Error while trying to add the node\n";
            break;

        case 'd':
            if (linked_list.delete_all_nodes())
                cout << "Success deleting the list\n";
            else
                cout << "Could't delete all the nodes\n";

            break;

        case 'n':
            cout << "Node to delete : ";
            cin >> node_value;
            linked_list.delete_node(node_value);
            break;

        case 'g':
            cout << "Number of nodes you want to create ";
            cin >> node_value;
            linked_list.generate_list(node_value);
            break;

        case 'p':
            linked_list.print();
            break;

        case 'q':
            if (linked_list.delete_all_nodes())
                cout << "Success deleting the list\n";
            else
                cout << "Could't delete all the nodes\n";

            quit = true;
            break;

        default:
            cout << "No valid option, try again\n";
            break;
        }

    } while (!quit);

    // Exit succesfully
    return (0);
}