#include <stdio.h>
#include <stdlib.h>

int EuclidGCD(unsigned int m, unsigned int n) {
    int r,opcount = 0;
    while(n!=0) {
        opcount++;
        r = m %n;
        m = n;
        n = r;
    }
    return opcount;
}
int PrimeFactors(int *factors, int number){
    int k = 0,count = 0;
    while(number %2 == 0){
        count++;
        factors[k++] = 2;
        number /= 2;
    }
    for(int i = 3;i<= number;i+=2){
        count++;
        while(number % i == 0){
            count++;
            factors[k++] = i;
            number /= i;
        }
    }
    return count;
}

int MiddleSchoolGCD(int number1, int number2){
    //int factors1[100],factors2[100];
    int *factors1 = (int*)calloc(100,sizeof(int));
    int *factors2 = (int*)calloc(100,sizeof(int));
    int gcd = 1;
    int ops1 = PrimeFactors(&factors1[0],number1);
    int ops2 = PrimeFactors(&factors2[0],number2);
    int i = 0, j = 0;

    while(factors1[i] && factors2[j]){
        if(factors1[i] < factors2[j])i++;
        else if(factors1[i] > factors2[j])j++;
        else {i++;j++;gcd*=factors1[i];}
        ops1++;
    }
    return ops1 + ops2;
}

int min(int number1, int number2){
    return (number1<number2)?number1:number2;
}

int GCD(int number1, int number2){
    int opercount = 0;
    int nmin = min(number1,number2);
    for(;nmin > 0;nmin--){
        opercount++;
        if((number1 % nmin == 0) && (number2 % nmin == 0))return opercount;
    }
}

int main(){
    int TestCases;
    printf("Enter no of TestCases: ");scanf("%d",&TestCases);
    int nums1[TestCases],nums2[TestCases];
    // for(int i = 0; i < TestCases; i++){
    //     printf("Enter TestCase %d number1: ",i+1);scanf("%d",&nums1[i]);
    //     printf("Enter TestCase %d number2: ",i+1);scanf("%d",&nums2[i]);
    // }
    int a = 8,b = 13;
    for(int i = 0; i < TestCases-2; i++){
        int ops = EuclidGCD(a,b);
        int ops1 = GCD(a,b);
        int ops2 = MiddleSchoolGCD(a,b);
        int c = a+b;
        printf("(m+n): %d ops: %d ops1: %d ops2: %d\n",c,ops,ops1,ops2);
        a =b;
        b =c;

    }
}