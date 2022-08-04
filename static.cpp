#include <iostream>
#include <fstream>
using namespace std;

struct mhs 
{
	int smstr;
	string mtkl;
	int ruang;
	string hari;
	float jam;
	string nma;
};
mhs x[100];

class tgsproyek 
{
	friend ostream& operator <<( const ostream&,tgsproyek&);
	friend ostream& operator <<(ostream& ,tgsproyek& );
	
	public:	
		void login();
		void home();
		void datstatis();
	    void proses1();
	    void proses3();
		void output();
	
	private:
	 	int n;
	  	int byk_org;
	  	int dat;
		string usname,pswd,kul,har;
		char lanjut;
		int pilihan;
 		int id;
 		ofstream tulis,letakkan;
};
void tgsproyek::datstatis(){
	byk_org=9;
	//data hari;
	x[0].hari="senin";
	x[1].hari="selasa";
	x[2].hari="rabu";
	x[3].hari="kamis";
	x[4].hari="Jum'at";
	x[5].hari="Sabtu";
	x[6].hari="senin";
	x[7].hari="selasa";
	x[8].hari="selasa";
	
	//data semester
	x[0].smstr=1;
	x[1].smstr=3;
	x[2].smstr=2;
	x[3].smstr=4;
	x[4].smstr=6;
	x[5].smstr=8;
	x[6].smstr=8;
	x[7].smstr=5;
	x[8].smstr=7;
	//data dosen
	x[0].nma="wahyu p m.kom";
	x[1].nma="taufik ismail m.kom";
	x[2].nma="fitri indra m.eng";
	x[3].nma="murinto kusno m.kom";
	x[4].nma="dwi normawati M.t";
	x[5].nma="murein miksa m M.t";
	x[6].nma="muslihudin M.T";
	x[7].nma="ahmad azhari m.kom";
	x[8].nma="juwanti M.h";
	
	//data matkul
	x[0].mtkl="alpro";
	x[1].mtkl="pweb";
	x[2].mtkl="ddp";
	x[3].mtkl="kalkulus";
	x[4].mtkl="logika";
	x[5].mtkl="Mdi";
	x[6].mtkl="arsikom";
	x[7].mtkl="dsk";
	x[8].mtkl="pancasila";
	
	//data jam
	x[0].jam=07.30;
	x[1].jam=08.45;
	x[2].jam=10.30;
	x[3].jam=08.45;
	x[4].jam=09.45;
	x[5].jam=12.00;
	x[6].jam=15.20;
	x[7].jam=07.00;
	x[8].jam=07.00;
	//data ruangan
	x[0].ruang=311;
	x[1].ruang=131;
	x[2].ruang=523;
	x[3].ruang=710;
	x[4].ruang=955;
	x[5].ruang=113;
	x[6].ruang=221;
	x[7].ruang=660;
	x[8].ruang=154;
	
}

void tgsproyek::login(){
	cout<<"masukkan username -> ";cin>>usname;
	cout<<"masukkan password -> ";cin>>pswd;
	ulang :
	if(usname == "Mahasiswa" && pswd == "mahasiswa" ){
		system("cls");
		home();
	}else if(usname == "Dosen" && pswd == "dosen"){
		system("cls");
		home();
	}else{
		cout<<"masukkan username dan password yang benar "<<endl;
		login();
	}
}

