#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

class Particle // abstract, afou exei pure virtual tin get_type
{   
	
	private:
		float electric_charge, mass, spin;
		char* statistics;
		
	public:
		virtual ~Particle() {delete[] statistics;}
		Particle(float,float,float, const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}	
		virtual int get_type() = 0;
		virtual int isFermion() = 0;
};

////////////////////////////////////////////////////////////////////////////

class Fermion : public Particle   // abstract, afou klironomei (kai den epanaorizei) tin get_type tis Particle                                  
{
	public:
		virtual ~Fermion() { }
		int isFermion() {return 1;}
		Fermion(float,float,float, const char*);
		void set_electric_charge(float ec) { Particle::set_electric_charge(ec); }
		void set_mass(float m) {Particle::set_mass(m); }
		void set_spin(float s) {Particle::set_spin(s);}
		void set_statistics(const char* s) { Particle::set_statistics(s); };
		float get_electric_charge() {return Particle::get_electric_charge();}
		float get_mass() {return Particle::get_mass();}
		float get_spin() {return Particle::get_spin();}
		char* get_statistics() {return Particle::get_statistics();}		
};

//////////////////////////////////////////////////////////////////////////

class Boson : public Particle  // abstract, afou klironomei (kai den epanaorizei) tin get_type tis Particle                                                        
{
	public:
		virtual ~Boson() { } 
		int isFermion() {return 0;}
		Boson(float,float,float, const char*);
		void set_electric_charge(float ec) { Particle::set_electric_charge(ec); }
		void set_mass(float m) {Particle::set_mass(m); }
		void set_spin(float s) {Particle::set_spin(s);}
		void set_statistics(const char* s) { Particle::set_statistics(s); };
		float get_electric_charge() {return Particle::get_electric_charge();}
		float get_mass() {return Particle::get_mass();}
		float get_spin() {return Particle::get_spin();}
		char* get_statistics() {return Particle::get_statistics();}		
};

///////////////////////////////////////////////////////////////////////////

class Electron : public Fermion
{
	public:
		~Electron();
		Electron();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}
		int get_type() {return 0;}	
};

///////////////////////////////////////////////////////////////////////////

class Proton : public Fermion
{
	public:
		~Proton();
		Proton();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}	
		int get_type() {return 1;}	
};

////////////////////////////////////////////////////////////////////////////

class Neutron : public Fermion
{
	public:
		~Neutron();
		Neutron();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}	
		int get_type() {return 2;}	
		
};

//////////////////////////////////////////////////////////////////////////////////
class Positron : public Fermion
{
	public:
		~Positron();
		Positron();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}	
		int get_type() {return 3;}	
};

////////////////////////////////////////////////////////////////////////////////////

class Neutrino : public Fermion
{
	public:
		~Neutrino();
		Neutrino();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}	
		int get_type() {return 4;}	
};

///////////////////////////////////////////////////////////////////////////////////////////

class Antineutrino : public Fermion
{
	public:
		~Antineutrino();
		Antineutrino();
		void set_electric_charge(float ec) { Fermion::set_electric_charge(ec); }
		void set_mass(float m) {Fermion::set_mass(m); }
		void set_spin(float s) {Fermion::set_spin(s);}
		void set_statistics(const char* s) { Fermion::set_statistics(s); };
		float get_electric_charge() {return Fermion::get_electric_charge();}
		float get_mass() {return Fermion::get_mass();}
		float get_spin() {return Fermion::get_spin();}
		char* get_statistics() {return Fermion::get_statistics();}	
		int get_type() {return 5;}	
};

/////////////////////////////////////////////////////////////////////////////////////////

class Photon : public Boson
{
	public:
		~Photon();
		Photon();
		void set_electric_charge(float ec) { Boson::set_electric_charge(ec); }
		void set_mass(float m) {Boson::set_mass(m); }
		void set_spin(float s) {Boson::set_spin(s);}
		void set_statistics(const char* s) { Boson::set_statistics(s); };
		float get_electric_charge() {return Boson::get_electric_charge();}
		float get_mass() {return Boson::get_mass();}
		float get_spin() {return Boson::get_spin();}
		char* get_statistics() {return Boson::get_statistics();}	
		int get_type() {return 6;}		
};

int allilepidrasi(Particle* array[], int tyx);
int diaspasi(Particle* array[], int tyx, int M);

