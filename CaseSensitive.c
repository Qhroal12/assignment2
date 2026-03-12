#include <stdio.h>

int main(void) {

	char str[30] = { 0, };
	int length = 0;

	printf("문자열을 입력하세요 : ");
	gets(str);

	for (int i = 0; str[i] != '\0'; ++i)
		length += 1;							//문자열 길이 계산

	for (int i = 0; i < length; ++i) {
		if (str[i] > 96 && str[i] < 123)		//알파벳 소문자 범위의 변수 대문자로 변환
			str[i] = str[i] - 32;
		else if (str[i] > 64 && str[i] < 90)	//알파벳 대문자 범위의 변수 소문자로 변환
			str[i] = str[i] + 32;
	}

	printf("%s", str);

	return 0;

}
