#include<stdio.h> 
#include <string.h>

/*
 *   Program name: GCDLCMcalc.c
 *   Author: Tim Catana
 *   Last Update: November 27, 2019
 *   Function: Calculates the Greatest Common Divider and the Lowest Common Multiple of two numbers
 *	       or in a range of 2 numbers
 *   Notes: none
 *   Compilation: gcc -ansi -o GCDLCM GCDLCMcalc.c     OR     using the makefile 'make GCDLCM'
 *   Execution: ./GCDLCM 100 150
 */

/* using Euclids Algorithm */
int GCD(int a, int b) { 
	int x = 0;
	int y = 0;
	int r = 1;

	if(b < a){
		y = a;
		x = b;
	} else {
		y = b;
		x = a;
	}

	r = y % x;

	while(r != 0){

		y = x;
		x = r;
		r = y % x;

	}

	return(x);
} 

/* using previousely calculated GCD */
int LCM(int a,int b, int gcd) { 
	int lcm = 0;

	lcm = (a * b) / gcd;
	return(lcm);
} 


int main(int argc, char *argv[]) {
	long minLcm = 10000000000;

	int gcd = 0;
	int lcm = 0;

	int num1 = 0;
	int num2 = 0;

	char currentInput[100];
	int choose = 0;

	int i = 0;
	int j = 0;

	int smlLcmNum1 = 0;
	int smlLcmNum2 = 0;

	if(argc != 3){
		printf("ERROR - excecution: ./<exefilename> <num1> <num2>\n");
		return(0);
	}

        /* make sure num1 is always smaller than num2 */
	if( atoi(argv[1]) < atoi(argv[2])){
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
	} else {
		num2 = atoi(argv[1]);
		num1 = atoi(argv[2]);
	}

	system("clear");

	while(strcmp(currentInput, "1") != 0  && strcmp(currentInput, "2") != 0  ){
		printf("do you want to check only these two numbers (1) or everything in between as well (2): ");
		fgets(currentInput, 100, stdin);
		sscanf(currentInput, "%s", currentInput);
		if(strcmp(currentInput, "1") != 0  && strcmp(currentInput, "2") != 0){
			system("clear");
			printf("Only the numbers 1 and 2 are acceptable\n");
		}
	}

	if(strcmp(currentInput, "1") == 0 ){
		gcd = GCD(num1, num2);
		lcm = LCM(num1, num2, gcd);

		system("clear");

		printf("The GCD of the numbers %d and %d is %d\n", num1, num2, gcd);
		printf("The LCM of the numbers %d and %d is %d\n", num1, num2, lcm);
	}

	if(strcmp(currentInput, "2") == 0){
		system("clear");
		printf("beginning calculation... NOTE: program will not calculate when num1 = num2\n");

		system(" sleep 3.50");

		for(i = num1; i <= num2; i++){
			for(j = num1; j <= num2; j++){

				if(i != j){
					gcd = GCD(i, j);
					lcm = LCM(i, j, gcd);

					printf("%-2d & %-2d :  GCD: %-4d   LCM: %-4d\n", i, j, gcd, lcm);

					if(lcm < minLcm){
						minLcm = lcm;
						smlLcmNum1 = i;
						smlLcmNum2 = j;
					}
				}
			}
		}

		printf("the smallest LCM between two distinct numbers in between the range %d and %d is %d found at %d & %d\n", num1, num2, minLcm, smlLcmNum1, smlLcmNum2);
	}
	return(0);
}
