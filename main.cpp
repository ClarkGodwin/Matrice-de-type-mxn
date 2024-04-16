#include"header.hpp"

using namespace std;

int main()
{
	vector<Matrice*> matrice;
	string reponse;
	int r(0), c(0), n(0), il(0), ic(0), rep(0), p(0);
	Fraction nbr(0);
	cout<<endl<<endl;
	cout<<"  ********************************************"<<endl<<endl;
	cout<<"       Clark Godwin Niyonzima : Matrice       "<<endl<<endl;
	cout<<"  ********************************************"<<endl<<endl;
	
	do{
		cout<<endl<<" Operation disponibles: "<<endl<<endl;
		cout<<" 1.Basics(addition, soustraction, multiplication, division, puissance ou une combinaison)"<<endl<<endl;
		cout<<" 2.Determinant"<<endl<<endl;
		cout<<" 3.Inverse"<<endl<<endl;
		cout<<" 4.Rang"<<endl<<endl;
		cout<<" Quelle operation voulez-vous effectuer(1, 2, 3 ou 4): ";
	
		do{
			cin>>r;
		
			if(r < 1 || r > 4)
				cout<<endl<<" Erreur, choisissez entre 1, 2, 3 et 4: ";
				
		}while(r < 1 || r > 4);
	
		switch(r)
		{
			case 1:
			{
				cout<<endl<<" Quelle operation voulez-vous effectuer: "<<endl<<endl;
				cout<<" 1.Addition"<<endl<<endl;
				cout<<" 2.Soustraction"<<endl<<endl;
				cout<<" 3.Multiplication"<<endl<<endl;
				cout<<" 4.Division"<<endl<<endl;
				cout<<" 5.Puissance"<<endl<<endl;
				cout<<" 6.Combinaision des 2 ou plusieurs des operations ci-haut"<<endl<<endl;
				cout<<" Votre choix(1, 2, 3, 4, 5 ou 6): ";
				
				do{
					cin>>c;
					
					if(c < 1 || c > 6)
						cout<<endl<<" Erreur, recommencer: ";
						
				}while(c < 1 || c > 6);
				
				switch(c)
				{
					case 1:
					{
						cout<<endl<<" Combien de matrice cette operation impliquera-t-elle: ";
						cin>>n;
						cout<<endl<<" Entrer les informations des matrices: "<<endl<<endl;
						
						for(int i=0; i < n; i++)
						{
							matrice.push_back(nullptr);
							matrice[i] = new Matrice;
							cin>>*matrice[i];
							cout<<*matrice[i];
							
							if(i == 0)
							{
								il = matrice[0]->get_line();
								ic = matrice[0]->get_column();
							}
								
							else
							{
								if(il != matrice[i]->get_line() || ic != matrice[i]->get_column())
									cout<<endl<<"Erreur, cette matrice est de type different."<<endl<<endl;
							}
							
							cout<<endl;
						}
						
						Matrice sum(*matrice[0]);
						
						for(int i=1; i < n; i++)
						{
							sum += *matrice[i];
							sum.set_name(sum.get_name() + " + " + matrice[i]->get_name());
						}
						
						cout<<sum<<endl;
						
						break;
					}
					
					case 2:
					{
						cout<<endl<<" Combien de matrice cette operation impliquera-t-elle: ";
						cin>>n;
						cout<<endl<<" Entrer les informations des matrices: "<<endl<<endl;
						
						for(int i=0; i < n; i++)
						{
							matrice.push_back(nullptr);
							matrice[i] = new Matrice;
							cin>>*matrice[i];
							cout<<*matrice[i];
							
							if(i == 0)
							{
								il = matrice[0]->get_line();
								ic = matrice[0]->get_column();
							}
								
							else
							{
								if(il != matrice[i]->get_line() || ic != matrice[i]->get_column())
									cout<<endl<<"Erreur, cette matrice est de type different."<<endl<<endl;
							}
							
							cout<<endl;
						}
						
						Matrice diff(*matrice[0]);
						
						for(int i=1; i < n; i++)
						{
							diff -= *matrice[i];
							diff.set_name(diff.get_name() + " - " + matrice[i]->get_name());
						}
						
						cout<<diff<<endl;
						
						break;
					}
					
					case 3:
					{
						cout<<endl<<" Multiplication par un nombre(1) ou une/plusieurs matrice/matrices(2): ";
						
						do{
							cin>>rep;
							
							if(rep < 1 || rep > 2)
								cout<<endl<<" Erreur, choisissez entre 1 et 2: ";
								
						}while(rep < 1 || rep > 2);
						
						if(rep == 1)
						{
							cout<<endl<<" Entrer Ce nombre: ";
							cin>>nbr;
							n = 1;
							cout<<endl<<" Entrer les informations de la matrice: "<<endl<<endl;
							matrice.push_back(nullptr);
							matrice[0] = new Matrice;
							cin>>*matrice[0];
							*matrice[0] *= nbr;
							matrice[0]->set_name(matrice[0]->get_name() + " * " + nbr.ftos());
							cout<<*matrice[0];
						}
						
						else
						{
							cout<<endl<<" Combien de matrice cette operation impliquera-t-elle: ";
							cin>>n;
							cout<<endl<<" Entrer les informations des matrices: "<<endl<<endl;
						
							for(int i=0; i < n; i++)
							{
								matrice.push_back(nullptr);
								matrice[i] = new Matrice;
								cin>>*matrice[i];
								cout<<*matrice[i];
							
								if(i == 0)
								{
									il = matrice[0]->get_line();
									ic = matrice[0]->get_column();
								}
								
								cout<<endl;
							}
							
							Matrice diff(*matrice[0]);
						
							for(int i=1; i < n; i++)
							{
								diff = diff * *matrice[i];
								diff.set_name(diff.get_name() + " * " + matrice[i]->get_name());
							}
							
							cout<<diff<<endl;
						}
						
						break;
					}
					
					case 4:
					{
						cout<<endl<<" Division par un nombre(1) ou une/plusieurs matrice/matrices(2): ";
						
						do{
							cin>>rep;
							
							if(rep < 1 || rep > 2)
								cout<<endl<<" Erreur, choisissez entre 1 et 2: ";
								
						}while(rep < 1 || rep > 2);
						
						if(rep == 1)
						{
							cout<<endl<<" Entrer Ce nombre: ";
							cin>>nbr;
							n = 1;
							cout<<endl<<" Entrer les informations de la matrice: "<<endl<<endl;
							matrice.push_back(nullptr);
							matrice[0] = new Matrice;
							cin>>*matrice[0];
							nbr = 1/nbr;
							*matrice[0] *= nbr;
							matrice[0]->set_name(matrice[0]->get_name() + " * " + nbr.ftos());
							cout<<*matrice[0];
						}
						
						else
						{
							cout<<endl<<" Cette operation ne peut impliquer que 2 matrices"<<endl;
							n = 2;
							cout<<endl<<" Entrer les informations des matrices: "<<endl<<endl;
						
							for(int i=0; i < n; i++)
							{
								matrice.push_back(nullptr);
								matrice[i] = new Matrice;
								cin>>*matrice[i];
								cout<<*matrice[i];
							
								if(i == 0)
								{
									il = matrice[0]->get_line();
									ic = matrice[0]->get_column();
								}
								
								cout<<endl;
							}
							
							Matrice diff(*matrice[0]);
						
							for(int i=1; i < n; i++)
							{
								diff = diff / *matrice[i];
								diff.set_name(diff.get_name() + " / " + matrice[i]->get_name());
							}
							
							cout<<diff<<endl;
						}
						
						break;
					}
					
					case 5:
					{
						n = 1;
						cout<<endl<<" Quelle est la puissance: ";
						cin>>p;
						matrice.push_back(nullptr);
						matrice[0] = new Matrice;
						cout<<endl;
						cin>>*matrice[0];
						matrice[0]->puissance(p);
						cout<<endl<<*matrice[0];
						break;
					}
					
					case 6:
					{
						cout<<endl<<" Combien de matrice cette operation impliquera-t-elle: ";
						cin>>n;
						cout<<endl<<" Entrer les informations des matrices: "<<endl<<endl;
						
						for(int i=0; i < n; i++)
						{
							matrice.push_back(nullptr);
							matrice[i] = new Matrice;
							cout<<" A quelle puissance la matrice "<<i+1<<" est-elle elevee(sinon, taper 1): ";
							cin>>p;
							
							if (p < 1)
							{
								cout<<endl<<" Operation Impossible";
								exit(0);
							}
								
							cout<<endl<<" Multiplier par quel nombre(sinon, taper 1): ";
							cin>>nbr;
							cout<<endl;
							cin>>*matrice[i];
							matrice[i]->puissance(p);
							*matrice[i] *= nbr;
							
							if(nbr != 1 && p != 1)
								matrice[i]->set_name(nbr.ftos() + "*"+matrice[i]->get_name());
							
							else if(nbr != 1 && p == 1)
								matrice[i]->set_name(nbr.ftos() + "*"+matrice[i]->get_name());
							
							cout<<endl<<*matrice[i];
							
							if(i == 0)
							{
								il = matrice[0]->get_line();
								ic = matrice[0]->get_column();
							}
								
							else
							{
								if(il != matrice[i]->get_line() || ic != matrice[i]->get_column())
									cout<<endl<<" Erreur, cette matrice est de type different."<<endl<<endl;
							}
							
							cout<<endl;
						}
						
						Matrice sum(*matrice[0]);
						
						for(int i=1; i < n; i++)
						{
							sum += *matrice[i];
							sum.set_name(sum.get_name() + " + " + matrice[i]->get_name());
						}
						
						cout<<sum;
						
						break;
					}
				}
				
				break;
			}
			
			case 2:
			{
				cout<<endl<<" Combien de matrices voulez-vous en calculer le determinant: ";
				cin>>n;
				cout<<endl<<" Entrer les informations de la/des matrice/s: "<<endl<<endl;
				
				for(int i=0; i < n; i++)
				{
					matrice.push_back(nullptr);
					matrice[i] = new Matrice;
					cin>>*matrice[i];
					cout<<endl<<*matrice[i]<<endl<<" det("<<matrice[i]->get_name()<<") = "<<matrice[i]->calc_det()<<endl;
				}
				
				break;
			}
			
			case 3:
			{
				cout<<endl<<" Combien de matrices voulez-vous en calculer l'inverse: ";
				cin>>n;
				cout<<endl<<" Entrer les informations de la/des matrice/s: "<<endl<<endl;
				
				for(int i=0; i < n; i++)
				{
					matrice.push_back(nullptr);
					matrice[i] = new Matrice;
					cin>>*matrice[i];
					cout<<endl<<*matrice[i]<<endl<<matrice[i]->inverse()<<endl;
				}
				
				break;
			}
			
			case 4:
			{
				cout<<endl<<" Combien de matrices voulez-vous en calculer le rang: ";
				cin>>n;
				cout<<endl<<" Entrer les informations de la/des matrice/s: "<<endl<<endl;
				
				for(int i=0; i < n; i++)
				{
					matrice.push_back(nullptr);
					matrice[i] = new Matrice;
					cin>>*matrice[i];
					cout<<endl<<*matrice[i]<<endl<<" rang("<<matrice[i]->get_name()<<") = "<<matrice[i]->rang()<<endl<<endl;
				}
				
				break;
			}
			
		}
		
		cout<<endl<<" Souhaitez-vous recommencer(oui ou non): ";
		
		do{
			cin>>reponse;
			
			if(reponse != "oui" && reponse != "Oui" && reponse != "OUI" && reponse != "non" && reponse != "Non" && reponse != "NON")
				cout<<endl<<" Erreur, choisissez entre oui et non: ";
				
		}while(reponse != "oui" && reponse != "Oui" && reponse != "OUI" && reponse != "non" && reponse != "Non" && reponse != "NON");
		
	}while(reponse == "oui" || reponse == "Oui" || reponse == "OUI");
	
	for(int i=0; i < matrice.size(); i++)
	{
		delete matrice[i];
		matrice[i] = nullptr;
	}
	
	return 0;
}
