#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int div(int a, int b) {
	return a / b;
}

int main(void) {
	char sel;
	int num1, num2;
	int(*fptr[4])(int, int) = { add, sub, mul, div };

	printf("a : ");
	scanf("%d", &num1);
	printf("b : ");
	scanf("%d", &num2);
	printf("연산 종류 (+, -, *, /) : ");
	scanf(" %c", &sel);

	switch (sel) {
	case '+':
		printf("a + b = %d", fptr[0](num1, num2));
		break;
	case '-':
		printf("a - b = %d", fptr[1](num1, num2));
		break;
	case '*':
		printf("a * b = %d", fptr[2](num1, num2));
		break;
	case '/':
		printf("a / b = %d", fptr[3](num1, num2));
		break;
	}
	return 0;
}