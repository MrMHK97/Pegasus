#include <stdio.h>
#include <conio.h>

int NumberofEquations;
double Matrix[10][10], EquationsResults[10], Determinants[11];
const char * NumberOrder(int number);
double DeterminantDeterminer(double matrix[10][10]);

main()
{
	int i, j, k, x, y;
	printf("Pegasus V1.0.1\nMuntadhar Haydar aka mrmhk97\n----------------------\n");
	printf("Enter the number of equations to solve (maximum value is 10): "); scanf("%d", &NumberofEquations);
	if (NumberofEquations <= 2 || NumberofEquations > 10)
	{
		printf("Sorry! wrong input\n");
		getch();
		return 0;
	}
	for (i = 0; i < NumberofEquations; i++)
	{
		for (j = 0; j < NumberofEquations; j++)
		{
			printf("Please, enter the %s parameter of the %s equation: ", NumberOrder(j + 1), NumberOrder(i + 1));
			scanf("%lf", &Matrix[i][j]);
		}
	}
	for (k = 0; k < NumberofEquations; k++)
	{
		printf("Please, enter the %s equation's result: ", NumberOrder(k + 1));
		scanf("%lf", &EquationsResults[k]);
	}
	Determinants[0] = DeterminantDeterminer(Matrix);
	for (i = 0; i < NumberofEquations; i++)
	{
		double newMatrix[10][10];
		for (x = 0; x < NumberofEquations; x++)
			for (y = 0; y < NumberofEquations; y++)
				newMatrix[x][y] = Matrix[x][y];
		for (j = 0; j < NumberofEquations; j++)
			newMatrix[j][i] = EquationsResults[j];
		Determinants[i + 1] = DeterminantDeterminer(newMatrix);
	}
	for (i = 1; i <= NumberofEquations; i++)
		printf("The value of the %s variable is: %.2lf\n", NumberOrder(i), Determinants[i]);
	getch();
	return 0;
}

const char * NumberOrder(int number)
{
	if (number == 1) return "1st";
	else if (number == 2) return "2nd";
	else if (number == 3) return "3rd";
	else
	{
		printf("%d", number);
		return "th";
	}
}

double DeterminantDeterminer(double matrix[10][10])
{
	int q;
	double result = 0;
	for (q = 0; q < NumberofEquations; q++)
	{
		int m = 1, n = 0;
		double right = 1, left = 1;
		while (m < NumberofEquations)
		{
			if (n == q) { n++; continue; }
			right *= matrix[m][n];
			m++; n++;
		}
		n = 0; m = NumberofEquations - 1;
		while (n < NumberofEquations)
		{
			if (n == q) { n++; continue; }
			left *= matrix[m][n];
			n++; m--;
		}
		double cross = right - left;
		cross *= ((q % 2) == 0) ? (1) : (-1);
		cross *= matrix[0][q];
		result += cross;
	}
	return result;
}
