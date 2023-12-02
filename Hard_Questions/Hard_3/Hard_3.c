
#include <stdio.h>
#include <math.h>


//counts the number of one's
int countDigitOne(int n) {
    if (n <= 0) {
        return 0;
    }

    int count = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        count += (n / divider) * i + fmin(fmax(n % divider - i + 1, 0), i);
    }

    return count;
}

int main() {
    // Enter the value of integer
    
    int n;
    scanf("%d",&n);
    
    //if integer is greater than 109 or less than 0 we have to re enter the integer
    if(n<=0 || n>109)
    {
		
		   printf("you have enterd number more than 109 or less than 0 please re-enter\n");
		   
		   scanf("%d",&n);

	}
    
    //Print the output
    printf("Output 1: %d\n", countDigitOne(n));

    

    return 0;
}
