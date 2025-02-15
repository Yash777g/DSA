#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bfsTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == nullptr) {
            cout << endl;
            if(!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->val << " ";
            if(temp->left) {
                q.push(temp->left);
            } if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void solve(vector<string>& result, TreeNode* root, string path) {
    if(root->left == nullptr && root->right == nullptr) {
        path += to_string(root->val);
        
        result.push_back(path);
        return ;
    }

    path += to_string(root->val);
    path += "->";

    if(root->left) 
        solve(result, root->left, path);
    if(root->right) 
        solve(result, root->right, path);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    string path = "";

    solve(result, root, path);
    return result;
}

int main() {
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(3);

    TreeNode* node3 = new TreeNode(2, nullptr, node1);
    TreeNode* root = new TreeNode(1, node3, node2);

    bfsTraversal(root);

    vector<string> ans = binaryTreePaths(root);

    for(auto i : ans) {
        cout << i << endl;
    }
    return 0;
}