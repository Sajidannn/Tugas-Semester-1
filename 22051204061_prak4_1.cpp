#include <stdio.h> 
#define n 10
main()
{
int A[n], i, min, t; 
float T, X;

printf("Input %i bilangan:\n\n", n); 
for (i = 0; i < n; i++) {
	printf("Bil %i: ", (i + 1));
	scanf("%i", &A[i]);
}
T= min = A[0];
for (i = 1; i < n; i++) {
	if (A[i] < min) {
		min = A[i];
	}
t=T=T+A[i];
}
X=T/n;
printf("Nilai terkecil = %i\n", min);
printf("Jumlah nilai = %i\n", t); 
printf("Rata-rata nilai = %f\n", X); 
return 0;
}


