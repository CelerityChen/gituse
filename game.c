#include "game.h"


void showAll(char (*ptarr)[COL]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(j != COL-1)	printf(" %c |",*(*(ptarr+i)+j));
			else	printf(" %c \n",*(*(ptarr+i)+j));
		}
		if(i != ROW-1)	printf("---|---|---\n");
	}
}

void init(char (*ptarr)[COL]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			*(*(ptarr+i)+j) = ' ';
		}
	}
	showAll(ptarr);
}

int isFull(char (*ptarr)[COL]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(*(*(ptarr+i)+j) == ' ')	return 0;
		}
	}
	return 1;
}

char result(char (*ptarr)[COL]){
	
	int flag = 0;
	//jugde by ROW
	for(int i = 0; i < ROW; i++){
		for(int j = 1; j < COL; j++){
			if(**(ptarr+i) == *(*(ptarr+i)+j) && **(ptarr+i) != ' ')	flag = 1;
			else{
				flag = 0;	
				break;
			}
		}
		if(flag == 1)	return **(ptarr+i);
	}
	//judge by COL
	for(int i = 0; i < COL; i++){
		for(int j = 1; j < ROW; j++){
			if(*(*ptarr+i) == *(*(ptarr+j)+i) && *(*ptarr+i) != ' ')	flag = 1;
			else{
			      	flag = 0;
				break;
			}
		}
		if(flag == 1) return *(*ptarr+i);
	}
	//judge by diagonal
/*
 * for this situation
 *  * 
 *    *
 *      *
 */
	for(int i = 1; i < ROW; i++){
		if(**ptarr == *(*(ptarr+i)+i) && **ptarr != ' ')	flag = 1;
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1) return **ptarr;
/*
 * for this situation
 *  * 
 *    * 
 *      *  
 */
	for(int i = 1; i < ROW; i++){
		if(**(ptarr + ROW - 1) ==  *(*(ptarr + ROW - 1 - i) + i) && **(ptarr + ROW -1) != ' ')	flag = 1;
		else{
		       	flag = 0;
			break;
		}
	}
	if(flag == 1) return *(*(ptarr+1)-1);

	if(isFull(ptarr))	return 'Q';
	else	return 'C';
	
}

void human_go(char (*ptarr)[COL]){
	int x = 0, y = 0;
	printf("please select the position\n");
	while(1){
		scanf("%d %d",&x, &y);
		//whether the position is available
		if(x >= 1 && x <= ROW && y >= 1 && y <= COL){
			//whether the position is selected
			if(*(*(ptarr + x - 1) + y - 1) == ' '){
				*(*(ptarr + x - 1) + y - 1)= '*';
				break;
			}
			else	printf("the position had been selected.\n");
		}else	printf("Error! Please selected again.\n");
	}		
	showAll(ptarr);
}

void computer_go(char (*ptarr)[COL]){
	while(1){
		int x = rand() % ROW;
		int y = rand() % COL;
		if(*(*(ptarr + x ) + y ) == ' '){
			*(*(ptarr + x ) + y )  = 'x';
			printf("computer has choosed:\n");
			break;
		}
	}
	showAll(ptarr);
}

