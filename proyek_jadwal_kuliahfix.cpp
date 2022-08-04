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
	string nma[50];
};
mhs x[100];

class tgsproyek {
	friend ostream& operator <<( const ostream&,tgsproyek&);
	
	public:	
		void login();
		void home();
	  	void input();
	    void proses1();
	    void proses3();
	    void proses4();
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
    cout<<"|| 4. input jadwal               ||"<<endl;
    cout<<"|| 5. tampilkan hasil sorting    ||"<<endl;
    cout<<"|| 6. keluar                     ||"<<endl;
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
	      
	      break;
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
	      break;
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
	      
	      tulis.open("sercday.txt");
	      tulis << "Hari                      : " << x[i].hari << endl;
	      tulis << "Mata Kuliah               : " << x[i].mtkl << endl;
	      tulis << "Ruang                     : " << x[i].ruang << endl;
	      tulis << "Semester                  : " << x[i].smstr << endl;
	      tulis << "Nama Dosen                : " << x[i].nma << endl;
	      tulis << "jam                       : "<<x[i].jam<<endl;
	      tulis.close();
	      
	      break;
	    }
	  }
	  cout<<"apakah anda ingin melanjutkan ?(y/n) ";cin>>lanjut;
	  if(lanjut == 'Y' || lanjut == 'y'){
	  		goto awal;
	  		system("cls");
	  }else{

	  }
	}

    
    //jika pilihanya input data
    if(pilihan == 4){
  	  cout << "|=======================================================|" << endl;
	  cout << "|                   INPUTKAN JADWAL                     |" << endl;
	  cout << "|=======================================================|" << endl;
	  cout << "Masukan jumlah semester : ";cin>>byk_org;
	  cout << endl;
	  
	  for (int i = 0; i < byk_org; i++)
	  {
		    cout << "Ruangan               : ";cin >> x[i].ruang;
		    cout << "Semester              : ";cin >> x[i].smstr;
		    cout << "Nama Dosen            : ";cin.ignore();
											   cin.getline(x[i].nma,50);
		    cout << "Mata Kuliah           : ";cin >> x[i].mtkl;
		    cout << "Hari                  : ";cin >> x[i].hari;
		    cout << "jam                   : ";cin >> x[i].jam;
		    cout << endl;
		    cout << "";
	  }
	  cout<<"apakah anda ingin melanjutkan ? (Y/t)";cin>>lanjut;
	  if(lanjut == 'Y' || lanjut == 'y'){
	  		system("cls");
	  		goto awal;
	  		
	  }else{
		//biarkan kosong
	  }
	}
	
	//jika pilihan 5 melihat hasil sorting
	if(pilihan == 5){
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
		
			  }
		}
		
}	else{
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
void tgsproyek::output(){
	proses3();
	tulis.open("letakkan.txt");
  	tulis << "==============================================================================================" << endl;
  	tulis << "|                         PENGURUTAN BERDASARKAN RUANGAN                                       |" << endl;
 	tulis << "================================================================================================"<<endl;
    tulis << "|      Ruangan      |   Semester     |   Nama Dosen   |   Mata Kuliah    |  Hari     |   jam   |"<<endl;
	tulis << "================================================================================================"<<endl;

  for (int i = 0; i < byk_org; i++){
  	tulis << "==============================================================================================" << endl;
    tulis <<"|\t    "<< x[i].ruang << "\t      |      "    << x[i].smstr << "      |    "<< x[i].nma <<"   |     "<< x[i].mtkl << "    |     "<< x[i].hari << "    |    "<<x[i].jam<< endl;
  }
   tulis  << "==============================================================================================" << endl;
   tulis <<endl;
   tulis.close();
}

int main() {
  tgsproyek x;
  x.login();
  x.proses1();
  cout<<x;
  x.proses3();
  x.output();
  return 0;
}
