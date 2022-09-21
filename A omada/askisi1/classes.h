class Up_quark                                                        //klash up quark
{
	private:
		float electric_charge, mass, spin;
		char* statistics;

	public:
		~Up_quark();
		Up_quark(float,float,float, const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}		
};

class Down_quark                                                       //klash down quark
{
	private:
		float electric_charge, mass, spin;
		char* statistics;

	public:
		~Down_quark();
		Down_quark(float,float,float,const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}
};

class Gluon // klash gluon
{
	private:
		float electric_charge, mass, spin;
		char* statistics;

	public:
		~Gluon();
		Gluon(float,float,float, const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}
};

class Proton // klash proton
{
	private:
		int electric_charge;
		float mass, spin;
		char* statistics;
		Up_quark uq, uq2;
        Down_quark dq;
        Gluon g, g2, g3;
	public:
		~Proton();
		Proton(int,float,float,const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}	
};	

class Neutron // klash neutron
{
	private:
		int electric_charge;
		float mass, spin;
		char* statistics;
		Down_quark dq, dq2;
        Up_quark uq;
        Gluon g, g2, g3;
	public:
		~Neutron();
		Neutron(int, float, float,const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics(const char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}	
};	

class Electron // klash electron
{
	private:
		float electric_charge;
		double mass;
		float spin;
		char* statistics;

	public:
		~Electron();
		Electron(float,double,float,const char*);
		void set_electric_charge(float ec) { electric_charge=ec;}
		void set_mass(float m) {mass=m;}
		void set_spin(float s) {spin=s;}
		void set_statistics( char*);
		void print();
		float get_electric_charge() {return electric_charge;}
		float get_mass() {return mass;}
		float get_spin() {return spin;}
		char* get_statistics() {return statistics;}
};

class Nucleus // klash nucleus
{
	private:
		Proton** parray; //pinakas deiktwn se protonia (afou den gnorizw eksarxis to plithos tous (kai to protonio den exei default constructor))
		Neutron** narray; // omoiws gia ta netronia
		int p_plithos;
		int n_plithos;
	public:
		Nucleus(int prot_number, int neutr_number);
		~Nucleus();
		int get_atom_number() {return p_plithos;}	
		int get_mass_number() {return p_plithos+n_plithos;}	
		void print();
};

class Atom // klash atom
{
	private:
		int mass_number;
		float electric_charge;
		Nucleus n;
		Electron** earray; //pinakas deiktwn se electrons (afou den gnorizw eksarxis to plithos tous (kai to electron den exei default constructor))
		int e_plithos; // kai to plithos tous (mikos tou pinaka)
	public:
		~Atom();
		Atom(int, int, int);
		int get_atom_number() {n.get_atom_number();}
		int get_mass_number() {n.get_mass_number();}
		int get_electric_charge() {return n.get_atom_number()-e_plithos;} 
		void print();
};