int main (int argc, char** argv)
{
	int M, arxiko_M, N, i, tyx, type1, type2, egine_allil, egine_diasp, plithos_f, plithos_b;
	int aplithos_ele, aplithos_prot, aplithos_neutro, aplithos_posi, aplithos_neutri, aplithos_anti, aplithos_ph;
	int tplithos_ele, tplithos_prot, tplithos_neutro, tplithos_posi, tplithos_neutri, tplithos_anti, tplithos_ph;
	float sinoliko_fortio_arx, sinoliko_fortio_tel, diafora_mazas, sinolikh_maza_arx, sinolikh_maza_tel, diafora_fortiou, spin_arx, spin_tel, diafora_spin;
	
	if(argc<3)
	{
		cout<<"Parakalw dwste ta M kai N tin epomeni fora"<<endl;
		return 0;
	}
	
	M = atoi(argv[1]); 
	arxiko_M = M;
	if(M==0) // elegxos plithous swmatidiwn > 0
	{
		cout<<"Plithos Swmatidiwn 0"<<endl;
		return 0;
	}
	
	N = atoi(argv[2]); 

	srand(time(NULL));
	
	Particle* array[M+2*N]; // arxika exw M swmatidia, to poly na prostethoun 2N, afou kathe diaspasi afairei 1 kai vazei 3 (ara +2)
	
	for(i=0; i<M+2*N; i++)
		array[i] = NULL;
	
	for(i=0; i<M; i++) // tyxaia dimiourgia swmatidiwn
	{
		tyx = rand()%7;                         //to tyx borei na parei times apo 0 eos kai 6
		if(tyx==0) array[i] = new Electron();
		if(tyx==1) array[i] = new Proton();
		if(tyx==2) array[i] = new Neutron();
		if(tyx==3) array[i] = new Positron();
		if(tyx==4) array[i] = new Neutrino();
		if(tyx==5) array[i] = new Antineutrino();
		if(tyx==6) array[i] = new Photon();
	}
	
	// ypologismos arxikwn swmatidiwn
	aplithos_ele=0; aplithos_prot=0; aplithos_neutro=0; aplithos_posi=0; aplithos_neutri=0; aplithos_anti=0; aplithos_ph=0;
    for(i=0; i<arxiko_M; i++)
	{
		if(array[i]->get_type() == 0) aplithos_ele++;
		else if(array[i]->get_type() == 1) aplithos_prot++;
		else if(array[i]->get_type() == 2) aplithos_neutro++;
		else if(array[i]->get_type() == 3) aplithos_posi++;
		else if(array[i]->get_type() == 4) aplithos_neutri++;
		else if(array[i]->get_type() == 5) aplithos_anti++;
		else aplithos_ph++;
	}
	 
	// ypologizw arxiko fortio, maza kai spin
	sinoliko_fortio_arx= aplithos_ele*(-1) + aplithos_prot*1 + aplithos_neutro*0 + aplithos_posi*1 + aplithos_neutri*0 + aplithos_anti*0 + aplithos_ph*0;
	sinolikh_maza_arx=aplithos_ele*0.510998946 + aplithos_prot*938.27208 + aplithos_neutro*939.56541 + aplithos_posi*0.510998946 + aplithos_neutri*0.320 + aplithos_anti*0.320 + aplithos_ph*0;
	spin_arx=aplithos_ele*0.5 + aplithos_prot*0.5 + aplithos_neutro*0.5 + aplithos_posi*0.5 + aplithos_neutri*0.5 + aplithos_anti*0.5 + aplithos_ph*0.5;
	
	for(i=0; i<N; i++) //gia kathe loop
	{
		cout<<" \nEpanalipsi: "<< i <<endl;
		tyx = rand()%M; cout<<" \nTrying: "<< tyx <<endl;
		if(tyx==M-1) // einai to teleutaio, ara paei me to proigoumeno tou
		{
			egine_allil = allilepidrasi(array, tyx); // dokimazei allilepidrasi me to proigoumeno
			if(egine_allil == 0) // diaspasi
		  	{
				egine_diasp = diaspasi(array, tyx, M); // dokimazei diaspasi
				if(egine_diasp == 1) // an egine
					M = M+2;	// + 2 swmatidia (-1 + 3)
			}
		}
		else if(tyx==0) // to 1o paei anagkastika me to epomeno
		{
			tyx = 1;	// giati stin allilepidrasi, i synartisi to tsekarei me vasi to proigoumeno tou
			egine_allil = allilepidrasi(array, tyx);
			if(egine_allil == 0) // diaspasi
			{
				egine_diasp = diaspasi(array, tyx, M);
					if(egine_diasp == 1) // an egine
						M = M+2;	// + 2 swmatidia (-1 + 3)
			}
		}
		else // endiamesi thesi pinaka
		{
			egine_allil = allilepidrasi(array, tyx); // dokimazw me to amesws proigoumeno
			if(egine_allil == 0)
			{
				egine_allil = allilepidrasi(array, tyx+1); // an den egine, dokimazw me to amesws epomeno
				if(egine_allil == 0)
				{
					egine_diasp = diaspasi(array, tyx, M); // an den katafera allilepidrasi, koitazw gia diaspasi
					if(egine_diasp == 1) // an egine
						M = M+2;	// + 2 swmatidia (-1 + 3)
				}	
			}
		}
		
	} //for(i=0; i<N; i++)
	
	// ypologizw fermionia kai bozonia gia na dw an exw material world
	plithos_f = 0; plithos_b = 0;
	for(i=0; i<M; i++)
	{
		if(array[i]->isFermion() == 1) 
			plithos_f++;
		else
			plithos_b++;
	}

	// ypologismos telikwn swmatidiwn
    tplithos_ele=0; tplithos_prot=0; tplithos_neutro=0; tplithos_posi=0; tplithos_neutri=0; tplithos_anti=0; tplithos_ph=0;
    for(i=0; i<M; i++)
	{
		if(array[i]->get_type() == 0) tplithos_ele++;
		else if(array[i]->get_type() == 1) tplithos_prot++;
		else if(array[i]->get_type() == 2) tplithos_neutro++;
		else if(array[i]->get_type() == 3) tplithos_posi++;
		else if(array[i]->get_type() == 4) tplithos_neutri++;
		else if(array[i]->get_type() == 5) tplithos_anti++;
		else tplithos_ph++;
	}	
    
    // ypologizw teliko fortio, maza kai spin
    sinoliko_fortio_tel= tplithos_ele*(-1) + tplithos_prot*1 + tplithos_neutro*0 + tplithos_posi*1 + tplithos_neutri*0 + tplithos_anti*0 + tplithos_ph*0;
    sinolikh_maza_tel=tplithos_ele*0.510998946 + tplithos_prot*938.27208 + tplithos_neutro*939.56541 + tplithos_posi*0.510998946 + tplithos_neutri*0.320 + tplithos_anti*0.320 + tplithos_ph*0;
    spin_tel=tplithos_ele*0.5 + tplithos_prot*0.5 + tplithos_neutro*0.5 + tplithos_posi*0.5 + tplithos_neutri*0.5 + tplithos_anti*0.5 + tplithos_ph*0.5;
    
    // ypologismoi diaforwn
	diafora_mazas=sinolikh_maza_tel - sinolikh_maza_arx;
	diafora_fortiou=sinoliko_fortio_tel - sinoliko_fortio_arx;
	diafora_spin=spin_tel - spin_arx;
    
	cout<<"\n\n\n "<<endl;
	for(i=0; i<M; i++)
		delete array[i];
		
	cout<<"\n\n - - - - - ARXIKI KATASTASI - - - - - " << endl;	
	cout<<"\nO synolikos arithmos twn swmatidiwn  einai " << arxiko_M << endl;	
	
	cout<<"\nO synolikos arithmos twn ilektroniwn einai " <<aplithos_ele << endl;
	cout<<"O synolikos arithmos twn protoniwn einai " <<aplithos_prot << endl;
	cout<<"O synolikos arithmos twn netroniwn einai " <<aplithos_neutro << endl;
	cout<<"O synolikos arithmos twn positroniwn einai " <<aplithos_posi << endl;
	cout<<"O synolikos arithmos twn netrinwn einai " <<aplithos_neutri << endl;
	cout<<"O synolikos arithmos twn antinetrinwn einai " <<aplithos_anti << endl;
	cout<<"O synolikos arithmos twn fotoniwn einai " <<aplithos_ph << endl;
	
///////////////////////////////////////////////////////////////////////////////////////////////	

	cout<<"\n\n - - - - - TELIKI KATASTASI - - - - - " << endl;
	cout<<"\nO synolikos arithmos twn swmatidiwn telika einai " << M << endl;
		
	cout<<"\nO synolikos arithmos twn ilektroniwn telika einai " <<tplithos_ele << endl;
	cout<<"O synolikos arithmos twn protoniwn telika einai " <<tplithos_prot << endl;
	cout<<"O synolikos arithmos twn netroniwn telika einai " <<tplithos_neutro << endl;
	cout<<"O synolikos arithmos twn positroniwn telika einai " <<tplithos_posi << endl;
	cout<<"O synolikos arithmos twn netrinwn telika einai " <<tplithos_neutri << endl;
	cout<<"O synolikos arithmos twn antinetrinwn telika einai " <<tplithos_anti << endl;
	cout<<"O synolikos arithmos twn fotoniwn telika einai " <<tplithos_ph << endl;
	
//////////////////////////////////////////////////////////////////////////////////////////////

	cout<<"\n\n - - - - - METAVOLES - - - - - " << endl;
	cout<<"\nAfksisi plithismu twn swmatidiwn kata " << 100.0*(M-arxiko_M)/arxiko_M << " % " <<endl;
	
	if(aplithos_ele>0) cout<<"\nAfksisi plithismu twn ilektroniwn kata " << 100.0*(tplithos_ele-aplithos_ele)/aplithos_ele << " % " <<endl;
	if(aplithos_prot>0) cout<<"Afksisi plithismu twn protoniwn kata " << 100.0*(tplithos_prot-aplithos_prot)/aplithos_prot << " % " <<endl;
	if(aplithos_neutro>0) cout<<"Afksisi plithismu twn netroniwn kata " << 100.0*(tplithos_neutro-aplithos_neutro)/aplithos_neutro << " % " <<endl;
	if(aplithos_posi>0) cout<<"Afksisi plithismu twn positroniwn kata " << 100.0*(tplithos_posi-aplithos_posi)/aplithos_posi << " % " <<endl;
	if(aplithos_neutri>0) cout<<"Afksisi plithismu twn netrinwn kata " << 100.0*(tplithos_neutri-aplithos_neutri)/aplithos_neutri << " % " <<endl;
	if(aplithos_anti>0) cout<<"Afksisi plithismu twn antinetrinwn kata " << 100.0*(tplithos_anti-aplithos_anti)/aplithos_anti<< " % " <<endl;
	if(aplithos_ph>0) cout<<"Afksisi plithismu twn fotoniwn kata " << 100.0*(tplithos_ph-aplithos_ph)/aplithos_ph<< " % " <<endl;
	
	cout<<"\n\n - - - - -SYMPERASMATA - - - - - \n" << endl; 
	if(plithos_f > plithos_b)
		cout<<"Living in a material world!" <<endl;
	else if(plithos_f < plithos_b)
		cout<<"Radiation prevails!" <<endl;
	else
		cout<<"Equilibrium!" <<endl;
		
	if (sinoliko_fortio_arx == sinoliko_fortio_tel)
	cout<<"Conservation verified (arxiko fortio: " <<sinoliko_fortio_arx<<", teliko fortio: "<< sinoliko_fortio_tel << ")!"<<endl;
	
	cout<<"Diafora mazas: "<< diafora_mazas <<" (arxiki maza: " <<sinolikh_maza_arx<<", teliki maza: "<< sinolikh_maza_tel << ")!"<<endl;
	cout<<"Diafora spin: "<< diafora_spin <<" (arxiko spin: " << spin_arx <<", teliko spin: "<< spin_tel << ")!"<<endl;
	if(diafora_mazas !=0 || diafora_spin!=0)
		cout<<"How it comes! "<<endl;
	
	return 0;
}

