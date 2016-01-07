#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  double p[2], q[2], pnew[2], qnew[2]; 
  double e = 0.6;
  
  double dt = 0.05;
  double tstart = 0.0;
  double tend = 20.0*3.1415;
  int N = int((tstart-tend)/dt + 0.5);
  double H;
  
  ofstream out;
  out.open("kepler.dat");
  
  p[0] = 0.0;
  p[1] = sqrt((1+e)/(1-e));
  q[0] = 1.0 - e;
  q[1] = 0.0;
 
  for(double t = tstart; t < tend; t+= dt){
    pnew[0] = p[0] - dt*q[0]/pow((q[0]*q[0]+q[1]*q[1]),1.5);
    pnew[1] = p[1] - dt*q[1]/pow((q[0]*q[0]+q[1]*q[1]),1.5);
    qnew[0] = q[0] + dt*p[0];
    qnew[1] = q[1] + dt*p[1];
    
    p[0] = pnew[0];
    p[1] = pnew[1];
    q[0] = qnew[0];
    q[1] = qnew[1];
    
    H = 0.5*(p[0]*p[0] + p[1]*p[1]) - 1.0/sqrt(q[0]*q[0] + p[0]*p[0]);
    
    out << t << "\t" << p[0] << "\t" << p[1] << "\t" << q[0] << "\t" << q[1] << "\t" << H << endl;
  }
  
  out.close();
  
  return 0;
}