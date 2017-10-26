/*
 * Problem 102: Triangle containment.
 *
 * https://projecteuler.net/problem=102
 */


#include <stdio.h>

#define VERBOSE 0


//Tells whether a one dimensional point is inside a segment
int is_point_in_segment(int point, int s1, int s2){
    if (s1 < s2){
        return point >= s1 && point <= s2;
    }
    else{
        return point >= s2 && point <= s1;
    }
}

//Tells whether a two dimensional segment intersects the x axis in (-inf, 0]
int intersects_x(int x1, int y1, int x2, int y2){
    //In the case of a horizontal segment intersection occurs only when they overlap
    if (y1 == y2){
        return y1 == 0;
    }
    
    //In any other case, calculate the segment and see if they cross
    if (x1 == x2){
        if (x1 <= 0){
            return is_point_in_segment(0, y1, y2);
        }
        return 0;
    }
    
    //In the case of a non vertical segment wee need to calculate the intersection point
    //In this program the point is calculated using the slope intercept formula
    float m = (y2-y1)/(float)(x2-x1);
    float b = y1 - m*x1;
    //m will never be 0
    float x = -b/m;
    if (x <= 0){
        return is_point_in_segment(x, x1, x2);
    }
    return 0;
}

//The only time a triangle contains the center is if a line along the x asis in (-infinity, 0]
//  intersects only one of the sides of the triangle
int main(){
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int intersections, count = 0;
    
    //Read the file
    FILE *file = fopen("triangles.txt", "r");
    if (file != NULL){
        while (fscanf(file, "%d,%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &x3, &y3) != EOF){
            //Reset the intersection count and test all three sides
            intersections = 0;
            if (intersects_x(x1, y1, x2, y2)){
                intersections++;
            }
            if (intersects_x(x1, y1, x3, y3)){
                intersections++;
            }
            if (intersects_x(x2, y2, x3, y3)){
                intersections++;
            }
            
            //If there is only one intersection, the triangle contains the center
            if (intersections == 1){
                count++;
            }
            
            if (VERBOSE){
                if (intersections == 1){
                    printf("(%d, %d), (%d, %d), (%d, %d) contains the center, 1 intersection\n", x1, y1, x2, y2, x3, y3);
                }
                else{
                    printf("(%d, %d), (%d, %d), (%d, %d) doesn't contain the center, %d intersections\n", x1, y1, x2, y2, x3, y3, intersections);
                }
            }
        }
        
        //Close, print the solution, and exit
        fclose(file);
        printf("\nThe number of triangles containing the center is %d\n\n", count);
        return 0;
    }
    else{
        printf("Couldn't read the file...\n\n");
        return 1;
    }
}
