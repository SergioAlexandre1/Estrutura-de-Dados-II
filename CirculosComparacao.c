#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1 = 0, y1 = 0;
    int x2, y2;
    int r1, r2;

    printf("Digite o raio do Círculo 1: ");
    scanf("%d", &r1);

    printf("Digite o raio do Círculo 2: ");
    scanf("%d", &r2);

    printf("Digite o ponto x do Círculo 2: ");
    scanf("%d", &x2);

    printf("Digite o ponto y do Círculo 2: ");
    scanf("%d", &y2);

    double d = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));

    if (d == 0 && r1 == r2) {
        printf("Os círculos são iguais com mesmo raio e possuem infinitos pontos em comum.\n");
    } else if (d > r1 + r2) {
        printf("Os círculos não se encostam.\n");
    } else if (d < fabs(r1 - r2)) {
        printf("Os círculos não se encostam.\n");
    } else if (d == r1 + r2) {
        printf("Os círculos se encostam em 1 ponto tangencial externo.\n");
    } else if (d == fabs(r1 - r2)) {
        printf("Os círculos se encostam em 1 ponto tangencial interno.\n");
    } else {
        printf("Os círculos se encontram em 2 pontos.\n");
    }
    return 0;
}