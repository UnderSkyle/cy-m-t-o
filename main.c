#include<stdlib.h>
#include<stdio.h>
#include "filter.h"
#include<string.h>


weather_elements* createweather_element(){
	weather_elements* weather = malloc(sizeof(weather_elements));
	if(weather == NULL){
		exit(1);
	}
	return weather;
}


int main(int argc, const char* argv[]){
	printf("hello1");
	FILE* fichier = NULL;
	char letter = argv[1][0];
	int whichfilter = atoi(argv[2]);
	AVLNode* humidity_avl = NULL;
	Tree* humidity_abr = NULL;
	AVLNode* altitude_avl = NULL;
	Tree* altitude_abr = NULL;
	AVLNode* temperature_avl = NULL;
	FILE* f1;
	f1=fopen("temp.csv","r");
	char line[50];
	char* x_c;
	char* y_c;
	printf("hello");
	switch(letter){
		case 'm':
			char* humidity_c;
			if(f1 == NULL){
				printf("error humidity");
				exit(2);
			}

			switch (whichfilter){
				case 1 :
				AVLNode* humidity_avl = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_avl = addchildAVL_A(humidity_avl,weather);
						}
						walkthrough_infAvl(humidity_avl,'m');
					break;
				case 2 :
				Tree* humidity_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_abr = addchildABR(humidity_abr,weather);
						}
						walkthrough_inf(humidity_abr,'m');
            break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						//int fusion=RapidFilter(...);
						}

					break;
				default :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_avl = addchildAVL_A(humidity_avl,weather);
						}
						walkthrough_infAvl(humidity_avl,'m');
				}

		case 'h' :
			char* height_c;
			if(f1 == NULL){
				printf("error altitude");
				exit(2);
			}

			switch (whichfilter){
				case 1 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_avl = addchildAVL_A(altitude_avl,weather);
						}
						walkthrough_infAvl(altitude_avl,'h');
					break;
				case 2 :
				Tree* altitude_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_abr = addchildABR(altitude_abr,weather);
						}
						walkthrough_inf(altitude_abr,'h');

					break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						//int fusion = RapidFilter(...);
						}
					break;
				default :
					AVLNode* altitude_avl = NULL;

					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_avl = addchildAVL_A(altitude_avl,weather);
						}
					walkthrough_infAvl(altitude_avl,'h');
					break;
				}

		case 't' :
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
				AVLNode* temperature_avl = NULL;

				while(fgets(line,50,f1) != NULL){
					weather_elements* weather = createweather_element();
					ID = strtok(line,";");
					temp_c = strtok(NULL,";");
					temp_min = strtok(NULL,";");
					temp_max = strtok(NULL,";");
					strcpy(weather->station,ID);
					strcpy(weather->tempe_min,temp_min); 		// pas sur de ca
					strcpy(weather->tempe_max,temp_max);		// "		"
					strcpy(weather->temperature,temp_c);		// "		"
					weather->toSort = atoi(ID);
					temperature_avl = addchildAVL_A(temperature_avl, weather);
				}break;

				case 2 : break;

				case 3 :


					break;
				default :
				break;
				}


		default :
			printf("we have a problem");
		}
}
