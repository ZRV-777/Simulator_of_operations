#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct coordinate
{
    double x;
    double y;
};

vector<coordinate> input_coordinate_point(double a, double b, vector<coordinate> *vector1);

bool check_coordinate (vector<coordinate> &vector1, vector<coordinate> &vector2);

bool is_cut_start (vector<coordinate> &vector1, vector<coordinate> &vector2);

bool is_cut_end (vector<coordinate> &vector1, vector<coordinate> &vector2);