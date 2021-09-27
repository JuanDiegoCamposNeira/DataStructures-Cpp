#include <bits/stdc++.h>

using namespace std;

//---------------------------------  Structures  ---------------------------------
// Single node struct
typedef struct Node
{
    // Atributes
    int value;
    Node *parent;
    Node *left;
    Node *right;

    // Constructor of a single node in the tree
    Node(int data) : value(data), left(NULL), parent(NULL), right(NULL) {}
} Node;
// Binary tree struct
typedef struct Binary_Tree
{
    // Atributes
    Node *root;

    // Constructor
    Binary_Tree() : root(NULL) {}

    //-------------------------  Insertion / Deletion  ------------------------
    // Insert recursively
    // Two options to insert a node recursively

    // THE FIRST option is just by returning "the path" that follows the algorithm when searching a free spot
    Node *insert_recursively_returning_path(Node *node, int value, Node *parent)
    {
        // Check if the node passed is null, this means that we found our correct spot
        if (node == NULL)
        {
            Node *insert = new Node(value); // Create the node
            insert->parent = parent;        // Assign the parent to the node
            node = insert;                  // Assign the new node to the parent
            return node;                    // Return the node
        }
        // If the node isn't null, means there are more nodes to look first
        else if (value < node->value) // If the value to insert is less than the value of the node, call recursively the function with the left sub-tree
            node->left = insert_recursively_returning_path(node->left, value, node);
        else if (value > node->value) // If the value to insert is gratter than the value of the node, call recursively the function with the right sub-tree
            node->right = insert_recursively_returning_path(node->right, value, node);
    }

    // THE SECOND option is NOT returning the path, and just search for a correct node and then adding it
    // if the spot is empty
    void insert_recursively_no_path_returning(Node *node, int value, Node *parent)
    {
        // If the root of the tree is empty, assign the node as the root
        if (root == NULL)
        {
            Node *node_to_insert = new Node(value);
            root = node_to_insert;
        }
        // If the tree or sub-tree already have a root, and the value of the new node is less than the root
        else if (value < node->value)
        {
            if (node->left == NULL)
            {
                Node *node_to_insert = new Node(value);
                node_to_insert->parent = parent;
                node->left = node_to_insert;
            }
            else
                insert_recursively_no_path_returning(node->left, value, node);
        }

        // If the value of the node to insert is grater than the value of the root
        else if (value > node->value)
        {
            if (node->right == NULL)
            {
                Node *node_to_insert = new Node(value);
                node_to_insert->parent = parent;
                node->right = node_to_insert;
            }
            else
                insert_recursively_no_path_returning(node->right, value, node);
        }
        // This return the root of the sub-tree
        // return root;
    }
    // Insert iteratively
    void insert_iteratively(Node *tree_root, int value)
    {
        Node *current = tree_root;
        Node *parent = NULL;
        // Search the node in the tree
        while (current != NULL)
        {
            parent = current;
            // If the value to insert is less than the current->value
            if (value < current->value)
                current = current->left;
            else // if (value > current->value)
                current = current->right;
        }

        // Create the new node
        Node *node_to_insert = new Node(value);
        node_to_insert->parent = parent;

        // Insert the node into the tree
        if (parent == NULL) // Tree is empty
            root = node_to_insert;

        // If the tree is not empty, add it to the parent node
        else if (value < parent->value)
            parent->left = node_to_insert;
        else if (value > parent->value)
            parent->right = node_to_insert;
    }

    //-------------------------------  Queries  -------------------------------
    Node *search(Node *node, int value)
    {
        // If the node is NULL, the searched value is not in the tree
        if (node == NULL)
            return NULL;
        // Otherwise, check if the searched value is the node itself
        if (node->value == value)
            return node;
        // If the value of the node doesn't match the value and the node isn't NULL,
        // call the function again passing the right or left child, following the constraints
        if (value < node->value) // If the value to search is less than the value of the node, the value should be in the left sub-tree
            search(node->left, value);
        else // Otherwise, means that the value to search is grater than the node value, so it means that the value should be in the right sub-tree
            search(node->right, value);
    }

    Node *minimun(Node *node)
    {
        // If the tree is empty, return
        if (node == NULL)
            return NULL;
        // Call the left child of the tree while it is different from NULL
        while (node->left != NULL)
            node = node->left;
        // When the loop is finished, the 'node' will holds the minimun element
        return node;
    }

    Node *maximum(Node *node)
    {
        // If the tree is empty, return
        if (node == NULL)
            return NULL;
        // Call the right element untill it gets to the last element in the right  sub-tree
        while (node->right != NULL)
            node = node->right;
        // When the loop has finished, 'node' will hold the maximum element in the tree
        return node;
    }

    //------------------------------  Traversals  -----------------------------
    // Inorder traversal
    void inorder(Node *node)
    {
        // Check that the node is not NULL
        if (node != NULL)
        {
            inorder(node->left);        // Call every left sub-tree untill a leaf
            cout << node->value << " "; // Print the value of the node
            cout << "Parent ";          // Print the parent of the node
            (node->parent != NULL) ? cout << node->parent->value << "\n" : cout << "NULL \n";
            inorder(node->right); // Call every right sub-tree
        }
        // If the node is NULL, don't do anything
    }
    // Preorder traversal
    void preorder(Node *node)
    {
        // Check if the passed node is NULL or not
        if (node != NULL)
        {
            cout << node->value << " "; // Print the value of the node before calling the sub-trees
            preorder(node->left);       // Call the left sub-tree
            preorder(node->right);      // Call the right sub-tree
        }
        // If the node is NULL (a leaf child) don't do anything
    }
    // Post order traversal
    void postorder(Node *node)
    {
        // Check if the node is NULL or not
        if (node != NULL)
        {
            postorder(node->left);      // Call the left sub-tree
            postorder(node->right);     // Call the right sub-tree
            cout << node->value << " "; // Print the value after calling all the nodes
        }
        // If the node is NULL, then is a leaf child, so, don't do anything
    }

} Binary_Tree;

