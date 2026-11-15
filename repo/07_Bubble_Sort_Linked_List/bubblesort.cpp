#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void bubbleSort(Node* head)
{
    if(head == NULL)
        return;

    bool swapped;
    Node* last = NULL;

    do
    {
        swapped = false;
        Node* curr = head;

        while(curr->next != last)
        {
            if(curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }

            curr = curr->next;
        }

        last = curr;
    }
    while(swapped);
}

void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(64);
    head->next = new Node(34);
    head->next->next = new Node(25);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(22);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(90);

    cout << "Before sorting: ";
    display(head);

    bubbleSort(head);

    cout << "\nAfter sorting: ";
    display(head);

    return 0;
}
