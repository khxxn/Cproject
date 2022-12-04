# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int i, j, k;
int turn = 2;	// ���� ���ϱ�
int win;		//���� ���ϱ�

void intro()		//���� ��Ģ�� ���� ��Ʈ��
{
	printf(" ƽ����(tic - tac - toe)�� �� ���� �����ư���\n");
	printf(" O�� X�� 3���� 3��3 �ǿ� �Ἥ\n");
	printf(" ���� ��� 3����\n");
	printf(" ����, ����, Ȥ�� �밢�� �� ���̵��� �ϴ� �����Դϴ�.\n");
	printf(" ���� ������ ���� ������� ���� ����� �¸��մϴ�.\n\n");

	printf(" ����)\n");			//���� (player 1 �� bottom ������ (1,3) ��ǥ�� ���� ������) 
	printf(" board(1 : top, 2 : mid, 3 : bottom)\n");
	printf(" x, y = {1, 2, 3}\n");
	printf(" player 1 ( board, x, y ) : 3 1 3\n\n");

	printf("  (top)\t\t\t");
	printf("(mid)\t\t      ");
	printf("(bottom)\t\t\n\n");

	for (i = 0; i < 2; i++)
	{
		printf("  �ӤѤѤӤѤѤӤѤѤ�");
		printf("  �ӤѤѤӤѤѤӤѤѤ�");
		printf("  �ӤѤѤӤѤѤӤѤѤ�\n");
		printf("  ��    ��    ��    ��");
		printf("  ��    ��    ��    ��");
		printf("  ��    ��    ��    ��\n");
	}
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�\n");
	printf("  ��    ��    ��    ��");
	printf("  ��    ��    ��    ��");
	printf("  ��  O ��    ��    ��\n");
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�\n\n");

}

int board(char(*mark)[3][3]);
int playerturn(char(*mark)[3][3]);
int winner(char(*mark)[3][3]);

int main()
{
	intro();
	char mark[3][3][3];		//���Ӻ��忡 ���� ��	


	for (i = 0; i < 3; i++)		//������ �������� �ʱ�ȭ
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				mark[i][j][k] = '    ';
			}
		}
	}

	while (turn++)
	{
		playerturn(*mark);		//�÷��̾ ���� ���� ��ǥ�� �Է¹���
		board(*mark);			//���Ӻ��忡 ���� �Է��ϰ� ���Ӻ��� ǥ��
		win = winner(*mark);	// ���ڰ� ���ö����� ���ѷ����� ���ڰ� ������ break �� Ż��
		if (win == 1)
		{
			printf("\nplayer 1 win !\n");
			break;
		}
		else if (win == 2)
		{
			printf("\nplayer 2 win !\n");
			break;
		}
	}

}

int board(char(*mark)[3][3])		//���Ӻ��带 ����ؼ� ���� �����Ȳ�� ǥ����
{
	printf("  (top)\t\t\t");
	printf("(mid)\t\t      ");
	printf("(bottom)\t\t\n\n");

	for (i = 0; i < 3; i++)
	{
		printf("  �ӤѤѤӤѤѤӤѤѤ�");
		printf("  �ӤѤѤӤѤѤӤѤѤ�");
		printf("  �ӤѤѤӤѤѤӤѤѤ�\n");
		printf("  ��  %c ��  %c ��  %c ��", mark[0][0][i], mark[0][1][i], mark[0][2][i]);
		printf("  ��  %c ��  %c ��  %c ��", mark[1][0][i], mark[1][1][i], mark[1][2][i]);
		printf("  ��  %c ��  %c ��  %c ��\n", mark[2][0][i], mark[2][1][i], mark[2][2][i]);
	}
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�");
	printf("  �ӤѤѤӤѤѤӤѤѤ�\n");

}

