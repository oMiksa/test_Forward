#include "internal_combustion_engine.h"

double internal_combustion_engine::M_by_V(double V) {
	if (V < M_V.begin()->second || V > M_V.rbegin()->second)
		return -1;
	vector<pair<int, int>>::iterator itr = M_V.begin();
	vector<pair<int, int>>::iterator itr_next = M_V.begin() + 1;
	for (; itr_next != M_V.end();) {
		if (itr->second <= V && V <= itr_next->second)
			return value_calculation(itr->second, itr_next->second, itr->first, itr_next->first, V);
		itr++;
		itr_next++;
	}
	return -1;
}

double internal_combustion_engine::value_calculation(int V1, int V2, int M1, int M2, double V) {
	return M1 + (V - V1) / (V2 - V1) * (M2 - M1);
}

bool internal_combustion_engine::overheat() {
	return (T_engine >= T_overheat);
}

double internal_combustion_engine::get_V_engine() {
	return V_engine;
}

double internal_combustion_engine::get_M_engine() {
	return M_engine;
}

double internal_combustion_engine::get_T_engine() {
	return T_engine;
}

double internal_combustion_engine::get_T_space() {
	return T_space;
}

void internal_combustion_engine::set_M_engine(double M) {
	M_engine = M;
}

void internal_combustion_engine::set_V_engine(double V) {
	V_engine = V;
}

void internal_combustion_engine::set_T_engine(double T) {
	T_engine = T;
}

void internal_combustion_engine::set_T_space(double T) {
	T_space = T;
}

void internal_combustion_engine::input_T_space() {
	string str;
	regex re("-?[0-9]+");
	do {
		cout << "Введите температуру окружающей среды в С*." << endl;
		cin >> str;
	} while (!regex_match(str, re));
	set_T_engine(stod(str));
	set_T_space(stod(str));
	
}

double internal_combustion_engine::boosting(double M) {
	return M * I;
}

double internal_combustion_engine::speed_heating(int M, int V) {
	return M * H_M + pow(V, 2) * H_V;
}

double internal_combustion_engine::speed_cooling() {
	return C * (T_space - T_engine);
}

void internal_combustion_engine::print_end(int time) {
	if (this->overheat()) {
		cout << "При температуре окружающей среды " << get_T_space() << " С*, перегрев произошёл на " << time << " секунде." << endl;
		cout << "Скорость вращения вала ~" << get_V_engine() << " рад/сек." << endl;
	}
	else
	{
		cout << "При температуре окружающей среды " << get_T_space() << " C* перегрева не будет более суток." << endl;
		cout << "Скорость вращения вала ~" << get_V_engine() << " рад/сек." << endl;
	}
}

internal_combustion_engine::internal_combustion_engine(double T) {
	M_V.push_back(pair<int, int>(20, 0));
	M_V.push_back(pair<int, int>(75, 75));
	M_V.push_back(pair<int, int>(100, 150));
	M_V.push_back(pair<int, int>(105, 200));
	M_V.push_back(pair<int, int>(100, 250));
	M_V.push_back(pair<int, int>(0, 300));

	I = 0.1;
	T_overheat = 110;
	H_M = 0.01;
	H_V = 0.0001;
	C = 0.1;

	T_space = T;
	T_engine = T_space;
	V_engine = 0;
	M_engine = M_by_V(V_engine);
}

internal_combustion_engine::internal_combustion_engine() {
	M_V.push_back(pair<int, int>(20, 0));
	M_V.push_back(pair<int, int>(75, 75));
	M_V.push_back(pair<int, int>(100, 150));
	M_V.push_back(pair<int, int>(105, 200));
	M_V.push_back(pair<int, int>(100, 250));
	M_V.push_back(pair<int, int>(0, 300));

	I = 0.1;
	T_overheat = 110;
	H_M = 0.01;
	H_V = 0.0001;
	C = 0.1;

	T_space = 0;
	T_engine = T_space;
	V_engine = 0;
	M_engine = M_by_V(V_engine);
}

internal_combustion_engine::~internal_combustion_engine() {

}
