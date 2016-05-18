#include "GlobalVar.h"

GlobalVar GV;

GlobalVar::GlobalVar()
{
	GameUpdateMillisecond = 1 / 60 * 1000;
	BattleUpdateMillisecond = 100;
}
