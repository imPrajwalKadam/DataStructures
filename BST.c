/*
  BST(Binary Search Tree)
  Function names and its prototype:  - InsertNode(Double pointer , integer)
                                      Inorder(pinter);
                                      PreaOrder(pointer);
                                      PostOrder(pointer);
                                      Count(pointer);
  Date        :  7th july 2021
  author name :  Prajwal Kadam                                   
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *rChild;
    struct node *lChild;
} NODE, *PNODE, **PPNODE;

void InsertNode(PPNODE Head, int iNo)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->lChild = NULL;
    newn->rChild = NULL;
    if (*Head == NULL)//root null
    {
        *Head = newn;
    }
    else
    {
        while (1)
        {
            if(iNo > temp->data)
            {
                if (temp->rChild == NULL)
                {
                    temp->rChild = newn;
                    break;
                }
                temp = temp->rChild;
            }

            else if (iNo < temp->data)
            {
                if (temp -> lChild ==   NULL)
                {
                    temp -> lChild = newn;
                    break;
                }
                 temp = temp->lChild;
            }   

            else if (iNo == temp->data)
            {
                printf("Duplicate elements\n");
                free(newn);
                break;
            }
       }
    }
}
/*In-order Traversal में सबसे पहले Left sub-tree को एक्सेस किया जाता हैं और उसके बाद Root Node को access  किया जाता हैं
  last में Right Sub-tree access / Visit किया जाता हैं */
void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lChild);
        printf("%d\t",Head->data);
        Inorder(Head->rChild);
    }
}

/* Pre-order Traversal में सबसे पहले Root Node को visit किया जाता हैं उसके बाद left subtree को access किया जाता हैं 
   उसके बाद right subtree को access किया जाता हैं 
*/

void PreOrder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data);
        PreOrder(Head->lChild);
        PreOrder(Head->rChild);
    }
}
/*Post-order Traversal में सबसे पहले Left subtree को access
 किया जाता हैं उसके बाद right subtree को एक्सेस किया जाता हैं उसके बाद सबसे लास्ट में रुट Node को access किया जाता हैं
*/
void PostOrder(PNODE Head)
{
    if(Head != NULL)
    {
        PostOrder(Head->lChild);
        PostOrder(Head->rChild);
        printf("%d\t",Head->data);
    }
}  

int Count(PNODE Head)
{

    static int iCnt = 0;

    if (Head != NULL)
    {
        iCnt++;
        Count(Head->lChild);
        Count(Head->rChild);
    }

    return iCnt;
}

int main()
{
    PNODE Root = NULL;

    int iChoice = 1, iNo = 0, i = 0, bRet = 0,iCnt = 0;

    while (iChoice != 0)
    {
        printf("Enter option\n");
        printf("1: Insert node\n");
        printf("2: Display Inorder\n");
        printf("3: Display PreOredr\n");
        printf("4: Display PostOrder\n");
        printf("5: Count nodes\n");
        printf("6: CountLeaf nodes\n");
        printf("7: CountParent nodes\n");
        printf("8: Search element\n");
        printf("0: Exit\n");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter number:\n");
            scanf("%d", &iNo);
            InsertNode(&Root, iNo);
            break;

        case 2:
            Inorder(Root);
            break;

        case 3:
             PreOrder(Root);
            break;

        case 4:
             PostOrder(Root);
            break;

        case 5:
            iCnt = Count(Root);
            printf("Count of nodes is:%d\n",iCnt);
            break;

        case 6:
            i = 0;
            //CountLeaf(Root, &i);
            printf("Number of Leaf nodes are:%d\n", i);
            i = 0;
            break;

        case 7:
            i = 0;
            //CountParent(Root, &i);
            printf("Number of Parent nodes are:%d\n", i);
            i = 0;
            break;

        case 8:
            printf("Enter element to search:\n");
            scanf("%d", &iNo);
            //bRet = SearchX(Root, iNo);
            if (bRet == true)
            {
                printf("%d is Preasent in BST\n");
            }
            else
            {
                printf("%d is not preasent in BST\n");
            }

        case 0:
            printf("Thanks\n");
            break;

        default:
            printf("please enter valid option\n");
            break;
        }
    }

    return 0;
}