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

// need to make average calculation for vecteurs
