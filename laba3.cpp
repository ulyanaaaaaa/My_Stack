#include <iostream>
#include <ctime>
using namespace std;

struct Stack {
    int info;
    bool x = false;
    Stack* next = NULL;
}*p;

void push(int value, Stack* f) {
    if (f->x != true) {
        f->info = value;
        f->x = true;
        return;
    }
    Stack* p = new Stack;
    p->info = f->info;
    f->info = value;
    p->next = f->next;
    f->next == p;
}

Stack* delEven(Stack* f) {     
    Stack* p = f;
    Stack* p1 = f;
    while (p != NULL) {
        if (p->info % 2 != 0) {
            p1 = p;
            p = p->next;
        }
        else {
            if (p == f) {
                f = f->next;
                delete p;
                return f;
            }
            else {
                p1->next = p->next;
                delete p;
                p = p1->next;
            }
        }
    }
}

void view(Stack* f) {
    Stack* p = f;
    while (f != NULL) {
        cout << " " << f->info << endl;
        f = f->next;
    }
}

void Sort_p(Stack** f) {
    Stack* p = NULL, * p1, * r;
    if ((*f)->next->next == NULL) return;
    do {
        for (p1 = *f; p1->next->next != p; p1 = p1->next)
            if (p1->next->info > p1->next->next->info) {
                r = p1->next->next;
                p1->next->next = r->next;
                r->next = p1->next;
                p1->next = r;
            }
        p = p1->next;
    } while ((*f)->next->next != p);
}

void Sort_info(Stack* f) {
    Stack* p = NULL, * p1;
    int r;
    do {
        for (p1 = p; p1->next != p; p1 = p1->next)
            if (p1->info > p1->next->info) {
                r = p1->info;
                p1->info = p1->next->info;
                p1->next->info = r;
            }
        p = p1;
    } while (p->next != p);
}


int main()
{
    srand(time(NULL));
    Stack* my_stack = NULL;
    cout << " 1 - fill up the stack with random numbers" << '\n' <<
        " 2 - eject an element from the stack" << '\n' <<
        " 3 - delete even numbers" << '\n' <<
        " 4 - sort the stack" << '\n' <<
        " 5 - view stack"<<'\n'<<
        " 0 - exit";
    bool flag = false;
    while (!flag) {
        int num;
        cin >> num;
        switch (num) {
        case 1:
        {
            cout << "Enter the stack size" << endl;
            int size;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                push(rand() % 200 - 100, my_stack);
            }
            view(my_stack);
            break;
        }
        case 2:
        {
            int a;
            cin >> a;
            push(a, my_stack);
            cout << a << " was ejected" << endl;
            system("pause");
            break;
        }

        case 3:
        {
            system("cls");
            cout << "Old stack:" << endl;
            view(my_stack);
            delEven(my_stack);
            cout << endl << "New stack:" << endl;
            view(my_stack);
            system("pause");
            break;
        }

        case 4:
        {
            Sort_info(my_stack);
        }

        case 5:
        {
            view(my_stack);
        }

        case 0: {
            flag = true;
        }
        }
    }
    
}

    

