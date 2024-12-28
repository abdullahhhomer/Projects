#include <iostream>

using namespace std;




//The code defines a Node class and an AVLTree class that implements an AVL tree data structure.
//The Node class represents a node in the AVL tree, and contains fields for the node's unique id, 
//the number of duplicates of this node, the score associated with the node, the height of the node in the AVL tree, 
//and pointers to the node's left and right children. 
//The AVLTree class represents the AVL tree data structure, and contains a pointer to the root node of the tree.
//The AVLTree class provides functions for inserting nodes into the tree, deleting nodes from the tree, 
//searching for nodes in the tree, and printing the contents of the tree in sorted order.



// Node class definition
class Node {
public:
    int id; // unique id of the node
    int count; // number of duplicates of this node
    int score; // score associated with the node
    int height; // height of the node in the AVL tree
    Node* left; // pointer to the left child of the node
    Node* right; // pointer to the right child of the node

    // Constructor for the Node class
    Node(int id, int score) {
        this->id = id;
        this->count = 1;
        this->score = score;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// AVL tree class definition
class AVLTree {
public:
    Node* root; // pointer to the root node of the AVL tree

    // Constructor for the AVLTree class
    AVLTree(int score) {


        this->root = new Node(100, score);   // initialize the root node with id 100 and the given score
    }

    // Utility function to get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // Utility function to get the balance factor of a node
    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Utility function to update the height of a node
    void updateHeight(Node* node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // Utility function to perform left rotation on a node
    Node* rotateLeft(Node* node) {
        Node* newParent = node->right;
        node->right = newParent->left;
        newParent->left = node;
        updateHeight(node);
        updateHeight(newParent);
        return newParent;
    }

    // Utility function to perform right rotation on a node
    Node* rotateRight(Node* node) {
        Node* newParent = node->left;
        node->left = newParent->right;
        newParent->right = node;
        updateHeight(node);
        updateHeight(newParent);
        return newParent;
    }

    // Utility function to balance a node
    Node* balance(Node* node) {
        int bf = getBalanceFactor(node);
        if (bf > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        else if (bf < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    // Utility function to insert a node recursively
    Node* insertRecursive(Node* node, int id, int score) {
        if (node == nullptr) {
            return new Node(id, score);
        }
        if (id < node->id) {
            node->left = insertRecursive(node->left, id, score);
        }
        else if (id > node->id) {
            node->right = insertRecursive(node->right, id, score);
        }
        else {
            node->count++;
        }
        updateHeight(node);
        return balance(node);
    }

    // Function to insert a node into the AVL tree
    void insert(int score) {

        srand(time(NULL));
        int ID = rand() % 201;

        this->root = insertRecursive(this->root, ID, score);
    }

    // Utility function to find the node with the minimum id
    Node* findMin(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node;
        }
        return findMin(node->left);
    }

    // Utility function to delete a node recursively
    Node* deleteRecursive(Node* node, int id) {
        if (node == nullptr) {
            return nullptr;
        }
        if (id < node->id) {
            node->left = deleteRecursive(node->left, id);
        }
        else if (id > node->id) {
            node->right = deleteRecursive(node->right, id);
        }
        else {
            if (node->count > 1) {
                node->count--;
            }
            else {
                if (node->left == nullptr && node->right == nullptr) {
                    delete node;
                    return nullptr;
                }
                else if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                else {
                    Node* minRight = findMin(node->right);
                    node->id = minRight->id;
                    node->count = minRight->count;
                    node->score = minRight->score;
                    node->right = deleteRecursive(node->right, minRight->id);
                }
            }
        }
        updateHeight(node);
        return balance(node);
    }

    // Function to delete a node from the AVL tree
    void remove(int id) {
        cout << "Deleting node with id " << id << " if present" << endl;
        this->root = deleteRecursive(this->root, id);
    }

    // Utility function to search for a node recursively
    Node* searchRecursive(Node* node, int id) {
        if (node == nullptr) {
            return nullptr;
        }
        if (id < node->id) {
            return searchRecursive(node->left, id);
        }
        else if (id > node->id) {
            return searchRecursive(node->right, id);
        }
        else {
            return node;
        }
    }

    // Function to search for a node in the AVL tree
    Node* search(int id) {
        return searchRecursive(this->root, id);
    }

    // Utility function to perform an inorder traversal of the AVL tree
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->id << " " << node->count << " " << node->score << endl;
            inorderTraversal(node->right);
        }
    }

    // Function to print the contents of the AVL tree in sorted order
    void print() {
        cout << "Printing the contents of the AVL tree in sorted order:" << endl;
        inorderTraversal(this->root);
    }


    // Utility function to delete a node with the given score recursively
    Node* deleteByScoreRecursive(Node* node, int score) {
        if (node == nullptr) {
            return nullptr;
        }
        if (score < node->score) { // if the score to be deleted is less than the score of the current node, go left
            node->left = deleteByScoreRecursive(node->left, score);
        }
        else if (score > node->score) { // if the score to be deleted is greater than the score of the current node, go right
            node->right = deleteByScoreRecursive(node->right, score);
        }
        else { // if the scores match
            if (node->count > 1) { // if there are multiple nodes with the same score, decrement the count
                node->count--;
            }
            else { // if this is the only node with this score
                if (node->left == nullptr && node->right == nullptr) { // if the node has no children
                    delete node; // simply delete the node
                    return nullptr;
                }
                else if (node->left == nullptr) { // if the node has only a right child
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if (node->right == nullptr) { // if the node has only a left child
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                else { // if the node has both left and right children
                    Node* minRight = findMin(node->right); // find the minimum node in the right subtree
                    node->id = minRight->id; // copy the id, count, and score of the minimum node to the node to be deleted
                    node->count = minRight->count;
                    node->score = minRight->score;
                    node->right = deleteRecursive(node->right, minRight->id); // delete the minimum node from the right subtree
                }
            }
        }
        updateHeight(node); // update the height of the current node
        return balance(node); // balance the tree
    }

    // Function to delete a node with the given score from the AVL tree
    void deleteByScore(int score) {
        cout << "Deleting node with score " << score << " if present" << endl;
        this->root = deleteByScoreRecursive(this->root, score); // call the recursive delete function starting from the root
    }


    // Destructor
    ~AVLTree() {
        if (this->root != nullptr)
            deleteSubtree(this->root);
    }

    // Utility function to delete the subtree rooted at a given node
    void deleteSubtree(Node* node) {
        if (node != nullptr) {
            deleteSubtree(node->left);
            deleteSubtree(node->right);
            delete node;
        }
    }

    int sumScores(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return (node->count * node->score) + sumScores(node->left) + sumScores(node->right);
    }



};

//// Main function to test the AVL tree implementation
//int main() {
//    AVLTree tree(50); // create an AVL tree with root score 50
//    tree.insert(200, 20); // insert nodes with id 200 and score 20
//    tree.insert(300, 30); // insert nodes with id 300 and score 30
//    tree.insert(150, 40); // insert nodes with id 150 and score 40
//    tree.insert(100, 10); // insert nodes with id 100 and score 10
//    tree.print(); // print the contents of the AVL tree in sorted order
//    tree.remove(150); // remove the node with id 150
//    tree.print(); // print the contents of the AVL tree in sorted order
//    Node* node = tree.search(100); // search for the node with id 100
//    if (node != nullptr) {
//        cout << "Found node with id " << node->id << " and score " << node->score << endl;
//    }
//    else {
//        cout << "Node with id 100 not found" << endl;
//    }
//    return 0;
//}