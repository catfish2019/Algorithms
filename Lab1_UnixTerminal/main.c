// Add your program here!
# include <stdio.h>
double power(double base, double n){
	double result = 1;
	for (int i = 1; i <= n; i ++){
		result = result * base;
	}
	return result;
}

int main(){
for (int i = 1; i < 11; i++){
double p = power(2, i);
printf("power(2, %i) is %f\n", i, p);
}
return 0;

}
