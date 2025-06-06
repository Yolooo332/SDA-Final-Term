/*
 *	Created by Nan Mihai on 11.04.2023
 *	Copyright (c) 2023 Nan Mihai. All rights reserved.
 *	Laborator 7 - Structuri de date și algoritmi
 *	Facultatea de Automatica si Calculatoare
 *	Anul Universitar 2022-2023, Seria CD
 */
#include "avl.h"

Tree createTree(T value)
{
    Tree root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->value = value;
    root->left = root->right = NULL;
    root->height = 0;
    return root;
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(Tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int balancedFactor(Tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (height(root->right) - height(root->left));
}

void updateHeight(Tree root)
{
    if (root == NULL)
    {
        return;
    }
    root->height = 1 + max(height(root->left), height(root->right));
}

Tree leftRotation(Tree x)
{
    Tree z;
    z = x->right;
    x->right = z->left;
    z->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    z->height = max(height(z->right), x->height) + 1;
    return z;
}

Tree rightRotation(Tree x)
{
    Tree z;
    z = x->left;
    x->left = z->right;
    z->right = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    z->height = max(height(z->left), x->height) + 1;
    return z;
}

Tree insert(Tree root, T value)
{
    if (root == NULL)
    {
        root = createTree(value);
        return root;
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        return root;
    }
    root->height = max(heigh(root->left), height(root->right)) + 1;
    int bf = height(root->left) - height(root->right);
    if (bf > 1 && value < root->left->value)
    {
        return rightRotation(root);
    }
    if (bf < -1 && value > root->right->value)
    {
        return leftRotation(root);
    }
    if (bf > 1 && value > root->left->value)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (bf < -1 && value < root->right->value)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

Tree minimum(Tree root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Tree delete(Tree root, T value)
{
    if (root == NULL)
    {
        return NULL;
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
        if (root->left == NULL || root->right == NULL)
        {
            Tree temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        Tree temp = minimum(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }

    updateHeight(root);

    int bf = balancedFactor(root);

    if (bf > 1 && balancedFactor(root->left) >= 0)
    {
        return rightRotation(root);
    }
    if (bf < -1 && balancedFactor(root->right) <= 0)
    {
        return leftRotation(root);
    }
    if (bf > 1 && balancedFactor(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (bf < -1 && balancedFactor(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

Tree freeTree(Tree root)
{
    if (root == NULL)
    {
        return NULL;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
    return NULL;
}
