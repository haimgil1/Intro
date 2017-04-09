/******************************************
 * Haim Gil
 * 203676945
 * 8911003
 * ex4
 ******************************************/
#include "GDAT.h"

// Help generic function decleration's.
static Elm BSTFindFather (BST_ROOT root, Elm node);
static Elm BSTFindSmallest (BST_ROOT root, Elm node);
static Result RemoveNoChildren(BST_T *tree, BST_T *rootDelete,
                               BST_T *father);
static Result RemoveLeftChild(BST_T *tree, BST_T *rootDelete,
                              BST_T *father, BST_T *temp);
static Result RemoveRightChild(BST_T *tree, BST_T *rootDelete,
                               BST_T *father, BST_T *temp);
static Result RemoveTwoChildren(BST_T *tree, BST_T *rootDelete,
                                BST_T *father, BST_T *temp, Elm node);
static void WhereIsTheSon(BST_T *father, BST_T *child,
                          BST_T *caseDelete);
static int NumOfLevels(BST_T* root);
static void PrintTree(BST_ROOT root, int numOfLevels, int level);
static int NumOfChildren(BST_ROOT root);
static void PrintLevel(BST_ROOT root, int level, int currentLevel,
                       int rootsPerLevel, int rootsPrinted);
static int RootsPerLevel(BST_ROOT root, int level);

/************************************************************************
 * function name: BSTCreate.
 * The Input: void* value, and pointers to functions.
 * The output: void* root.
 * The Function operation: The function recives value and functions
 * and create a tree.
 *************************************************************************/
BST_ROOT BSTCreate (Elm root_val, Elm (*Create_elm)(),
                    void (*cpy_elm)(Elm,Elm),int (*cmp_elm)(Elm, Elm),
                    void (*free_elm)(Elm),void(*Print_elm)(Elm))
{
    // Allocating memory.
    BST_T *root = (BST_T*) malloc(sizeof(struct BST_S));
    
    // If the allocation didn't failed.
    if ( NULL != root )
    {
        root->val = (Elm)Create_elm();
        cpy_elm(root->val, root_val);
        root->left = NULL;
        root->right = NULL;
        root->cpy_elm = cpy_elm;
        root->cmp_elm = cmp_elm;
        root->free_elm = free_elm;
        root->Print_elm = Print_elm;
        root->Create_elm = Create_elm;
    }
    return root;
}

/************************************************************************
 * function name: BSTAddElement.
 * The Input: void* root, and void* node.
 * The output: enum result.
 * The Function operation: The function adding element to the tree.
 *************************************************************************/
extern Result BSTAddElement (BST_ROOT root, Elm node)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    
    // If the node is bigger than current root.
    if ((tree->cmp_elm(tree->val, node)) > 0)
    {
        // Found the spot.
        if (tree->left == NULL)
        {
            tree->left = BSTCreate(node, tree->Create_elm, tree->cpy_elm,
                                   tree->cmp_elm, tree->free_elm,
                                   tree->Print_elm);
        }
        // Didn't found and calling again.
        else
        {
            BSTAddElement(tree->left, node);
        }
    }
    // If the node is smaller than current root.
    else
    {
        // Found the root.
        if (tree->right == NULL)
        {
            tree->right = BSTCreate(node, tree->Create_elm, tree->cpy_elm,
                                    tree->cmp_elm, tree->free_elm,
                                    tree->Print_elm);
        }
        // Didn't found and calling again.
        else
        {
            BSTAddElement(tree->right, node);
        }
    }
    return SUCEESS;
}

/************************************************************************
 * function name: BSTFindElement.
 * The Input: void* root, and void* node.
 * The output: void* root.
 * The Function operation: The function findding element and return it.
 * Note: In case the node isn't in the tree the function will return NULL.
 *************************************************************************/
extern Elm BSTFindElement (BST_ROOT root, Elm node)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    // Temp void*.
    Elm exist = NULL;
    int compare = tree->cmp_elm(tree->val, node);
    
    // If the node is bigger than current root.
    if ((compare < 0) && (tree->right != NULL))
    {
        // Calling recursive.
        exist = BSTFindElement(tree->right, node);
    }
    
    // If the node is smaller than current root.
    else if ((compare > 0) && (tree->left != NULL))
    {
        // Calling recursive.
        exist = BSTFindElement(tree->left, node);
    }
    
    // Found the root.
    else if ((tree->cmp_elm(tree->val, node)) == 0)
    {
        exist = tree;
    }
    return exist;
}

