#include <stdio.h>

typedef int T;
#include "SortedList.h"

TSortedList getNaturals(int A, int B)
{
    TSortedList nats = NULL;
    int i;
    for (i = A; i <= B; i++)
    {
        nats = insert(nats, i);
    }
    return nats;
}

TSortedList getPrimes(int N)
{
    TSortedList nats = getNaturals(2, N);

    // TODO: Cerința Bonus

    while (nats != NULL)
    {
        TSortedList current = nats;
        int prime = current->value;
        nats = nats->next;

        // Remove all multiples of the prime
        TSortedList prev = NULL;
        TSortedList curr = nats;
        while (curr != NULL)
        {
            if (curr->value % prime == 0)
            {
                if (prev == NULL)
                {
                    nats = curr->next;
                    free(curr);
                    curr = nats;
                }
                else
                {
                    prev->next = curr->next;
                    free(curr);
                    curr = prev->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    return nats;
}

void printInts(TSortedList list)
{
    while (!isEmpty(list))
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    printInts(getPrimes(100));
    return 0;
}
