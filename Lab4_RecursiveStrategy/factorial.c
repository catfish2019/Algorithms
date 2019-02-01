// gcc factorial.c -o factoriali
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
long factorial(int n){
	long factorial = 1;
	if (n > 0) {
		for (int i = 1; i <= n; i++){
			factorial = factorial * i;
		}
		return factorial;
	}
		else{
			return 0;
		}
}


// TODO: Implement recursive solution here
long factorial_rec(int n){
	if (n > 0){
		return n * factorial_rec(n - 1);
	}
	else{
		return 1;
	}
}

int main(){

  printf("factorial(10) = %ld\n",factorial(10));
  printf("factorial_rec(10) = %ld\n",factorial_rec(10));


  return 0;
}