/************************************************************************
 * function name: BSTRemoveElement.
 * The Input: void* root, and void* node.
 * The output: enum.
 * The Function operation: The function findding element and delete it.
 * Note: In case the node isn't in the tree the function will 
 * return BAD_ARGS.
 *************************************************************************/
extern Result BSTRemoveElement (BST_ROOT root, Elm node)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    // Finding the root in the tree.
    BST_T *rootDelete = BSTFindElement(tree, node);
    // Temporary BST_T.
    BST_T *temp = NULL;
    Result result;
    
    // The node isn't in the tree.
    if (rootDelete == NULL)
    {
        return BAD_ARGS;
    }
    
    // Finding the father of the root.
    BST_T *father = BSTFindFather(tree, node);
    
    // Deleting a root with no children.
    if ((rootDelete->left == NULL) && (rootDelete->right == NULL))
    {
        result = RemoveNoChildren(tree, rootDelete, father);
    }
    
    // Deleting a root with only left child.
    else if (rootDelete->right == NULL)
    {
        result = RemoveLeftChild(tree, rootDelete, father, temp);
    }
    
    // Deleting a root with only right child.
    else if (rootDelete->left == NULL)
    {
        result = RemoveRightChild(tree, rootDelete, father, temp);
    }
    
    // Deleting a root with two children.
    else if ((rootDelete->left != NULL) && (rootDelete->right != NULL))
    {
        result = RemoveTwoChildren(tree, rootDelete, father, temp, node);
    }
    return result;
}

/************************************************************************
 * function name: BSTFindFather.
 * The Input: void* root, and void* node.
 * The output: void* root.
 * The Function operation: The function findding element and return
 * his father.
 * Note: In case the node isn't in the tree the function will return NULL.
 *************************************************************************/
static Elm BSTFindFather (BST_ROOT root, Elm node)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    Elm father = NULL;
    int compare = tree->cmp_elm(tree->val, node);
    
    // Finding the node in the right son.
    if ((tree->right != NULL) &&
       (tree->right->cmp_elm(tree->right->val, node) == 0))
    {
        father = tree;

    }
    
    // Finding the node in the left son.
    else if ((tree->left != NULL) &&
            (tree->left->cmp_elm(tree->left->val, node) == 0))
    {
        father = tree;
    }
    
    // If the node is bigger than current root.
    else if (((compare) < 0) && (tree->right != NULL))
    {
        father = BSTFindFather(tree->right, node);
    }
    
    // If the node is smaller than current root.
    else if (((compare) > 0) && (tree->left != NULL))
    {
        father = BSTFindFather(tree->left, node);
    }
    return father;
}

/************************************************************************
 * function name: RemoveNoChildren.
 * The Input: BST_T *tree, BST_T *rootDelete and BST_T *father.
 * The output: enum.
 * The Function operation: The function remove root with two children.
 * Note: In case the root has no father the funcion return FAILURE
 * and SUCEESS otherwise.
 *************************************************************************/
static Result RemoveNoChildren(BST_T *tree, BST_T *rootDelete,
                               BST_T *father)
{
    // Last root to delete.
    if (father == NULL)
    {
        return FAILURE;
    }
    
    // Finding where the son is located.
    WhereIsTheSon(father, rootDelete, NULL);
    // Deleting the root.
    rootDelete->free_elm(rootDelete->val);
    free(rootDelete);
    rootDelete = NULL;
    return SUCEESS;
}

/************************************************************************
 * function name: RemoveLeftChild.
 * The Input:BST_T *tree, BST_T *rootDelete, BST_T *father and BST_T *temp.
 * The output: enum.
 * The Function operation: The function remove root with left child.
 *************************************************************************/
static Result RemoveLeftChild(BST_T *tree, BST_T *rootDelete,
                              BST_T *father, BST_T *temp)
{
    // Deleting the first root.
    if (father == NULL)
    {
        // Copy the left rootDelete value to rootDelete.
        rootDelete->cpy_elm(rootDelete->val, rootDelete->left->val);
        temp = rootDelete->left;
        // Conecting the left rootDelete to rootDelete.
        rootDelete->left = temp->left;
        rootDelete->right = temp->right;
        // Deleting the left rootDelete.
        temp->free_elm(temp->val);
        free(temp);
        return SUCEESS;
    }
    
    // Finding where the son is located.
    WhereIsTheSon(father, rootDelete, rootDelete->left);
    // Deleting the root.
    rootDelete->free_elm(rootDelete->val);
    free(rootDelete);
    return  SUCEESS;
}

/************************************************************************
 * function name: RemoveRightChild.
 * The Input:BST_T *tree, BST_T *rootDelete, BST_T *father and BST_T *temp.
 * The output: enum.
 * The Function operation: The function remove root with right child.
 *************************************************************************/
