#include <iostream>
using namespace std;

struct nod
{
int info;
struct nod* next;
};

typedef struct nod node;

class list
{
node* f;
    node* r; // Pointer to the rear end of the list

public:
list()
{
f = NULL;
        r = NULL;
}

void insFront(int num)
{
node* p = new node;
p->info = num;
p->next = f;
f = p;

        // If the list is empty, set r to the newly inserted node
        if (r == NULL)
            r = p;
}

void insRear(int num)
{
node* p = new node;
p->info = num;
p->next = NULL;

        // If the list is empty, set f and r to the newly inserted node
if (f == NULL)
{
f = p;
            r = p;
        }
        else
        {
            r->next = p;
            r = p;
        }
}

void delFront()
{
node* temp = f;
if (f == NULL)
cout << "\nNo elements to delete.\n";
else
{
cout << "\nThe deleted element is: " << f->info;
f = f->next;
delete temp;
cout << "\nDeletion successful.\n";
}
}

void delRear()
{
if (f == NULL)
{
cout << "\nNo elements to delete.\n";
return;
}

if (f == r)
{
cout << "\nThe deleted element is: " << f->info;
delete f;
f = NULL;
r = NULL;
cout << "\nDeletion successful.\n";
return;
}

node* temp = f;
while (temp->next != r)
temp = temp->next;

cout << "\nThe deleted element is: " << r->info;
delete r;
r = temp;
r->next = NULL;
cout << "\nDeletion successful.\n";
}

void disp()
{
node* temp = f;
if (f == NULL)
cout << "\nList is empty.\n";
else
{
cout << "\nElements in the list are: ";
while (temp != NULL)
{
cout << temp->info << " ";
temp = temp->next;
}
}
}
};

int main()
{
int num, ch = 1;
list ob;
cout << "\nOperation allowed are:\n";
cout << "\n1] Insert at the front\n2] Insert at the rear\n3] Delete from the front\n4] Delete from the rear\n5] Display\n6] Exit";
while (ch)
{
cout << "\nEnter your choice: ";
cin >> ch;
switch (ch)
{
case 1:
cout << "\nEnter number to be inserted at the front: ";
cin >> num;
ob.insFront(num);
ob.disp();
break;
case 2:
cout << "\nEnter number to be inserted at the rear: ";
cin >> num;
ob.insRear(num);
ob.disp();
break;
case 3:
ob.delFront();
ob.disp();
break;
case 4:
ob.delRear();
ob.disp();
break;
case 5:
ob.disp();
break;
case 6:
return 0;
default:
cout << "Invalid choice.\n";
break;
}
}
return 0;
}
