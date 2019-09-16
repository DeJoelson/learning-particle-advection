#ifndef VTK_PROCESSOR
#define VTK_PROCESSOR

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

class VTKProcessor
{
public:
	template<typename ScalarDataAtPoint>
	static void Write3DRectilinearGridToFile(std::vector<std::tuple<double, double, double, ScalarDataAtPoint>>& list_of_points, std::string filename);
private:
	template<typename ScalarDataAtPoint>
	static bool SortStrategy_(const std::tuple<double, double, double, ScalarDataAtPoint>& a, const std::tuple<double, double, double, ScalarDataAtPoint>& b);
	
	template<typename ScalarDataAtPoint>
	static std::set<double> GetUniqueComponents(std::vector<std::tuple<double, double, double, ScalarDataAtPoint>>& list_of_points, int component);
};

template<typename ScalarDataAtPoint>
inline void VTKProcessor::Write3DRectilinearGridToFile(std::vector<std::tuple<double, double, double, ScalarDataAtPoint>>& list_of_points, std::string filename)
{
	// (1) Sort the data appropriately.
	std::sort(list_of_points.begin(), list_of_points.end(), SortStrategy_<ScalarDataAtPoint>);
	// (2) Get components as their own separate list.
	std::set<double> x_components = GetUniqueComponents(list_of_points, 0);
	std::set<double> y_components = GetUniqueComponents(list_of_points, 1);
	std::set<double> z_components = GetUniqueComponents(list_of_points, 2);

	// (3) Write preliminary header data to file.
	std::ofstream vtk_file;
	vtk_file.open(filename);
	vtk_file << "# vtk DataFile Version 3.0" << std::endl;
	vtk_file << "vtk output" << std::endl;
	vtk_file << "ASCII" << std::endl;
	vtk_file << "DATASET RECTILINEAR_GRID" << std::endl;
	// The +1 to the component size is due to a pattern seen in other rectilinear grids -- it may not be accurate.
	vtk_file << "DIMENSIONS " << x_components.size() << " " << y_components.size() << " " << z_components.size() << std::endl;

	// All sets are ordered by the C++ standard, as defined by the << operator of the elements.
	// (4a) Write x coordinates
	vtk_file << "X_COORDINATES " << x_components.size() << " double" << std::endl;
	for (double x_component : x_components)
	{
		vtk_file << x_component << std::endl;
	}
	// (4b) Write y coordinates
	vtk_file << "Y_COORDINATES " << y_components.size() << " double" << std::endl;
	for (double y_component : y_components)
	{
		vtk_file << y_component << std::endl;
	}
	// (4c) Write z coordinates
	vtk_file << "Z_COORDINATES " << z_components.size() << " double" << std::endl;
	for (double z_component : z_components)
	{
		vtk_file << z_component << std::endl;
	}
	/*
	SCALARS mesh_quality/aspect float
LOOKUP_TABLE default
	*/
	// (5) Write out scalar data 
	// (Is each scalar is technically assigned to each cell where the point is the one in the positive xyz corner?)
	vtk_file << "POINT_DATA " << list_of_points.size() << std::endl;
	
	//vtk_file << "FIELD FieldData 4" << std::endl;
	//vtk_file << "density 1               " << list_of_points.size() << " double" << std::endl;
	
	vtk_file << "SCALARS generated_value" << " double 1" << std::endl;
	vtk_file << "LOOKUP_TABLE default" << std::endl;
	for (int index = 0; index < list_of_points.size() - 1; index++)
	{
		vtk_file << std::get<3>(list_of_points[index]) << std::endl;
	}
	// No newline on last row.
	vtk_file << std::get<3>(list_of_points[list_of_points.size() - 1]);
	
	vtk_file.close();
}

template<typename ScalarDataAtPoint>
inline bool VTKProcessor::SortStrategy_(const std::tuple<double, double, double, ScalarDataAtPoint>& a, const std::tuple<double, double, double, ScalarDataAtPoint>& b)
{
	if (std::get<0>(a) == std::get<0>(b))
	{
		if (std::get<1>(a) == std::get<1>(b))
		{
			if (std::get<2>(a) == std::get<2>(b))
			{
				return (std::get<3>(a) < std::get<3>(b));
			}
			return (std::get<2>(a) < std::get<2>(b));
		}
		return (std::get<1>(a) < std::get<1>(b));
	}
	return (std::get<0>(a) < std::get<0>(b));
}

template<typename ScalarDataAtPoint>
inline std::set<double> VTKProcessor::GetUniqueComponents(std::vector<std::tuple<double, double, double, ScalarDataAtPoint>>& list_of_points, int component)
{
	// Initialize component values vector
	std::set<double> component_values;
	// Add all components to the vector
	for (int index = 0; index < list_of_points.size(); index++)
	{
		double component_value;
		if (component == 0)
		{
			component_value = std::get<0>(list_of_points[index]);
		}
		if (component == 1)
		{
			component_value = std::get<1>(list_of_points[index]);
		}
		if (component == 2)
		{
			component_value = std::get<2>(list_of_points[index]);
		}
		component_values.insert(component_value);
	}
	/*
	// Remove duplicates
	std::vector<double>::iterator iter;
	iter = std::unique(component_values.begin(), component_values.end());
	// Resize the vector so there are no "undefined" values due to the duplicate removal.
	//component_values.resize(std::distance(component_values.begin(), iter));
	component_values.erase(std::unique(component_values.begin(), component_values.end()), component_values.end());
	// Return duplicate-free vector
	*/
	return component_values;
}

#endif
