#include<iostream>
using namespace std;

// задание 24
// Входная последовательность представляет собой два набора натуральных чисел,
// упорядоченных по возрастанию. Между ними стоит число 0. Вывести все натуральные числа
// в порядке возрастания.

struct Node
{
    int num;
    Node* next;
    Node* prev;
    Node() {
        num = 0;
        next = nullptr;
        prev = nullptr;
    };
};

Node* GetList();
void printList(Node* el);


int main()
{
    Node* h1 = GetList();
    Node* h2 = GetList();

    printList(h1); cout << endl;
    printList(h2); cout << endl;

    while (h1 != nullptr || h2 != nullptr)
    {
        if (h1 == nullptr) 
        {
            printList(h2);
            break;
        }
        else if (h2 == nullptr) 
        {
            printList(h2);
            break;
        }
        if (h1->num < h2->num)
        {
            cout << h1->num << " ";
            h1 = h1->next;
        }
        else {
            cout << h2->num << " ";
            h2 = h2->next;
        }
        
    }
    return 0;
}

Node* GetList()
{
    cout << "Enter a sorted list : ";
    int num; 
    cin >> num;
    bool start = true;
    Node* head = new Node();
    Node* pointer = head;

    while (num != 0)
    {
        if (start) {
            pointer->num = num;
            pointer->prev = nullptr;
            pointer->next = nullptr;
            start = !start;
        } 
        else
        {
            pointer->next = new Node();
            pointer->next->prev = pointer;
            pointer = pointer->next;

            pointer->next = nullptr;
            pointer->num = num;
        }
        cin >> num;
    };

    return head;
}

void printList(Node* el)
{
    cout << el->num << " ";
    if (el->next != nullptr) printList(el->next);   
}