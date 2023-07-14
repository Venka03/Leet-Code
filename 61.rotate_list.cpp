/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/
#include <iostream>
#include <vector>

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
    static ListNode* rotateRight(ListNode* head, int k) {
        if (head){
            ListNode* tmp = head;
            vector<int> vals;
            vals.push_back(tmp->val);
            while (tmp->next){
                tmp = tmp->next;
                vals.push_back(tmp->val);
            }
            tmp->next = head;
            k %= vals.size();
            tmp = head;
            for (int i=0; i<k; i++){
                tmp = tmp->next;
            }
            for (int i=0; i<vals.size(); i++){
                tmp->val = vals[i];
                tmp = tmp->next;
            }
            tmp = head;
            for (int i=0; i<vals.size()-1; i++)
                tmp = tmp->next;
            tmp->next = nullptr;
        }
        return head;
    }
};

int main(){
    {
        ListNode *five = new ListNode(5);
        ListNode *four = new ListNode(4, five);
        ListNode *three = new ListNode(3, four);
        ListNode *two = new ListNode(2, three);
        ListNode *one = new ListNode(1, two);
        ListNode* tmp = one;
        cout << "Before rotation: \n" << tmp->val << ' ';
        while (tmp->next){
            tmp = tmp->next;
            cout << tmp->val << ' ';
        }
        cout << endl;

        tmp = Solution::rotateRight(one, 2);
        cout << "After rotation by 2: \n" << tmp->val << ' ';
        while (tmp->next){
            tmp = tmp->next;
            cout << tmp->val << ' ';
        }
        cout << endl;
    }
    {
        ListNode *three = new ListNode(2);
        ListNode *two = new ListNode(1, three);
        ListNode *one = new ListNode(0, two);
        ListNode* tmp = one;
        cout << "Before rotation: \n" << tmp->val << ' ';
        while (tmp->next){
            tmp = tmp->next;
            cout << tmp->val << ' ';
        }
        cout << endl;

        tmp = Solution::rotateRight(one, 4);
        cout << "After rotation by 4: \n" << tmp->val << ' ';
        while (tmp->next){
            tmp = tmp->next;
            cout << tmp->val << ' ';
        }
        cout << endl;
    }
    return 0;
}
