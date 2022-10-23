#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    Node() {
        data = -1;
        left = NULL;
        right = NULL;
    }

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *createRoot(Node *root, int data) {
        root->data = data;
        root->left = root->right = NULL;
        cout << "The value of root is now " << root->data << endl;
        return root;
}

Node *insertNode(Node *root,int data) {
    if (root == NULL) {
        Node *newNode = new Node(data);
        return newNode;
    } 
    if (data > root->data) {
        root->right = insertNode(root->right,data);  
    } else {
        root->left = insertNode(root->left,data);  
    } 
    return root;
}

Node *minValue(Node *root) {
    Node *temp = root;
    while(temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root) {
    Node *temp = root;
    while(temp && temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

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
        Node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool searchNode(Node *root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;

    bool leftSubtree = searchNode(root->left, data);
    if(leftSubtree) return true;
 
    bool rightSubtree = searchNode(root->right, data);
    return rightSubtree;
}


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