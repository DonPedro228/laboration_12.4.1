#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Insert(Elem*& L, Info value);
void Print(Elem* L);
bool Sub_list(Elem* L1, Elem* L2);

int main() {
    Elem* L1 = NULL;

    Elem* L2 = NULL;

    cout << "Enter elements for L1 (type -1 to end input):" << endl;
    int value;
    while (true) {
        cin >> value;
        if (value == -1)
            break;
        Insert(L1, value);
    }

    Print(L1);

    cout << "Enter elements for L2 (type -1 to end input):" << endl;
    while (true) {
        cin >> value;
        if (value == -1)
            break;
        Insert(L2, value);
    }

    Print(L2);

    if (Sub_list(L1, L2))
        cout << "L1 is sublist L2" << endl;
    else {
        cout << "L1 is not sublist L2" << endl;
        return 1;
    }

	return 0;
}


void Insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem; 
    tmp->info = value; 
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link; 
        T->link = tmp; 
    }
    else
    {
        L = tmp; 
    }
    tmp->link = L; 
}


void Print(Elem* L) {
    if (L == NULL
        )
        return
        ;
    Elem* first = L;
    cout << setw(4) << L
        ->info;
    while (L
        ->link != first)

    {
        L = L
            ->link;
        cout << setw(4) << L
            ->info;

    }
    cout << endl;
}

bool Sub_list(Elem* L1, Elem* L2) {
    if (L1 == nullptr)
        return true;

    Elem* current1 = L1;
    Elem* current2 = L2;

    while (current2 != nullptr) {
        if (current1->info == current2->info) {
            Elem* temp1 = current1->link;
            Elem* temp2 = current2->link;


            while (temp1 != L1 && temp2 != L2 && temp1->info == temp2->info) {
                temp1 = temp1->link;
                temp2 = temp2->link;
                if (temp1 == current1)
                    return true;
            }

            if (temp1 == L1)
                return true;
        }
        current2 = current2->link;

        if (current2 == nullptr)
            current2 = L2;
            break;
    }

    return false;
}


