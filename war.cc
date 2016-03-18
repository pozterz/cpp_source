#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    while(scanf("%lf %lf",&x,&y) && !feof(stdin)){
        if( y >= x )
            printf("%.0lf\n",y-x);
        else
            printf("%.0lf\n",x-y);
    }
    exit(EXIT_SUCCESS);
}
