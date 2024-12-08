//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
int coin; //얻은 코인 개수
int cycle; //모든 플레이어가 한 번씩 주사위를 던졌을 때 1이 됨
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {	
		if(player_status[i] == PLAYERSTATUS_LIVE)
        {
			if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
	        {
	            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
	            player_status[i] = PLAYERSTATUS_DIE;
	        }
    	}
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
    int i;
    int cnt = 0;
    for (i=0; i<N_PLAYER; i++)
    {
        if(player_status[i] == PLAYERSTATUS_END)
            cnt++;
    }
    return cnt;
}

int getWinner(void)
{
    int i;
    int winner = 0;
    int max_coin = -1;

    for (i=0; i<N_PLAYER; i++)
    {
        if(player_status[i] == PLAYERSTATUS_END)
        {
            if (player_coin[i] > max_coin)
            {
                max_coin = player_coin[i];
                winner = i;
            }
        }
    }
    return winner;
}
// ----- EX. 6 : game end ------------











int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;




// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {   
            turn = (turn + 1)%N_PLAYER;
            if (turn == 0)
            {
                int shark_pos = board_stepShark();
                printf("Shark moved to %i\n", shark_pos);
                //check die
                checkDie();
            }
            continue;
        }

// ----- EX. 4 : player ------------



        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
// ----- EX. 4 : player ------------
        dieResult = rolldie();
    


        
        //step 2-3. moving 
        player_position[turn] = player_position[turn] + dieResult;
        printf("Die result %d, %s moved to %d!\n", dieResult, player_name[turn], player_position[turn]);
        
        //step 2-4. coin
        coin = board_getBoardCoin(player_position[turn]);
        if(coin != 0)
        {
            player_coin[turn] = player_coin[turn] + coin;
            printf("Lucky! %s get %d coin!\n", player_name[turn], coin);
        }
        
        
        //step 2-5. end process
        if(player_position[turn] >= N_BOARD-1)
        {
            printf("%s reached to the end! (coins : %d)\n", player_name[turn], player_coin[turn]);
            player_status[turn] = PLAYERSTATUS_END;
        }

		
		if(player_status[0] != PLAYERSTATUS_LIVE && player_status[1] != PLAYERSTATUS_LIVE && player_status[2] != PLAYERSTATUS_LIVE)
			break;

        turn = (turn + 1)%N_PLAYER;

        
        if (turn == 0)
            {
                int shark_pos = board_stepShark();
                printf("Shark moved to %i\n", shark_pos);
                //check die
                checkDie();
            }

// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    if(player_status[0] == PLAYERSTATUS_DIE && player_status[1] == PLAYERSTATUS_DIE && player_status[2] == PLAYERSTATUS_DIE)
    {
        printf("GAME END!\n");
        printf("All players have died.\n");
    }else{
    //step 3. game end process
    printf("GAME END!!\n");
    printf("%i players are alive! winner is %s.\n", getAlivePlayer(), player_name[getWinner()]);}
// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------
	
    return 0;
}


