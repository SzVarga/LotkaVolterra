#include "include/simulation.h"

Simulation::Simulation()
{
    reprB = 2;
    reprR = 0.000002;
    deathB = 0.002;
    deathR = 0.2;
    timestep = 0.1;
    tMax = 100;

    B0 = 50000;
    R0 = 500;
}

void Simulation::set_B0(double new_B0)
{
    B0 = new_B0;
}

void Simulation::set_R0(double new_R0)
{
    R0 = new_R0;
}

void Simulation::set_reprB(double new_reprB)
{
    reprB = new_reprB;
}

void Simulation::set_reprR(double new_reprR)
{
    reprR = new_reprR;
}

void Simulation::set_deathB(double new_deathB)
{
    deathB = new_deathB;
}

void Simulation::set_deathR(double new_deathR)
{
    deathR = new_deathR;
}

void Simulation::set_timestep(double new_timestep)
{
    timestep = new_timestep;
}

void Simulation::set_tMax(double new_tMax)
{
    tMax = new_tMax;
}

void Simulation::explEulerSolve()
{   
    //clear previous calculations
    B.clear();
    R.clear();
    time.clear();
    t = 0;

    //insert initial conditions
    B.push_back(B0);
    R.push_back(R0);
    time.push_back(t);

    //calculate species while time has not been exceeded
    while (t < tMax)
    {
        //increment time by the timestep
        t += timestep;

        double b, r;
        //Calculate new B and R values
        b = B.back() + timestep * (reprB*B.back()-deathB*B.back()*R.back());
        r = R.back() + timestep * (reprR*B.back()*R.back() - deathR*R.back());

        //save new values
        B.push_back(b);
        R.push_back(r);
        time.push_back(t);
    }
}

void Simulation::implEulerSolve()
{
    //clear previous calculations
    B.clear();
    R.clear();
    time.clear();
    t = 0;

    //insert initial conditions
    B.push_back(B0);
    R.push_back(R0);
    time.push_back(t);

    //calculate species while time has not been exceeded
    while (t < tMax)
    {
        //increment time by the timestep
        t += timestep;

        double b, r;
        //Calculate and save new B values
        b = B.back() + timestep * (reprB*B.back()-deathB*B.back()*R.back());
        B.push_back(b);

        //Calculate and save new R values
        r = R.back() + timestep * (reprR*B.back()*R.back() - deathR*R.back());
        R.push_back(r);

        //save new time value
        time.push_back(t);
    }
}

vector<double> Simulation::getB()
{
    return B;
}

vector<double> Simulation::getR()
{
    return R;
}

vector<double> Simulation::getTime()
{
    return time;
}
