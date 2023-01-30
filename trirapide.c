#include <stdio.h>

void flip(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                flip(&tab[i], &tab[j]);
            }
        }
        flip(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

int main() {
    int tab[100], nbr, i;
  
    printf("\n Entrer the total amount of elements :  ");
    scanf("%d", &nbr);
    
    printf("\n Entrer the elements  :  ");
    for(i = 0; i < nbr; i++)
        scanf("%d", &tab[i]);
    
    triRapid(tab, 0, nbr - 1);
    
    printf("\n organized from lowest to highest : ");
    for(i = 0; i < nbr; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}
