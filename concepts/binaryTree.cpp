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

int main() {
    Treenode *root = nullptr;
    root = addNode(root);

    bfsTraversal(root);
    return 0;
}