//#include "tools.h"
#include "../include/tools.h"

vector<coordinate> input_coordinate_point(double x, double y, vector<coordinate> *vector)
{
    cout << "Input coordinate x: ";
    cin >> x;
    cout << "Input coordinate y: ";
    cin >> y;

    vector->push_back(coordinate{x, y});

    return *vector;
}

bool check_coordinate (vector<coordinate> &point_one, vector<coordinate> &point_two)
{
    if (point_one[0].x != point_two[0].x || point_one[0].y != point_two[0].y) return false;
    else return true;
}

bool is_cut_start (vector<coordinate> &point_one, vector<coordinate> &point_two)
{
    if (point_one[0].x < point_two[0].x && point_one[0].y < point_two[0].y)
    {
        return false;
    }

    return true;
}

bool is_cut_end (vector<coordinate> &point_one, vector<coordinate> &point_two)
{
    if (point_one[0].x > point_two[0].x && point_one[0].y > point_two[0].y)
    {
        return false;
    }

    return true;
}

void scalpel(vector <coordinate> &scalpel_start, vector <coordinate> &scalpel_end)
{
    cout << "\n" << "The cut makes from [" << scalpel_start[0].x << ":" << scalpel_start[0].y << "] to ["
        << scalpel_end[0].x << ":" << scalpel_end[0].y << "]" << endl;
}

void hemostat(vector <coordinate> &point_h)
{
    cout << "\n" << "Hemostat at [" << point_h[0].x << ":" << point_h[0].y << "]" << endl;
}

void tweezers(vector <coordinate> &point_t)
{
    cout << "\n" << "Tweezers at [" << point_t[0].x << ":" << point_t[0].y << "]" << endl;
}

void suture(vector <coordinate> &suture_start, vector <coordinate> &suture_end)
{
    cout << "\n" << "The cut was sewn up from [" << suture_start[0].x << ":" << suture_start[0].y << "] to ["
        << suture_end[0].x << ":" << suture_end[0].y << "]" << endl;
}