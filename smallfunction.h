#include<stdlib.h>
#include<stdio.h>
#include "header.h"


int max(int a, int b,int c){ // for the rotation in the AVL
	if(a>b && a>c){
		return a;	
	}
	else if(a<=b && c<=b){
		return b;
	}
	else if(c>=a && c>=b){
		return c;
	}
	else if(a>=c && a>=b){
		return a;
	}
		
}
int min (int a, int b , int c){ // for the rotation of the AVL
	if(a<=b && b<=c){
		return a;
	}
	else if(b<=a && a<=c){
		return b;
	}
	else if(c<=a && a <=b){
		return c;
	}
}
int min2(int a, int b){ // for the rotation of the AVL
	if(a<=b){
		return a;
	}
	else{
	    return b;
	}
}
int max2(int a, int b){ // for the rotation in the AVL
	if(a<=b){
		return b;
	}
	else{
	    return a;
	}
}

// need to m

// need to make average calculation for vecteurs
int average( int a, int b , int c ){
	int total;
	int average;
	total=a+b+c;
	average=total/3;
	return average;
}	
