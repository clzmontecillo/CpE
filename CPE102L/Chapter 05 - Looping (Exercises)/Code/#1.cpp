#include <stdio.h>

int main(void){
	/* Problem 1a */
	int a = 1;
	int b = 2;
	int c = 5;
	while(a < c){
		a = a + 1;
		b = b + c;
	}
	printf("#1a\n");
	printf("----------\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("c: %d\n\n", c);


	/* Problem 1b */
	int d = 4;
	int e = 6;
	int f = 7;
	while(d > f){
		d = d + 1;
		e = e - 1;
	}
	printf("#1b\n");
	printf("----------\n");
	printf("d: %d\n", d);
	printf("e: %d\n", e);
	printf("f: %d\n\n", f);


	/* Problem 1c */
	int g = 4;
	int h = 6;
	while(g < h){
		g = g + 1;
	}
	printf("#1c\n");
	printf("----------\n");
	printf("g: %d\n", g);
	printf("h: %d\n\n", h);


        /* Problem 1d */
        printf("#1d\n");
        printf("----------\n");
        int j = 2;
        int k = 5;
        int n = 9;
	//int m = 6;
        while(j < k){
		int m = 6;
                while(m < n){
                        printf("Goodbye\n");
                        m = m + 1;
                }
                j = j + 1;
        }
        printf("\n");


	/* Problem 1e */
	printf("#1e\n");
	printf("----------\n");
	// since variables j, k, and n are already declared, no need for 'int' as this would lead to errors
	// 'm' is declared within the while-loop, so it has to be declared again with 'int'
	j = 2;
	k = 5;
	int m = 6;
	n = 9;
	while(j < k){
		while(m < n){
			printf("Hello\n");
			m = m + 1;
		}
		j = j + 1;
	}
	printf("\n");


	/* Problem 1f */
	printf("#1f\n");
	printf("----------\n");
	int p = 2;
	int q = 4;
	while(p < q){
		printf("Adios\n");
		int r = 1;
		while(r < q){
			printf("Adios\n");
			r = r + 1;
		}
		p = p + 1;
	}
}
