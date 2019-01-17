#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <regex>

#define ONE_DAY 86400

using namespace std;

class internal_combustion_engine {
private:
	double M_engine;
	double V_engine;
	double T_engine;

	double I;
	vector<pair<int, int>> M_V;
	double T_overheat;
	double T_space;
	double H_M;
	double H_V;
	double C;

	
	double value_calculation(int V1, int V2, int M1, int M2, double V);

public:
	bool overheat();
	double M_by_V(double V);
	double get_M_engine();
	double get_V_engine();
	double get_T_engine();
	double get_T_space();
	void set_M_engine(double M);
	void set_V_engine(double V);
	void set_T_engine(double T);
	void set_T_space(double T);
	void input_T_space();
	double boosting(double M);
	double speed_heating(int M, int V);
	double speed_cooling();
	void print_end(int time);

	internal_combustion_engine();
	internal_combustion_engine(double T_space);
	virtual ~internal_combustion_engine();
};

