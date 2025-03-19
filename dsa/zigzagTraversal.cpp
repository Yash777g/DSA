#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;

    while(!q.empty()) {
        int size = q.size();
        deque<int> temp;

        for(int i = 0; i < size; i++) {
            TreeNode* data = q.front();
            q.pop();

            if(flag) { temp.push_back(data->val); }
            else { temp.push_front(data->val); }

            if(data->left) {
                q.push(data->left);
            } if(data->right) {
                q.push(data->right);
            }
        }

        flag = !flag;
        ans.push_back(vector<int>(temp.begin(), temp.end()));
    }

    return ans;
}

int main() {
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node3, node5);
    TreeNode* node9 = new TreeNode(9, nullptr, node7);
    TreeNode* root = new TreeNode(4, node2, node9);

    print(root);

    zigzagLevelOrder(root);
    return 0;
}