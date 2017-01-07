#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main(){
    Score students[22];
    int i, n;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d%d%d",&students[i].score[0],&students[i].score[1],&students[i].score[2]);
        students[i].id=i+1;
    }
    qsort(students, n, sizeof(Score), cmp);

    for(i=0;i<n;i++){
        printf("%d ", students[i].id);
    }
    return 0;
}
