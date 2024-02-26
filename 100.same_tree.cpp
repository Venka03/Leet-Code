#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    static bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p && q || p && !q)
            return false;
        if (p->val != q->val)
            return false;
        if (!p->left && q->left || p->left && !q->left || !p->right && q->right || p->right && !q->right)
            return false;
        if (!(p->left || q->left || p->right || q->right)) // if all children are nullptr, nodes are equal
            return true;
        if (!(p->left || q->left))
            return isSameTree(p->right, q->right);
        if (!(p->right || q->right))
            return isSameTree(p->left, q->left);
        return p->left->val == q->left->val && p->right->val == q->right->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main(){
    if (Solution::isSameTree(new TreeNode(1, new TreeNode(2), new TreeNode(3)), new TreeNode(1, new TreeNode(2), new TreeNode(3))))
        cout << "Trees are the same" << endl;
    else
        cout << "Trees are not the same" << endl;
    if (Solution::isSameTree(new TreeNode(1, new TreeNode(2), nullptr), new TreeNode(1, nullptr, new TreeNode(2))))
        cout << "Trees are the same" << endl;
    else
        cout << "Trees are not the same" << endl;
    if (Solution::isSameTree(new TreeNode(1, new TreeNode(2), new TreeNode(1)), new TreeNode(1, new TreeNode(1), new TreeNode(2))))
        cout << "Trees are the same" << endl;
    else
        cout << "Trees are not the same" << endl;
    if (Solution::isSameTree(new TreeNode(), new TreeNode()))
        cout << "Trees are the same" << endl;
    else
        cout << "Trees are not the same" << endl;
}
