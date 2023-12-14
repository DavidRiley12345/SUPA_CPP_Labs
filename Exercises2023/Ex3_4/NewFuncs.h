#include <string>
#include <vector>
#include <cmath>
#include "FiniteFunctions.h"

#pragma once

class normalDist : public FiniteFunction {
    public:
        normalDist();
        normalDist(double range_min, double range_max, double sig, double mean, std::string outfile);
        ~normalDist();
        double callFunction(double x);
    private:
        double m_sigma;
        double m_mean;
        double calcNormalDist(double x);

};

class cauchyLorenz : public FiniteFunction {
    public:
        cauchyLorenz();
        cauchyLorenz(double range_min, double range_max, double gamma, double mean, std::string outfile);
        ~cauchyLorenz();
        double callFunction(double x);
    private:
        double m_gamma;
        double m_mean;
        double calcCauchyLorenz(double x);
};

class crystalBall : public FiniteFunction {
    public:
        crystalBall();
        crystalBall(double range_min, double range_max, double alpha, double n, double sigma, double mean, std::string outfile);
        ~crystalBall();
        double callFunction(double x);
    private:
        double m_alpha;
        double m_n;
        double m_sigma;
        double m_mean;
        double calcCrystalBall(double x);
};