// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fields/ABCUnsteadyVectorField.cpp>
#include <utils/NP.h>
#include <dataio/VTKProcessor.h>
#include <math.h>
#include <string>

int main()
{    // Heavy use of "header library"-like functionality for code reuse going into the future.
    // Still need to decide on an integration strategy. Stepwise Euler is probably sufficient for now.

    // Configure base name of all output files.
    std::string base_output_directory = "../outputs/ABCUnsteady/";
    std::string base_filename = "ABCUnsteadyVectorField";

    // Determine parameterized field to visualize

    /* The "standard" way to access implemented abstract methods from parent class:
    Base* b;
    Derived d;
    b = &d;
    b->abstractMethod();	
    */

    ParameterizedUnsteadyVectorField* field;
    ABCUnsteadyVectorField abcUnsteadyInstance;
    field = &abcUnsteadyInstance;

    // Configure "Time" Settings
    double cycle_count = 512;
    double time_step = 0.001;
    double time_start = 0.0;
    double time_end = (cycle_count * time_step) - time_step;

    // Configure "Window" Settings
    double x_min = 0.0;
    double x_max = 2.0 * M_PI;
    int x_count = 64;
    double y_min = 0.0;
    double y_max = 2.0 * M_PI;
    int y_count = 64;
    double z_min = 0.0;
    double z_max = 2.0 * M_PI;
    int z_count = 64;

    // Get Window and Time Points
    std::vector<double> time_steps = NP::Linspace(time_start, time_end, cycle_count);
    std::vector<double> x_coords = NP::Linspace(x_min, x_max, x_count);
    std::vector<double> y_coords = NP::Linspace(y_min, y_max, y_count);
    std::vector<double> z_coords = NP::Linspace(z_min, z_max, z_count);

    std::vector<std::tuple<double, double, double, double>> list_of_points;
    int timestep_index = 0;
    for (double point_in_time : time_steps)
    {
        for (double x_val : x_coords)
        {
            for (double y_val : y_coords)
            {
                for (double z_val : z_coords)
                {
                    double mag = field->getDeltaMValue(point_in_time, x_val, y_val, z_val);
                    list_of_points.push_back(std::make_tuple(x_val, y_val, z_val, mag));
                }
            }
        }
        std::string filename = base_output_directory;
        filename.append(base_filename);
        filename.append("_");
        filename.append(std::to_string(timestep_index));
        filename.append(".vtk");
        VTKProcessor::Write3DRectilinearGridToFile <double> (list_of_points, filename);
        timestep_index += 1;
        std::cout << "Printing line " << timestep_index << " of " << time_steps.size() << "; " << round(10000.0 * timestep_index / time_steps.size()) / 100.0 << "%" << std::endl;
    }
}