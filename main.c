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
	char temperature[20];
	char tempe_min[20];
	char tempe_max[20];
	char station[20];
	 

}weather_elements;

weather_elements* createweather_element(){
	weather_elements* weather = malloc(sizeof(weather_elements));
	if(weather == NULL){
		exit(1);
	}
	return weather;
}
	

int main(int argc, const char* argv[]){
FILE* fichier = NULL;
char letter;
int whichfilter;
 
	switch(letter){
		case 'm':
			FILE* f1;
			f1=fopen("temp.csv","r");
			char line[50];
			char* humidity_c;
			char* x_c;
			char* y_c;
			if(f1 == NULL){
				printf("error humidity");
				exit(2);
			}
			
			switch (whichfilter){
				case 1 :
				AVL* humidity_avl = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->humidity=humidity_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						humidity_avl = addchildAVL(humidity_avl,weather);
						}
						walkthrough(humidity_avl,'m');	
					break;
				case 2 :
				ABR* humidity_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->humidity=humidity_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						humidity_abr = addchildABR(humidity_abr,weather);
						}
						walkthrough(humidity_avl,'m');	
					break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->humidity=humidity_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						int fusion=RapidFilter(...);
						}
						
					break;
				default :
					AVL* humidity_avl = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->humidity=humidity_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						humidity_avl = addchildAVL(humidity_avl,weather);
						}
						walkthrough(humidity_avl,'m');
				}
			
		case 'h' :
			FILE* f1;
			f1=fopen("temp.csv","r");
			char line[50];
			char* height_c;
			char* x_c;
			char* y_c;
			if(f1 == NULL){
				printf("error altitude");
				exit(2);
			}
			
			switch (whichfilter){
				case 1 :
				AVL* altitude_avl = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->altitude=height_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						altitude_avl = addchildAVL(altitude_avl,weather);
						}
						walkthrough(altitude_avl,'h');	
					break;
				case 2 :
				ABR* altitude_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->altitude=height_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						altitude_abr = addchildABR(altitude_abr,weather);
						}
						walkthrough(altitude_abr,'h');	
					break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->altitude=height_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						int fusion = RapidFilter(...);
						}
						
					break;
				default :
					AVL* altitude_avl = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";" 
						weather->altitude=height_c;
						weather->coord_x=x_c;
						weather->coord_y=y_c;
						altitude_avl = addchildAVL(altitude_avl,weather);
						}
						walkthrough(altitude_avl,'h');	
				}
			
		case 't' :
			FILE* f1;
			f1=fopen("temp.csv","r");
			char line[50];
			char* temp_c;
			char* ID;
			char* temp_min;
			char* temp_max;
			if(f1 == NULL){
				printf("error temp");
				exit(2);
			}
			
			switch (whichfilter){
				case 1 :
				AVL* temperature_avl = NULL;
				while(fgets(line,50,f1) != NULL){
					weather_elements* weather = createweather_element();
					ID = strtok(line,";");
					temp_c = strtok(NULL,";");
					temp_min = strtok(NULL,";");
					temp_max = strtok(NULL,";");
					weather->station=ID;
					weather->tempe_min = atoi(temp_min); 		// pas sur de ca 
					weather->tempe_max = atoi(temp_max);		// "		"
					weather->temperature= atoi(temp_c);		// "		"
				
				case 2 :
				
				case 3 :
					
						
					break;
				default :
					
				}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		default :
			printf("we have a problem");
		}
			
}
