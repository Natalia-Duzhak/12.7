#include <iostream>
#include <windows.h>

using namespace std;
struct Elem

{
    int info;
    Elem* link;
};
void Stream(Elem*& first, int num);
void Print(Elem* first);
void Minus(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1);
void Add(Elem*& first, Elem*& last, int value);
int Delete(Elem*& first, Elem*& last);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;
    Elem* first1 = NULL,
        * last1 = NULL;

    int N;
    cout << "Кількість елементів списку: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cout << "Елемент: ";
        int num;
        cin >> num;
        Stream(first, num);
    }

    Print(first);
    Minus(first, last, first1, last1);
    cout << endl;
    cout << "Від'ємні:" << endl;
    Print(first1);
    cout << endl;
    return 0;

    return 0;
}
void Stream(Elem*& first, int num)

{

    if (first == NULL)
    {
        first = new Elem;
        first->info = num;
        first->link = NULL;

    }
    else
    {
        if (num <= first->info)
        {
            Elem* tmp = new Elem;
            tmp->info = num;
            tmp->link = first;
            first = tmp;
        }
        else
        {
            Elem* ptr = first;
            while (ptr->link && num >= ptr->link->info)
            {
                ptr = ptr->link;
            }

            Elem* link = ptr->link;
            Elem* tmp = new Elem;
            tmp->info = num;
            ptr->link = tmp;
            tmp->link = link;

        }

    }
}
void Print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << "  ";
        first = first->link;
    }
    cout << endl;
}
void Minus(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1)
{
    int i = 0;
    while (first != NULL)
    {
        if (first->info < 0)
        {
            i = Delete(first, last);
            Add(first1, last1, i);
        }
        else
            first = first->link;
    }
}
void Add(Elem*& first, Elem*& last, int value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

int Delete(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    int value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}
