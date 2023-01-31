#include <stdio.h>
#include <stdlib.h>
#include "smallfunction.h"

//////////////////////////////////////// AVL filter////////////////////////////////////////////

typedef struct AVLNode2 {
  int value;
  int height;
  struct AVLNode2 *Left;
  struct AVLNode2 *Right;
} AVLNode;

int get_height(AVLNode *pTree) {
  if (pTree == NULL) {
    return 0;
  }
  return pTree->height;
}

int get_balance_factor(AVLNode *pTree) {
  if (pTree == NULL) {
    return 0;
  }
  return get_height(pTree->Left) - get_height(pTree->Right);
}

AVLNode *createtreeAVL(int val){
    AVLNode* pTree=malloc(sizeof(AVLNode));
    if(pTree==NULL){
        exit(1);
    }
    pTree->value=val;
    pTree->Left=NULL;
    pTree->Right=NULL;
    pTree->height=0;
    return pTree;

}

AVLNode *rotate_right(AVLNode* pTree) {
	AVLNode* Pivot=NULL;
	int eq_p,eq_a;
	Pivot=pTree->Right;
	pTree->Right=Pivot->Left;
	Pivot->Left = pTree;
	eq_a=pTree->height;
	eq_p=Pivot->height;
	pTree->height=eq_a-min(eq_p, 0) + 1;
	Pivot->height=max(eq_a+2,eq_a+eq_p+2,eq_p+1);
	Pivot=pTree;
	return pTree;
}

AVLNode *rotate_left(AVLNode *pTree) {
 	AVLNode* Pivot=NULL;
	int eq_p,eq_a;
	Pivot=pTree->Left;
	pTree->Left=Pivot->Right;
	Pivot->Right = pTree;
	eq_a=pTree->height;
	eq_p=Pivot->height;
	pTree->height=eq_a-min(eq_p, 0) + 1;
	pTree->height=max(eq_a+2,eq_a+eq_p+2,eq_p+1);
	Pivot=pTree;
	return pTree;
}
AVLNode* doublerotate_left(AVLNode* pTree){
	pTree->Right=rotate_right(pTree->Right);
	return rotate_left(pTree);
}
AVLNode* doublerotate_right(AVLNode* pTree){
	pTree->Left=rotate_left(pTree->Left);
	return rotate_right(pTree);
}
AVLNode* balanceAVL(AVLNode* pTree){
	if(pTree->height >= 2){
		if(pTree->height=get_height(pTree->Right) >= 0){
			return rotate_left(pTree);
		}
		else{
			return doublerotate_left(pTree);
		}
		
	}
	else if(pTree->height <= -2){
		if(pTree->height=get_height(pTree->Left)<= 0){
			return rotate_right(pTree);
		}
		else{
			return doublerotate_right(pTree);
		}
	}
	return pTree;
}

AVLNode* addchildAVL(AVLNode *pTree, int val,int* h) {
	if (val < pTree->value) {
    	pTree->Left = addchildAVL(pTree->Left, val, h);
  	} 
  	else if (val > pTree->value) {
   	 pTree->Right = addchildAVL(pTree->Right, val, h);
 	 } 
	else {
    	return pTree;
  	}
	if(pTree==NULL){
		*h=1;
	return createtreeAVL(val);
	}
	
	else if (val<pTree->value){
		pTree->Left=addchildAVL(pTree->Left,val,h);
		*h=-*h;
	}
	else if(val>pTree->value){
		pTree->Right=addchildAVL(pTree->Right,val,h);
		}
	else {
		*h=0;
		return pTree;
		}
	if(*h!=0){
	pTree->height = height + *h;
	pTree=balanceAVL(pTree);
		if(pTree->height == 0){
			*h=0;
		}
		else{
			*h=1;
		}
	}
return pTree;		
}




void walkthrough_pre(AVLNode* pTree){
	if(pTree != NULL){
		printf("|%d",pTree->value);
		walkthrough_pre(pTree->Left);
		walkthrough_pre(pTree->Right);
	}
}

///////////////////////////////////// simple filter///////////////////////////////////////////
void flip(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Rapidfilter(int tab[], int first, int last) {
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
        Rapidfilter(tab, first, j - 1);
        Rapidfilter(tab, j + 1, last);
    }
}

/////////////////////////////////////////////ABR filter////////////////////////////////////////

typedef struct Tree{
	int value;
	struct Tree* pLeft;
	struct Tree* pRight;
}Tree;

Tree* createTreeABR(int val){
	Tree* pTree=malloc(sizeof(Tree));
	if(pTree==NULL){
		exit(1);
	}
	pTree->value=val;
	pTree->pLeft=NULL;
	pTree->pRight=NULL;
	return pTree;
}

int isEmpty(Tree* pTree){
	return(pTree==NULL);
}


Tree* addchildABR(Tree* pTree, int val){
	if(isEmpty(pTree)){
		return (createTree(val));
	}
	if(val<pTree->value){
		pTree->pLeft=addchildABR(pTree->pLeft,val);
	}
	if(val>pTree->value){
		pTree->pRight=addchildABR(pTree->pRight,val);
	}
	return(pTree);
}




void process(Tree* pTree){
	if(!isEmpty(pTree)){
		printf("|%d",pTree->value);
	}
	
}

void walkthrough_pre(Tree* pTree){
	if(pTree != NULL){
	process(pTree);
	walkthrough_pre(pTree->pLeft);
	walkthrough_pre(pTree->pRight);	
	}
}
