#include <stdio.h>
#include <string.h>
int main()
{
	char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
	int result;
	// comparing strings str1 and str2
	result = strcmp(str1, str2);
	if(result > 0) {
		printf("strcmp(str1, str2) = %d\n", result);
		printf("not fount string\n");
	}

	// comparing strings str1 and str3
	result = strcmp(str1, str3);
	if( result == 0)
	{
		printf("strcmp(str1, str3) = %d\n", result);
		printf("found string\n");
	}
	return 0;
}
