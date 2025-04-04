#include <stdio.h>
#include <math.h>

int EuclidGCD(int m, int n){
    if(n == 0)return m;
    return EuclidGCD(n, m%n);
}

int max(int m, int n){
    return (m > n)?m:n;
}

int ConsecutiveInt(int m ,int n){
    int maximum = max(m,n);
    while(maximum > 1){
        if(m%maximum == 0 && n%maximum == 0)return maximum;
        maximum --;
    }
    return maximum;
}

int primeFactors(int *factor,int m){
    int i = 0;
    while(m%2 == 0){
        factor[i++] = 2;
        m /= 2;
    }
    for(int j = 3;j <= m;j++){
        while(m%j == 0){
            factor[i++] = j;
            m /= j;
        }
    }
    return i;
}

int MiddleSchool(int m, int n){
    int Factors1[50],Factors2[50];
    int len1 = primeFactors(&Factors1[0],m);
    int len2 = primeFactors(&Factors2[0],n);
    int GCD = 1;
    int i=0,j=0;
    while(i < len1 && j < len2){
        if(Factors1[i] == Factors2[j]){
            GCD *= Factors1[i];
            i++;j++;
        }else if(Factors1[i] > Factors2[j])j++;
        else i++;
    }
    return GCD;

}

int main(){
    printf("Hello World!");
    printf("%d /n",EuclidGCD(56,14));
    printf("%d /n",ConsecutiveInt(56,14));
    printf("%d",MiddleSchool(56,14));

    return 0;
}