#include <iostream>
using namespace std;

typedef struct node
{
     int idata;
     struct node *next;
     struct node *prev;
}NODE, *PNODE;

class DoublyCirc
{
private:
     PNODE Head;
     PNODE Tell;
     int iSize;

public:
     DoublyCirc()
     {
          this->Head = NULL;
          this->Tell = NULL;
          iSize = 0;
     }
     void InsertFirst(int);
     void InsertLast(int);
     void Display();
};

void DoublyCirc :: InsertFirst(int iNo)
{
     PNODE newn = new NODE;
     newn -> next = NULL;
     newn -> prev = NULL;
     newn -> idata = iNo;

     if(iSize == 0)
     {
          Head = newn;
          Tell = newn;
     }
     else{
          newn -> next = Head;
          Head -> prev = newn;
          Head = newn;
     }
     Tell -> next = Head;
     Head -> prev = Tell;
     iSize++; 
} 

void DoublyCirc :: InsertLast(int iNo)
{
     PNODE newn = new NODE;
     newn -> next = NULL;
     newn -> prev = NULL;
     newn -> idata = iNo;

     if(iSize == 0)
     {
          Head = newn;
          Tell = newn;
     } 
     else
     {
          Tell -> next = newn;
          Tell = newn;
          Tell -> next = Head;
     }
     iSize++;
}
void DoublyCirc :: Display()
{
     PNODE temp = Head;
     for(int i = 1;i<=iSize ; i++)
     {
          cout<<temp -> idata<<"\t";
          temp = temp->next;
     }
}

int
main()
{
     int iChoice = 1, iNo = 0, iRet = 0, iPos = 0;
     DoublyCirc obj;

     while (iChoice != 0)
     {
          cout << "Enter your choice:\n";
          cout << "1 : Insert First\n";
          cout << "2 : Insert Last\n";
          cout << "3 : Insert at pos\n";
          cout << "4 : Delete first \n";
          cout << "5 : Delete Last\n";
          cout << "6 : Delete at pos\n";
          cout << "7 : Display the elements\n";
          cout << "8 : Count number of elements\n";
          cout << "0 : Exit the application\n";
          cin >> iChoice;

          switch (iChoice)
          {
          case 1:
               cout << "Enter number\n";
               cin >> iNo;
               obj.InsertFirst(iNo);
               break;



          case 2:
               cout << "Enter number\n";
               cin >> iNo;
               obj.InsertLast(iNo);
               break;
/*
          case 3:
               cout << "Enter number\n";
               cin >> iNo;
               cout << "Enter position\n";
               cin >> iPos;
               obj.InsertAtPos(iNo, iPos);
               break;

          case 4:
               obj.DeleteFirst();
               break;

          case 5:
               obj.DeleteLast();
               break;

          case 6:
               cout << "Enter the position\n";
               cin >> iPos;
               obj.DeleteAtPos(iPos);
               break;
               */

          case 7:
               cout << "Elements of LL are\n";
               obj.Display();
               break;

          case 8:
            //   iRet = obj.Count();
               cout << "Number of nodes are : " << iRet << "\n";
               break;

          case 0:
               cout << "Thank you for using the application\n";
               system("clear");
               break;
               

          default:
               cout << "Please enter proper option\n";
               break;
          } // End of switch
     }      // End of while

     return 0;
} // End of main
