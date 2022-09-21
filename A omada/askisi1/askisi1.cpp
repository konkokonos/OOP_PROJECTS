#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "classes.h"

using namespace std;


int main() // main synarthsh
{
	//Proton p(1, 1.007, 0.5, "Fermi-Dirac"); p.print();
	//cout<<"\n\n---------------------------"<<endl;
	//Neutron n(0, 1.0085, 0.5, "Fermi-Dirac"); n.print();
	//cout<<"\n\n---------------------------"<<endl;
	//Electron e(-1, 0.000548579909070, 0.5, "Fermi-Dirac"); e.print();
	//cout<<"\n\n---------------------------"<<endl;
	//Nucleus nu(3,2); nu.print();
	//Atom a(3,2,4); a.print(); cout<<"To fortio tou einai: "<< a.get_electric_charge()<<endl;
	
	int i, n, sum_netroniwn, sum_protoniwn;
	int protons,neutrons,electric_charge,electrons,e_plithos;
	int get_atom_number();
	int get_mass_number();
	
	srand(time(NULL));
	Atom** atom_array;    //pinakas deiktwn se atoma
	cout<<"Doste plithos Atomwn : ";
	cin>>n;
	atom_array = new Atom*[n];
	
	for(i=0; i<n; i++)
	{
		atom_array[i] = new Atom(6, 6+rand()%3, 6);
	}
	
	sum_netroniwn = 0; sum_protoniwn = 0; electric_charge = 0;
	for(i=0; i<n; i++)
	{
		atom_array[i]->print();
		sum_netroniwn = sum_netroniwn + atom_array[i]->get_mass_number() - atom_array[i]->get_atom_number();  //ypologismos arithmoy netroniwn
		sum_protoniwn = sum_protoniwn + atom_array[i]->get_atom_number();                                     // ypologismos arithmoy protoniwn
		electric_charge = electric_charge + atom_array[i]->get_electric_charge();                             // ypologismos synolikoy fortioy
	}
	
	cout<<"Synolikos arithmos protwniwn = "<<sum_protoniwn<<endl;
	cout<<"Synolikos arithmos netroniwn = "<<sum_netroniwn<<endl;
	cout<<"To synoliko fortio einai "<< electric_charge<<endl;
    
	cout<<"\n\nEND OF MAIN\n"<<endl; 
	
	for(i=0; i<n; i++)
		delete atom_array[i];
	
	delete[] atom_array;	
}


