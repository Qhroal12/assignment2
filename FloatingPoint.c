#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	float num = 0;
	int negative = 0;

	printf("수를 입력하세요 : " );
	scanf("%f", &num);

	if (num < 0) {
		negative = 1;		
		num *= -1;
	}						//음수 확인용 변수(1 == true, 0 == false)

	int Inum = 0;
	Inum = (int)num;
	int Iarr[8] = { 0, };
	int Ilength = sizeof(Iarr) / sizeof(int);

	for (int i = 0; i < Ilength; ++i) {

		if (Inum < 0) {
			Iarr[7 - i] = 0;		
		}
		Iarr[7 - i] = Inum % 2;
		Inum = Inum / 2;

	}						// 정수 부분 이진법 변환후 역순으로 배치



	float Rnum = 0;
	Rnum = num - (int)num;
	int Rarr[23] = { 0, };
	int Rlength = sizeof(Rarr) / sizeof(int);

	for (int i = 0; i < Rlength; ++i) {

		Rnum = Rnum * 2;

		if (Rnum < 1.0) {
			Rarr[i] = 0;
		}
		else {
			Rarr[i] = 1;
			Rnum = Rnum - (int)Rnum;
		}
	}						//실수 부분 이진법 변환

	int IarrExponent = 0;
	for (int i = 0; i < Ilength; ++i) {
		IarrExponent += 1;
		if (Iarr[i] == 1) {
			break;
			IarrExponent += 1;
		}
	}						//이동할 칸 수(지수) 계산을 위한 보수 계산

	for (int i = 0; i < (Ilength - IarrExponent); ++i) {
		Rarr[i + ((Ilength - IarrExponent))] = Rarr[i];
		Rarr[i] = 0;
	}						//가수 부분 이동

	for (int i = 0; i < (Ilength - IarrExponent); ++i) {
		Rarr[i] = Iarr[IarrExponent + i];
	}
							//지수 부분 가수 부분으로 이동



	Inum = 127 + (Ilength - IarrExponent);

	for (int i = 0; i < Ilength; ++i) {

		if (Inum < 0) {
			Iarr[7 - i] = 0;
		}
		Iarr[7 - i] = Inum % 2;
		Inum = Inum / 2;

	}											//지수비트 연산 후 이진법 변환


	///////////////////////////////아래는 출력///////////////////////////////////

	printf("%d/", negative);					//부호비트 출력

	for (int i = 0; i < Ilength; ++i) {			//지수비트 출력
		if (i % 4 == 0 && i > 1) {
			printf(" ");
		}
		printf("%d", Iarr[i]);
	}

	printf("/");

	for (int i = 0; i < Rlength; ++i) {			//가수비트 출력
		if (i % 4 == 0 && i > 1) {
			printf(" ");
		}
		printf("%d", Rarr[i]);
	}


	return 0;
}