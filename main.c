#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
#include "filter.h"


weather_elements* createweather_element(){                                                    
	weather_elements* weather = malloc(sizeof(weather_elements));    
	if(weather == NULL){
		exit(1);
	}
	return weather;
}


int main(int argc, const char* argv[]){
	FILE* fichier = NULL;
	char letter = argv[1][0];		// retrieving the info for with element 
	int whichfilter = atoi(argv[2]);	// retrieving which number to know which filter to use 
	AVLNode* humidity_avl = NULL; 		// all the different trees for the filters
	Tree* humidity_abr = NULL;
	AVLNode* altitude_avl = NULL;
	Tree* altitude_abr = NULL;
	AVLNode* temperature_avl = NULL;
	FILE* f1;
	f1=fopen("temp.csv","r"); 		// opening the filtered file 
	char line[50];				//to keep the amount of lines known
	char* x_c;
	char* y_c;
	char* humidity_c;
	char* height_c;
	char* temp_c;
	char* ID;
	char* temp_min;
	char* temp_max;
	weather_elements** tab = malloc(63*sizeof(malloc(sizeof(weather_elements))));
	int j = 0;
	int isIn = 0;
	switch(letter){
		case 'm':
			if(f1 == NULL){
				printf("error file not existant");
				exit(2);
			}
			switch (whichfilter){
				case 1 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						if(line[0] == ';'){
							continue;
						}
						else{
							humidity_c = strtok(line, ";");
							y_c = strtok(NULL,","); 				// taking the data from the beginning of the folder til ","
							x_c = strtok(NULL,"\n"); 				// taking from "," to ";"
							strcpy(weather->humidity, humidity_c);
							strcpy(weather->coord_x, x_c);
							strcpy(weather->coord_y,y_c);
							weather->toSort = atoi(humidity_c);
							//printf("%s %s %d\n", weather->coord_x, weather->coord_y, weather->toSort);
						humidity_avl = addchildAVL_A(humidity_avl, weather);
						}
					}
					printf("ok");
					walkthrough_infAvl(humidity_avl,'m');

					break;
				case 2 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						if(line[0] == ';'){
							continue;
						}
						else{
							humidity_c = strtok(line, ";");
							y_c = strtok(NULL,","); 				// taking the data from the beginning of the folder til ","
							x_c = strtok(NULL,"\n"); 				// taking from "," to ";"
							strcpy(weather->humidity, humidity_c);
							strcpy(weather->coord_x, x_c);
							strcpy(weather->coord_y,y_c);
							weather->toSort = atoi(humidity_c);
							humidity_abr = addchildABR(humidity_abr, weather);

						}
					}
					walkthrough_inf(humidity_abr,'m');
					break;
				default :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						if(line[0] == ';'){
							continue;
						}
						else{
							humidity_c = strtok(line, ";");
							y_c = strtok(NULL,","); 				// taking the data from the beginning of the folder til ","
							x_c = strtok(NULL,"\n"); 				// taking from "," to ";"
							strcpy(weather->humidity, humidity_c);
							strcpy(weather->coord_x, x_c);
							strcpy(weather->coord_y,y_c);
							weather->toSort = atoi(humidity_c);
							//printf("%s %s %d\n", weather->coord_x, weather->coord_y, weather->toSort);
						humidity_avl = addchildAVL_A(humidity_avl, weather);
						}
					}
					printf("ok");
					walkthrough_infAvl(humidity_avl,'m');
			}


		case 'h' :
			if(f1 == NULL){
				printf("error altitude");
				exit(2);
			}

			switch (whichfilter){

				default :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						if(line[0] == ';'){
							continue;
						}
						else{
							y_c = strtok(NULL,","); 				// taking the data from the beginning of the folder til ","
							x_c = strtok(NULL,";"); 				// taking from "," to ";"
							height_c = strtok(line, "\n");
							strcpy(weather->altitude, height_c);
							strcpy(weather->coord_x, x_c);
							strcpy(weather->coord_y,y_c);
							weather->toSort = atoi(height_c);
						}
					}

			}
			break;


		case 't' :

			if(f1 == NULL){
				printf("error temp");
				exit(2);
			}

			switch (whichfilter){

				default :
				break;
				}

		}
	return 0;
}
