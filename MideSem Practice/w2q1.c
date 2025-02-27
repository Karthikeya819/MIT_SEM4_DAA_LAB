#include <stdio.h>

int EuclidGCD(int a, int b){
    if(a == 0) return b;
    return EuclidGCD(b%a,a);
}
int nmin(int a,int b){
    return (a<b)?a:b;
}

int ConsecutiveGCD(int a,int b){
    int i = nmin(a,b);
    for(;i>0;i--){
        if( a % i == 0 && b % i == 0)return i;
    }
}

int PrimeFactors(int *factors,int number){
    int i = 0;
    while(number % 2 == 0){
        factors[i++] = 2;
        number /= 2;
    }
    for(int j = 3;j<=number;j+=2){
        while(number % j == 0){
            factors[i++] = j;
            number /= j;
        }
    }
    return i;
}
int MiddleSchoolGCD(int a, int b){
    int PrimeF1[100],PrimeF2[100];
    int len1 = PrimeFactors(&PrimeF1[0],a);
    int len2 = PrimeFactors(&PrimeF2[0],b);
    int i=0,j=0,gcd=1;
    while(i<len1 && j<len2){
        if(PrimeF1[i] == PrimeF2[j]){
            gcd *= PrimeF1[i];
            i++;j++;
        }else if(PrimeF1[i] > PrimeF2[j])j++;
        else if(PrimeF1[i] < PrimeF2[j])i++;
    }
    return gcd;
}

int main(){
    int a,b;
    printf("Enter a: ");scanf("%d",&a);
    printf("Enter b: ");scanf("%d",&b);
    printf("Euclid Result: %d",EuclidGCD(a,b));
    printf("\nConsecutive Result: %d",ConsecutiveGCD(a,b));
    printf("\nMiddleSchool Result: %d",MiddleSchoolGCD(a,b));

    return 0;
}