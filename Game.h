#include "Definition.h"

int Game(/*Player USER*/);
void Move(int &x,int &y,int xcen, int ycen,char Map[][MapMax]);
bool MoveCheck(int &x,int &y,int xcen, int ycen, int xmove, int ymove, char Map[][MapMax]);
int Input(void);
