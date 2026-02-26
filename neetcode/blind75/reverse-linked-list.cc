#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ListNode *head = new ListNode(0);
    ListNode *second = new ListNode(1);
    ListNode *third = new ListNode(2);
    ListNode *fourth = new ListNode(3);

    head->next = second;
    second->next = third;
    third->next = fourth;

    ListNode *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    head = reverseList(head);

    temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}