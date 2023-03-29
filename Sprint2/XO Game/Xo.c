/*
 ============================================================================
 Name        : Xo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
uint8_t board[9];
uint8_t position[1] ;

void drawBoard(uint8_t* board) {

	for (uint8_t i = 1; i < 10; i++) {
		if (i == 3 || i == 6)
			printf("%c\n\n", board[i - 1]);
		else if (i == 9)
			printf("%c\n\n\n", board[i - 1]);
		else
			printf("%c\t", board[i - 1]);
	}
}


void updateBoard(uint8_t* board, uint8_t position, uint8_t value) {
	 uint8_t x = 0;
	  for(x=0; x<9; x++){
	      if(position==board[x]){
	          board[x] = value;
	            }
	  }
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol) {

	printf("Please enter you symbol(x/o) player%c\n",playerNumber);
	fflush(stdout);
	scanf(" %c", symbol);

	*symbol = tolower(*symbol);
	if (*symbol == 'o' || *symbol == 'x'){
		return 0;
	return 1;
}
}

void setPlayerConfig(uint8_t* configArray) {
	int Error = 1;
	while (Error) {
		Error = getPlayerSymbol('1', &configArray[0]);
	}
	Error = 1;
	while (Error) {
		Error = getPlayerSymbol('2', &configArray[1]);
	}
	if(configArray[0] == 'x'){
		printf("\n\nPlayer1:x \nPlayer2:o");
		configArray[1]='o';
	}
	else{
		printf("Player1:o \nPlayer2:x\n");
		configArray[1]='x';
	    }
}

void loadAndUpdate(uint8_t playerNumber){
	printf("\nPlease enter the position ,player%d\n",playerNumber);
	fflush(stdout);
	scanf(" %c",&position[0]);
	}


void getGameState(uint8_t *board, uint8_t *gameState){
	if(board[0]==board[1]&&board[1]==board[2])
		*gameState = 0;
	else if(board[3]==board[4]&&board[4]==board[5])
		*gameState = 0;
	else if(board[6]==board[7]&&board[7]==board[8])
			*gameState = 0;
	else if(board[0]==board[3]&&board[3]==board[6])
			*gameState = 0;
	else if(board[1]==board[4]&&board[4]==board[7])
			*gameState = 0;
	else if(board[2]==board[5]&&board[5]==board[8])
			*gameState = 0;
	else if(board[0]==board[4]&&board[4]==board[8])
			*gameState = 0;
	else if(board[2]==board[4]&&board[4]==board[6])
			*gameState = 0;
	else if(board[0]!='1' && board[1]!='2' && board[2]!='3' && board[3]!='4'
			&& board[4]!='5' &&board[5]!='6' &&board[6]!='7'
			&&board[7]!='8' &&board[8]!='9')
		    *gameState = 1;
	else
		*gameState = 2;
}




int main(void) {

	uint8_t Board[9] = {'1','2','3','4','5','6','7','8','9'};
	uint8_t xo[2] ;
	uint8_t state ;
	uint8_t player=1;

	printf("Lets play X-O\n\n");
	drawBoard(Board);
	setPlayerConfig(xo);
	do{

        player = (player % 2) ? 1 : 2;

        loadAndUpdate(player);
        updateBoard (Board, position[0], xo[player-1]);
        getGameState(Board, &state);
        drawBoard(Board);
        player++;
     } while (state == 2);

    if(state == 0)
   {
       printf("Player %d win", --player);
  }
    else if(state == 1){
    	printf("Draw");
    }



	return 0;
}


