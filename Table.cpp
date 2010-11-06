// (C) 2010 tmiz.net
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Table.h"

__BEGIN_NAMESPACE_15_PAZZLE

enum {
    D_UP = 0,
    D_RIGHT,
    D_DOWN,
    D_LEFT,
};

Table::Table()
{
    init();
}

Table::~Table()
{}

void Table::init()
{
    int i = 1, j = 0;
    for (; i < 16; i++, j++) {
	mTable[j] = i;
    }
    mTable[15] = 0;
}

void Table::printTable()
{
    printf("-------------------\n");
    int i = 0;
    for (i = 0; i < 16; i++) {
	if (mTable[i]) {
	    printf(" %2d", mTable[i]);
	} else {
	    printf("   ");
	}
	if ((i % 4)==3) printf("\n"); 
    }
}

int Table::find(int target)
{
    int i = 0;
    for (;i < 16; i++) {
	if (mTable[i] == target) {
	    return i;
	}
    }
	return -1;
}

bool Table::canMove(int m)
{
    int pos = findZero();
    int x = pos % 4;
    int y = pos / 4;
    
    switch (m) {
    case D_UP: {
	if (y == 0) return false;
	break;
    }
    case D_DOWN: {
	if (y == 3) return false;
	break;
    }
    case D_LEFT: {
	if (x == 0) return false;
	break;
    }
    case D_RIGHT: {
	if (x == 3) return false;
	break;
    }
    default:
	break;
    }
    return true;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Table::move(int m)
{
    int pos = findZero();
    switch (m) {
    case D_UP: {
	swap(&mTable[pos - 4], &mTable[pos]);
	break;
    }
    case D_DOWN: {
	swap(&mTable[pos + 4], &mTable[pos]);
	break;
    }
    case D_LEFT: {
	swap(&mTable[pos - 1], &mTable[pos]);
	break;
    }
    case D_RIGHT: {
	swap(&mTable[pos + 1], &mTable[pos]);
	break;
    }
    default:
	break;
    }
}

void Table::moveNumber(int m)
{
    int pos = findZero();    
    if ((pos>=4) && (mTable[pos-4] == m)) {
	if (canMove(D_UP)) {
	    move(D_UP);
	}
	return;
    }   
    if ((pos<12) && (mTable[pos+4] == m)) {
	if (canMove(D_DOWN)) {
	    move(D_DOWN);
	}
	return;
    }   
    if ((pos>=1) && (mTable[pos-1] == m)) {
	if (canMove(D_LEFT)) {
	    move(D_LEFT);
	}
	return;
    }
    if ((pos<15) && (mTable[pos+1] == m)) {
	if (canMove(D_RIGHT)) {
	    move(D_RIGHT);
	}
	return;
    }
}

int Table::getState()
{
    int i = 0, j = 1;
    for (; i<15; i++,j++) {
	if (mTable[i] != j) {
	    break;
	}
    }
    if (i == 15) {
	//clear
	return 1;
    }
    //continue
    return 0;
}


void Table::randomize(int step)
{
    //init table
    srand((unsigned int)time(NULL));
    int i = 0;
    for (; i < step;) {
	int m = rand() % 4;
	if (canMove(m)) {
	    move(m);
	    i++;
	    continue;
	}
    }
}

__END_NAMESPACE_15_PAZZLE

