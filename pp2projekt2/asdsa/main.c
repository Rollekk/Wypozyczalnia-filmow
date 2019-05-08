#include <stdio.h>
#include <stdlib.h>

int rekurencja(int i)
{
    if(i==1){
        return 3;
    }else{
        return (rekurencja(i) + 2);}
        printf("\n%d\n", i);

}

int main()
{
    puts("_______________");
    int i;
    scanf("%d", &i);
    rekurencja(i);
    return main();
}
