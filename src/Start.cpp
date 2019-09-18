// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fields/ABCUnsteadyVectorField.h>
#include <utils/NP.h>
#include <dataio/VTKProcessor.h>

int main()
{
	// Heavy use of "header library"-like functionality for code reuse going into the future.
	// Still need to decide on an integration strategy. Stepwise Euler is probably sufficient for now.
	
	/* The "standard" way to access implemented abstract methods from parent class:
	Base* b;
	Derived d;
	b = &d;
	b->abstractMethod();	
	*/
	
	ParameterizedUnsteadyVectorField* field;
	ABCUnsteadyVectorField abcUnsteadyInstance;
	field = &abcUnsteadyInstance;

	//ABCTimeSeriesVectorField field();

	std::vector<std::tuple<double, double, double, double>> list_of_points;

	// Example of pushing back a tuple onto the list:
	// list_of_points.push_back(std::make_tuple(1.0, 2.0, 3.0, 4.0));

	std::vector<double> x_coords = NP::Linspace(-10, 10, 64);
	std::vector<double> y_coords = NP::Linspace(-10, 10, 64);
	std::vector<double> z_coords = NP::Linspace(-10, 10, 64);

	double time_step = 0.0;

	for (double x_val : x_coords)
	{
		for (double y_val : y_coords)
		{
			for (double z_val : z_coords)
			{
				double mag = field->getDeltaMValue(time_step, x_val, y_val, z_val);
				list_of_points.push_back(std::make_tuple(x_val, y_val, z_val, mag));
			}
		}
	}

	VTKProcessor::Write3DRectilinearGridToFile <double> (list_of_points, std::string("sam_output_4.vtk"));
}