int diaspasi(Particle* array[], int tyx, int M) // dokimazei ti thesi tyx me tin proigoumeni gia allilepidrasi
{
	int type1, i;
	
	type1 = array[tyx]->get_type(); 
	cout<<"Trying for diaspasi: " << tyx <<endl;
	if(type1 == 2	|| type1 == 1)
	{
		for(i=M-1; i>tyx; i--) // olisthisi 2 theseis pros ta deksia
			array[i+2] = array[i];

		if(type1 == 2) //Neutron
		{
			cout<<"Egine diaspasi Neutron"<<endl;
			delete array[tyx];
			array[tyx] = new Proton();
			array[tyx+1] = new Electron();
			array[tyx+2] = new Antineutrino();
		}
		else //Proton
		{
			cout<<"Egine diaspasi Proton"<<endl;
			delete array[tyx];
			array[tyx] = new Neutron();
			array[tyx+1] = new Positron();
			array[tyx+2] = new Neutrino();
		}
		
		return 1;
	}

	return 0;
}


int allilepidrasi(Particle* array[], int tyx) // dokimazei ti thesi tyx me tin proigoumeni gia allilepidrasi
{
	int type1, type2;
	
	type1 = array[tyx-1]->get_type(); type2 = array[tyx]->get_type();
	cout<<"Trying: " << tyx-1 << " with "<< tyx <<endl;

	if((type1 == 2 && type2 == 4) || (type1 == 4 && type2 == 2)) // netronio kai netrino
	{
		delete array[tyx-1]; delete array[tyx];
		array[tyx-1] = new Proton(); array[tyx] = new Electron();
		return 1;
	}
	
	if((type1 == 1 && type2 == 5) || (type1 == 5 && type2 == 1)) // prwtonio kai antinetrino
	{
		delete array[tyx-1]; delete array[tyx];
		array[tyx-1] = new Neutron(); array[tyx] = new Positron();
		return 1;
	}
	
	if((type1 == 1 && type2 == 0) || (type1 == 0 && type2 == 1)) // prwtonio kai ilektronio
	{
		delete array[tyx-1]; delete array[tyx];
		array[tyx-1] = new Neutron(); array[tyx] = new Neutrino();
		return 1;
	}
	
	if((type1 == 0 && type2 == 3) || (type1 == 3 && type2 == 0)) // ilektronio kai pozitronio
	{
		delete array[tyx-1]; delete array[tyx];
		array[tyx-1] = new Photon(); array[tyx] = new Photon();
		return 1;
	}
	
	if(type1 == 6 && type2 == 6) // photonio kai photonio
	{
		delete array[tyx-1]; delete array[tyx];
		array[tyx-1] = new Electron(); array[tyx] = new Positron();
		return 1;
	}
	else
		return 0;
}



