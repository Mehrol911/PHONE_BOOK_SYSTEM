#include <iostream>
#include <cstring>
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
    char name[30];
    char number[50];
    char gmail[40];
    char birthday[30];
    dnode *prev, *next;
    dnode(char n[], char r[], char g[], char b[])
    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(gmail, g);
        strcpy(birthday, b);
        next = NULL;
        prev = NULL;
    }
    friend class dlist;
};

class dlist
{
    dnode *head, *temp, *ptr;

    dnode *ptr1, *ptr2, *dup;

public:
    dnode *prevn;
    void insert();
    void deletecontact(char n[20]);
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);
    void searchByBirthday(char p[20]);

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
    char birthday[30];
    cout << "\n\tPlease enter the details in order to add new contact" << endl;
    cout << "\tName: ";
    cin >> name;
    cout << "\tTel number [9digits]: "; // only write numbers!!!
    cin >> number;
    cout << "\tEmail: ";
    cin >> gmail;
    cout << "\tBirthday Format should be [dd.mm.yyyy]: ";
    cin >> birthday;
    cout << "\n\tContact has been successfully created\n";

    temp = new dnode(name, number, gmail, birthday);
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
}
void dlist::display()
{
    ptr = head; //start the node
    cout << "\n\t\t\t\t\t LIST OF CONTACTS";
    cout << "\n\t------------------------------------------------------------------" << endl;
    cout << "\tNames:"
         << "\t\tTel Numbers:";
    cout << "\tEmails:"
         << "\t\t\tBirthdays:" << endl;
    while (ptr != NULL) //traverse till last
    {
        cout << "\t" << ptr->name;
        if (strlen(ptr->name) <= 7)
        {
            cout << "\t";
        }
        cout << "\t" << ptr->number;
        cout << "\t" << ptr->gmail;
        if (strlen(ptr->gmail) <= 15)
        {
            cout << "\t";
        }
        cout << "\t" << ptr->birthday << endl;

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
    ptr = head;  //

    while (ptr != NULL)
    {
        if (strcmp(ptr->name, s) == 0)
        {
            temp = ptr;
            break;
        }
        else
        {
            if (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            else
            {
                cout << "Name has not been found!\n";
                break;
            }
        }
    }

    if (head == NULL || temp == NULL)
    {
        cout << "Node was not deleted\n";
        return;
    }
    if (head == temp)
    {
        head = ptr->next;
        cout << "Node deleted\n";
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
        cout << "Node deleted\n";
    }
    if (temp->prev != NULL)
    {
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
            cout << "\tName Found!" << endl;
            cout << "\tContact details are below: \n"
                 << endl;
            cout << "\tName: " << ptr->name << endl;
            cout << "\tTel Number: " << ptr->number << endl;
            cout << "\tEmail: " << ptr->gmail << endl;
            cout << "\tBirthday: " << ptr->birthday << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "\tCould not found the account with the name you provided";
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
            cout << "\tTelephone Number Found!" << endl;
            cout << "\tContact details are below: \n"
                 << endl;
            cout << "\tName: " << ptr->name << endl;
            cout << "\tTel Number: " << ptr->number << endl;
            cout << "\tEmail: " << ptr->gmail << endl;
            cout << "\tBirthday: " << ptr->birthday << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "\tCould not found the account with the name you provided";
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
            cout << "\tEmail Found!" << endl;
            cout << "\tContact details are below: \n"
                 << endl;
            cout << "\tName: " << ptr->name << endl;
            cout << "\tTel Number: " << ptr->number << endl;
            cout << "\tEmail: " << ptr->gmail << endl;
            cout << "\tBirthday: " << ptr->birthday << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "\tCould not found the account with the name you provided";
    }
}

void dlist::searchByBirthday(char bth[20])
{
    bool found = false;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(bth, ptr->birthday) == 0)
        {
            cout << "\tBirthday Found!" << endl;
            cout << "\tContact details are below: \n"
                 << endl;
            cout << "\tName: " << ptr->name << endl;
            cout << "\tTel Number: " << ptr->number << endl;
            cout << "\tEmail: " << ptr->gmail << endl;
            cout << "\tBirthday: " << ptr->birthday << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "\tCould not found the account with the birthday you provided";
    }
}

int main()
{
    char name[10];
    char number[10];
    char gmail[20];
    char birthday[10];
    dlist d1;
    int usersChoice;
    for (;;)
    {
        cout << "\n\n\t\t\t\t Welcome to Phone Book"; // \n means down to (vertical), \t means right to (horizontal)
        cout << "\n\n\t\t\t\t\t      MAIN MENU";
        cout << "\n\t\t\t\t ------------------------------------";
        cout << "\n\t\t\t\t [1] Add contact";
        cout << "\n\t\t\t\t [2] Show my contacts";
        cout << "\n\t\t\t\t [3] Delete contact";
        cout << "\n\t\t\t\t [4] Search contact";
        cout << "\n\t\t\t\t [5] Exit";
        cout << "\n\t\t\t\t Enter your choice: ";
        cin >> usersChoice;
        if (usersChoice == 1)
        {
            d1.insert();
        }
        else if (usersChoice == 2)
        {
            d1.display();
        }
        else if (usersChoice == 3)
        {
            cout << "\nEnter the name you want to delete from your phonebook\n";
            cin >> name;
            d1.deletecontact(name);
        }
        else if (usersChoice == 4)
        {
            int usersChoice2;
            for (;;) // you can search details by 4 options
            {        // it can help you for example if you know one of the following detail of the person you can find other details from search section
                cout << "\n\t\t\t\t Choose one of the options";
                cout << "\n\t\t\t\t [1] Search by Name";
                cout << "\n\t\t\t\t [2] Search by Tel Number";
                cout << "\n\t\t\t\t [3] Search by Email";
                cout << "\n\t\t\t\t [4] Search by Birthday";
                cout << "\n\t\t\t\t [5] Exit from search section";
                cout << "\n\t\t\t\t Enter your choice: ";
                cin >> usersChoice2;
                if (usersChoice2 == 1)
                {
                    cout << "\tEnter person that has to be searched = ";
                    cin >> name;
                    d1.searchbyname(name);
                    cout << endl;
                }
                else if (usersChoice2 == 2)
                {
                    cout << "\tEnter Tel Number that has to be searched = ";
                    cin >> number;
                    d1.searchbynumber(number);
                    cout << endl;
                }
                else if (usersChoice2 == 3)
                {
                    cout << "\tEnter email that has to be searched = ";
                    cin >> gmail;
                    d1.searchbygmail(gmail);
                    cout << endl;
                }
                else if (usersChoice2 == 4)
                {
                    cout << "\tEnter birthday that has to be searched = ";
                    cin >> birthday;
                    d1.searchByBirthday(birthday);
                    cout << endl;
                }
                else if (usersChoice2 == 5)
                {
                    break;
                }
            }
        }
        else if (usersChoice == 5)
        {
            cout << "\n\t\t\t\t THANKS FOR USING!" << endl;
            break;
        }
        else
        {
            cout << "\nWrong input, please input again!\n";
        }
    }
}
