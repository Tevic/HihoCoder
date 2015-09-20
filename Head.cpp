#include "Head.h"

void ReOpenText()
{
#ifdef DEBUG_MODE
	freopen("Input.txt", "r", stdin);
#endif // DEBUG_MODE
}