void tgsproyek::home(){
	//menu home
	awal:
	cout<<"SELAMAT DATANG DI SIMANGAN "<<endl;
	cout<<"==================================="<<endl;
	cout<<"+================================+"<<endl;
    cout<<"||          MENU UTAMA           ||"<<endl;
    cout<<"||===============================||"<<endl;
    cout<<"|| 1. pencarian jadwal semester  ||"<<endl;
    cout<<"|| 2. pencarian jadwal matkul    ||"<<endl;
    cout<<"|| 3. pencarian hari kuliah      ||"<<endl;
    cout<<"|| 4. tampilkan hasil sorting    ||"<<endl;
    cout<<"|| 5. keluar                     ||"<<endl;
    cout<<"+================================+"<<endl;
    cout<<"Masukkan Pilihan Anda : ";
    cin>>pilihan;
    system("cls");
    
    //jika pilihannya mencari jadwal berdasarkan semester
    if(pilihan == 1){
      cout<<"|===============================|"<<endl;
	  cout<<"|   Search berdasar semester    : ";
	  cin >> id;
	  cout<<"|===============================|"<<endl;
	  for (int i = 0; i < byk_org; i++) {
	    if(x[i].smstr == id){
	      cout << "Ruang                     : " << x[i].ruang << endl;
	      cout << "Semester                  : " << x[i].smstr << endl;
	      cout << "Nama Dosen                : " << x[i].nma << endl;
	      cout << "Mata Kuliah               : " << x[i].mtkl << endl;
	      cout << "Hari                      : " << x[i].hari << endl;
	      cout << "jam                       : " << x[i].jam <<endl;
	      
	      tulis.open("sercsmster.txt");
	      tulis << "Ruang                     : " << x[i].ruang << endl;
	      tulis << "Semester                  : " << x[i].smstr << endl;
	      tulis << "Nama Dosen                : " << x[i].nma << endl;
	      tulis << "Mata Kuliah               : " << x[i].mtkl << endl;
	      tulis << "Hari                      : " << x[i].hari << endl;
	      tulis << "jam                       : " << x[i].jam <<endl;
	      tulis.close();
	      
	    }
	  }
	  cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
	  if(lanjut == 'Y' || lanjut == 'y'){
	  		goto awal;
	  }else{

	  }
	}
	
	//jika pilihanya mencari jadwal berdasarkan mata kuliah
	if(pilihan == 2){
		cout<<"|====================================|"<<endl;
		cout<<"1. alpro "<<endl;
		cout<<"2. pweb"<<endl;
		cout<<"3. ddp"<<endl;
		cout<<"4. kalkulus"<<endl;
		cout<<"5. logika"<<endl;
		cout<<"6. Mdi"<<endl;
		cout<<"7. arsikom"<<endl;
		cout<<"8. dsk"<<endl;
		cout<<"9. pancasila"<<endl;
		// sercing matkul
	  cout<<"|====================================|"<<endl;
	  cout<<"|   Search berdasar mata kuliah    : ";
	  cin >> kul;
	  cout<<"|===============================|"<<endl;
	  for (int i = 0; i < byk_org; i++) {
	    if (x[i].mtkl == kul) {
	      cout << "Mata Kuliah               : " << x[i].mtkl << endl;
	      cout << "Ruang                     : " << x[i].ruang << endl;
	      cout << "Semester                  : " << x[i].smstr << endl;
	      cout << "Nama Dosen                : " << x[i].nma << endl;
	      cout << "Hari                      : " << x[i].hari << endl;
	      cout << "jam                       : " << x[i].jam <<endl;
	      
	      tulis.open("sercmatkul.txt");
	      tulis << "Mata Kuliah               : " << x[i].mtkl << endl;
	      tulis << "Ruang                     : " << x[i].ruang << endl;
	      tulis << "Semester                  : " << x[i].smstr << endl;
	      tulis << "Nama Dosen                : " << x[i].nma << endl;
	      tulis << "Hari                      : " << x[i].hari << endl;
	      tulis << "jam                       : "<<x[i].jam<<endl;
	      tulis.close();
	      
	    }
	  }
	  cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
	  if(lanjut == 'Y' || lanjut == 'y'){
	  		goto awal;
	  		system("cls");
	  }else{

	  }
	}
	
	//jika pilihanya mencari jadwal berdasarkan hari
	if(pilihan == 3){
	  cout<<"|====================================|"<<endl;
	  cout<<"|   Search berdasarkan hari kuliah: ";
	  cin >> har;
	  cout<<"|===============================|"<<endl;
	  for (int i = 0; i < byk_org; i++) {
	    if (x[i].hari == har) {
	      cout << "Hari                      : " << x[i].hari << endl;
	      cout << "Mata Kuliah               : " << x[i].mtkl << endl;
	      cout << "Ruang                     : " << x[i].ruang << endl;
	      cout << "Semester                  : " << x[i].smstr << endl;
	      cout << "Nama Dosen                : " << x[i].nma << endl;
	      cout << "jam                       : " << x[i].jam <<endl;
	  }
}
	  for (int j = 0; j < byk_org; j++){
	  	if(x[j].hari == har){
		  
	      tulis.open("sercday.txt");
	      tulis << "Hari                      : " << x[j].hari << endl;
	      tulis << "Mata Kuliah               : " << x[j].mtkl << endl;
	      tulis << "Ruang                     : " << x[j].ruang << endl;
	      tulis << "Semester                  : " << x[j].smstr << endl;
	      tulis << "Nama Dosen                : " << x[j].nma << endl;
	      tulis << "jam                       : " <<x[j].jam<<endl;
	      tulis.close();
	  		}
	    }
	  cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
	  if(lanjut == 'Y' || lanjut == 'y'){
	  		goto awal;
	  		system("cls");
	  }else{

	  }
	}

	//jika pilihan 4 melihat hasil sorting
	if(pilihan == 4){
		sercsort:
		cout<<"||===============================||"<<endl;
    	cout<<"|| 1. urutan berdasarkam Semester||"<<endl;
    	cout<<"|| 2. urutan berdasarkan Ruangan ||"<<endl;
    	cout<<"||===============================||"<<endl;
    	int tamsort;
    	cout<<"|| masukkan pilihan anda ->      || ";cin>>tamsort;
    	if(tamsort == 1){
    		proses1();
		  	cout<< "==============================================================================================" << endl;
		  	cout<< "|                         PENGURUTAN BERDASARKAN SEMESTER                                    |" << endl;
		 	cout<< "==============================================================================================="<<endl;
		    cout<< "|       Semester      |   Ruangan   |   Nama Dosen   |   Mata Kuliah    |  Hari     |   jam   |"<<endl;
			cout<< "=============================================================================================="<<endl;
		
			for (int i = 0; i < byk_org; i++){
			  	cout << "==============================================================================================" << endl;
			    cout <<"|\t    "<< x[i].smstr << "\t      |      "    << x[i].ruang<< "      |    "<< x[i].nma <<"   |     "<< x[i].mtkl << "    |     "<< x[i].hari << "    |    "<<x[i].jam<< endl;
			}
			   cout  << "==============================================================================================" << endl;
			   cout <<endl;
			   
			cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
			if(lanjut == 'Y' || lanjut == 'y'){	
			  	system("cls");
			  	goto sercsort;
			  }else{
			  	system("cls");
				goto awal;
			  }
			}
			
		if(tamsort == 2){
			proses3();
			cout<< "==============================================================================================" << endl;
		  	cout<< "|                         PENGURUTAN BERDASARKAN RUANGAN                                      |" << endl;
		 	cout<< "==============================================================================================="<<endl;
		    cout<< "|       Ruangan       |   Semester   |   Nama Dosen   |   Mata Kuliah    |  Hari     |   jam   |"<<endl;
			cout<< "=============================================================================================="<<endl;
		
			for (int i = 0; i < byk_org; i++){
			  	cout << "==============================================================================================" << endl;
			    cout <<"|\t    "<< x[i].ruang << "\t      |      "    << x[i].smstr<< "      |    "<< x[i].nma <<"   |     "<< x[i].mtkl << "    |     "<< x[i].hari << "    |    "<<x[i].jam<< endl;
			}
			   cout  << "==============================================================================================" << endl;
			   cout <<endl;
			   cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
			if(lanjut == 'Y' || lanjut == 'y'){
			  		
			  		system("cls");
			  		goto sercsort;
			  }else{
			  		system("cls");
					goto awal;
			  }
		}
		
}	else{
	system("cls");
	cout<<"=============================================="<<endl;
	cout<<"||       anda berhasil log out               ||"<<endl;
	cout<<"||silahkan login untuk beraktifitas          ||"<<endl;
	cout<<"=============================================="<<endl;
	login();
}
}

