/*
 *	Created by Nan Mihai on 05.05.2021
 *	Copyright (c) 2020 Nan Mihai. All rights reserved.
 *	Laborator 6 - Structuri de date
 *	Grupa 314CD
 *	Facultatea de Automatica si Calculatoare
 *	Anul Universitar 2020-2021, Seria CD
 */
#include "tree.h"

/*
 *	Funcție care creează un arbore cu un singur nod
 */
Tree createTree(Tree parent, Item value)
{
    Tree root = malloc(sizeof(TreeNode));
    root->parent = parent;
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
void init(Tree *root, Tree parent, Item value)
{
    // TODO 0
    if (root == NULL)
    {
        (*root) = malloc(sizeof(TreeNode));
    }
    else
    {
        (*root)->parent = parent;
        (*root)->value = value;
        (*root)->left = (*root)->right = NULL;
    }
}

/*
 *	Funcție care inserează o valoare într-un arbore binar, respectând
 * proprietățile unui arbore binar de căutare
 */
Tree insert(Tree root, Item value)
{
    // TODO 1
    // if (root == NULL)
    // {
    //     return createTree(NULL, value);
    // }
    // if (value < root->value)
    // {
    //     root->left = insert(root->left, value);
    //     root->left->parent = root;
    // }
    // if (value > root->value)
    // {
    //     root->right = insert(root->right, value);
    //     root->right->parent = root;
    // }
    // return root;

    if (root == NULL)
    {
        return createTree(NULL, value);
    }
    Tree current = root;
    Tree parent = NULL;

    while (current)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->left;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            return root;
        }
    }

    Tree NewNode = createTree(parent, value);
    if (value < parent->value)
    {
        parent->left = NewNode;
    }
    if (value > parent->value)
    {
        parent->right = NewNode;
    }
    return root;
}

/*
 *	Funcție care verifică dacă un arbore este vid sau nu
 *		- întoarce 1 dacă arborele este vid
 *		- întoarce 0 dacă arborele nu este vid
 */
int isEmpty(Tree root)
{
    // TODO 2
    return root == NULL ? 1 : 0;
}

/*
 *	Funcție care verifică dacă o valoare există sau nu în arbore
 *		- 1 dacă value există în arbore
 *		- 0 dacă value nu există în arbore
 */
int contains(Tree tree, Item value)
{
    // TODO 3
    Tree current = tree;
    while (current)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

/*
 *	Funcție care determină elementul minim dintr-un arbore binar de căutare
 *		- NULL pentru arbore vid
 */
Tree minimum(Tree tree)
{
    // TODO 4.1
    if (tree == NULL)
    {
        return NULL;
    }
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree;
}

/*
 *	Funcție care determină elementul maxim dintr-un arbore binar de căutare
 *		- NULL pentru arbore vid
 */
Tree maximum(Tree tree)
{
    // TODO 4.2
    if (tree == NULL)
    {
        return NULL;
    }
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree;
}

/*
 *	Funcție care determină succesorul în inordine pentru nodul care conține
 * valoarea value.
 */
Tree successor(Tree root, Item value)
{
    // TODO 5
    Tree current = root;
    Tree successor = NULL;

    while (current)
    {
        if (value < current->value)
        {
            successor = current;
            current = current->left;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            if (current->right)
            {
                successor = minimum(current->right);
            }
            break;
        }
    }
    return successor;
}

/*
 *	Funcție care determină predecesorul în inordine pentru nodul care conține
 * valoarea value.
 */
Tree predecessor(Tree root, Item value)
{
    // TODO 6
    Tree current = root;
    Tree predecessor = NULL;

    while (current)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else if (value > current->value)
        {
            predecessor = current;
            current = current->right;
        }
        else
        {
            if (current->left)
            {
                predecessor = maximum(current->left);
            }
            break;
        }
    }
    return predecessor;
}

/*
 *	Funcție care dealocă întreaga memorie alocată pentru un arbore binar
 *		- root va pointa către NULL după ce se va apela funcția
 */
void destroyTree(Tree *root)
{
    // TODO
    destroyTree(&((*root)->left));
    destroyTree(&((*root)->right));

    // Eliberează memoria pentru nodul curent și setează pointerul la NULL
    free(*root);
    *root = NULL;
}

/*
 *	Funcție care șterge un nod cu o anumită valoare din arbore
 */
Tree delete(Tree root, Item value)
{
    // TODO 7
    if (root == NULL)
    {
        return root;
    }
    if (value < root->value)
    {
        root->left = delete(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        if (root->left && root->right)
        {
            Tree temp = minimum(root->right);
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
        }
        else
        {
            Tree temp = root;
            if (root->left)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            free(temp);
        }
    }
    return root;
}

/*
 *	Funcție care determină cel mai apropiat strămoș comun pentru
 * două noduri având cheile value1 și value2
 */
Tree lowestCommonAncestor(Tree root, Item value1, Item value2)
{
    // TODO 8
    if (root == NULL)
    {
        return NULL;
    }
    if (value1 < root->value && value2 < root->value)
    {
        return lowestCommonAncestor(root->left, value1, value2);
    }
    else if (value1 > root->value && value2 > root->value)
    {
        return lowestCommonAncestor(root->right, value1, value2);
    }
    else
    {
        return root;
    }
}