// Main program to call the binary tree
int main()
{
    // Instance of the binary tree
    Binary_Tree binary_tree;
    // Falg for the program to stay running
    bool run = true;
    int option;
    int value;
    Node *min, *max, *search;

    while (run)
    {
        cout << "Option : \n";
        cout << "0. Quit \n";
        cout << "1. Add recursively with no path returned \n";
        cout << "11. Add recursively returning the path traversed\n";
        cout << "2. Add iteratively \n";
        cout << "3. Inorder \n";
        cout << "4. Preorder \n";
        cout << "5. Postorder \n";
        cout << "6. Search \n";
        cout << "7. Minimum \n";
        cout << "8. Maximun \n";
        cin >> option;

        switch (option)
        {
        case 0:
            run = false;
            break;
        case 1:
            cout << "Value to add recursively : ";
            cin >> value;
            binary_tree.insert_recursively_no_path_returning(binary_tree.root, value, NULL);
            break;

        case 11:
            cout << "Value to add recursively : ";
            cin >> value;
            binary_tree.root = binary_tree.insert_recursively_returning_path(binary_tree.root, value, NULL);
            break;

        case 2:
            cout << "Value to add iteratively : ";
            cin >> value;
            binary_tree.insert_iteratively(binary_tree.root, value);
            break;

        case 3:
            cout << "Inorder traversal : ";
            binary_tree.inorder(binary_tree.root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder traversal \n";
            binary_tree.preorder(binary_tree.root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder traversal : ";
            binary_tree.postorder(binary_tree.root);
            break;

        case 6:
            cout << "Value to search : ";
            cin >> value;
            search = binary_tree.search(binary_tree.root, value);
            break;

        case 7:
            cout << "Minimun : ";
            min = binary_tree.minimun(binary_tree.root);
            (min != NULL) ? cout << min->value << endl : cout << "The tree is empty \n";
            cout << endl;
            break;

        case 8:
            cout << "Maximun : ";
            max = binary_tree.maximum(binary_tree.root);
            (max != NULL) ? cout << max->value << endl : cout << "The tree is empty \n";
            cout << endl;
            break;

        default:
            break;
        }
    }

    // Add nodes to the tree
    /*
    cout << "Insert 12 : ";
    binary_tree.root = binary_tree.insert_recursively(binary_tree.root, 12, NULL);
    cout << endl;
    cout << "Insert 13 : ";
    binary_tree.root = binary_tree.insert_recursively(binary_tree.root, 13, NULL);
    cout << endl;
    cout << "Insert 11 : ";
    binary_tree.root = binary_tree.insert_recursively(binary_tree.root, 11, NULL);
    cout << endl;
    cout << "Insert 14 : ";
    binary_tree.root = binary_tree.insert_recursively(binary_tree.root, 14, NULL);
    cout << endl;
    cout << "Insert 10 : ";
    binary_tree.root = binary_tree.insert_recursively(binary_tree.root, 10, NULL);
    cout << endl;
    cout << "Insert 20 : ";
    binary_tree.insert_iteratively(binary_tree.root, 20);
    cout << endl;
    cout << "Inorder traversal : \n";
    binary_tree.inorder(binary_tree.root);
    cout << endl;
    cout << "Preorder traversal : ";
    binary_tree.preorder(binary_tree.root);
    cout << endl;
    cout << "Postorder traversal : ";
    binary_tree.postorder(binary_tree.root);
    cout << endl;
    */

    //Exits the program normally
    return (0);
}
