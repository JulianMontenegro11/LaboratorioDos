#include "problemas.h"
#include "auxiliar.h"

bool numAmigable (int n){

    bool x=true;
    int divisor1=0, divisor2=0;

    for(int i=1;i<=n/2;i++)if(n%i==0)divisor1+=i;
    for(int i=1;i<=divisor1/2;i++)if(divisor1%i==0)divisor2+=i;


    if(n!=divisor2 || n==divisor1) x=false;
    return x;
}