int playerturn(char(*mark)[3][3])
{
	int b, x, y;						//�÷��̾ ���� ����,x,y ��ǥ�� �Է¹ް�
	if (turn % 2 == 1)
	{
		printf(" board(1 : top, 2 : mid, 3 : bottom)\n");
		printf(" x, y = {1, 2, 3}\n");
		printf(" player 1 ( board, x, y ) : ");
	}
	else
	{
		printf(" board(1 : top, 2 : mid, 3 : bottom)\n");
		printf(" x, y = {1, 2, 3}\n");
		printf(" player 2 ( board, x, y ) : ");
	}

	scanf("%d %d %d", &b, &x, &y);
	printf("\n");


	if (b != 1 && b != 2 && b != 3)					//���� �̹� ���� �������ִ� ���̰ų� 
	{												//�߸��� ��ǥ���
		printf("�߸��� ��ǥ �Դϴ�.\n\n");			//�Լ� Ż���� �ٽ� �Է¹ް���
		turn--;
		return 0;
	}
	else if (x != 1 && x != 2 && x != 3)
	{
		printf("�߸��� ��ǥ �Դϴ�.\n\n");
		turn--;
		return 0;
	}
	else if (y != 1 && y != 2 && y != 3)
	{
		printf("�߸��� ��ǥ �Դϴ�.\n\n");
		turn--;
		return 0;
	}
	else if (mark[b - 1][x - 1][y - 1] == 'O' || mark[b - 1][x - 1][y - 1] == 'X')
	{
		printf("���Ӻ��忡 �̹� ���� �ֽ��ϴ�.\n\n");
		turn--;
		return 0;
	}

	if (turn % 2 == 1)		//��ǥ �Է�
	{
		mark[b - 1][x - 1][y - 1] = 'O';
	}
	else
	{
		mark[b - 1][x - 1][y - 1] = 'X';
	}

}

int winner(char(*mark)[3][3])	//���� ����
{

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (mark[0][i][j] == 'O' && mark[1][i][j] == 'O' && mark[2][i][j] == 'O')
				return 1;
			else if (mark[0][i][j] == 'X' && mark[1][i][j] == 'X' && mark[2][i][j] == 'X')
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (mark[i][0][j] == 'O' && mark[i][1][j] == 'O' && mark[i][2][j] == 'O')
				return 1;
			else if (mark[i][0][j] == 'X' && mark[i][1][j] == 'X' && mark[i][2][j] == 'X')
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (mark[i][j][0] == 'O' && mark[i][j][1] == 'O' && mark[i][j][2] == 'O')
				return 1;
			else if (mark[i][j][0] == 'X' && mark[i][j][1] == 'X' && mark[i][j][2] == 'X')
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if (mark[i][0][0] == 'O' && mark[i][1][1] == 'O' && mark[i][2][2] == 'O')
			return 1;
		else if (mark[i][0][0] == 'X' && mark[i][1][1] == 'X' && mark[i][2][2] == 'X')
			return 2;
		else if (mark[i][0][2] == 'O' && mark[i][1][1] == 'O' && mark[i][2][0] == 'O')
			return 1;
		else if (mark[i][0][2] == 'X' && mark[i][1][1] == 'X' && mark[i][2][0] == 'X')
			return 2;
	}

	for (i = 0; i < 3; i++)
	{
		if (mark[0][i][0] == 'O' && mark[1][i][1] == 'O' && mark[2][i][2] == 'O')
			return 1;
		else if (mark[0][i][0] == 'X' && mark[1][i][1] == 'X' && mark[2][i][2] == 'X')
			return 2;
		else if (mark[0][i][2] == 'O' && mark[1][i][1] == 'O' && mark[2][i][0] == 'O')
			return 1;
		else if (mark[0][i][2] == 'X' && mark[1][i][1] == 'X' && mark[2][i][0] == 'X')
			return 2;
	}

	for (i = 0; i < 3; i++)
	{
		if (mark[0][0][i] == 'O' && mark[1][1][i] == 'O' && mark[2][2][i] == 'O')
			return 1;
		else if (mark[0][0][i] == 'X' && mark[1][1][i] == 'X' && mark[2][2][i] == 'X')
			return 2;
		else if (mark[2][0][i] == 'O' && mark[1][1][i] == 'O' && mark[0][2][i] == 'O')
			return 1;
		else if (mark[2][0][i] == 'X' && mark[1][1][i] == 'X' && mark[0][2][i] == 'X')
			return 2;
	}

	if (mark[0][0][0] == 'O' && mark[1][1][1] == 'O' && mark[2][2][2] == 'O')
		return 1;
	else if (mark[0][0][0] == 'X' && mark[1][1][1] == 'X' && mark[2][2][2] == 'X')
		return 2;
	else if (mark[0][2][2] == 'O' && mark[1][1][1] == 'O' && mark[2][0][0] == 'O')
		return 1;
	else if (mark[0][2][2] == 'X' && mark[1][1][1] == 'X' && mark[2][0][0] == 'X')
		return 2;
	else if (mark[0][0][2] == 'O' && mark[1][1][1] == 'O' && mark[2][2][0] == 'O')
		return 1;
	else if (mark[0][0][2] == 'X' && mark[1][1][1] == 'X' && mark[2][2][0] == 'X')
		return 2;
	else if (mark[2][0][2] == 'O' && mark[1][1][1] == 'O' && mark[0][2][0] == 'O')
		return 1;
	else if (mark[2][0][2] == 'O' && mark[1][1][1] == 'O' && mark[0][2][0] == 'O')
		return 2;
}

