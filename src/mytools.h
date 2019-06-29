#ifndef MYTOOLS
#define MYTOOLS

#define NOMINMAX

#include <vector>
#include <iostream>
#include <Eigen/Dense>
#include <igl/vertex_triangle_adjacency.h>
#include "nanoflann.hpp"
#include <igl/fit_plane.h>
#include <Eigen/SVD>

#include <random>
#include <Eigen/LU>
#include <igl/boundary_loop.h>
#include <igl/boundary_facets.h>
#include <igl/setdiff.h>
#include <igl/slice.h>
#include <igl/slice_into.h>
#include <igl/cotmatrix.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>

void get_axis(Eigen::MatrixXd & axis);


void calculate_vertex_normal(
	Eigen::MatrixXd const & V,
	Eigen::MatrixXi const & F,
	Eigen::MatrixXd const & FN,
	Eigen::MatrixXd & out_VN);

void calculate_vertex_normal_flann(
	Eigen::MatrixXd const & V, 
	Eigen::MatrixXi const & F,  
	Eigen::MatrixXd & out_VN);

Eigen::MatrixXd findNN(
            Eigen::MatrixXd Q,
            Eigen::MatrixXd P,
            size_t numberOfNN);

Eigen::SparseMatrix<double> uniform_LPB(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F
		);

double triangleArea(
		Eigen::RowVector3d a,
		Eigen::RowVector3d b,
		Eigen::RowVector3d c);

Eigen::SparseMatrix<double> getM(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F);


Eigen::SparseMatrix<double> invertDiagSparseMatrix(
        Eigen::SparseMatrix<double> M);

Eigen::VectorXd getH(
                     Eigen::MatrixXd V,
                     Eigen::MatrixXi F,
                     bool cotan);

void get_example_mesh(
                      std::string const meshname,
                      Eigen::MatrixXd & V,
                      Eigen::MatrixXi & F,
                      Eigen::MatrixXd & VN);

Eigen::VectorXd getGaussCurv(
                             Eigen::MatrixXd V,
                             Eigen::MatrixXi F);

double getAngle(
                Eigen::RowVector3d a,
                Eigen::RowVector3d b,
                Eigen::RowVector3d c);

Eigen::SparseMatrix<double> cotan_LPB(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F);

Eigen::MatrixXd getSpectralMeshes(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F,
		int k);

Eigen::MatrixXd explicit_LPB_smoothing(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F,
		double lambda,
		int maxIter);

Eigen::MatrixXd implicit_LPB_smoothing(
		Eigen::MatrixXd V,
		Eigen::MatrixXi F,
		double lambda,
        int maxIter);

void addGaussNoise(
		Eigen::MatrixXd & M,
		double scale);

#endif