///////////////////////// PARTICLE ///////////////////////////

void Particle::set_statistics(const char* sta) 
{
	statistics = new char[strlen(sta)+1]; 
	strcpy(statistics,sta);
} 

Particle::Particle(float ele,float ma,float sp,const char* stat)
{   
	electric_charge=ele;
	mass=ma;
	spin=sp;
	statistics = new char[strlen(stat)+1]; 
	strcpy(statistics,stat);                              
}

/////////////////////////// Fermion ///////////////////////////

Fermion::Fermion(float ele,float ma,float sp,const char* stat)  : Particle(ele, ma, sp, stat)
{   
	                            
}

///////////////////////////// Boson ///////////////////////////////

Boson::Boson(float ele,float ma,float sp,const char* stat) : Particle(ele, ma, sp, stat)
{   
	                             
}

////////////////////////// Electron /////////////////////////////

Electron::~Electron()       
{
  cout<<"An electron will be destroyed"<<endl;
}


Electron::Electron() : Fermion(-1,0.510998946,0.5,"Fermi-Dirac")  
{  
	cout<<"An electron has been constructed"  <<endl;                                  
}
 
///////////////////////////// Proton /////////////////////////////

Proton::~Proton()       
{
  cout<<"A proton will be destroyed"<<endl;
  	
}

