#include <stdio.h>
#include <conio.h>

void mini(), input();
void sort_1(), sort_2(), sort_3(); //�����Լ�
void prt(), mini_prt(); // ����Լ�

int pi[10][30], mini_pi[10][30]; //10x10�� pi�� ���� �������� ǥ�� ǥ�ð���
char num[10][4], num2[10][4]; //������ �Է¹޴� �迭����
int i, j, k, a, b; //for���� �� ������ �Է¹޴� ����
int c, count, count_2;  // count����

void main() {
	input(); // pi �� ������ �Է¹޴� �Լ�
	mini();
}

void input() {     // �迭 99�� �ʱ�ȭ 
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 30; j++) {
			pi[i][j] = 99;
			mini_pi[i][j] = 99;
		}
	}
	printf("\n  < PI�� (1,2), (1,2,3,4)�̸� PI �� : 2 >\n");
	printf("  PI�� ������ �Է����ּ��� : ");
	scanf_s("%d", &a);
	printf("  < PI�Է� ( PI�� (1,2) �̸� PI�� ���ԵǴ� �� : 2 >\n");
	for (i = 1; i < a + 1; i++)
	{  // �Է��� pi �� ����� �Է�
		printf("  PI�� ���ԵǴ� ���� ��ΰ�? : ");
		scanf_s("%d", &b);    // �Է��� pi�ȿ� ��� ���� ����ִ��� �Է�
		for (j = 0; j < b; j++) {  // pi�ȿ� �� �Է�
			printf("  [�Է�] : ");
			scanf_s(" %d", &pi[i][j]);
			if (pi[i][j] < 0 || pi[i][j]>15) {
				printf("�ٽ��Է����ּ���\n");
				j--;
			}
		}
		printf(" �������� �Է����ּ���(��:1-01)\n ");
		for (k = 0; k < 4; k++)
		{   //-- pi�������� �Է�
			scanf_s(" %c", &num[i][k]);
			if (num[i][k] != 48 && num[i][k] != 49 && num[i][k] != 45)
			{   //--���ڷ� �Է� ���� �� �ִ� ��(�ƽ�Ű�ڵ�) -> 0(48),1(49),-(45)
				printf("�ٽ� �Է����ּ���");
				k--;
			}
		}
		for (j = 0; j < b; j++)
		{   //-------------�Է¹��� pi�� ���� �� ���� ���ʷ� ����
			for (k = 0; k < b; k++)
				if (pi[i][j] < pi[i][k])
					sort_1(i, j, k);
		}
	}
	mini_prt(a + 1, pi, num); // �Է¹����� �����ؼ� ���
}

