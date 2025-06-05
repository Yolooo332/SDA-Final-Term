/*
 *	Created by Nan Mihai on 28.03.2021
 *	Copyright (c) 2021 Nan Mihai. All rights reserved.
 *	Laborator 5 - Structuri de date
 *	Facultatea de Automatica si Calculatoare
 *	Anul Universitar 2020-2021, Seria CD
 */
#include "tree.h"

/*
 *	Funcție care creează un arbore cu un singur nod
 */
Tree createTree(Item value)
{
    Tree root = malloc(sizeof(TreeNode));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

/*
 *	Funcție care inițializează un nod de arbore
 *		- îi alocă memorie
 *		- îi setează câmpul valoare
 *		- setează left și right să pointeze către NULL
 */
void init(Tree *root, Item value)
{
    // TODO 1
}

/*
 *	Funcție care inserează o valoare într-un arbore binar, respectând
 * proprietățile unui arbore binar de căutare
 */
Tree insert(Tree root, Item value)
{
    // TODO 2
    return root;
}

/*
 *	Funcție care afișează nodurile folosind parcurgerea în postordine
 */
void printPostorder(Tree root)
{
    // TODO 3
}

/*
 *	Funcție care afișează nodurile folosind parcurgerea în preordine
 */
void printPreorder(Tree root)
{
    // TODO 4
}

/*
 *	Funcție care afișează nodurile folosind parcurgerea în inordine
 */
void printInorder(Tree root)
{
    // TODO 5
}

/*
 *	Funcție care dealocă întreaga memorie alocată pentru un arbore binar
 *		- root va pointa către NULL după ce se va apela funcția
 */
void freeTree(Tree *root)
{
    // TODO 6
}

/*
 *	Funcție care determină numărul de noduri dintr-un arbore binar
 */
int size(Tree root)
{
    // TODO 7
    return -1;
}

/*
 *	Funcție care returnează adâncimea maximă a arborelui
 */
int maxDepth(Tree root)
{
    // TODO 8
    return -1;
}

/*
 *	Funcție care construiește oglinditul unui arbore binar
 */
void mirror(Tree root)
{
    // TODO 9
}

/*
 *	Funcție care verifică dacă doi arbori binari sunt identici
 */
int sameTree(Tree root1, Tree root2)
{
    // TODO 10
    return -1;
}
