#include <stdio.h>

int sum_values(int value_one , int value_two)
{
	return value_one + value_two;
}

int main(void)
{
	int x = 1;
	int y = 10;

	int result = sum_values(x, y);   // store the return value
	printf("Result is  %d\n", result);  // print it

}
