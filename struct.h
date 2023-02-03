#include <stdio.h>
#include <stdlib.h>

typedef struct weather_elements{
	int toSort;
	char altitude[20];
	char coord_x[40];
	char coord_y[40];
	char humidity[20];
	char temperature[20];
	char tempe_min[20];
	char tempe_max[20];
	char station[40];
}weather_elements;


typedef struct AVLNode2 {
  weather_elements* elmt;
  int height;
  struct AVLNode2 *Left;
  struct AVLNode2 *Right;
} AVLNode;

typedef struct Tree{
	weather_elements* elmt;
	struct Tree* pLeft;
	struct Tree* pRight;
}Tree;
