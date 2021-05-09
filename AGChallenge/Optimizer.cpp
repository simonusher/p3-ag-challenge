#include "Optimizer.h"

#include <cfloat>
#include <iostream>
#include <windows.h>

using namespace std;

COptimizer::COptimizer(CEvaluator &cEvaluator)
	: c_evaluator(cEvaluator)
{
	vector<int> domain{ 0, 1 };
	this->pyramid = new Pyramid(domain, cEvaluator);
	d_current_best_fitness = 0;
}
COptimizer::~COptimizer() {
	delete pyramid;
}
//COptimizer::COptimizer(CEvaluator &cEvaluator)

void COptimizer::vInitialize()
{
	d_current_best_fitness = -DBL_MAX;
	v_current_best.clear();
}//void COptimizer::vInitialize()

void COptimizer::vRunIteration()
{
	this->pyramid->runSingleIteration();
	double newFitness = pyramid->getBestFitness();
	if (newFitness > d_current_best_fitness) {
		d_current_best_fitness = newFitness;
		v_current_best = pyramid->getBestSolution();
	}
	std::cout << "BEST FITNESS: " << d_current_best_fitness << std::endl;
}//void COptimizer::vRunIteration()