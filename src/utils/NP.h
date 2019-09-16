#ifndef NP_H
#define NP_H

#include <iostream>
#include <vector>

class NP
{
public:
	template<typename Scalar>
	static std::vector<double> Linspace(Scalar start_inclusive, Scalar end_inclusive, int total_number_of_entries);

	template<typename Scalar>
	static std::vector<double> Arange(Scalar start_inclusive, Scalar end_exclusive, Scalar step_size);
};

template<typename Scalar>
std::vector<double> NP::Linspace(Scalar start_inclusive, Scalar end_inclusive, int total_number_of_entries)
{
	// Implementation taken from https://stackoverflow.com/questions/27028226/python-linspace-in-c
	std::vector<double> linspaced;

	double start = static_cast<double>(start_inclusive);
	double end = static_cast<double>(end_inclusive);
	double num = static_cast<double>(total_number_of_entries);

	if (num == 0) { return linspaced; }
	if (num == 1)
	{
		linspaced.push_back(start);
		return linspaced;
	}

	double delta = (end - start) / (num - 1);

	for (int i = 0; i < num - 1; ++i)
	{
		linspaced.push_back(start + (delta * i));
	}
	linspaced.push_back(end); // I want to ensure that start and end
							  // are exactly the same as the input
	return linspaced;
}

template<typename Scalar>
std::vector<double> NP::Arange(Scalar start_inclusive, Scalar end_exclusive, Scalar step_size)
{
	std::vector<double> aranged;

	double start = static_cast<double>(start_inclusive);
	double end = static_cast<double>(end_exclusive);
	double step = static_cast<double>(step_size);

	for (double current_value = start; current_value < end; current_value += step)
	{
		aranged.push_back(current_value);
	}

	return aranged;
}
#endif