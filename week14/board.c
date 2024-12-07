//
//  board.h
//  sharkGame
//


#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>

// ----- EX. 3 : board ------------
#define N_BOARD                 20

//0 - OK, 1 - destroyed
#define BOARDSTATUS_NOK          1
#define BOARDSTATUS_OK           0

int board_initBoard(void);
int board_getBoardStatus(int pos);
int board_getShartPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);
void board_printBoardStatus(void);
// ----- EX. 3 : board ------------
#endif /* board_h */














//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD] = {0};
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------
int coin_pos[N_COINPOS] = {0};
int coin_value[N_COINPOS] = {0};

static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation , 20241207김예지
    for (i=0;i<N_COINPOS;i++) 
    {
    	while(coin_value[i] == 0)
        {
            coin_pos[i] = rand()%N_BOARD;//동전을 놓을 칸을 랜덤으로 지정
            if(board_coin[coin_pos[i]] == 0)
            {
                coin_value[i] = rand()%MAX_COIN+1;
    		    board_coin[coin_pos[i]] = coin_value[i];
            }
        }
	}
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void)
{
    int i;
    int shark_step = rand()%MAX_SHARKSTEP+1; // 상어가 움직이는 칸 수, 1~MAX_SHARKSTEP 중 랜덤
    shark_position = shark_position + shark_step; // 상어 포지션 변경, 기존 포지션에서 움직이는 칸 수 만큼 더해줌
    
    //상어 포지션까지 destroyed board_status 만들기
    for(i=0;i<=shark_position;i++)
    {
        board_status[i] = BOARDSTATUS_NOK;
    }
    return shark_position;
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
