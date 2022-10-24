#include <iostream>
using namespace std;

// creating a class to manage a node of the bst
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    // this is the default constrcutor, we give it some default data when initialising without any parameters
    Node() {
        data = -1;
        left = NULL;
        right = NULL;
    }

    // the parameterised constructor
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// creating the binary search tree or rather the root of the tree
Node *createRoot(Node *root, int data) {
        root->data = data;
        root->left = root->right = NULL;
        cout << "The value of root is now " << root->data << endl;
        return root;
}

// insertion of any node in the tree
Node *insertNode(Node *root,int data) {
    if (root == NULL) {
        Node *newNode = new Node(data);
        return newNode;
    } 
    // checking basic bst conditions
    if (data > root->data) {
        root->right = insertNode(root->right,data);  
    } else {
        root->left = insertNode(root->left,data);  
    } 
    return root;
}

// getting the smallest value in the tree
Node *minValue(Node *root) {
    Node *temp = root;
    while(temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// getting the largest value in the tree
Node *maxValue(Node *root) {
    Node *temp = root;
    while(temp && temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

// deleting a node in the tree
    Node *deleteNode(Node *root, int data) {
        if (root == NULL) return root;
        if (data > root->data) {
            root->right = deleteNode(root->right,data);
        } else if (data < root->data) {
            root->left = deleteNode(root->left,data);
        } else {
            if (root->right == NULL) {
                Node *temp = root->left;
                free(root);
                return temp;
            } else if (root ->left == NULL) {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            // whenever we delete a node with two children,
            // the smallest value from its right subtree is used to replace it
            Node *temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // looking whether a node exists in the bst
    bool searchNode(Node *root, int data) {
        if (root == NULL) return false;
        if (root->data == data) return true;

        bool leftSubtree = searchNode(root->left, data);
        if(leftSubtree) return true;
    
        bool rightSubtree = searchNode(root->right, data);
        return rightSubtree;
    }

    //  All three traversals
    void inorderTraversal(Node *root) {
        if (root != NULL) {
            inorderTraversal(root->left);
            cout << root->data << " -> ";
            inorderTraversal(root->right); 
        }
    }

    void postorderTraversal(Node *root) {
        if (root != NULL) {
            postorderTraversal(root->left);
            postorderTraversal(root->right); 
            cout << root->data << " -> ";
        }
    }

    void preorderTraversal(Node *root) {
        if (root != NULL) {
            cout << root->data << " -> ";
            preorderTraversal(root->left);
            preorderTraversal(root->right); 
        }
    }

// writing some basic driver code to make the code interactive and menu driven
int main() {
    Node *root = new Node();
    int rootData;
    cout << "Enter the value of the root node of the tree: " << endl;
    cin >> rootData;
    int choice;
    root = createRoot(root, rootData);
    while (true) {
        cout << "1 -> Insert Element" << endl;
        cout << "2 -> Delete Element" << endl;
        cout << "3 -> Minimum Value" << endl;
        cout << "4 -> Maximum Value" << endl;
        cout << "5 -> Search Element" << endl;
        cout << "6 -> Inorder Traversal" << endl;
        cout << "7 -> Postorder traversal" << endl;
        cout << "8 -> Preorder Traversal" << endl;
        cout << "-1 -> Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {

                int data;
                cout << "Enter the data to be inserted into the tree: " << endl;
                cin >> data;
                root = insertNode(root, data);
                cout << "The value " << data << " has been inserted into the tree" << endl;
                continue;
            }
            case 2: {

                int data;
                cout << "Enter the data to be deleted from the tree: " << endl;
                cin >> data;
                root = deleteNode(root, data);
                cout << "The value " << data << " has been deleted from the tree" << endl;
                continue;
            }
            case 3: {

                Node *temp = new Node();
                temp = minValue(root);
                cout << "The smallest element in the tree is " << temp->data << endl;
                continue;
            }
            case 4: {

                Node *temp = new Node();
                temp = maxValue(root);
                cout << "The largest element in the tree is " << temp->data << endl;
                continue;
            }
            case 5: {
                int toBeSearched;
                cout << "Enter the element you want to search in the tree" << endl;
                cin >> toBeSearched;
                bool isPresent = searchNode(root, toBeSearched);
                string message1 = "Element is present in the tree";
                string message2 = "Element is not present in the tree";
                isPresent ? cout << message1 << endl : cout << message2 << endl;
                continue;
            }
            case 6: {
                cout << "The inorder traversal of the tree is: ";
                inorderTraversal(root);
                cout << endl;
                continue;
            }
            case 7:{
                cout << "The postorder traversal of the tree is: ";
                postorderTraversal(root);
                cout << endl;
                continue;
            }
            case 8: {
                cout << "The preorder traversal of the tree is: ";
                preorderTraversal(root);
                cout << endl;
                continue;
            }
            case -1: {
                cout << "Exiting...";
                break;
            }
        }
        break;
    }
    return 0;
}