#include<stdlib.h>
#include<stdio.h>
#include "filter.h"
#include<string.h>
#include "header.h"


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
					while(fgets(line,50,f1) != NULL){				//continues to read the doc until the end
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);			// copying the info from each element
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_avl = addchildAVL_A(humidity_avl,weather);	//sending into the filter 
						}
						walkthrough_infAvl(humidity_avl,'m');			// sending back the info in descending order
					break;
				case 2 :
				Tree* humidity_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);			//copying the info 
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_abr = addchildABR(humidity_abr,weather);	//sending into the filter
						}
						walkthrough_inf(humidity_abr,'m');			// sending back the info in descending order
            break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						humidity_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->humidity, humidity_c);			//copying the info
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
						strcpy(weather->humidity, humidity_c);			//copying the info
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(humidity_c);
						humidity_avl = addchildAVL_A(humidity_avl,weather);	// sending it into the filter 
						}
						walkthrough_infAvl(humidity_avl,'m');			// sending back the info in descending order
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
						strcpy(weather->altitude, height_c);			//copying the info
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_avl = addchildAVL_A(altitude_avl,weather);	//sending it into the filter
						}
						walkthrough_infAvl(altitude_avl,'h');			// sending back the info in descending order
					break;
				case 2 :
				Tree* altitude_abr = NULL;
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);			//copying the info
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_abr = addchildABR(altitude_abr,weather);	//sending it into the filter
						}
						walkthrough_inf(altitude_abr,'h');			// sending back the info in descending order

					break;
				case 3 :
					while(fgets(line,50,f1) != NULL){
						weather_elements* weather = createweather_element();
						y_c = strtok(line,","); 				// taking the data from the beginning of the folder til ","
						x_c = strtok(NULL,";"); 				// taking from "," to ";"
						height_c = strtok(NULL,";"); 				//taking from ";" to ";"
						strcpy(weather->altitude, height_c);			//copying the info
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
						strcpy(weather->altitude, height_c);			//copying the info
						strcpy(weather->coord_x, x_c);
						strcpy(weather->coord_y,y_c);
						weather->toSort = atoi(height_c);
						altitude_avl = addchildAVL_A(altitude_avl,weather);	//sending it into the filter
						}
					walkthrough_infAvl(altitude_avl,'h');				// sending back the info in descending order
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
					ID = strtok(line,";");						//taking the data from the beginning to ;
					temp_c = strtok(NULL,";");					//taking the info from where it ended to ;
					temp_min = strtok(NULL,";");					//taking the info from where it ended to ;
					temp_max = strtok(NULL,";");					//taking the info from where it ended to ;
					strcpy(weather->station,ID);
					strcpy(weather->tempe_min,temp_min); 		
					strcpy(weather->tempe_max,temp_max);		
					strcpy(weather->temperature,temp_c);
					weather->toSort = atoi(ID);
					temperature_avl = addchildAVL_A(temperature_avl, weather);	//sending it into the filter
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
