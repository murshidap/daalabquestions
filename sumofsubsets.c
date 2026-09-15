#include <stdio.h>

int elements[100], solution[100];
int n, target;

int findSubset(int index, int sum, int count)
{
	if (sum == target)
	{
		printf("Yes, combination can be formed.\n");
		printf("solution set: ");
		for (int i = 0; i < count; i++)
			printf("%d ", solution[i]);
		printf("\n");
		return 1;
	}

	if (index == n || sum > target)
		return 0;

	solution[count] = elements[index];
	if (findSubset(index + 1, sum + elements[index], count + 1))
		return 1;

	return findSubset(index + 1, sum, count);
}

int main(void)
{
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &elements[i]);

	printf("Enter the target sum: ");
	scanf("%d", &target);

	if (!findSubset(0, 0, 0))
		printf("No combination can be formed to precisely add upto the target sum.\n");

	return 0;
}
