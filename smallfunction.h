int max(int a, int b,int c){ // for the rotation in the AVL
	if(a>b && a>c){
		return a;	
	}
	if(a<b && c<b){
		return b;
	}
	if(c>a && c>b){
		return c;
	}
	if( a=b && a>c){
		return a;
	}
	if( b=c && b>a){
		return b;
	}
	if( a=c && c>b){
		return c;
	}
	else{
		return a;
	}
		
}
int min (int a, int b){ // for the rotation of the AVL
	if(a>b){
		return a;
	}
	if(a<b){
		return b;
	}
	else{
		return a;
	}
}

// need to make average calculation for vecteurs
