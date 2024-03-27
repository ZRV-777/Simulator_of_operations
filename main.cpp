#include "src/tools.cpp"

using namespace std;

int main()
{
    string command;
    string current_command;

    bool is_cut = false;

    double coordinate_x = 0.0;
    double coordinate_y = 0.0;

    vector<coordinate> scalpel_start;
    vector<coordinate> scalpel_end;
    vector<coordinate> point_h;
    vector<coordinate> point_t;
    vector<coordinate> suture_start;
    vector<coordinate> suture_end;

    int count_command = 0;

    while (command != "exit")
    {
        cout << "Enter command: ";
        cin >> command;
        current_command = command;

        if (count_command == 0 && current_command != "scalpel")
        {
            cerr << "\n" << "First command must be scalpel" << endl;
        }
        else
        {
            count_command++;

            if (command == "scalpel")
            {
                if (is_cut)
                {
                    cerr << "You can't cut the same place twice" << endl;
                }

                cout << endl << "Input start cut" << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &scalpel_start);

                cout << endl << "Input end cut: " << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &scalpel_end);

                scalpel(scalpel_start, scalpel_end);

                is_cut = true;

                //current_command = "scalpel";
                count_command++;
            }
            else if (command == "hemostat")
            {
                cout << endl << "Input hemostat point" << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &point_h);
                if (!is_cut_start(point_h, scalpel_start))
                {
                    cerr << "Hemostat can't be used before the cut" << endl;
                }
                else if (!is_cut_end(point_h, scalpel_end))
                {
                    cerr << "Hemostat can't be used after the cut" << endl;
                }
                else
                {
                    hemostat(point_h);
                }

                //current_command = "hemostat";
                count_command++;
            }
            else if (command == "tweezers")
            {
                cout << endl << "Input tweezers point" << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &point_t);
                if (!is_cut_start(point_t, scalpel_start))
                {
                    cerr << "Tweezers can't be used before the cut" << endl;
                }
                else if (!is_cut_end(point_t, scalpel_end))
                {
                    cerr << "Tweezers can't be used after the cut" << endl;
                }
                else
                {
                    tweezers(point_t);
                }

                //current_command = "tweezers";
                count_command++;
            }
            else if (command == "suture")
            {
                cout << endl << "Input start sewing" << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &suture_start);
                if (!check_coordinate(scalpel_start, suture_start))
                {
                    cerr << "Incorrect suture start coordinate" << endl;
                }

                cout << endl << "Input end sewing" << endl;
                input_coordinate_point(coordinate_x, coordinate_y, &suture_end);
                if (!check_coordinate(scalpel_end, suture_end))
                {
                    cerr << "Incorrect suture end coordinate" << endl;
                }

                suture(suture_start, suture_end);

                cout << endl << "Operation finished!" << endl;
                is_cut = false;

                cout << "\n" << "Did you want to continue? (yes/no): ";
                cin >> command;

                if (command == "yes")
                {
                    cout << endl << "Input start cut" << endl;
                    input_coordinate_point(coordinate_x, coordinate_y, &scalpel_start);
                    cout << endl << "Input end cut" << endl;
                    input_coordinate_point(coordinate_x, coordinate_y, &scalpel_end);

                    scalpel(scalpel_start, scalpel_end);

                    //current_command = "scalpel";

                    is_cut = true;
                }
                else if (command == "no")
                {
                    command = "exit";
                    cout << "\n" << "Goodbye!" << endl;
                }
                else
                {
                    cerr << "\n" << "Incorrect command" << endl;
                }
            }
        }
    }
}