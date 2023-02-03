#include<stdlib.h>
#include<stdio.h>

typedef struct Tree{
	int value;
	struct Tree* pLeft;
	struct Tree* pRight;
}Tree;

Tree* createTree(int val){
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

int recherche(Tree* pTree, int val){
	if(isEmpty(pTree)){
		return 0;
	}
	else if(pTree->value==val){
		return 1;
	}
	else if(val<pTree->value){
		return recherche(pTree->pLeft,val);
	}
	else{
		recherche(pTree->pRight,val);
	}
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

Tree* suppMax(Tree* pTree,int *pval){
	Tree* tmp=NULL;
	if(pTree->pRight!=NULL){
		pTree->pRight=suppMax(pTree->pRight,pval);
	}
	else{
		*pval=pTree->value;
		tmp=pTree;
		pTree=pTree->pLeft;
		free(tmp);
	}
	return pTree;
}

Tree* suppression(Tree* pTree,int val){
	Tree* tmp=NULL;
	if(isEmpty(pTree)){
		return pTree;
	}
	else if(val>pTree->value){
		pTree->pRight=suppression(pTree->pRight,val);
	}
	else if(val<pTree->value){
		pTree->pLeft=suppression(pTree->pLeft,val);
	}
	else if(pTree->pLeft==NULL){
		tmp=pTree;
		pTree=pTree->pRight;
		free(tmp);
	}
	else{
		pTree->pLeft=suppMax(pTree->pLeft,&pTree->value);
	}
	return pTree;	
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
 int main(){
	int val;
	Tree* Luffy=NULL;
	Luffy=createTree(10);
	addchildABR(Luffy,3);
	addchildABR(Luffy,5);
	addchildABR(Luffy,15);
	addchildABR(Luffy,20);
	addchildABR(Luffy,12);
	addchildABR(Luffy,7);
	addchildABR(Luffy,45);
	addchildABR(Luffy,9);
	walkthrough_pre(Luffy);
	if(recherche(Luffy,20)==1){
		printf("\nLa valeur 20  est bien dans l'arbre");
	}
	printf("\n");
	suppression(Luffy,15);	
	walkthrough_pre(Luffy);
	printf("\n");

	return 0;
}

