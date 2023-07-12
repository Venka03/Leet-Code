/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ln = new ListNode();
        ListNode *begin = ln;
        ListNode *tmp = new ListNode();
        ln->val = l1->val + l2->val;
        tmp->val = ln->val / 10;
        ln->val %= 10;
        while (l1->next && l2->next){
            ln->next = tmp;
            ln = ln->next;
            l1 = l1->next;
            l2 = l2->next;
            tmp = new ListNode();
            ln->val += l1->val + l2->val;
            tmp->val = ln->val / 10;
            ln->val %= 10;
        }
        if (l1->next){
            ln->next = tmp;
            ln = ln->next;
            l1 = l1->next;
            ln->val += l1->val;
            tmp = new ListNode();
            tmp->val = ln->val / 10;
            ln->val %= 10;
            while (l1->next){
                ln->next = tmp;
                ln = ln->next;
                l1 = l1->next;
                tmp = new ListNode();
                ln->val += l1->val;
                tmp->val = ln->val / 10;
                ln->val %= 10;
            }
        }
        else if (l2->next){
            ln->next = tmp;
            ln = ln->next;
            l2 = l2->next;
            ln->val += l2->val;
            tmp = new ListNode();
            tmp->val = ln->val / 10;
            ln->val %= 10;
            while (l2->next){
                ln->next = tmp;
                ln = ln->next;
                l2 = l2->next;
                tmp = new ListNode();
                ln->val += l2->val;
                tmp->val = ln->val / 10;
                ln->val %= 10;
            }
        }
        if (tmp->val)
            ln->next = tmp;
        return begin;
    }
};

int main(){
    {
        ListNode *three = new ListNode(3);
        ListNode *two = new ListNode(4, three);
        ListNode *one = new ListNode(2, two);
        ListNode *three1 = new ListNode(4);
        ListNode *two1 = new ListNode(6, three1);
        ListNode *one1 = new ListNode(5, two1);
        ListNode *sol = Solution::addTwoNumbers(one, one1);
        cout << sol->val << ' ';
        while (sol->next){
            sol = sol->next;
            cout << sol->val << ' ';
        }
        cout << endl;
    }
    {
        ListNode *one = new ListNode(0);
        ListNode *one1 = new ListNode(0);
        ListNode *sol = Solution::addTwoNumbers(one, one1);
        cout << sol->val << ' ';
        while (sol->next){
            sol = sol->next;
            cout << sol->val << ' ';
        }
        cout << endl;
    }
    {
        ListNode *seven = new ListNode(9);
        ListNode *six = new ListNode(9, seven);
        ListNode *five = new ListNode(9, six);
        ListNode *four = new ListNode(9, five);
        ListNode *three = new ListNode(9, four);
        ListNode *two = new ListNode(9, three);
        ListNode *one = new ListNode(9, two);

        ListNode *four1 = new ListNode(9);
        ListNode *three1 = new ListNode(9, four1);
        ListNode *two1 = new ListNode(9, three1);
        ListNode *one1 = new ListNode(9, two1);

        ListNode *sol = Solution::addTwoNumbers(one, one1);
        cout << sol->val << ' ';
        while (sol->next){
            sol = sol->next;
            cout << sol->val << ' ';
        }
        cout << endl;
    }
}