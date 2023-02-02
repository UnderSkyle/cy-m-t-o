#include<stdlib.h>
#include<stdio.h>
#include "filter.h"
#include "struct.h"
#include<string.h>

typedef struct weather_elements{
	int val;
	char altitude[20];
	char coord_x[20];
	char coord_y[20];
	char humidity[20];
	 

}weather_elements;

weather_elements* createweather_element(){
	weather_elements* weather = malloc(sizeof(weather_elements));
	if(weather == NULL){
		exit(1);
	}
	return weather;
}
	

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
			FILE* f1;
			f1=fopen("temp.csv","r");
			char line[50];
			char* height_c;
			char* x_c;
			char* y_c
			switch (whichfilter){
				case 1 :
					trier AVL
					break;
				case 2 :
					if(f1 == NULL){
						printf("error altitude abr");
						exit(2);
					}
					AVLNode* altitude_avl = NULL;
						while(fgets(line,50,f1) != NULL){
							weather_elements* weather = createweather_element();
							y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
							x_c = strtok(NULL,";"); 				// taking from "," to ";"
							height_c = strtok(NULL,";"); 				//taking from ";" to ";" 
							weather->altitude=height_c;
							weather->coord_x=x_c;
							weather->coord_y=y_c;
							
						
					
					
							
							
						
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
