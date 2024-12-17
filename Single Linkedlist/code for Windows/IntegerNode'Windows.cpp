#include <iostream>
using namespace std;

//Struct Node :
struct Node{
	int data;
	Node *next;
};
Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;
//Pembuatan Node Awal:
	void buatNodeAwal(int i){
	n = new Node;
	n->data = i;
	tail = n;
	head = n;
	tail->next = NULL;
}
//Penambahan node pada posisi belakang:
void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}
//Penambahan node pada posisi depan:
void tambahDiDepan(int i){
	n = new Node; n->data = i; n->next = head;
	head = n;
}
//Penambahan node pada posisi tengah
void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
}
//Penghapusan node pada posisi depan:
void hapusDiDepan(){
	x =head;
	head = head;
	head=head->next;
	delete(x);
}
//Penghapusan node pada posisi belakang:
void hapusDiBelakang(){
	x =head;
	while(x->next != tail) x=x->next;
	tail = x;
	delete(x->next);
	tail->next = NULL;
}
//Penghapusan node pada posisi tengah:
void hapusDiTengah(int i){
	Node *temp=NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete(x);
}
//Tampil data:
void tampilData(){
	x=head;
	while(x!=NULL){
		cout << x->data << " ";
		x= x->next;
	}
}
bool search(int src){
	x=head;
	while(x!=NULL){
		if(x->data==src){
			return true;
		}
		x=x->next;
	}return false;
}
void ui();
void ui1();
void clearNode();
int main() {
	Node node;
	int choice,n,ch,chc,hps;
	while(choice!=5){
		ui();cin>>choice;
			if((cin.fail())){ 
				system("cls");
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"pilihan tidak tersedia..."<<endl;
				system("pause");
			}
			if(choice==1){
			system("cls");
				if(head==NULL){
					cout<<"Buat Node Baru\n";
					cout<<"==============\n\n";
					cout<<"Masukkan Nilai : ";cin>>n;
					buatNodeAwal(n);
					cout<<"Nilai "<<n<<" Berhasil dimasukkan di awal...\n";
				}else{
					cout<<"Node Awal/Baru sudah dibuat...\n";
				}system("pause");
		}
			else if(choice==2){
				if(head == NULL){
					system("cls");
					cout<<"Node belum tersedia...\n";
					system("pause");
				}
				else{
					system("cls");
					ui1();cin>>ch;
					switch(ch){
						case 1:{
							system("cls");
							cout<<"Tambah Node di Depan\n";
							cout<<"====================\n\n";
							cout<<"Masukkan nilai :";cin>>n;
							tambahDiDepan(n);
							if((cin.fail())){ 
								system("cls");
								cin.clear();
								cin.ignore(1000, '\n');
								cout<<"Input is not falid..."<<endl;
								system("pause");
							}else{
								cout<<"Node dengan nilai "<<n<<" berhasil ditambahkan pada posisi depan.\n";
								system("pause");
							}
							break;
						}
						case 2:{
							system("cls");
							cout<<"Tambah Node di Belakang\n";
							cout<<"====================\n\n";
							cout<<"Masukkan nilai : ";cin>>n;
							tambahDiBelakang(n);
							cout<<"Node dengan nilai "<<n<<" berhasil ditambahkan pada posisi belakang.\n";
							system("pause");
							break;
						}
						case 3:{	
							system("cls");
							cout<<"Tambah Node di Tengah\n";
							cout<<"====================\n\n";
							cout<<"Node dimasukkan setelah node dengan nilai \t: ";cin>>chc;
							if(search(chc)==true){
								cout<<"Masukkan nilai Node yang baru		\t: ";cin>>n;
								tambahDiTengah(n,chc);
								cout<<"Node dengan nilai "<<n<<" berhasil ditambahkan setelah node dengan nilai "<<chc<<endl;
								system("pause");
							}else{
								cout<<"nilai tidak ditemukan!!"<<endl;
								system("pause");
								break;
							}
						}
					}
				}
		}
			else if(choice==3){
				if(head==NULL){
					system("cls");
					cout<<"Node belum tersedia...\n";
					system("pause");
				}else{
					system("cls");
					clearNode();cin>>ch;
					switch(ch){
						case 1:{
							system("cls");
							cout<<"Node pada posisi depan berhasil dihapus"<<endl;
							hapusDiDepan();
							system("pause");
							break;
						}
						case 2:{
							system("cls");
							cout<<"Node pada posisi belakang berhasil dihapus"<<endl;
							hapusDiBelakang();
							system("pause");
							break;
						}
						case 3:{
							cout<<"Hapus Node di tengah\n";
							cout<<"====================\n\n";
							cout<<"Masukkan nilai pada Node yang akan dihapus : ";cin>>hps;
							hapusDiTengah(hps);
							cout<<"Node dengan nilai "<<hps<<" berhasil dihapus...\n";
							system("pause");
							system("cls");
							break;
						}
					}
				}
				
			}
			else if(choice==4){
				if(head==NULL){
					system("cls");
					cout<<"Node belum tersedia...\n";
					system("pause");
				}else{
					system("cls");
					cout<<"Lish Data:\n";
					tampilData();
					cout<<endl<<" "<<endl;
					system("pause");
				}
			}
	}
	cout<<"Sampai Jumpa..."<<endl;
}
void ui(){
	system("cls");
	cout<<"Menu:\n";
	cout<<"1. Buat Node Awal\n";
	cout<<"2. Tambah Node\n";
	cout<<"3. Hapus Node\n";
	cout<<"4. Tampil Data\n";
	cout<<"5. Keluar\n";
	cout<<"Masukkan pilihan [1..5] :";
}
void ui1(){
	cout<<"Pilihan:\n";
	cout<<"1. Tambah Node di Depan\n";
	cout<<"2. Tambah Node di Belakang\n";
	cout<<"3. Tambah Node di Tengah\n";
	cout<<"4. Batal\n";
	cout<<"Masukkan pilihan [1..4] :";
}
void clearNode(){
	cout<<"Pilihan:\n";
	cout<<"1. Hapus Node di Depan\n";
	cout<<"2. Hapus Node di Belakang\n";
	cout<<"3. Hapus Node di Tengah\n";
	cout<<"4. Batal\n";
	cout<<"Masukkan pilihan [1..4] :";
}