static Result RemoveRightChild(BST_T *tree, BST_T *rootDelete,
                               BST_T *father, BST_T *temp)
{
    // Deleting the first root.
    if (father == NULL)
    {
        // Copy the right rootDelete value to rootDelete.
        rootDelete->cpy_elm(rootDelete->val, rootDelete->right->val);
        temp = rootDelete->right;
        // Conecting the right rootDelete to rootDelete.
        rootDelete->left = temp->left;
        rootDelete->right = temp->right;
        // Deleting the right rootDelete.
        temp->free_elm(temp->val);
        free(temp);
        return SUCEESS;
    }
    
    // Finding where the son is located.
    WhereIsTheSon(father, rootDelete, rootDelete->right);
    // Deleting the root.
    rootDelete->free_elm(rootDelete->val);
    free(rootDelete);
    return SUCEESS;
}

/************************************************************************
 * function name: RemoveTwoChildren.
 * The Input: BST_T *tree, BST_T *rootDelete, BST_T *father, BST_T *temp
 * and node.
 * The output: enum.
 * The Function operation: The function remove root with two children.
 *************************************************************************/
static Result RemoveTwoChildren(BST_T *tree, BST_T *rootDelete,
                                BST_T *father, BST_T *temp, Elm node)
{
    // Finding the smallest in the right rootDelete.
    BST_T *smallest = BSTFindSmallest(rootDelete->right, node);
    // Finding the father of the smallest.
    BST_T *fatherSmallest = BSTFindFather(rootDelete, smallest->val);
    // Finding where the son is located.
    WhereIsTheSon(fatherSmallest, smallest, smallest->right);
    
    // Deleting the first root.
    if (father == NULL)
    {
        // Copy the smallest value to rootDelete.
        rootDelete->cpy_elm(rootDelete->val, smallest->val);
        // Deleting the smallest.
        smallest->free_elm(smallest->val);
        free(smallest);
        return SUCEESS;
    }
    
    // Finding where the son is located.
    WhereIsTheSon(father, rootDelete, smallest);
    // Conecting the rootDelete to smallest.
    smallest->right = rootDelete->right;
    smallest->left = rootDelete->left;
    
    // Delting the root.
    rootDelete->free_elm(rootDelete->val);
    free(rootDelete);
    return SUCEESS;
}

/************************************************************************
 * function name: BSTFindSmallest.
 * The Input: BST_ROOT root, void* node.
 * The output: enum.
 * The Function operation: The function remove root with two children.
 *************************************************************************/
static Elm BSTFindSmallest (BST_ROOT root, Elm node)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    Elm smallest = root;
    if (tree->left != NULL)
    {
        // If there is left son there is smaller element.
        smallest = BSTFindSmallest(tree->left, node);
    }
    return smallest;
}

/************************************************************************
 * function name: WhereIsTheSon.
 * The Input: BST_T *father, BST_T *child and BST_T *caseDelete.
 * The output: enum.
 * The Function operation: The function remove root with two children.
 *************************************************************************/
static void WhereIsTheSon(BST_T *father, BST_T *child, BST_T *caseDelete)
{
    // This is the son
    if (father->left == child)
    {
        // Connecting father's son to the case.
        father->left = caseDelete;
    }
    else
    {
        father->right = caseDelete;
    }
}

/************************************************************************
 * function name: BSTDestroy.
 * The Input: BST_ROOT root.
 * The output: enum.
 * The Function operation: The function destroy the tree.
 *************************************************************************/
extern void BSTDestroy (BST_ROOT root)
{
    // Casting from void* to BST_T.
    BST_T *tree = root;
    
    // Root has no son.
    if (tree->right == NULL && tree->left == NULL)
    {
        tree->free_elm(tree->val);
        free(tree);
        return;
    }
    
    BST_T* pRootRight = tree->right;
    BST_T* pRootLeft = tree->left;
    
    // Deleting the root.
    tree->free_elm(tree->val);
    free(tree);
    tree = NULL;
    
    // Deleting the right son.
    if (pRootRight != NULL)
    {
        BSTDestroy(pRootRight);
    }
    
    // Deleting the left son.
    if (pRootLeft != NULL)
    {
        BSTDestroy(pRootLeft);
    }
}

/************************************************************************
 * function name: PrintBST.
 * The Input: BST_ROOT root.
 * The output: None.
 * The Function operation: The function
 * per level.
 *************************************************************************/
