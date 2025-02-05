#include <iostream>
#include <queue>
using namespace std;

class Treenode{
    public:
        int data;
        Treenode* left;
        Treenode* right;

        Treenode(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        } 
};

// adding child node to parent node or root node.
Treenode* addNode(Treenode* root) {
    cout << "Enter data:";
    int data;
    cin >> data;

    root = new Treenode(data);
    if(data == -1) {
        return nullptr;
    }

    cout << "Enter left child node of " << root->data << ":" << endl;
    root->left = addNode(root->left);
    cout << "Enter right child node of " << root->data << ":" << endl;
    root->right = addNode(root->right);

    return root;
} 

// level order traversal or breadth first search
void bfsTraversal(Treenode* root) {
    queue<Treenode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        Treenode* temp = q.front();
        // for reverse level order traversal use stack
        // stack<int> reverse;
        q.pop();

        if(temp == nullptr) {
            cout << endl;
            if(!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            } 
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

// inorder traversal : L->left/N->node/R->right
void inorderTraversal(Treenode* root) {
    if(root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// pre-order traversal: N->node/L->left/R->right
void preorderTraversal(Treenode* root) {
    if(root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// post-order traversal: L->left/R->right/N->node
void postorderTraversal(Treenode* root) {
    if(root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Treenode *root = nullptr;
    root = addNode(root);

    cout << endl;
    bfsTraversal(root);

    cout << endl;
    inorderTraversal(root);

    cout << endl;
    preorderTraversal(root);

    cout << endl;
    postorderTraversal(root);
    return 0;
}