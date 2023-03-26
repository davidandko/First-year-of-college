#include <iostream>
#include <cstring>

using namespace std;

class korisnik{
private:
	char *ime;
	float *merenja;
	int brMerenja;

public:
	korisnik(){
		ime=new char[1];
		strcpy(ime,"");
		brMerenja=1;
		merenja=new float[1];
		merenja[0]=60.0;
	}

	korisnik(const korisnik &k){
		brMerenja=k.brMerenja;
		ime=new char[strlen(k.ime)+1];
		strcpy(ime,k.ime);

		merenja=new float(k.brMerenja);
		for(int i=0;i<brMerenja;i++){
			merenja[i]=k.merenja[i];
		}
	}

	korisnik(char *imev,float *merenjav,int brojv){
		brMerenja=brojv;
		ime=new char[strlen(imev)+1];
		strcpy(ime,imev);

		merenja=new float[brMerenja];
		for(int i=0;i<brMerenja;i++){
			merenja[i]=merenjav[i];
		}
	}

	~korisnik(){
		delete[] ime;
		delete[] merenja;
	}

	void pechati(){
		cout<<"Ime: "<<ime<<", broj na merenja: "<<brMerenja<<endl;
		for(int i=0;i<brMerenja;i++){
			cout<<i+1<<". ";
			cout<<merenja[i]<<endl;
		}
	}

	void dodadiMerenje(float m){
		// nova niza
		float *novaNiza=new float[brMerenja+1];
		for(int i=0;i<brMerenja;i++){
			novaNiza[i]=merenja[i];
		}
		delete[] merenja;
		novaNiza[brMerenja++]=m;
		merenja=novaNiza;
	}

	void brishiMerenje(){
		float *novaNiza=new float[brMerenja-1];
		for(int i=0;i<brMerenja-1;i++){
			novaNiza[i]=merenja[i+1];
		}
		delete[] merenja;

		merenja=novaNiza;
		brMerenja--;

	}
};

int main(){
	float nizaMerenja[4] = {69,45,80,100};

	korisnik k("David",nizaMerenja,4);
	k.pechati();
	k.dodadiMerenje(69.3);
	k.pechati();
	k.brishiMerenje();
	k.pechati();

	return 0;
}
