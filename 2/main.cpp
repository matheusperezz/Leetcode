//
// Created by mdperez on 6/26/25.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
            int x = (l1 ? l1->val : 0);
            int y = (l2 ? l2->val : 0);
            int sum = x + y + carry;

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2 -> next;
        }
        return dummy.next;
    }
};

ListNode* buildList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

/* Prints list values */
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> first = {9};
    vector<int> second = {1,9,9,9,9,9,9,9,9,9};

    ListNode* l1 = buildList(first);
    ListNode* l2 = buildList(second);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    printList(result);
    return 0;
}
