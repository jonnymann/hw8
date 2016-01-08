#include <fstream>
#include <cmath>


using namespace std;

void writeToFile(const double* const u);

void step(double* q, dt){
	double q



}

int main(){
	double e=0.2 // 0 ist Kreis, 1 ist Parabell
	const int dim =4;
	double tEnd = 20*3.1415;
	double dt = 0.01;
	double q[4];
	double t=0;
	q[0]=1-e;		//q1
	q[1]=0;			//q2
	q[2]=0;			//p1	
	q[3]=sqrt((1+e)/(1-e));	//p2
	
	ofstream out("Daten");
	
	for(double t=0;t<tEnd;t=t+dt){
		step(q);

		writeToFile(q);
	}
	out.close();
	return 0;
}

void writeToFile(const double* const u)
{
   
   for(int i=0; i<4; i++){
     double x = i * dx;
     out << x << "\t" << u[i] << endl;
   }
   
}
