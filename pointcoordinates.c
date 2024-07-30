#include <stdio.h>

struct Point {
    int x;
    int y;
};

int getQuadrant(struct Point p) {
    if (p.x > 0 && p.y > 0) {
        return 1; // First quadrant
    } else if (p.x < 0 && p.y > 0) {
        return 2; // Second quadrant
    } else if (p.x < 0 && p.y < 0) {
        return 3; // Third quadrant
    } else if (p.x > 0 && p.y < 0) {
        return 4; // Fourth quadrant
    } else {
        return 0; // On axis or origin
    }
}

int main() {
    struct Point p;

    printf("Enter the x-coordinate of the point: ");
    scanf("%d", &p.x);

    printf("Enter the y-coordinate of the point: ");
    scanf("%d", &p.y);

    int quadrant = getQuadrant(p);

    switch (quadrant) {
        case 1:
            printf("The point is in the first quadrant.\n");
            break;
        case 2:
            printf("The point is in the second quadrant.\n");
            break;
        case 3:
            printf("The point is in the third quadrant.\n");
            break;
        case 4:
            printf("The point is in the fourth quadrant.\n");
            break;
        default:
            printf("The point is on an axis or at the origin.\n");
            break;
    }

    return 0;
}