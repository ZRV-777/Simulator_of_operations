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

bool is_valid_point_cut (vector<coordinate> &point_start, vector<coordinate> &point_check, vector<coordinate> &point_end);