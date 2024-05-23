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
    Node* add(int number)
    {
        next = new Node;
        next->prev = this;
        next->num = number;
        return next;
    }
};

void fillList(Node* head);
void printList(Node* el);


int main()
{
    bool start = true;
    Node* h1 = new Node;
    Node* h2 = new Node;
    fillList(h1);
    fillList(h2);
    
    Node* res = new Node;
    Node* head = res;

    printList(h1); 
    cout << endl;
    printList(h2); 
    cout << endl;

    while (h1 != nullptr || h2 != nullptr)
    {
        if (h1 == nullptr) 
        {
            if(start)
            {
                start = !start;
                res->num = h2->num;
            } else {
            res = res->add(h2->num);
            h2 = h2->next;}
        }
        else if (h2 == nullptr) 
        {
            if(start)
            {
                start = !start;
                res->num = h1->num;
            } else {
            res = res->add(h1->num);
            h1 = h1->next;}
        }
        else if (h1->num < h2->num)
        {
            if(start)
            {
                start = !start;
                res->num = h1->num;
                h1 = h1->next;
            }
            else {res = res->add(h1->num);
            h1 = h1->next;}
        }
        else {
            if(start)
            {
                start = !start;
                res->num = h2->num;
                h2 = h2->next;
            }
            else {
            res = res->add(h2->num);
            h2 = h2->next; }
        }
        
    }
    printList(head);
    return 0; 
}

void fillList(Node* head)fjjj
{
    cout << "Enter a sorted list : ";
    int num; 
    cin >> num;
    bool start = true;
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
}

void printList(Node* el)
{
    cout << el->num << " ";
    if (el->next != nullptr) printList(el->next);   
}