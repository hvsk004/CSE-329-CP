#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
int findLength(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *findIntersection(Node *head1, Node *head2, int l1, int l2)
{
    if (l1 > l2)
    {
        int diff = l1 - l2;
        while (diff--)
        {
            head1 = head1->next;
        }
    }
    else if (l2 > l1)
    {
        int diff = l2 - l1;
        while (diff--)
        {
            head2 = head2->next;
        }
    }
    while (head1 != nullptr || head2 != nullptr)
    {
        head1 = head1->next;
        head2 = head2->next;
        if (head1 == head2)
        {
            return head1;
        }
    }
    return nullptr;
}
int main()
{
    Node *head1 = new Node(1);
    Node *head2 = new Node(10);
    Node *x = new Node(5);
    x->next = new Node(6);
    x->next->next = new Node(7);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(100);
    head1->next->next->next->next->next = x;
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);
    head2->next->next->next->next = x;
    int l1 = findLength(head1);
    int l2 = findLength(head2);
    Node *intersection = findIntersection(head1, head2, l1, l2);
    if (intersection != nullptr)
    {
        cout << "Intersection at Node : " << intersection->data << endl;
    }
    else
    {
        cout << "NO Intersection" << endl;
    }
    return 0;
}