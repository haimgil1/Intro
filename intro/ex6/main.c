/******************************************
 * Haim Gil
 * 203676945
 * 8911003
 * ex4
 ******************************************/
#include <stdio.h>
#include <stdlib.h>
#include "GDAT.h"
#include <math.h>

// Struct of point that include x and y.
typedef struct point
{
    int x;
    int y;
} point;

// Int functions declaration.
Elm Create_int_elm();
void Cpy_int_elm(Elm a, Elm b);
int Cmp_int_elm(Elm pa, Elm pb);
void Free_int_elm(Elm a);
void Dlt_int_elm(Elm a);
void Print_int_elm(Elm a);

// Point functions declaration.
Elm Create_point_elm();
void Cpy_point_elm(Elm a, Elm b);
int Cmp_point_elm(Elm pa, Elm pb);
void Free_point_elm(Elm a);
void Dlt_point_elm(Elm a);
void Print_point_elm(Elm a);

// Scaning input function declaration.
Elm ScanInput(int task);
// Menu function declaration.
void Menu(BST_T *root, int task);

/*****************************************************************************
 * function name: ScanInput
 * The Input: Value of task.
 * The output: void*.
 * The Function operation: The function recives from the user task,
 * if the task is 0 the function scan int and point otherwise.
 *****************************************************************************/
Elm ScanInput(int task)
{
    int val;
    point p;
    Elm scan;
    
    // Scaning int.
    if (task == 0)
    {
        scanf("%d", &val);
        scan = Create_int_elm();
        Cpy_int_elm(scan, &val);
        return scan;
    }
    // Scaning point.
    else
    {
        scanf(" (%d,%d)", &p.x, &p.y);
        scan = Create_point_elm();
        Cpy_point_elm(scan, &p);
        return scan;
    }
}

/************************************************************************
 * function name: main.
 * The Input: None.
 * The output: 0.
 * The Function operation: The function recives from the user number of
 * mission, if it's 0 the function create BST of integers and BST of struct
 * point otherwise.
 *************************************************************************/
int main()
{
    BST *root = NULL;
    int val;
    point p;
    int task;
    scanf(" %d", &task);
    switch (task)
    {
        // Create BST of integers.
        case 0:
        {
            scanf(" %d", &val);
            root = BSTCreate (&val, Create_int_elm, Cpy_int_elm,
                              Cmp_int_elm, Free_int_elm,
                              Print_int_elm);
            break;
        }
        // Create BST of points.
        case 1:
        {
            scanf(" (%d,%d)", &p.x, &p.y);
            root = BSTCreate (&p, Create_point_elm, Cpy_point_elm,
                              Cmp_point_elm, Free_point_elm,
                              Print_point_elm);
            break;
        }
        default:
            break;
    }
    // Calling the menu.
    Menu(root, task);
    return 0;
}


/************************************************************************
 * function name: Menu.
 * The Input: Root and number of task.
 * The output: None.
 * The Function operation: The function recives from the user letter of
 * mission and do the task.
 * Note: In case the user entered d, and it's the last node in the 
 * tree, the program will end.
 * Note: In case the user entered e, the program will end.
 *************************************************************************/
void Menu(BST_T *root, int task)
{
    int num;
    Elm scanInput;
    char mission;
    scanf("%c", &mission);
    switch(mission)
    {
        case 'a':
        {
            scanInput = ScanInput(task);
            BSTAddElement(root, scanInput);
            free (scanInput);
            break;
        }
        case 's':
        {
            scanInput = ScanInput(task);
            if (BSTFindElement(root, scanInput) != NULL)
            {
                printf("TRUE\n");
            }
            else
            {
                printf("FALSE\n");
            }
            free (scanInput);
            break;
        }
        case 'd':
        {
            scanInput = ScanInput(task);
            num = BSTRemoveElement(root, scanInput);
            
            // There isn't a node like this in the tree.
            if (num == 2)
            {
                printf("FALSE\n");
            }
            // Last node was deleted.
            else if (num == 3)
            {
                free (scanInput);
                BSTDestroy(root);
            }
            free (scanInput);
            break;
        }
        case 'p':
        {
            PrintBST(root);
            break;
        }
        case 'e':
        {
            BSTDestroy(root);
            return;
        }
        default:
        {
            break;
        }
    }
    Menu(root, task);
}


