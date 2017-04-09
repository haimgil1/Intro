/******************************************
 * Haim Gil
 * 203676945
 * 8911003
 * ex4
 ******************************************/
#ifndef GENBST_H
#define GENBST_H
#include <stdio.h>
#include <stdlib.h>

typedef void* Elm;
typedef void* BST;
typedef void* BST_ROOT;

typedef struct BST_S
{
    Elm val;
    struct BST_S* left;
    struct BST_S* right;
    void (*cpy_elm)(Elm, Elm);
    int (*cmp_elm)(Elm, Elm);
    void (*free_elm) (Elm);
    void (*Dlt_elm)(Elm);
    void (*Print_elm)(Elm);
    Elm (*Create_elm)();
} BST_T;

typedef enum {SUCEESS, OUT_OF_MEM, BAD_ARGS, FAILURE } Result;

BST_ROOT BSTCreate( Elm root_val,
                   Elm (*create_elm)(),
                   void (*cpy_elm) (Elm,Elm),
                   int (*cmp_elm) (Elm, Elm),
                   void (*free_elm)(Elm),
                   void(*Print_elm)(Elm) );

extern void BSTDestroy (BST_ROOT root);
extern Result BSTAddElement (BST_ROOT root, Elm node);
extern Result BSTRemoveElement (BST_ROOT root, Elm node);
extern Elm BSTFindElement (BST_ROOT root, Elm node);
extern void PrintBST(BST_ROOT root);

#endif