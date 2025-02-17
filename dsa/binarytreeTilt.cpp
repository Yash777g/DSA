#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* root) {
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
    } cout << endl;
}

int computeTilt(TreeNode* root, int& totalTilt) {
    if (!root) return 0;

    int leftSum = computeTilt(root->left, totalTilt);
    int rightSum = computeTilt(root->right, totalTilt);

    totalTilt += abs(leftSum - rightSum);
    return root->val + leftSum + rightSum;
}

int findTilt(TreeNode* root) {
    int totalTilt = 0;
    computeTilt(root, totalTilt);
    return totalTilt;
}


int main() {
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node3, node5);
    TreeNode* node9 = new TreeNode(9, nullptr, node7);
    TreeNode* root = new TreeNode(4, node2, node9);

    print(root);

    cout << findTilt(root);
    return 0;
}