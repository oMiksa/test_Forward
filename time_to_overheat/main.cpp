#include "internal_combustion_engine.h"
#include <iostream>

using namespace std;


int main(int argc, int *argv[]) {
	setlocale(LC_ALL, "rus");

	internal_combustion_engine my_engine;

	my_engine.input_T_space();

	long long time = 0;
	for (; (time < ONE_DAY && !my_engine.overheat()); time++) {
		//V = V + a
		my_engine.set_V_engine(my_engine.get_V_engine() + my_engine.boosting(my_engine.get_M_engine()));
		//find new M
		my_engine.set_M_engine(my_engine.M_by_V(my_engine.get_V_engine()));
		//T = T + T_overheat + T_cooling
		my_engine.set_T_engine(my_engine.get_T_engine() + my_engine.speed_heating(my_engine.get_M_engine(), my_engine.get_V_engine()) + my_engine.speed_cooling());
	}

	my_engine.print_end(time);

	system("pause");
	return 0;
}
