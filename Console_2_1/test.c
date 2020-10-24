#include <stdio.h>
#include <conio.h>

void mini(), input();
void sort_1(), sort_2(), sort_3(); //정리함수
void prt(), mini_prt(); // 출력함수

int pi[10][30], mini_pi[10][30]; //10x10은 pi수 정리 나머지는 표에 표시공간
char num[10][4], num2[10][4]; //이진수 입력받는 배열변수
int i, j, k, a, b; //for문에 들어갈 변수와 입력받는 변수
int c, count, count_2;  // count변수

void main() {
	input(); // pi 와 이진수 입력받는 함수
	mini();
}

void input() {     // 배열 99로 초기화 
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 30; j++) {
			pi[i][j] = 99;
			mini_pi[i][j] = 99;
		}
	}
	printf("\n  < PI가 (1,2), (1,2,3,4)이면 PI 수 : 2 >\n");
	printf("  PI의 개수를 입력해주세요 : ");
	scanf_s("%d", &a);
	printf("  < PI입력 ( PI가 (1,2) 이면 PI에 포함되는 수 : 2 >\n");
	for (i = 1; i < a + 1; i++)
	{  // 입력할 pi 수 몇개인지 입력
		printf("  PI에 포함되는 수가 몇개인가? : ");
		scanf_s("%d", &b);    // 입력할 pi안에 몇개의 수가 들어있는지 입력
		for (j = 0; j < b; j++) {  // pi안에 수 입력
			printf("  [입력] : ");
			scanf_s(" %d", &pi[i][j]);
			if (pi[i][j] < 0 || pi[i][j]>15) {
				printf("다시입력해주세요\n");
				j--;
			}
		}
		printf(" 이진수를 입력해주세요(예:1-01)\n ");
		for (k = 0; k < 4; k++)
		{   //-- pi의이진수 입력
			scanf_s(" %c", &num[i][k]);
			if (num[i][k] != 48 && num[i][k] != 49 && num[i][k] != 45)
			{   //--문자로 입력 받을 수 있는 값(아스키코드) -> 0(48),1(49),-(45)
				printf("다시 입력해주세요");
				k--;
			}
		}
		for (j = 0; j < b; j++)
		{   //-------------입력받은 pi값 작은 수 부터 차례로 정리
			for (k = 0; k < b; k++)
				if (pi[i][j] < pi[i][k])
					sort_1(i, j, k);
		}
	}
	mini_prt(a + 1, pi, num); // 입력받은거 정리해서 출력
}

void mini() {
	count = 10;
	for (i = 1; i < a + 1; i++) sort_2(0, 10, i);//표 맨 위에 표시할 수 넣기
	for (i = 10; i < 30; i++) {
		for (j = 10; j < 30; j++) { // 표 맨 위에 표시할 수 정리
			if (pi[0][i] < 99 && pi[0][j] < 99 && pi[0][i] < pi[0][j])
				sort_1(0, i, j);
			if (i != j && pi[0][i] == pi[0][j])
				pi[0][j] = 99; // 표 맨 위에 표시할 수 중복이면 값을 99로 초기화
		}
	}
	count = 10;
	sort_2(10, 30, 0);	// 위에서 중복되는 값 99로 된거 없애서 정리
	for (i = count; i < 30; i++)pi[0][i] = 99;
	//입력받은 모든 수 중 각자 pi에 지정된 수 'X'(88)표시
	for (i = 1; i < a + 1; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 10; k < 30; k++)
				if (pi[i][j] == pi[0][k] && pi[i][j] < 88) pi[i][k] = 88;
		}
	}
	printf("\n   표↓  \n");
	prt();
	for (j = 10; j < 30; j++) {//  PI중 중복 없는 수 EPI(87) 선정↓
		count = 0;
		c = 0;
		for (i = 1; i < a + 1; i++) {
			if (pi[i][j] == 88) {
				count++;
				c = i;
			}
		}
		if (count == 1)	pi[c][j] = 87;
	}
	printf("\n  EPI -> E ↓ \n");
	prt();// EPI(87)가 있는 행에 있는 수(86)↓
	for (i = 1; i < a + 1; i++) {
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 87) {
				for (k = 10; k < 30; k++)
					if (pi[i][k] == 88)
						pi[i][k] = 86;
			}
		}
	}
	printf("\n  EPI있는 행에 있는 수 -> - ↓\n");
	prt();// EPI(87)가 있는 행에 있는 수의 열에 있는 수(86)↓
	for (i = 1; i < a + 1; i++) {
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 86) {
				for (k = 1; k < a + 1; k++)
					if (pi[k][j] == 88)
						pi[k][j] = 86;
			}
		}
	}
	printf("\n  EPI있는 행에 있는 수가 있는 열에 있는 수 -> - ↓\n");
	prt();
	c = 0;
	for (i = 1; i < a + 1; i++) {
		count = 0;
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 87) {
				count++;
				if (count == 1) sort_3();
			}// count==1이면 EPI가 있는 행이므로 새로운 배열 변수에 저장
		}    // 빈 공간 없이 차례로 저장하기 위함
	}
	for (i = 1; i < a + 1; i++) {
		count_2 = 0;
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 88) {
				count_2++;
				count = 0;
				for (k = 10; k < 30; k++)
					if (pi[i][k] == 86)  count++;
				if (count == 0 && count_2 == 1)	sort_3();
			} //count == 0이고 count_2 == 1면 EPI있는 행에 걸리는 수 없음
		}
	}
	printf("\n < 최종 EPI > ↓ \n");
	mini_prt(c, mini_pi, num2); // 최종 도출된 EPI출력
	printf("\n [ 조건식 f(x) = ");
	for (i = 0; i < c; i++) {
		if (i > 0)printf(" + ");  //조건식 이진수 0000 = a'b'c'd'
		for (j = 0; j < 4; j++) { //조건식 이진수 1111 = a b c d
			if (num2[i][j] == '1') printf("%c", j + 97);
			if (num2[i][j] == '0') printf("%c'", j + 97);
		}
	}
	printf(" ]\n\n");
	getch();
}

