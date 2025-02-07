/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
*/
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
        if (!p || !q)
            return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
