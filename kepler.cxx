#include <fstream>
#include <cmath>


using namespace std;


void step(double* q, double dt, int dim){
	double temp[4];
	for(int i=0;i<dim;i++)
		temp[i]=q[i];

	double Abstand3 = pow(sqrt(pow(temp[0],2)+pow(temp[1],2)),3);
	q[2]=temp[2]-dt*temp[0]/Abstand3;
	q[3]=temp[3]-dt*temp[1]/Abstand3;
	q[0]=temp[0]+dt*q[2];
	q[1]=temp[1]+dt*q[3];
}

int main(){
	double e=0.2;			// 0 ist Kreis, 1 ist Parabell
	const int dim = 4;
	double tEnd = 20*3.1415;
	double dt = 0.05;
	double q[dim];
	double H;
	double t=0;
	q[0]=1-e;				//q1
	q[1]=0;					//q2
	q[2]=0;					//p1	
	q[3]=sqrt((1+e)/(1-e));	//p2
	
	ofstream out("Daten");
	out <<"#Zeit" << "\t" << "q1" << "\t" << "q2" << "\t" << "p1" << "\t" << "p2" << "\t" << "H" << endl;
	for(double t=0;t<tEnd;t=t+dt){
		step(q,dt,dim);
		H=0.5*(pow(q[0],2)+pow(q[1],2))-1/sqrt(pow(q[2],2)+pow(q[3],2));
		out << t  << "\t";
		for(int i=0; i<dim; i++)
			out << q[i] << "\t";
		out << H << endl;
	}
	out.close();
	return 0;
}

