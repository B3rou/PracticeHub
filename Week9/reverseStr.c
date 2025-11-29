#include <stdio.h>
#include <string.h>


void reversing(char *str, char *reversedStr) {
	int len = strlen(str);
	int i;
	if (str[len-1] == '\n')
		str[len-1] = '\0';
	for (i = 0; i < len; i++) {
		reversedStr[len-2-i] = str[i];
	}
}

int main(void) {
	
	char str[30];
	char reversedStr[30];
	fgets(str, 30, stdin);
	reversing(str, reversedStr);
	printf("%s is reversed as %s", str, reversedStr);
	
	
	
}

