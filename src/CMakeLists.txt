cmake_minimum_required(VERSION 3.10)
project(learning_particle_advection)

#SET(VTKm_DIR ../vtk-m/lib/cmake/vtkm-1.4/)
#find_package(VTKm REQUIRED)

#SET(VTK_DIR /home/users/sam/apps/vtk/8.2.0/build)
#find_package(VTK REQUIRED)
set(ROOT /home/users/sam/summer_2019_workbench/learning-particle-advection/src)
include_directories(".")
add_executable(Start Start.cpp)
#target_link_libraries(Start)
