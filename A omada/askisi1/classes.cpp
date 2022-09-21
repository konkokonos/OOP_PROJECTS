#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "classes.h"

using namespace std;

Up_quark::~Up_quark()                                                  //destructor gia thn up quark
{
  	cout<<"An up_quark will be destroyed "<<endl;
  	delete[] statistics;
}
void Up_quark::set_statistics(const char* sta) 
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Up_quark::Up_quark(float ele,float ma,float sp,const char* stat)       //constructor gia thn up quark
{   
	electric_charge=ele;
	mass=ma;
	spin=sp;
	statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	cout<<"An up_quark has been constructed " <<endl;                                  
}

void Up_quark::print()                                                  // print gia thn up quark
{
	cout<< "ena up_quark exei hlektriko fortio " << electric_charge << " e,maza " << mass << " MeV/c^2, idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Down_quark::~Down_quark()                                                           // destructor gia thn down quark
{
  cout<<"A Down_quark will be destroyed "<<endl;
  	
}
void Down_quark::set_statistics(const char* sta)
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Down_quark::Down_quark(float ele, float ma, float sp,const char* stat)               //condtructor gia thn down_quark
{   
    statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	electric_charge=ele;
	mass=ma;
	spin=sp;
	cout<<"A down_quark has been constructed "  <<endl;                                  
}

void Down_quark::print()                                             // print gia thn down_quark
{
	cout<< "ena down_quark exei hlektriko fortio " << electric_charge << " e,maza " << mass << " MeV/c^2, idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

Gluon::~Gluon()                // distructor gia thn gluon
{
  cout<<"A gluon will be destroyed "<<endl;
  	
}
void Gluon::set_statistics(const char* sta)
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Gluon::Gluon(float ele,float ma,float sp, const char* stat)                // constructor gia thn gluon
{   
	electric_charge=ele;
	mass=ma;
	spin=sp;
	statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	cout<<"A gluon has been constructed " <<endl;                                  
}

void Gluon::print()                                    // print gia thn gluon
{
	cout<< "ena gluon exei hlektriko fortio " << electric_charge << " e,maza " << mass << " , idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

Proton::~Proton()                                      //distractor gia thn proton
{
  cout<<"A proton will be destroyed "<<endl;
  	
}
void Proton::set_statistics(const char* sta)
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Proton::Proton(int ele,float ma,float sp,const char* stat) : uq(0.666667, 2.01, 0.5, "Fermi-Dirac"), uq2(0.666667, 2.01, 0.5, "Fermi-Dirac"), // constructor toy proton me intializer list 
dq(-0.3333333, 4.7, 0.5, "Fermi-Dirac"), g(0, 0, 1, "Bose-Einstein"), g2(0, 0, 1, "Bose-Einstein"), g3(0, 0, 1, "Bose-Einstein")
{  
    statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	electric_charge=ele;
	mass=ma;
	spin=sp;
	cout<<"A proton has been constructed " <<endl;                                  
}

void Proton::print()                // print gia to proton
{
	cout<< "ena protonio exei hlektriko fortio " << electric_charge << "e, maza " << mass << "u, idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
	cout<< "epishs exei 3 quarks (2 up kai 1 down) kai 3 gluons "<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

Neutron::Neutron(int ele,float ma,float sp,const char* stat) : dq(-0.3333333, 4.7, 0.5, "Fermi-Dirac"), dq2(-0.3333333, 4.7, 0.5, "Fermi-Dirac"), // constructor toy neutron me intializerlist
uq(0.666667, 2.01, 0.5, "Fermi-Dirac"), g(0, 0, 1, "Bose-Einstein"), g2(0, 0, 1, "Bose-Einstein"), g3(0, 0, 1, "Bose-Einstein")
{  
	electric_charge=ele;
	mass=ma;
	spin=sp;
	statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	cout<<"A neutron has been constructed " <<endl;                                  
}	

Neutron::~Neutron()              //destructor ths neutron
{
  cout<<"A neutron will be destroyed "<<endl;
  	
}
void Neutron::set_statistics(const char* sta)
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

void Neutron::print()          // print gia thn neutron
{
	cout<< "ena netronio exei hlektriko fortio " << electric_charge << "e, maza " << mass << "u, idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
	cout<< "epishs exei 3 quarks (1 up kai 2 down), kai 3 gluons "<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////

Electron::~Electron()          //destructor gia thn electron
{
  cout<<"An electron will be destroyed "<<endl;
  	
}
void Electron::set_statistics( char* sta)
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Electron::Electron(float ele, double ma, float sp, const char* stat)      //constructor gia thn electron
{  
	electric_charge=ele;
	mass=ma;
	spin=sp;
	statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);
	cout<<"An electron has been constructed "  <<endl;                                  
}
 
void Electron::print()        // print gia thn electron
{
	cout<< "ena hlektronio exei hlektriko fortio " << electric_charge << "e, maza " << mass << "u, idiostroformh " << spin << " kai ypakouei sthn statistikh " << statistics << endl;
}

//////////////////////////////////////////////////////////////////////////////////

Nucleus::Nucleus(int prot_number, int neutr_number)    // constructor gia thn necleus
{
	int i;
	p_plithos = prot_number; 
	n_plithos = neutr_number;
	
	parray = new Proton*[p_plithos];  
	for(i=0; i<p_plithos; i++)
		parray[i] = new Proton(1, 1.007, 0.5, "Fermi-Dirac");  // gemizoume ton pinaka parray me protonia
	
	narray = new Neutron*[n_plithos];
	for(i=0; i<n_plithos; i++)
		narray[i] = new Neutron(1, 1.0085, 0.5, "Fermi-Dirac");  // gemizoume ton pinaka narray me metronia
		
	cout<<"A Nucleus with "<< prot_number << " protons and " << neutr_number <<" neutrons has been constructed "  <<endl;            
}
Nucleus::~Nucleus()                                   // destructor gia thn nucleus
{
	int i;
	for(i=0; i<p_plithos; i++)
		delete parray[i];
	
	for(i=0; i<n_plithos; i++)
		delete narray[i];
		
	delete[] parray;
	delete[] narray;
	cout<<"A Nucleus with "<< p_plithos << " protons and " << n_plithos <<" neutrons has just been destroyed "  <<endl; 
}

void Nucleus::print()                  //print gia thn nucleus
{
	int i;
	cout<<"\n\nA Nucleus ("<<p_plithos << "p , " << n_plithos <<"n) printing:"<<endl;
	for(i=0; i<p_plithos; i++)
		parray[i]->print();
	for(i=0; i<n_plithos; i++)
		narray[i]->print();
}

///////////////////////////////////////////////////////////////////////////////////

Atom::~Atom()                              //destructor gia thn atom
{
	int i;
	
	cout<<"An Atom with "<< get_atom_number() << " protons, " << get_mass_number()-get_atom_number() <<" neutrons and "<< e_plithos << " electrons will be destroyed "  <<endl;
	for(i=0; i<e_plithos; i++)
	    delete earray[i];	       
	delete[] earray;
}

Atom::Atom(int prot_number ,int neutr_number, int electr_number) : n(prot_number, neutr_number)  // constructor gia thn atom 
{   int i;
    e_plithos=electr_number;
	earray=new Electron*[e_plithos];
	  for(i=0; i<e_plithos; i++)
	       earray[i]=new Electron(-1, 0.000548579909070, 0.5, "Fermi-Dirac");     // gemizoume ton pinaka earray me nea electronia
	
	mass_number=prot_number+neutr_number;
	electric_charge=electr_number;
	cout<<"An Aton has been constructed "<<endl;
}

void Atom::print()               // print ths atom
{
	int i;
	cout<<"\n\nAn Atom with "<< get_atom_number() << " protons, " << get_mass_number()-get_atom_number() <<" neutrons and "<< e_plithos << " electrons printing:"  <<endl;
	n.print();
	for(i=0; i<e_plithos; i++)
		earray[i]->print();
}