void mini() {
	count = 10;
	for (i = 1; i < a + 1; i++) sort_2(0, 10, i);//ǥ �� ���� ǥ���� �� �ֱ�
	for (i = 10; i < 30; i++) {
		for (j = 10; j < 30; j++) { // ǥ �� ���� ǥ���� �� ����
			if (pi[0][i] < 99 && pi[0][j] < 99 && pi[0][i] < pi[0][j])
				sort_1(0, i, j);
			if (i != j && pi[0][i] == pi[0][j])
				pi[0][j] = 99; // ǥ �� ���� ǥ���� �� �ߺ��̸� ���� 99�� �ʱ�ȭ
		}
	}
	count = 10;
	sort_2(10, 30, 0);	// ������ �ߺ��Ǵ� �� 99�� �Ȱ� ���ּ� ����
	for (i = count; i < 30; i++)pi[0][i] = 99;
	//�Է¹��� ��� �� �� ���� pi�� ������ �� 'X'(88)ǥ��
	for (i = 1; i < a + 1; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 10; k < 30; k++)
				if (pi[i][j] == pi[0][k] && pi[i][j] < 88) pi[i][k] = 88;
		}
	}
	printf("\n   ǥ��  \n");
	prt();
	for (j = 10; j < 30; j++) {//  PI�� �ߺ� ���� �� EPI(87) ������
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
	printf("\n  EPI -> E �� \n");
	prt();// EPI(87)�� �ִ� �࿡ �ִ� ��(86)��
	for (i = 1; i < a + 1; i++) {
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 87) {
				for (k = 10; k < 30; k++)
					if (pi[i][k] == 88)
						pi[i][k] = 86;
			}
		}
	}
	printf("\n  EPI�ִ� �࿡ �ִ� �� -> - ��\n");
	prt();// EPI(87)�� �ִ� �࿡ �ִ� ���� ���� �ִ� ��(86)��
	for (i = 1; i < a + 1; i++) {
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 86) {
				for (k = 1; k < a + 1; k++)
					if (pi[k][j] == 88)
						pi[k][j] = 86;
			}
		}
	}
	printf("\n  EPI�ִ� �࿡ �ִ� ���� �ִ� ���� �ִ� �� -> - ��\n");
	prt();
	c = 0;
	for (i = 1; i < a + 1; i++) {
		count = 0;
		for (j = 10; j < 30; j++) {
			if (pi[i][j] == 87) {
				count++;
				if (count == 1) sort_3();
			}// count==1�̸� EPI�� �ִ� ���̹Ƿ� ���ο� �迭 ������ ����
		}    // �� ���� ���� ���ʷ� �����ϱ� ����
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
			} //count == 0�̰� count_2 == 1�� EPI�ִ� �࿡ �ɸ��� �� ����
		}
	}
	printf("\n < ���� EPI > �� \n");
	mini_prt(c, mini_pi, num2); // ���� ����� EPI���
	printf("\n [ ���ǽ� f(x) = ");
	for (i = 0; i < c; i++) {
		if (i > 0)printf(" + ");  //���ǽ� ������ 0000 = a'b'c'd'
		for (j = 0; j < 4; j++) { //���ǽ� ������ 1111 = a b c d
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
			if (i == 0) {  //-----ǥ ������ �� ���
				if (j == 0)printf(" PI");
				else if (j < 10)printf("   ");
				else if (pi[i][j] != 99 && pi[i][j] > 9)printf(" %d", pi[i][j]);
				else if (pi[i][j] != 99 && pi[i][j] < 10)printf("  %d", pi[i][j]);
			}
			else if (pi[i][j] < 80 && pi[i][j] > 9)	printf(" %d", pi[i][j]); // pi�������
			else if (pi[i][j] < 80 && pi[i][j] < 10)printf("  %d", pi[i][j]);// pi�������
			else if (pi[i][j] == 88)printf("  %c", pi[i][j]);  //ǥ�� 'X'�ڷ� ǥ��
			else if (pi[i][j] == 87)printf("  E", pi[i][j]); // EPI
			else if (pi[i][j] == 86)printf("  -", pi[i][j]); // EPI�� ���μ��ο� �ɸ��� ��
			else if (i > 0 && pi[i][j] == 99)printf("   ");
		}
		printf("\n");
	}
}

void mini_prt(int number, int arr[][30], char arr2[][4]) {  //-----����ϴ� �Լ�
	printf("------------------------------------------------------------------------------\n");
	for (i = 0; i < number; i++) {
		for (j = 0; j < 10; j++) { // pi���
			if (arr[i][j] == 99) printf("   ");
			else if (arr[i][j] > 9)   printf(" %d", arr[i][j]);
			else if (arr[i][j] < 10) printf("  %d", arr[i][j]);
		}
		for (j = 0; j < 4; j++)   printf("%c ", arr2[i][j]); //������ ���
		printf("\n");
	}
}

void sort_1(int nb1, int nb2, int nb3) {  // ���������� ���ʴ�� �����ϴ� �Լ�
	int change;
	change = pi[nb1][nb2];
	pi[nb1][nb2] = pi[nb1][nb3];
	pi[nb1][nb3] = change;
}

void sort_2(int p, int q, int r) {  //ǥ �� ���� ǥ���� ��(�Է¹��� pi�� ���� ��) �����ϴ� �Լ�
	for (j = p; j < q; j++) {
		if (pi[r][j] < 99) {
			pi[0][count] = pi[r][j];
			count++;
		}
	}
}

void sort_3() {   // �� ���� ���� ������� �����ϴ� �Լ�
	for (k = 0; k < 10; k++)
		mini_pi[c][k] = pi[i][k];
	for (k = 0; k < 4; k++)
		num2[c][k] = num[i][k];
	c++;
}