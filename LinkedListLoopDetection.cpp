#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {};
};

// Function to detect the loop and return the start node of the loop
Node *findLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there is a loop
        if (slow == fast)
        {
            fast = head;

            // Move both pointers one step at a time to find the loop start
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            // Return the starting node of the loop
            return slow;
        }
    }
    // No loop found
    return nullptr;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node *temp = head->next->next; // Node 3
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = temp; // Creating a loop that starts at Node 3

    Node *loop = findLoop(head);
    if (loop != nullptr)
    {
        cout << "Loop starts at " << loop->data << endl;
    }
    else
    {
        cout << "No loop found." << endl;
    }

    return 0;
}