void prt() {
	printf("------------------------------------------------------------------------------\n");
	for (i = 0; i < a + 1; i++) {
		for (j = 0; j < 30; j++) {
			if (i == 0) {  //-----표 맨위에 수 출력
				if (j == 0)printf(" PI");
				else if (j < 10)printf("   ");
				else if (pi[i][j] != 99 && pi[i][j] > 9)printf(" %d", pi[i][j]);
				else if (pi[i][j] != 99 && pi[i][j] < 10)printf("  %d", pi[i][j]);
			}
			else if (pi[i][j] < 80 && pi[i][j] > 9)	printf(" %d", pi[i][j]); // pi숫자출력
			else if (pi[i][j] < 80 && pi[i][j] < 10)printf("  %d", pi[i][j]);// pi숫자출력
			else if (pi[i][j] == 88)printf("  %c", pi[i][j]);  //표에 'X'자로 표시
			else if (pi[i][j] == 87)printf("  E", pi[i][j]); // EPI
			else if (pi[i][j] == 86)printf("  -", pi[i][j]); // EPI의 가로세로에 걸리는 수
			else if (i > 0 && pi[i][j] == 99)printf("   ");
		}
		printf("\n");
	}
}

void mini_prt(int number, int arr[][30], char arr2[][4]) {  //-----출력하는 함수
	printf("------------------------------------------------------------------------------\n");
	for (i = 0; i < number; i++) {
		for (j = 0; j < 10; j++) { // pi출력
			if (arr[i][j] == 99) printf("   ");
			else if (arr[i][j] > 9)   printf(" %d", arr[i][j]);
			else if (arr[i][j] < 10) printf("  %d", arr[i][j]);
		}
		for (j = 0; j < 4; j++)   printf("%c ", arr2[i][j]); //이진수 출력
		printf("\n");
	}
}

void sort_1(int nb1, int nb2, int nb3) {  // 작은수부터 차례대로 저장하는 함수
	int change;
	change = pi[nb1][nb2];
	pi[nb1][nb2] = pi[nb1][nb3];
	pi[nb1][nb3] = change;
}

void sort_2(int p, int q, int r) {  //표 맨 위에 표시할 수(입력받은 pi에 들어가는 수) 정렬하는 함수
	for (j = p; j < q; j++) {
		if (pi[r][j] < 99) {
			pi[0][count] = pi[r][j];
			count++;
		}
	}
}

void sort_3() {   // 빈 공간 없이 순서대로 저장하는 함수
	for (k = 0; k < 10; k++)
		mini_pi[c][k] = pi[i][k];
	for (k = 0; k < 4; k++)
		num2[c][k] = num[i][k];
	c++;
}