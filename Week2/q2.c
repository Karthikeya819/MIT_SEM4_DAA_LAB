// Write a program to find GCD using middle school method and analyze its time
// efficiency.
#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int TestCases;
    printf("Enter no of TestCases: ");scanf("%d",&TestCases);
    int nums1[TestCases],nums2[TestCases];
    for(int i = 0; i < TestCases; i++){
        printf("Enter TestCase %d number1: ",i+1);scanf("%d",&nums1[i]);
        printf("Enter TestCase %d number2: ",i+1);scanf("%d",&nums2[i]);
    }
    for(int i = 0; i < TestCases; i++){
        int ops = MiddleSchoolGCD(nums1[i],nums2[i]);
        printf("(m+n): %d ops: %d \n",nums1[i]+nums2[i],ops);
    }
}