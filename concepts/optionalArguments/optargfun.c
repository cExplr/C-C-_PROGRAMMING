#include<stdio.h>
#include<stdarg.h>

int add(int n,...);
int main(){
	
	printf("%d",add(6,2,3,5,6,8,12));
	
	return 0;
}
int add(int n,...){
	va_list argPtr;
	va_start(argPtr,n);
	int result=0;
	
	for(int i = 0 ; i<n;i++){
		result += va_arg(argPtr, int);
		}
	va_end(argPtr);
	return result;
}
