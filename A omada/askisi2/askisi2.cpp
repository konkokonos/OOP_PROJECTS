#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Atomo
{
	char type; //'c' or 'h'
	int no;
	Atomo* deiktes[4];
	int desmoi_idi; //posous desmous exei idi (gia na simplirothoun H sto telos)
 
public:
	Atomo(int t, int n);
	~Atomo() { cout<<"\nDestroying Atom "; print(); }
	void delete_all_H();
	void print() { cout<<type<<no; }
	char get_type() {return type;}
	int get_no() {return no;}
	int get_desmoi_idi() { return desmoi_idi; }
	void set_desmos(int thesi, Atomo* pou) { deiktes[thesi] = pou; desmoi_idi++;}
	Atomo* get_desmos(int thesi) {return deiktes[thesi];}
};

void print_compositions(Atomo** pinakas, int N);

int main(int argc, char** argv) // main synarthsh
{
	int n, i, r1, r2, id, j, perisevoun_current, perisevoun_next, tyxaia_enosi, max_enosi, enosi_me_epomeno;
	Atomo** atom_array;
	Atomo* trexon_H;
	
	srand(time(NULL));
	
	if(argc<2) //prepei na parei to ektelesimo kai to plithos C pros kataskevi
	{
		cout<<"Den eisagate plithos atomwn C pros kataskevi"<<endl;
		return 0;
	}
	
	n = atoi(argv[1]);
	
	if(n<1)
	{
		
		cout<<"Den dosate thetiko plithos atomwn C pros kataskevi"<<endl;
		return 0;
	}
	
	cout<<"Epileksate plithos Atomwn : "<<n<<endl;
	
	// desmevei pinaka deiktwn se Atoma gia tous C
	atom_array = new Atomo*[n];
	
	//kataskevazei tous n C
	for(i=0; i<n; i++)
		atom_array[i] = new Atomo('c', i);

	
	// mpainoun oi tyxaies enwseis metaksy twn atomwn tou anthraka
	for(i=0; i<n-1; i++)
	{
		perisevoun_current = 4 - atom_array[i]->get_desmoi_idi(); // posouss eleftherouss desmous exei o current
		perisevoun_next = 4- atom_array[i+1]->get_desmoi_idi(); // posous eleftherouss desmous exei o next tou
	
		if(perisevoun_current < perisevoun_next) // vriskw to min tous (anw orio desmwn pou mporoun na exoun)
			max_enosi = perisevoun_current;
		else
			max_enosi = perisevoun_next;
		
		if(max_enosi>0)			// an mporei na ginei desmos, vriskw me rand to eidos tis
			tyxaia_enosi = rand()%(1+max_enosi);
		else
			tyxaia_enosi = 0; 
			
		if(tyxaia_enosi == 4) // gia na min epitrepsw 4plo desmo (mono alkania, alkenia, alkinia)
			tyxaia_enosi = 3;
	
			
		
		for(j=0; j<tyxaia_enosi; j++) // kanw desmo i me i+1 kai i+1 me i (na ton vlepoun kai oi 2)
		{
			atom_array[i]->set_desmos(atom_array[i]->get_desmoi_idi(), atom_array[i+1]);
			atom_array[i+1]->set_desmos(atom_array[i+1]->get_desmoi_idi(), atom_array[i]);
		}	
	}
	
	// sto telos osoi desmoi perissevoun apo olous tous C, na ginoun me H
	id = 0;
	for(i=0; i<n; i++) // gia kathe C
	{
		for(j=atom_array[i]->get_desmoi_idi(); j<4; j++) // gia osous desmous tou perissevoun
		{
			trexon_H = new Atomo ('h', id); //dimiourgw H
			id++;
			atom_array[i]->set_desmos(atom_array[i]->get_desmoi_idi(),trexon_H); // kai tous enwnw
			trexon_H->set_desmos(0, atom_array[i]); // kai ton H me ton C
		}	
	}
	
	print_compositions(atom_array, n); // ektypwsi twn enwsewn
    
	cout<<"\n\nEND OF MAIN\n"<<endl; 
	
	// se prwti fasi delete ola ta H
	for(i=0; i<n; i++) 
		atom_array[i]->delete_all_H();
	
	// kai meta delete ola ta C
	for(i=0; i<n; i++)
		delete atom_array[i];
	
	// kai telos o pinakas
	delete[] atom_array;	
	
}

void print_compositions(Atomo** pinakas, int N)
{
	int i, j, enosi_me_epomeno;
	 
	/*
	for(i=0; i<N; i++)
	{
		cout<<endl;
		pinakas[i]->print(); 
		cout<<" (";
		for(j=0; j<4; j++)
		{
			pinakas[i]->get_desmos(j)->print();
			if(j<3) cout<<",";
			else cout<<")";
		}
	}
	*/
	
	//print ENOSEIS
	enosi_me_epomeno = 0; // arxika, o prwtos den exei desmo me ton proigoumeno tou (wste na anikei idi se enwsi)
	for(i=0; i<N; i++)
	{
		if(enosi_me_epomeno == 0) // gia kathe nea enosi (mi desmos me previous C)
			cout<<"\ncomp([";
		else
			cout<<", ";
			
		pinakas[i]->print(); // typwnw ton anthraka pou vriskomai (kai ksekinaei tin composition)
		cout<<"(";			// ksekinaw ti lista me tous desmous tou
		
		enosi_me_epomeno = 0;	// estw den exei desmo me epomeno C
		for(j=0; j<4; j++)		// pernaw 1-1 tous desmous tou
		{
			pinakas[i]->get_desmos(j)->print();	//ektypwne me poio atomo enwnetai
			if(j<3)
				cout<<",";
			else				// gia to telos na min exei komma, alla na kleini i parenthesi
				cout<<")";
				
			if((i<N-1) && (pinakas[i]->get_desmos(j) == pinakas[i+1])) // an kapoios deiktis sou (enosi) deixnei stin epomeni thesi tou pinaka (epomenos C), synexizei i idia composistion
				enosi_me_epomeno++;
		}	

		if(enosi_me_epomeno == 0) // an teleiwse i composition (mi enwsi me epomeno), tote kleinei
			cout<<"])";
	}
}

Atomo::Atomo(int t, int n) 
{
	int i; 
	type = t; 
	no = n; 
	desmoi_idi = 0; 
	for(i=0; i<4; i++) 
		deiktes[i] = NULL;
		
	cout<<"\nConstructing Atom "; print(); 
}

void Atomo::delete_all_H()
{
	int i;
	for(i=0; i<4; i++)
		if(deiktes[i]->get_type() == 'h')
			delete deiktes[i];
}

