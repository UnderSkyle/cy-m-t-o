#include<stdlib.h>
#include<stdio.h>
#include "filter.h"
#include "struct.h"


 

int main(){
FILE* fichier = NULL;
char letter;
int whichfilter;
 
	switch(letter){
		case 'm':
			switch (whichfilter){
				case 1 :
					trier AVL
					break;
				case 2 :
					trier abr
					break;
				case 3 :
					trier tab
					break;
				default :
					trier AVL
				}
			
		case 'h' :
			switch (whichfilter){
				case 1 :
					trier AVL
					break;
				case 2 :
					f1=fopen("temp.csv","r");
					if(f1 != NULL){
						while(f1 != EOF){
							fscanf(f1,"%d %d", coordinates, altitude);
							
							
							}
						}
					break;
				case 3 :
					trier tab
					break;
				default :
					trier AVL
				}
			
		default :
			printf("we have a problem");
		}
		
	
}
