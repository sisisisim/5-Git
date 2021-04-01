#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double recursion(int n )
{
    if(n == 1)
        return 1;
    double multi = 1;
    for(int i = 1;i<=n;i++)
        multi *= i;
    return (recursion(n-1) + multi);
}

int main(){
    double sum = 0, multi = 1;
    struct timeval start, end;
    gettimeofday( &start, NULL );
    
    for(int i = 0;i<1000;i++){
        sum = recursion(15);
    }
    
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    
    printf("n = 15, sum = %f\n", sum);
    printf("time: %d us\n", timeuse);

    return 0;
} 