#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class usfah{
	private:
		char name [15];
		char last_name[15];
		int co, appg, strd, ana, cpp, sys, html;
	public:
		void read_data();
		void write_record();

		void show_record();
		void show_data ();
		void count_data();
};

void usfah::count_data()
{
    int n;
    ifstream infile;
    infile.open("usfah.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
}

void usfah::read_data()
{
	cout<<"***IDENTIFICATION***"<<endl;
	cout<<"Nom :";
	cin>>name;
	cout<<"Prenom :";
	cin>>last_name;
	cout<<"\n";
	cout<<"**** Entrer Vos Notes ****"<<endl;
	cout<<"\t Concept Objet :";
	cin>>co;
	cout<<"\t Application Graphique :";
	cin>>appg;
	cout<<"\t Structure de Donnee :";
	cin>>strd;
	cout<<"\t Analyse Numerique :";
	cin>>ana;	
	cout<<"\t C++ :";
	cin>>cpp;
	cout<<"\t Systeme d'exploitation :";
	cin>>sys;
	cout<<"\t Html/Css :";
	cin>>html;
}

void usfah::show_data()
{
	cout<<"____________________"<<endl;
	cout<<"NOM DE L'ETUDIANT :"<<name<<endl;
	cout<<"PRENOM DE L'ETUDIANT :"<<last_name<<endl;
	cout<<"_____________________"<<endl;
	cout<<"\t Concept Objet :"<<co<<endl;
	cout<<"\t Application Graphique :"<<appg<<endl;
	cout<<"\t Structure de Donnee :"<<strd<<endl;
	cout<<"\t Analyse Numerique :"<<ana<<endl;
	cout<<"\t C++ :"<<cpp<<endl;
	cout<<"\t Systeme d'exploitation :"<<sys<<endl;
	cout<<"\t Html/Css :"<<html<<endl;
	cout<<"\n";
}

void usfah::write_record()
{
	usfah callit;
	ofstream outfile("usfah.txt", ios::binary|ios::app);
	if (!outfile)
	{
		cout<<"Failed while Opening file";
	}
	cout<<"Confirmer que vous etes etudiant de l'USFAH \n";
	string verify;
	cin>>verify;
	callit.count_data();
	if (verify!="yes")	
	{
		cout<<"\t Note Registering Failed !"<<endl;
		cout<<"\t Veuillez entrer yes/no"<<endl;
		return;
	}
	read_data();
	outfile.write(reinterpret_cast <char*>(this), sizeof(*this));
	cout<<"\t\t \n \n Notes Enregiste !"<<endl;
	cout<<"\n"<<name<<" "<<last_name<<" Voulez-vous voir votre moyenne? "<<endl;
	string answer;
	cin>>answer;
	if (true)
	{
		cout<<"\t \t Operation Not Available !";
		return;
	}

	outfile.close();
}

void usfah::show_record()
{
	ifstream infile("usfah.txt", ios::binary);
	if (!infile)
	{
		cout<<"Can't Open file";
	}
	while(!infile.eof())
	{
		if(infile.read(reinterpret_cast <char*>(this), sizeof(*this))>0)
		{
			show_data();
		}
	}
	infile.close();
}

main ()
{
	cout<<"**** COMPUTER SICENCE STUDENT NOTES **** \n";
	usfah program;
	while (true)
	{
		cout<<"\n \n";
		cout<<" 1----> Enregistrer vos notes"<<endl;
		cout<<" 2----> Voir les enregistrements"<<endl;
		cout<<" 3----> Quitter le programme"<<endl;
		cout<<" 4----> Count data"<<endl;

		int mon_choix;
		cout<<"\n \n";
		cout<<"L'option Choisie :";
		cin>>mon_choix;

		switch (mon_choix)
		{
			case 1: program.write_record();
			break;
			case 2: program.show_record();
			break;
			case 3: cout<<"\n\n";
			cout<<"\t\t Program Closed !"<<endl;
			exit(0);
			case 4: program.count_data();

		}
	}
	///system ("pause");
	return 0;
}


