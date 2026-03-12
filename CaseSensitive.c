#include <stdio.h>

int main(void) {

	char str[30] = { 0, };
	int length = 0;

	printf("문자열을 입력하세요 : ");
	gets(str);

	for (int i = 0; str[i] != '\0'; ++i)
		length += 1;

	for (int i = 0; i < length; ++i) {
		if (str[i] > 96 && str[i] < 123)		//소문자에서 대문자
			str[i] = str[i] - 32;
		else if (str[i] > 64 && str[i] < 90)	//대문자에서 소문자
			str[i] = str[i] + 32;
	}

	printf("%s", str);

	return 0;
}