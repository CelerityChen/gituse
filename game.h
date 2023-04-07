#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3

void init(char (*ptarr)[COL]);
void human_go(char (*ptarr)[COL]);
void computer_go(char (*ptarr)[COL]);
char result(char (*ptar)[COL]);