/*****************************************************************************
 * function name: Create_int_elm.
 * The Input: None.
 * The output: void *.
 * The Function operation: The function allocating memory to element.
 *****************************************************************************/
Elm Create_int_elm()
{
    int* x = (int*)malloc(sizeof(int));
    return x;
}

/*****************************************************************************
 * function name: Cpy_int_elm.
 * The Input: void* and void*.
 * The output: None.
 * The Function operation: The function copy one element to another.
 *****************************************************************************/
void Cpy_int_elm(Elm a, Elm b)
{
    *(int*)a = *(int*)b;
}

/*****************************************************************************
 * function name: Cmp_int_elm.
 * The Input: void* and void*.
 * The output: the diffrence by int.
 * The Function operation: The function compare two elements and return the
 * diffrence by int.
 *****************************************************************************/
int Cmp_int_elm(Elm pa, Elm pb)
{
    int a = *((int*)pa);
    int b = *((int*)pb);
    return (a-b);
}
/*****************************************************************************
 * function name: Free_int_elm.
 * The Input: void*.
 * The output: None.
 * The Function operation: The function free the memory to int element.
 *****************************************************************************/
void Free_int_elm(Elm a)
{
    free(((int*)a));
}

/*****************************************************************************
 * function name: Print_int_elm.
 * The Input: void*.
 * The output: None.
 * The Function operation: The function print the element.
 *****************************************************************************/
void Print_int_elm(Elm a)
{
    int b = *((int*)a);
    printf("%05d", b);
}


/*****************************************************************************
 * function name: Create_point_elm.
 * The Input: None.
 * The output: void *.
 * The Function operation: The function allocating memory to element.
 *****************************************************************************/
void* Create_point_elm()
{
    point *pt = (point*) malloc(sizeof(struct point));
    return pt;
}

/*****************************************************************************
 * function name: Cpy_point_elm.
 * The Input: void* and void*.
 * The output: None.
 * The Function operation: The function copy one element to another.
 *****************************************************************************/
void Cpy_point_elm(Elm a, Elm b)
{
    *(point*)a = *(point*)b;
}

/*****************************************************************************
 * function name: Cmp_point_elm.
 * The Input: void* and void*.
 * The output: the diffrence by int.
 * The Function operation: The function compare two elements, return 0
 * if even, 1 if pa is bigger than pb and -1 otherwise.
 *****************************************************************************/
int Cmp_point_elm(Elm pa, Elm pb)
{
    point a = *((point*)pa);
    float distanceA = sqrt((pow(a.x, 2)) + (pow(a.y, 2)));
    point b = *((point*)pb);
    float distanceB = sqrt((pow(b.x, 2)) + (pow(b.y, 2)));
    if ((distanceB == distanceA) && (a.x == b.x) && (a.y == b.y))
    {
        return 0;
    }
    if (distanceA > distanceB)
    {
        return 1;
    }
    return -1;
}

/*****************************************************************************
 * function name: Free_point_elm.
 * The Input: void*.
 * The output: None.
 * The Function operation: The function free the memory to int element.
 *****************************************************************************/
void Free_point_elm(Elm a)
{
    free(((point*)a));
}

/*****************************************************************************
 * function name: Print_point_elm.
 * The Input: void*.
 * The output: None.
 * The Function operation: The function print the element.
 *****************************************************************************/
void Print_point_elm(Elm a)
{
    point b = *((point*)a);
    printf("%02d|%02d", b.x, b.y);
}

