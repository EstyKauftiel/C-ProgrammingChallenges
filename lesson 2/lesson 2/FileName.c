
#include <stdio.h>
#include <string.h>

int string(char* s, char* t, char* str)
{
	int i, j = 0, start = 0, end = strlen(s) - 1, a = 0, e = 0, f = 0;

	for (i = 0; s[i] != NULL; i++)
	{
		for (j = 0; t[j] != NULL;)
		{
			if (s[i] == t[0] && e == 0)
			{
				start = i;
				e = 1;
			}
			else if (s[i] == t[strlen(t) - 1] && f == 0)
			{
				end = i;
				f = 1;
			}
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else break;
		}
		if (j == strlen(t))
			break;
	}
	int c, d;
	if (j == strlen(t))
	{
		for (c = 0, a = 0; c < start; c++, a++)
			str[a] = s[c];
		for (d = end + 1; d < strlen(s); d++, a++)
			str[a] = s[d];
		str[a] = '\0';
		printf("%s", str);
		printf("\n");
		return 1;
	}
	else return 0;
}

void main()
{
	while (string)
	{
		char s[] = "";
		char t[] = "";
		printf("enter string 1 \n");
		gets(s);
		printf("enter string 2 \n");
		gets(t);
		char str[sizeof(s)];
		string(s, t, str);
	}

}
