#include <stdio.h>
#include <stdlib.h>

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

AVLNode *createtree(int val){
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

AVLNode* value_search(AVLNode* pTree,int e){
	if(pTree==NULL){
		return NULL;
	}
	else if(pTree->value == e){
		return pTree;
	}
	else if(e < pTree->value){
		return value_search(pTree->Left,e);
	}
	else{
		return value_search(pTree->Right,e);
	}
}





int max(int a, int b,int c){
	if(a>b && a>c){
		return a;	
	}
	if(a<b && c<b){
		return b;
	}
	if(c>a && c>b){
		return c;
	}
	if( a=b && a>c){
		return a;
	}
	if( b=c && b>a){
		return b;
	}
	if( a=c && c>b){
		return c;
	}
	else{
		return a;
	}
		
}
int min (int a, int b){
	if(a>b){
		return a;
	}
	if(a<b){
		return b;
	}
	else{
		return a;
	}
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

AVLNode* insert(AVLNode *pTree, int val,int* h) {
	if (val < pTree->value) {
    	pTree->Left = insert(pTree->Left, val, h);
  	} 
  	else if (val > pTree->value) {
   	 pTree->Right = insert(pTree->Right, val, h);
 	 } 
	else {
    	return pTree;
  	}
	if(pTree==NULL){
		*h=1;
	return createtree(val);
	}
	
	else if (val<pTree->value){
		pTree->Left=insert(pTree->Left,val,h);
		*h=-*h;
	}
	else if(val>pTree->value){
		pTree->Right=insert(pTree->Right,val,h);
		}
	else {
		*h=0;
		return pTree;
		}
	if(*h!=0){
	pTree->height+=*h;
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

int main(){
AVLNode* Luffy=NULL;
printf("%d", Luffy->value);
int h;
Luffy=createtree(10);

insert(Luffy,3,&h);
insert(Luffy,9,&h);
insert(Luffy,4,&h);
insert(Luffy,12,&h);
insert(Luffy,6,&h);
insert(Luffy,1,&h);
walkthrough_pre(Luffy);




return 0;
}


