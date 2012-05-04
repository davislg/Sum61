// ***************************************************************
//  main.c
//  Sum61
//
//  Created by Davis on 5/2/12.
//  Copyright (c) 2012 Liquid Thoughts. All rights reserved.
//
// Simple project to help my son understand how quickly a computer
// can solve math problems.
// ***************************************************************

#include <stdio.h>

// ************
// Declarations
// ************
static const int PROBLEM_1              = 0x31;
static const int PROBLEM_1_DESCRIPTION  = 0x32;
static const int PROBLEM_2              = 0x33;
static const int QUIT                   = 0x30;

// ************************************
// Show menu of options to choose from.
// ************************************
void showMenu() {
    printf("\nPlease choose a problem to solve.\n");
    printf("\t0) Quit.\n");
    printf("\t1) Problem 1: Find 2 numbers (x,y) whose sum is 61 and y = x + 5.\n");
    printf("\t2) Problem 1: Description\n");
    printf("\t3) Problem 2: Find 2 numbers whose difference is 10 and whose sum is 14.\n");
}

// *******************************
// Find 2 numbers whose sum is 61.
// *******************************
void problem1Description() {
    int sum     = 61;
    int vSum    = 0;
    int x       = 0;
    int y       = 0;    

    printf("Find 2 numbers (x,y) whose sum is 61 where and y = x + 5.\n\n");
    printf("\tx + (x + 5) = %d\n", sum);
    printf("\t2x + 5 = %d\n", sum);
    printf("\t2x = %d - 5\n", sum);
    vSum = sum - 5;
    
    printf("\t2x = %d\n", vSum);
    printf("\tx = %d/2\n", vSum);
    x = vSum/2;
    
    printf("\tx = %d\n", x);
    printf("\ty = x + 5\n");
    y = x + 5;

    printf("\ty = %d\n", y);
    
    printf("\tx + y = %d\n", sum);
    vSum = x + y;
    
    printf("\t%d + %d = %d\n", x, y, vSum);
    
}

void problem1() {
    int sum     = 61;
    int x       = 0;
    int y       = 0;    

    printf("Find 2 numbers (x,y) whose sum is 61 and y = x + 5.\n\n");
    printf("\tFormula: 2x + 5 = %d\n", sum);
    printf("\t\tx = (%d - 5)/2\n", sum);

    x = (sum - 5)/2;
    printf("\t\tx = %d\n", x);

    printf("\t\ty = x + 5\n");
    y = x + 5;

    printf("\t\ty = %d\n", y);
}

// *******************************
// Find 2 numbers whose difference
// is 10 and whose sum is 14.
// *******************************
void problem2() {
    printf("Difference of 2 numbers = 10\nSum of the 2 numbers = 14\n\n");

    int dif = 10;
    int sum = 14;
    int x   = sum;
    int y   = 0;
    
    int vDif = 0;
    int vSum = 0;
    
    //for (; x > 0; x--) {                              // Optimize solution by starting at high number.        
    for (x=0; x < sum; x++) {        

        // Determine which number is higher 
        // and subtract the lower from it.
        y = ( dif > x ) ? dif - x : x - dif;
        
        // Log each try to show pattern.
        printf("x: %d | y: %d\n", x,y);
        vDif    = ( x > y ) ? x - y : y - x;
        vSum    = x + y;
        
        if (vSum == sum) {
            printf("We found our values!\n");
            printf("\tValue1: %d\n", x);
            printf("\tValue2: %d\n", y);
            printf("\tDif: %d\n", vDif);
            printf("\tSum: %d\n", sum);
            return;
        }
    }
}

// ************************
// Application Entry Point.
// ************************
int main(
    int argc, 
    const char *argv[]
    ) {
    
    int input;
    
    showMenu();
    input = getchar();
    
    while (input != QUIT) {
        switch (input) {
            case PROBLEM_1:
                problem1();
                showMenu();
                break;
            case PROBLEM_1_DESCRIPTION:
                problem1Description();
                showMenu();
                break;
            case PROBLEM_2:
                problem2();
                showMenu();
                break;
            case QUIT:
                return 0;
        }
        input = getchar();
    }
    	
    return 0;
}

