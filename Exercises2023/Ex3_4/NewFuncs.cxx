#include "FiniteFunctions.h"
#include "NewFuncs.h"
#include <string>
#include <cmath>

normalDist::normalDist(){
        m_RMin = -5.0;  
        m_RMax = 5.0;
        m_sigma = 1.0;
        m_mean = 0.0;
        this->checkPath("DefaultFunction");
        m_FunctionName = "Normal Distribution";
        m_Integral = NULL;
}

normalDist::normalDist(double range_min, double range_max, double sig, double mean, std::string outfile){
        m_RMin = range_min;
        m_RMax = range_max;
        this->checkPath(outfile);
        m_sigma = sig;
        m_mean = mean;
        m_FunctionName = "Normal Distribution";
        m_Integral = NULL;
}

normalDist::~normalDist(){
  Gnuplot gp; //Set up gnuplot object
  this->generatePlot(gp); //Generate the plot and save it to a png using "outfile" for naming 
}

double normalDist::calcNormalDist(double x){
        double result;
        result = (1/(m_sigma * sqrt(2*3.14)))*exp(-0.5*pow((x-m_mean)/m_sigma,2));
        //result = exp(x*x-m_mean);
        //result = pow(x,2);
        return result;
}

double normalDist::callFunction(double x) {return this->calcNormalDist(x);}; 


//---------------------------------------------------------------------------------------------
// cauchy lorenz definition
// empty constructor
cauchyLorenz::cauchyLorenz(){
        m_RMin = -5.0;  
        m_RMax = 5.0;
        m_gamma = 1.0;
        m_mean = 0.0;
        this->checkPath("DefaultFunction");
        m_Integral = NULL;
}

// constructor
cauchyLorenz::cauchyLorenz(double range_min, double range_max, double gamma, double mean, std::string outfile){
        m_RMin = range_min;
        m_RMax = range_max;
        this->checkPath(outfile);
        m_gamma = gamma;
        m_mean = mean;
        m_FunctionName = "Cauchy Lorenz Distribution";
        m_Integral = NULL;
}
// destructor
cauchyLorenz::~cauchyLorenz(){
  Gnuplot gp; //Set up gnuplot object
  this->generatePlot(gp); //Generate the plot and save it to a png using "outfile" for naming 
}
double cauchyLorenz::calcCauchyLorenz(double x){
        double result;
        result = 1.0 / (3.14 * m_gamma * (1.0 + pow((x-m_mean)/m_gamma,2)));
        return result;
}

double cauchyLorenz::callFunction(double x) {return this->calcCauchyLorenz(x);};

//---------------------------------------------------------------------------------------------
// crystal ball definition
// empty constructor
crystalBall::crystalBall(){
        m_RMin = -5.0;  
        m_RMax = 5.0;
        m_mean = 0.0;
        m_sigma = 1.0;
        m_alpha = 1.0;
        m_n = 1.0;
        this->checkPath("DefaultFunction");
        m_Integral = NULL;
}

// constructor
crystalBall::crystalBall(double range_min, double range_max, double alpha, double n, double mean, double sigma, std::string outfile){
        m_RMin = range_min;
        m_RMax = range_max;
        this->checkPath(outfile);
        m_mean = mean;
        m_sigma = sigma;
        m_alpha = alpha;
        m_n = n;
        m_FunctionName = "Crystal Ball Distribution";
        m_Integral = NULL;
}
// destructor
crystalBall::~crystalBall(){
  Gnuplot gp; //Set up gnuplot object
  this->generatePlot(gp); //Generate the plot and save it to a png using "outfile" for naming 
}

double crystalBall::calcCrystalBall(double x){
        double result;
        double A = pow(m_n/fabs(m_alpha),m_n)*exp(-0.5*pow(fabs(m_alpha),2));
        double B = m_n/fabs(m_alpha) - fabs(m_alpha);
        double C = m_n/fabs(m_alpha) * 1.0/(m_n-1.0) * exp(-0.5*pow(fabs(m_alpha),2));
        double D = sqrt(3.14/2.0)*(1.0+erf(fabs(m_alpha)/sqrt(2.0)));
        double N = 1.0/(m_sigma*(C+D));
        if((x-m_mean)/m_sigma > -m_alpha){
                result = N*exp(-0.5*pow((x-m_mean)/m_sigma,2));
        }
        else{
                result = N*A*pow(B-(x-m_mean)/m_sigma,-m_n);
        }
        return result;
}

double crystalBall::callFunction(double x) {return this->calcCrystalBall(x);};