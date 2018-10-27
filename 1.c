#include <stdio.h> 

int main() {

    int i,n;

    scanf("%d",&n);
    char s[n][100];


    for(i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("%s\n",s[i]);
    }

    return 0;

}