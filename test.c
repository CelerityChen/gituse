#include "game.h"

void menu();
void game();

int main(){

	int state = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("please chose\n");
		scanf("%d", &state);
		switch(state){
			case 1:
				game();
				break;
			case 0:

				break;
			default:
				printf("Error input, please chose again\n");
				scanf("%d", &state);
				break;
		}
	}while(state);

	return 0;
}

void menu(){
	printf("*****************************\n");
	printf("***********1. play***********\n");
	printf("***********0. exit***********\n");
	printf("*****************************\n");
}

void game(){
	char arr[ROW][COL] = {0};
	char ret = '\0';
	init(arr);
	while(1){
		human_go(arr);
		ret = result(arr);
		if(ret != 'C' || ret == 'Q')	break;
		computer_go(arr);
		ret = result(arr);
		if(ret != 'C')	break;
	}
	if(ret == '*')	printf("You win!\n");
	else if(ret == 'x')	printf("computer win!\n");
	else	printf("it's tied\n");
}

