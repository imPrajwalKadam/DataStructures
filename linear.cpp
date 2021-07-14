#include <iostream>
using namespace std;
typedef struct node
{
     int data;
     struct node *next;
} NODE, *PNODE;

class LinearLL
{
private:
         int iSize;
         PNODE Head;

public:
     LinearLL()
     {
          iSize = 0;
          Head = NULL;
     }

     int Count()
     {
          return iSize;
     }
     void Display()
     {
          PNODE temp = Head;
          while(temp != NULL)
          {
               cout<<temp->data<<"\t";
               temp = temp->next;
          }
          cout<<"\n";
     }

     void InsertFirst(int value)
     {
          PNODE newn = NULL;
          newn = new NODE;
          newn->data=value;
          newn->next = NULL; 
          if(Head == NULL)
          {
               Head = newn;
          }
          else 
          {
               Head = newn;
               newn->next = Head;
          }
          iSize++;
     }

     void InsertLast(int value)
     {
          PNODE newn = NULL;
          newn = new NODE;
          newn->data = value;
          newn->next = NULL;  

          if(Head == NULL)
          {
               Head = newn;
          }
          else
          {
               PNODE temp = Head; 
               while(temp->next != NULL)
               {
                    temp = temp->next;
               }
               temp->next = newn;
               iSize++;
          }
     }

     void DeleteFirst()
     {
          if(Head != NULL)
          {
               PNODE temp = Head;
               Head = Head->next;
               delete temp;
          }
          iSize--;
     }
};

int main()
{
     int iChoice = 1,iValue=0,iNo = 0, iPos=0;
    
    LinearLL obj1;
    
    while(iChoice != 0)
    {
        cout<<"Enter your choice :"<<"\n";
        cout<<"1 : Insert at first position "<<"\n";
        cout<<"2 : Insert at last position "<<"\n";
        cout<<"3 : Insert at given position "<<"\n";
        cout<<"4 : Delete first node "<<"\n";
        cout<<"5 : Delete last node "<<"\n";
        cout<<"6 : Delete node at give position "<<"\n";
        cout<<"7 : Display the contents "<<"\n";
        cout<<"8 : Count the number of nodes "<<"\n";
        cout<<"0 : Exit the application "<<"\n";
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertFirst(iNo);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertLast(iNo);
                break;
            
            case 3:
           cout<<"Enter Data to insert"<<"\n";
            cin>>iValue;
            cout<<"Enter The Position"<<"\n";
            cin>>iPos;
          //  obj1.InsertAtPosition(iValue,iPos);
                break;
            
            case 4:
               obj1.DeleteFirst();
                break;
            
            case 5:
                //obj1.DeleteLast();
                break;
                
            case 6:
            cout<<"Enter The Position"<<"\n";
            cin>>iPos;
          //  obj1.DeleteAtPosition(iPos);
                break;
            
            case 7:
               obj1.Display();
                break;
            
            case 8:
                iNo = obj1.Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter Valid option\n";
                break;
        }
    }

     return 0;
}