extern void PrintBST(BST_ROOT root)
{
    BST_T *tree = root;
    int level = 0, numOfLevels;
    
    // Nothing to print in empty tree.
    if (tree != NULL)
    {
        // Counting the number of levels in the tree.
        numOfLevels = NumOfLevels(tree);
        // Print the tree.
        PrintTree(tree, numOfLevels, level);
    }
    return;
}
/************************************************************************
 * function name: NumOfLevels.
 * The Input: BST_T* root.
 * The output: int number of levels in the tree.
 * The Function operation: The function claculate the number of levels in
 * the tree.
 * Note: I used stackoverflow to build this function.
 *************************************************************************/
static int NumOfLevels(BST_T* root)
{
    // End of the tree.
    if (root == NULL)
        return 0;
    else
    {
        // Number of level in the right tree.
        int leftLevel = NumOfLevels(root->left);
        // Number of level in the left tree.
        int rightLevel = NumOfLevels(root->right);
        
        // Returning the bigger level.
        if (leftLevel > rightLevel)
        {
            return(leftLevel+1);
        }
        else return(rightLevel+1);
    }
}

/************************************************************************
 * function name: PrintTree.
 * The Input: BST_ROOT root, number of levels and courrent level.
 * The output: None.
 * The Function operation: The function printing the
 *************************************************************************/
static void PrintTree(BST_ROOT root, int numOfLevels, int level)
{
    BST_T *tree = root;
    int rootsPerLevel, rootsPrinted = 0, currentLevel = 0;
    
    // Stop print when level and numOfLevels equal.
    if (level != numOfLevels)
    {
        // Counting the number of level.
        rootsPerLevel = RootsPerLevel(tree, level);
        // Print by level.
        PrintLevel(root, level, rootsPerLevel, rootsPrinted, currentLevel);
        printf("\n");
        // New level.
        level++;
        // Print the next level.
        PrintTree(root, numOfLevels, level);
    }
}

/************************************************************************
 * function name: RootsPerLevel.
 * The Input: BST_ROOT root and number of level.
 * The output: Number of nodes per level.
 * The Function operation: The function claculate the number of
 * nodes per level.
 * Note: I used Stackoverflow to build this function.
 *************************************************************************/
static int RootsPerLevel(BST_ROOT root, int level)
{
    BST_T* newRoot = root;
    
    //  Stop when the tree is empty.
    if (root == NULL)
        return 0;
    
    // Count if its the current level.
    if (level == 0)
        return 1;
    
    return (RootsPerLevel(newRoot->left, level - 1) +
            RootsPerLevel(newRoot->right, level - 1));
}

/************************************************************************
 * function name: PrintLevel.
 * The Input: BST_ROOT root, level, number of roots per level,
 * number of roots that printed and current level.
 * The output: Number of nodes per level.
 * The Function operation: The function print a level of a tree.
 *************************************************************************/
static void PrintLevel(BST_ROOT root, int level, int rootsPerLevel,
                       int rootsPrinted, int currentLevel)
{
    BST_T *tree = root;
    int lastRootLevel = 0, leftChildren, rightChildren;
    
    //  Stop when the tree is empty.
    if (tree == NULL)
    {
        return;
    }
    
    // It's the current level.
    if (currentLevel == level)
    {
        // Counting the number of the left children.
        leftChildren = NumOfChildren(tree->left);
        // Print spaces by number of the left children.
        printf("%*s", 5 * leftChildren, "");
        // Print value.
        tree->Print_elm(tree->val);
        rootsPrinted++;
        
        // Turns the flag on.
        if (rootsPrinted == rootsPerLevel)
        {
            lastRootLevel = 1;
        }
        
        // If it's not the last root in the level.
        if(lastRootLevel == 0)
        {
            // Counting the number of the right children.
            rightChildren = NumOfChildren(tree->right);
            // Print spaces by number of the right children.
            printf("%*s", 5 * rightChildren, "");
        }
    }
    else
    {
        // Search the next level.
        currentLevel++;
        // Printing the next nodes in the level.
        PrintLevel(tree->left, level, rootsPerLevel,
                   rootsPrinted, currentLevel);
        printf("     ");
        // Printing the next nodes in the level.
        PrintLevel(tree->right, level, rootsPerLevel,
                   rootsPrinted, currentLevel);
        
    }
}

/************************************************************************
 * function name: NumOfChildren.
 * The Input: BST_ROOT root.
 * The output: int number of children in the tree.
 * The Function operation: The function claculate the number of children
 * in the tree.
 *************************************************************************/
static int NumOfChildren(BST_ROOT root)
{
    BST_T *tree = root;
    int count = 1;
    
    //  Stop when the tree is empty.
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Counting the children.
        count+= NumOfChildren(tree->left);
        count+= NumOfChildren(tree->right);
        return count;
    }
}





