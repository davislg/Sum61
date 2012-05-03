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
static const int PROBLEM_1  = 0x31;
static const int PROBLEM_2  = 0x32;
static const int QUIT       = 0x33;

// ************************************
// Show menu of options to choose from.
// ************************************
void showMenu() {
    printf("\nPlease choose a problem to solve.\n");
    printf("\t1) Find 2 numbers whose sum is 61.\n");
    printf("\t2) Find 2 numbers whose difference is 10 and whose sum is 14.\n");
    printf("\t3) Quit.\n");
}

// *******************************
// Find 2 numbers whose sum is 61.
// *******************************
void problem1() {
    printf("Find 2 numbers whose sum is 61.\n\n");
    
    int sum     = 61;
    int vSum    = 0;
    int x       = 0;
    int y       = 0;
    
    for (x=1; x<=sum; x++) {
        y       = x + 5;
        vSum    = x + y;
        
        // Log each try to show pattern.
        printf("%d + (%d) = %d\n", x, y, vSum);
        if (vSum==sum) {
            printf("We found our values!\n");
            printf("\tValue1: %d\n", x);
            printf("\tValue2: %d\n", y);
            printf("\tSum: %d\n", vSum);
            return;
        }
    }
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