Proton::Proton() : Fermion(+1,938.27208,0.5,"Fermi-Dirac")  
{  
	cout<<"A proton has been constructed"<<endl;                                  
}
 
////////////////////////// Neutron /////////////////////////


Neutron::~Neutron()       
{
  cout<<"A neutron will be destroyed"<<endl;
  	
}

Neutron::Neutron() : Fermion(0, 939.56541, 0.5, "Fermi-Dirac")  
{  
	cout<<"A neutron has been constructed "  <<endl;                                  
}

//////////////////////////// Positron /////////////////////////

Positron::~Positron()       
{
  cout<<"A positron will be destroyed "<<endl;
  	
}

Positron::Positron() : Fermion(+1, 0.510998946, 0.5, "Fermi-Dirac")  
{  
	cout<<"A positron has been constructed "  <<endl;                                  
}

////////////////////////// Neutrino ///////////////////////////

Neutrino::~Neutrino()       
{
  cout<<"A neutrino will be destroyed "<<endl;
  	
}

Neutrino::Neutrino() : Fermion(0, 0.320, 0.5, "Fermi-Dirac")  
{  
	cout<<"A neutrino has been constructed "  <<endl;                                  
}
 
///////////////////////////// Antineutrino //////////////////////////////

Antineutrino::~Antineutrino()       
{
  cout<<"A antineutrino will be destroyed "<<endl;
  	
}

Antineutrino::Antineutrino() : Fermion(0, 0.320, 0.5, "Fermi-Dirac")  
{   
	cout<<"A antineutrino has been constructed "  <<endl;                                  
}
 
////////////////////////// Photon //////////////////////////////////

Photon::~Photon()       
{ 
  cout<<"A photon will be destroyed "<<endl;
  	
}

Photon::Photon() : Boson(0, 0, 1, "Bose-Einstein")  
{  

	cout<<"A photon has been constructed "  <<endl;                                  
}

