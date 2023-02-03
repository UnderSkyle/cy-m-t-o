#include <stdio.h>
#include <stdlib.h>
#include "smallfunction.h"
#include "header.h"


FILE* file;
//////////////////////////////////////// AVL filter////////////////////////////////////////////

AVLNode *createtreeAVL(weather_elements* element){
    AVLNode* pTree=malloc(sizeof(AVLNode));
    if(pTree==NULL){
        exit(1);
    }
    pTree->elmt=element;
    pTree->Left=NULL;
    pTree->Right=NULL;
    pTree->height=0;
    return pTree;

}

AVLNode *rotate_right(AVLNode* pTree) {
	AVLNode* Pivot=NULL;
	int eq_p,eq_a;
	Pivot=pTree->Left;
	pTree->Right=Pivot->Right;
	Pivot->Right = pTree;
	eq_a=pTree->height;
	eq_p=Pivot->height;
	pTree->height=eq_a-min(eq_a,eq_p, 0) + 1;
	Pivot->height=max(eq_a+2,eq_a+eq_p+2,eq_p+1);
	Pivot=pTree;
	return pTree;
}

AVLNode *rotate_left(AVLNode *pTree) {
 	AVLNode* Pivot=NULL;
	int eq_p,eq_a;
	Pivot=pTree->Right;
	pTree->Left=Pivot->Left;
	Pivot->Left = pTree;
	eq_a=pTree->height;
	eq_p=Pivot->height;
	pTree->height= (eq_a-min(eq_a, eq_p, 0) + 1);
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
		if(pTree->Right->height >= 0){
			return rotate_left(pTree);
		}
		else{
			return doublerotate_left(pTree);
		}

	}
	else if(pTree->height <= -2){
		if(pTree->Left->height<= 0){
			return rotate_right(pTree);
		}
		else{
			return doublerotate_right(pTree);
		}
	}
	return pTree;
}

AVLNode* addchildAVL_B(AVLNode *pTree, weather_elements* elmt ,int* h) {
	if(pTree==NULL){
		*h=1;
	return createtreeAVL(elmt);
	}
	if (elmt->toSort < pTree->elmt->toSort) {
    	pTree->Left = addchildAVL_B(pTree->Left , elmt, h);
  	}
  	else if (elmt->toSort > pTree->elmt->toSort) {
   	 pTree->Right = addchildAVL_B(pTree->Right , elmt, h);
	}
	else {
    	return pTree;
  	}


	if(*h!=0){
	pTree->height = pTree-> height + *h;
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
AVLNode* addchildAVL_A(AVLNode *pTree, weather_elements* elmt){
	int h;
	return addchildAVL_B(pTree,elmt,&h);
}
AVLNode* addchildAVL_A(AVLNode *pTree, int val, weather_elements* elmt){
	int h;
	return addchildAVL_B(pTree,  val, elmt,&h);
}
void remakeAVL(AVLNode** pTree, AVLNode* pTree_tmp){
	if(pTree_tmp != NULL){
		pTree_tmp -> element ->val_sorted = 1;
		*pTree = addchildAVL_A(*pTree,pTree_tmp->element->humidity, pTree_tmp-> element);
		remakeAVL(pTree, pTree_tmp->Left);
		remakeAVL(pTree, pTree_tmp->Right);
	}
}


void walkthrough_infAvl(AVLNode* pTree, char cara){
	if(pTree != NULL){
		walkthrough_infAvl(pTree->Left, cara);
		//processh(pTree); refait une ace AVLNode*
		walkthrough_infAvl(pTree->Right, cara);
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

Tree* createTreeABR(weather_elements* val){

	Tree* pTree=malloc(sizeof(Tree));
	if(pTree==NULL){
		exit(1);
	}
	pTree->elmt=val;
	pTree->pLeft=NULL;
	pTree->pRight=NULL;
	return pTree;
}

int isEmpty(Tree* pTree){
	if(pTree == NULL){
		return 1;
	}
}

Tree* addchildABR(Tree* pTree, weather_elements* val){
	if(isEmpty(pTree)){
		return (createTreeABR(val));
	}
	if(val->toSort<pTree->elmt->toSort){
		pTree->pLeft=addchildABR(pTree->pLeft,val);
	}
	if(val->toSort>pTree->elmt->toSort){
		pTree->pRight=addchildABR(pTree->pRight,val);
	}
	return(pTree);
}

void processh(Tree* pTree, char cara){
	file = fopen("output.csv","w");
	if(file == NULL){
		printf("Error file does not exist");
		exit(2);
	}
	if(!isEmpty(pTree)){
		switch (cara){
			case 'h' : fprintf(file, "%s %s %s", pTree->elmt->coord_x , pTree->elmt->coord_y, pTree->elmt->altitude); break;
			case 'm' : fprintf(file, "%s %s %s", pTree->elmt->coord_x , pTree->elmt->coord_y, pTree->elmt->humidity); break;
			case 'w' : break;
			case 't' : fprintf(file, "%s %s %s %s", pTree->elmt->station , pTree->elmt->temperature, pTree->elmt->tempe_min, pTree->elmt->tempe_min); break;
			//case 'p' : fprintf(file, "%s %s %s", pTree->elmt->coord_x , pTree->elmt->coord_y, pTree->elmt->pressure); break;
		}
	}
}


void walkthrough_inf(Tree* pTree, char cara){
	if(pTree != NULL){
	walkthrough_inf(pTree->pLeft, cara);
	processh(pTree, cara);
	walkthrough_inf(pTree->pRight, cara);
	}
}

