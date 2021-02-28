
// Ввести строку и слово. Вывести только те слова, окончание которых совпадает с введенным словом.

#include <stdio.h>

int is_ch(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int end_match(int *str, int *word, int i)
{
	int pos = i;
	int current = 0;
	while (str[i] != '\0')
	{
		if (word[current] == '\0' && !is_ch(str[i]))
		{
			i--;
			while (is_ch(str[i-1]) && (i >= 0))
			{
				i--;
			}
			return i;
		}
		if (word[current] != str[i])
		{
			current = 0;
			i++;
			continue;
		}
		current++;
		i++;
	}
	return -10;
}

int main()
{
	int a[100], b[10];
	int i = 0, pos = 0;

	printf("\n Input string: ");
	while ((a[i] = getchar()) != '\n')
	{
		i++;
		if (i == 100)
		{
			printf("\n ERROR: You entered too many characters.\n");
			return -1;
		}
	}
	a[i] = '\0';
	i = 0;

	printf(" Input word: ");
	while ((b[i] = getchar()) != '\n')
	{
		i++;
		if (i == 10)
		{
			printf("\n ERROR: You entered too many characters.\n");
			return -1;
		}
	}
	b[i] = '\0';
	i = 0;

	printf("\n -----------------------------------------------------\n Result: ");

	while (a[i] != '\0')
	{
		if ((pos = end_match(&a, &b, i)) != -10)
		{
			while (is_ch(a[pos]))
			{
				printf("%c", a[pos]);
				pos++;
			}
			break;
		}
		while (!is_ch(a[i]) && a[i] != '\0')
		{
			printf(" . ");
			i++;
		}
	}

	/*while (is_ch(a[i]))
	{
		printf("%c", a[i]);
		i++;
	}*/
}