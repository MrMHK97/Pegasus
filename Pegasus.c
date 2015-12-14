#include <stdio.h>

int NumberofEquations;
double Matrix[10][10], EquationsResults[10], Determinants[11];
const char * NumberOrder(int number);
double DeterminantDeterminer(double matrix[10][10]);

main()
{
	printf("Pegasus V1.0\nMuntadhar Haydar\n----------------------\n");
	printf("Enter the number of equations to solve (maximum value is 10): "); scanf("%d", &NumberofEquations);
	if (NumberofEquations < 2)
	{
		printf("Sorry! wrong input\n");
		return 0;
	}
	for (int i = 0; i < NumberofEquations; i++)
	{
		for (int j = 0; j < NumberofEquations; j++)
		{
			printf("Please, enter the %s parameter of the %s equation: ", NumberOrder(j + 1), NumberOrder(i + 1));
			scanf("%lf", &Matrix[i][j]);
		}
	}
	for (int k = 0; k < NumberofEquations; k++)
	{
		printf("Please, enter the %s equation's result: ", NumberOrder(k + 1));
		scanf("%lf", &EquationsResults[k]);
	}
	Determinants[0] = DeterminantDeterminer(Matrix);
	for (int i = 0; i < NumberofEquations; i++)
	{
		double newMatrix[10][10];
		for (int x = 0; x < NumberofEquations; x++)
			for (int y = 0; y < NumberofEquations; y++)
				newMatrix[x][y] = Matrix[x][y];
		for (int j = 0; j < NumberofEquations; j++)
			newMatrix[j][i] = EquationsResults[j];
		Determinants[i + 1] = DeterminantDeterminer(newMatrix);
	}
	for (int i = 1; i <= NumberofEquations; i++)
		printf("The value of the %s variable is: %.00lf\n", NumberOrder(i), Determinants[i]);
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
	double result = 0;
	for (int i = 0; i < NumberofEquations; i++)
	{
		int m = 1, n = 0;
		double right = 1, left = 1;
		while (m < NumberofEquations)
		{
			if (n == i) { n++; continue; }
			right *= matrix[m][n];
			m++; n++;
		}
		n = 0; m = NumberofEquations - 1;
		while (n < NumberofEquations)
		{
			if (n == i) { n++; continue; }
			left *= matrix[m][n];
			n++; m--;
		}
		double cross = right - left;
		cross *= ((i % 2) == 0) ? (1) : (-1);
		cross *= matrix[0][i];
		result += cross;
	}
	return result;
}
