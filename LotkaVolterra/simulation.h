#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>   //std::vector
using std::vector;

class Simulation
{
public:
    Simulation();
    void set_reprB(double);
    void set_reprR(double);
    void set_deathB(double);
    void set_deathR(double);

    void explEulerSolve();
    void implEulerSolve();

    vector<double> getB();
    vector<double> getR();
    vector<double> getTime();
private:
    //System variables
    double reprB, deathB, reprR, deathR;
    double t, timestep, tMax;
    double B0, R0;                          //This may be unimportant

    //Prey and predator
    vector<double> B;
    vector<double> R;
    vector<double> time;
};

#endif // SIMULATION_H
