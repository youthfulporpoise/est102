#include <stdio.h>
#include <math.h>
#define N 3

typedef struct Point {
    float x;
    float y;
} Point;

int main() {
    Point points[N];    
    for (unsigned i = 0; i < N; ++i) {
        Point s = {};
        printf("Point %u: ", i + 1);
        scanf("%f %f", &s.x, &s.y);
        points[i] = s;
    }

    unsigned a, b;
    printf("Choose between two points (1-3): ");
    scanf("%u %u", &a, &b);
    --a; --b;
    if (a > 3 || b > 3) {
        puts("invalid point: only 1-3");
        return 1;
    }
    float distance = sqrt(
        pow(points[a].x - points[b].x, 2) +
        pow(points[a].y - points[b].y, 2)
        );
    printf("Distance (%g, %g) (%g, %g): %f\n",
            points[a].x, points[a].y, points[b].x, points[b].y, distance);
    return 0; 
}
