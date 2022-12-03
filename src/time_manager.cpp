#include "time_manager.h"

#include "search.h"
#include "uci.h"
#include <algorithm>
#include <cfloat>
#include <cmath>

//Calculate how much time to spend on searching a move
void optimum(S_Board* pos, S_SearchINFO* info, int time, int inc) {
	//if we recieved a time parameter from the gui
	if (time != -1) {
		info->timeset = TRUE;
		//If we recieved a movestogo parameter
		if (info->movestogo != -1) {
			int safety_overhead = 50;
			time -= safety_overhead;
			int time_slot = time / info->movestogo;
			int basetime = (time_slot);
			//optime is the time we check anytime we clear a depth
			int optime = basetime * 0.6;
			//maxtime is the absolute maximum time we can spend on the current depth
			int maxtime = (std::min)(time, basetime * 5/3);
			info->stoptimeMax = info->starttime + maxtime;
			info->stoptimeOpt = info->starttime + optime;
		}
		else
		{
			int safety_overhead = 50;
			time -= safety_overhead;
			int time_slot = time / 20 + inc / 2;
			int basetime = (time_slot);
			//optime is the time we use to stop if we just cleared a depth
			int optime = basetime * 0.6;
			//maxtime is the absolute maximum time we can spend on a search
			int maxtime = (std::min)(time, basetime * 5/3);
			info->stoptimeMax = info->starttime + maxtime;
			info->stoptimeOpt = info->starttime + optime;
		}
	}

	return;
}
