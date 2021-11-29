#include <iostream> 
#include<cstring> 
using namespace std;
/*PHONE BOOK SYSTEM
TEAM NUMBER 5
U2010042 Bahronov Akobir
U2010046 Bazarov Mekhrol
U2010060 Daminov Samandar
U2010183 Najmiddinov Kobiljon
U2010237 Saidakhmatov Sanjarbek
*/
class dnode
{
public:
    char number[50];
    char gmail[40];
    char name[30];
    dnode* prev, * next;
    dnode(char n[], char r[], char g[])

    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(gmail, g);
        next = NULL;
        prev = NULL;
    }
    friend class dlist;
};


class dlist
{
    dnode* head, * temp, * ptr;

    dnode* ptr1, * ptr2, * dup;

public:
    dnode* prevn;
    void insert();
    void deletecontact(char n[20]);
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

    // dnode head,*temp,*ptr; 
    void accept();
    void display();
    dlist()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
    }
};

void dlist::accept()
{
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    do
    {
        cout << "ENTER NAME: ";
        cin >> name;
        cout << "ENTER PHONE NUMBER: ";
        cin >> number;
        while (strlen(number) != 9) // number should be 9 digit
        {
            cout << "ENTER VALID NUMBER: ";



            cin >> number;
        }
        cout << "ENTER G-MAIL ACCOUNT: ";
        cin >> gmail;
        temp = new dnode(name, number, gmail);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "DO YOU WANT TO CONTINUE? ";
        cin >> ans;
    } while (ans == 'yes');//again go to create new contact 

}
void dlist::display()
{
    ptr = head;//start the node 
    while (ptr != NULL)//traverse till last 
    {
        cout << "\n\nNAME IS: \t" << ptr->name;
        cout << "\nPHONE NUMBER IS: \t+998 " << ptr->number;
        cout << "\nG-MAIL ACCOUNT IS: \t" << ptr->gmail;
        ptr = ptr->next;
    }
}

void dlist::insert()
{
    accept();
}

void dlist::deletecontact(char s[20])
{

    temp = NULL; //this temp value will be equal to node we are going to delete in future 
    ptr = head; // 

    while (ptr != NULL) {
        if (strcmp(ptr->name, s) == 0) {
            temp = ptr;
            break;
        }
        else {
            if (ptr->next != NULL) ptr = ptr->next;
        }
    }

    if (head == NULL || temp == NULL) {
        cout << "Node was not deleted\n";
        return;
    }
    if (head == temp) {
        head = ptr->next;
        cout << "Node deleted\n";
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
        cout << "Node deleted\n";
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
        cout << "Node deleted\n";
    }
    free(temp);
    return;
}

void dlist::searchbyname(char na[10])
{
    bool found = false;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "NAME FOUND" << endl;
            cout << "CONTACT DETAILS ARE BELOW: \n" << endl;
            cout << "\n\nNAME IS: \t" << ptr->name;
            cout << "\nPHONE NUMBER IS: \t+998 " << ptr->number;
            cout << "\nG-MAIL ACCOUNT IS: \t" << ptr->gmail << endl;
            found = true;

        }
        ptr = ptr->next;

    }
    if (!found) 
    {
        cout << "Could not found the account with the name you provided";
    }
}
void dlist::searchbynumber(char num[20])
{
    bool found = false;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "NUMBER FOUND\n" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
            cout << "\n\nNAME IS: \t" << ptr->name;
            cout << "\nPHONE NUMBER IS: \t+998 " << ptr->number;
            cout << "\nG-MAIL ACCOUNT IS: \t" << ptr->gmail;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "Could not found the account with the name you provided";
    }
}
void dlist::searchbygmail(char gm[20])
{
    bool found = false;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(gm, ptr->gmail) == 0)
        {
            cout << "G-MAIL FOUND\n" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
            cout << "\n\nNAME IS :\t" << ptr->name;
            cout << "\nPHONE NUMBER IS :\t+998 " << ptr->number;
            cout << "\nG-MAIL ACCOUNT IS :\t" << ptr->gmail;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "Could not found the account with the name you provided";
    }
}

int main()
{
    char name[10];
    char number[10];
    char gmail[20];
    dlist d1;
    char ans;
    int ch, a;
    cout << "**************                                PHONE BOOK                          ********************";
    cout << "\n\nPLEASE INTRODUCE YOURSELF, WHAT IS YOUR FULL NAME?\n";
    cin.getline(name, 20);
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLET'S START CREATING OUR PHONEBOOK " << name << "  \n\n";
    d1.accept();
    do
    {
        cout << "\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) DELETE CONTACT\n4) SEARCH\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d1.display();
            break;


        case 2:
            d1.insert();
            break;
        case 3:
            cout << "\nENTER THE NAME YOU WANT TO DELETE FROM YOUR PHONEBOOK\n";
            cin >> name;
            cout << "Name has been entered \n";
            d1.deletecontact(name);
            break;

        case 4:
            do
            {
                cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "ENTER NAME WHICH YOU WANT TO SEARCH" << endl;
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "ENTER PHONE NUMBER WHICH TOU WANT TO SEARCH" << endl;
                    cin >> number;
                    d1.searchbynumber(number);
                    break;
                case 3:
                    cout << "ENTER G-MAIL ACCOUNT WHICH YOU WANT TO SEARCH" << endl;
                    cin >> gmail;
                    d1.searchbygmail(gmail);
                    break;
                default:cout << "\nWRONG INPUT PLEASE TRY AGAIN\n";
                }
                cout << "DO YOU WANT TO GO ON SEARCHING ?" << endl;
                cin >> ans;
            } while (ans == 'y');
            break;
        default:cout << "\nWRONG INPUT PLEASE TRY AGAIN\n";
        }
        cout << "\n\nDO YOU WANT TO GO ON SEARCHING ?" << endl;
        cin >> ans;
    } while (ans == 'y');
}