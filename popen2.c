/* Reading Larger Amounts of Data from a Pipe */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

char *trim (char *s)
{
    int i;

    while (isspace (*s)) s++;   // skip left side white spaces
    for (i = strlen (s) - 1; (isspace (s[i])); i--) ;   // skip right side white spaces
    s[i + 1] = '\0';
	return s;
}

int main()
{
	FILE *f;
	char buffer[BUFSIZ + 1];
	int rdata;
	memset(buffer, '\0', sizeof(buffer));
	f = popen("lscpu ", "r");
	if (f != NULL) {
		rdata = fread(buffer, sizeof(char), BUFSIZ, f);
		char *token = strtok(buffer,": " );
		char *t;
		char *r;

		// Keep printing tokens while one of the
		// delimiters present in buffer[].
		while (token != NULL) {
			if( !strcmp(token , "Architecture"))
			{
				t = strtok(NULL, "\n");
				r= trim(t);	
				printf("%s == %s\n", token, r);
			}
			token = strtok(NULL, ": ");
		}

	}
}
