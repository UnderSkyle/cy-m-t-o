typedef struct AVLNode2 {                          // structure for AVL //
  int value;
  int height;
  struct AVLNode2 *Left;
  struct AVLNode2 *Right;
} AVLNode;

typedef struct Tree{                             // structure for ABR //
	int value;
	struct Tree* pLeft;
	struct Tree* pRight;
}Tree;

//////////////////////////////////////////////AVL functions/////////////////////////////////////////
AVLNode *createtreeAVL(weather_elements* element)
AVLNode *rotate_right(AVLNode* pTree)
AVLNode *rotate_left(AVLNode *pTree) 
AVLNode* doublerotate_left(AVLNode* pTree)
AVLNode* doublerotate_right(AVLNode* pTree)
AVLNode* balanceAVL(AVLNode* pTree)
AVLNode* addchildAVL_B(AVLNode *pTree, weather_elements* elmt ,int* h)
AVLNode* addchildAVL_A(AVLNode *pTree, weather_elements* elmt)
void remakeAVL(AVLNode** pTree, AVLNode* pTree_tmp)
void walkthrough_infAvl(AVLNode* pTree, char cara)

/////////////////////////////////////////////fusion filter functions///////////////////////////////
void flip(int *a, int *b)
void Rapidfilter(int tab[], int first, int last)

/////////////////////////////////////////////ABR functions////////////////////////////////////////
Tree* createTreeABR(weather_elements* val)
int isEmpty(Tree* pTree)
Tree* addchildABR(Tree* pTree, weather_elements* val)
void processh(Tree* pTree, char cara)
void walkthrough_inf(Tree* pTree, char cara)

////////////////////////////////////////////small functions///////////////////////////////////////
int max(int a, int b,int c)
int min (int a, int b , int c)
int average( int a, int b , int c )
