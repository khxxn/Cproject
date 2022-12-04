# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int i, j, k;
int turn = 2;	// 순서 정하기
int win;		//승자 정하기

void intro()		//게임 규칙및 설명 인트로
{
	printf(" 틱택토(tic - tac - toe)는 두 명이 번갈아가며\n");
	printf(" O와 X를 3개의 3×3 판에 써서\n");
	printf(" 같은 모양 3개가\n");
	printf(" 가로, 세로, 혹은 대각선 상에 놓이도록 하는 놀이입니다.\n");
	printf(" 먼저 세줄을 같은 모양으로 맞춘 사람이 승리합니다.\n\n");

	printf(" 예시)\n");			//예시 (player 1 이 bottom 보드중 (1,3) 좌표에 말을 놓을때) 
	printf(" board(1 : top, 2 : mid, 3 : bottom)\n");
	printf(" x, y = {1, 2, 3}\n");
	printf(" player 1 ( board, x, y ) : 3 1 3\n\n");

	printf("  (top)\t\t\t");
	printf("(mid)\t\t      ");
	printf("(bottom)\t\t\n\n");

	for (i = 0; i < 2; i++)
	{
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ\n");
		printf("  ㅣ    ㅣ    ㅣ    ㅣ");
		printf("  ㅣ    ㅣ    ㅣ    ㅣ");
		printf("  ㅣ    ㅣ    ㅣ    ㅣ\n");
	}
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ\n");
	printf("  ㅣ    ㅣ    ㅣ    ㅣ");
	printf("  ㅣ    ㅣ    ㅣ    ㅣ");
	printf("  ㅣ  O ㅣ    ㅣ    ㅣ\n");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ\n\n");

}

int board(char(*mark)[3][3]);
int playerturn(char(*mark)[3][3]);
int winner(char(*mark)[3][3]);

int main()
{
	intro();
	char mark[3][3][3];		//게임보드에 놓을 말	


	for (i = 0; i < 3; i++)		//말들을 공백으로 초기화
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
		playerturn(*mark);		//플레이어가 놓을 말의 좌표를 입력받음
		board(*mark);			//게임보드에 말을 입력하고 게임보드 표기
		win = winner(*mark);	// 승자가 나올때까지 무한루프후 승자가 나오면 break 로 탈출
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

int board(char(*mark)[3][3])		//게임보드를 출력해서 게임 진행상황을 표시함
{
	printf("  (top)\t\t\t");
	printf("(mid)\t\t      ");
	printf("(bottom)\t\t\n\n");

	for (i = 0; i < 3; i++)
	{
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
		printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ\n");
		printf("  ㅣ  %c ㅣ  %c ㅣ  %c ㅣ", mark[0][0][i], mark[0][1][i], mark[0][2][i]);
		printf("  ㅣ  %c ㅣ  %c ㅣ  %c ㅣ", mark[1][0][i], mark[1][1][i], mark[1][2][i]);
		printf("  ㅣ  %c ㅣ  %c ㅣ  %c ㅣ\n", mark[2][0][i], mark[2][1][i], mark[2][2][i]);
	}
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ");
	printf("  ㅣㅡㅡㅣㅡㅡㅣㅡㅡㅣ\n");

}

int playerturn(char(*mark)[3][3])
{
	int b, x, y;						//플레이어가 놓을 보드,x,y 좌표를 입력받고
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


	if (b != 1 && b != 2 && b != 3)					//만약 이미 말이 놓여져있는 곳이거나 
	{												//잘못된 좌표라면
		printf("잘못된 좌표 입니다.\n\n");			//함수 탈출후 다시 입력받게함
		turn--;
		return 0;
	}
	else if (x != 1 && x != 2 && x != 3)
	{
		printf("잘못된 좌표 입니다.\n\n");
		turn--;
		return 0;
	}
	else if (y != 1 && y != 2 && y != 3)
	{
		printf("잘못된 좌표 입니다.\n\n");
		turn--;
		return 0;
	}
	else if (mark[b - 1][x - 1][y - 1] == 'O' || mark[b - 1][x - 1][y - 1] == 'X')
	{
		printf("게임보드에 이미 말이 있습니다.\n\n");
		turn--;
		return 0;
	}

	if (turn % 2 == 1)		//좌표 입력
	{
		mark[b - 1][x - 1][y - 1] = 'O';
	}
	else
	{
		mark[b - 1][x - 1][y - 1] = 'X';
	}

}

int winner(char(*mark)[3][3])	//승패 결정
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

