#include<iostream>
using namespace std;
// Дано ддп, если в дереве нечетное кол. совершенных эл., то заменить все нечетные эл. их квадратами.
// 6 28 1 2 3 4 5 0
// 6 1 2 3 4 5 0

struct tree
{
public:
    int data;
    tree* left;
    tree* right;
    tree(int data)
    {
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
    void add(int data)
    {
        if (data < this->data)
        {
            if (left == nullptr)
            {
                left = new tree(data);
            }
            else left->add(data);
        }
        else {
            if (right == nullptr)
            {
                right = new tree(data);
            }
            else right->add(data);
        }
    }
    void print(){
        cout << data << " ";
        if (left != nullptr)
            left->print();
        if (right != nullptr)
            right->print();
    }
};
bool isPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number%i==0)
            sum += i;
    }
    if (sum == number)
        return true;
    return false;
}
int perfectCount(tree* el){
    if (el == nullptr)
        return 0;
    else
    {
        if(isPerfect(el->data)) return 1 + perfectCount(el->left) + perfectCount(el->right);
        return 0 + perfectCount(el->left) + perfectCount(el->right);
    }      
}

void replaceAllOdd(tree* el){
    if (el != nullptr)
    {
        if (el->data%2!=0) {
            el->data = el->data * el->data;
        }
        replaceAllOdd(el->left);
        replaceAllOdd(el->right);
    }
}
int main()
{
    int num, perfects;
    cout << "enter tree: "; cin >> num;
    tree* root = new tree(num);
    cin >> num;
    while (num != 0)
    {
        root->add(num);
        cin >> num;
        
    };
    cout << "previous tree" << endl;
    root->print();
    perfects = perfectCount(root);
    if (perfects % 2 != 0)
    {
        replaceAllOdd(root);
    }
    cout << endl << "current tree" << endl;
    root->print();
    return 0;
}