//proses pengurutan semester
void tgsproyek::proses1(){
  char temp[50]; 
  for (int i=0;i<byk_org;i++){
        for (int j=i+1;j<byk_org;j++){
        if (x[j].smstr<x[i].smstr){
            mhs temp;
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
         }		
      }
   }
}
//output sort untu txt. sort berdasarkan semester
ostream& operator <<(const ostream& out,tgsproyek& a){
	a.proses1();
	a.tulis.open("hasilsmester.txt");
  	a.tulis	<< "==============================================================================================" << endl;
  	a.tulis << "|                         PENGURUTAN BERDASARKAN SEMESTER                                    |" << endl;
 	a.tulis << "==============================================================================================="<<endl;
    a.tulis << "|       Semester      |   Ruangan   |   Nama Dosen   |   Mata Kuliah    |  Hari     |   jam   |"<<endl;
	a.tulis << "=============================================================================================="<<endl;

	for (int i = 0; i < a.byk_org; i++) {
	  	a.tulis << "==============================================================================================" << endl;
	    a.tulis <<"|\t    "<< x[i].smstr << "\t      |      "    << x[i].ruang<< "      |    "<< x[i].nma <<"   |     "<< x[i].mtkl << "    |     "<< x[i].hari << "    |    "<<x[i].jam<< endl;
	  }
	   a.tulis  << "==============================================================================================" << endl;
	   a.tulis <<endl;
	   a.tulis.close();
	}

//proses pengurutan semester
void tgsproyek::proses3(){
  char temp[50]; 
  for (int i=0;i<byk_org;i++){
        for (int j=i+1;j<byk_org;j++){
        if (x[j].ruang<x[i].ruang){
            mhs temp;
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
         }		
      }
   }
}
//output sort untu txt. sort berdasarkan Ruangan
ostream& operator <<(ostream& out,tgsproyek& b){
	b.proses3();
	b.letakkan.open("ruangantampil.txt");
  	b.letakkan << "==============================================================================================" << endl;
  	b.letakkan << "|                         PENGURUTAN BERDASARKAN RUANGAN                                       |" << endl;
 	b.letakkan << "================================================================================================"<<endl;
    b.letakkan << "|      Ruangan      |   Semester     |   Nama Dosen   |   Mata Kuliah    |  Hari     |   jam   |"<<endl;
	b.letakkan << "================================================================================================"<<endl;

  for (int i = 0; i < b.byk_org; i++){
  	b.letakkan << "==============================================================================================" << endl;
    b.letakkan <<"|\t    "<< x[i].ruang << "\t      |      "    << x[i].smstr << "      |    "<< x[i].nma <<"   |     "<< x[i].mtkl << "    |     "<< x[i].hari << "    |    "<<x[i].jam<< endl;
  }
   b.letakkan  << "==============================================================================================" << endl;
   b.letakkan <<endl;
   b.letakkan.close();
}

int main() {
  tgsproyek x;
  x.datstatis();
  x.login();
  x.proses1();
  cout<<x;
  x.proses3();
  cout<<x;
  return 0;
}
