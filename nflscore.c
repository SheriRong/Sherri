#include<stdio.h>
int main(void)
{
    int stop =0 ;
    int score;
    printf("Enter 0 or 1 to STOP\n");
{
     printf("Enter the NFL score:");
     scanf(" %d", &score);
     int i,j,k,b,a, remain;
    for( i = 0; i < 25; i++){
        for (j = 0; j<25; j++){
            for (k =0; k<25; k++){
                for (b = 0; b<25; b++){
                    for (a =0;a<25; a++){
                        remain = score - (8*i)-(7*j)-(6*k)-(3*b)-(2*a);
                        if (remain==0){
                           printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",i,j,k,b,a);
                        }
                    }
                }
            }
        }
    }
    scanf("%d", &stop);
} while(stop !=1)
return 0;
}
