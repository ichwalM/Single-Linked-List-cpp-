#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string nip;
    string alamat;
    Node *next;
    Node *prev;
};

Node *head = NULL, *tail = NULL, *n = NULL, *x = NULL;

void buatNodeBaru(string nama, string nip, string alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = NULL;
    n->prev = NULL;
    head = n;
    tail = n;
    cout << "dosen " << nama << " berhasil ditambahkan di awal.\n";
}

void tambahDiBelakang(string  nama, string  nip, string  alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->prev = tail;
    n->next = NULL;
    tail->next = n;
    tail = n;
    cout << "dosen " << nama << " berhasil ditambahkan di belakang.\n";
}

void tambahDiDepan(string  nama, string  nip, string  alamat) {
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;
    cout << "dosen " << nama << " berhasil ditambahkan di depan.\n";
}




void tambahDiTengah( string  nama, string  nip,   string  alamat,   string  after_nip) {
    x = head;
    while (x != NULL  && x->nip != after_nip) {
        x = x->next;
    }
    
    if (x == NULL) {
        cout << "dosen dengan NIP " << after_nip << " tidak ditemukan.\n";
        return;
    }
	
    n = new Node;
    n->nama = nama;
    n->nip = nip;
    n->alamat = alamat;
    n->next = x->next;
    n->prev = x;
    if (x->next != NULL) {
        x->next->prev = n;
    } else {
        tail = n;
    }
    x->next = n;
    cout << "Data dosen " << nama << " berhasil ditambahkan setelah NIP " << after_nip << ".\n";
	
}

void hapusDiDepan() {
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    cout << "dosen " << temp->nama << " berhasil dihapus depan.\n";
    delete temp;
}

void hapusDiBelakang() {
    Node *temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    cout << "Data dosen " << temp->nama << " berhasil dihapus dari belakang.\n";
    delete temp;
}

void hapusDiTengah(  string nip) {
    x = head;
    while (x != NULL && x->nip != nip) {
        x = x->next;
    }
    if (x == NULL) {
        cout << "dosen dengan NIP " << nip << " tidak ditemukan.\n";
        return;
    }
        x->prev->next = x->next;
        x->next->prev = x->prev;
        cout << "Data dosen " << x->nama << " berhasil dihapusd ditengah.\n";
        delete x;
}

void tampilDariDepan() {
    Node *temp = head;
    cout << "Data dosen dari depan:\n";
    while (temp != NULL) {
        cout <<"Nama: " << temp->nama << "\n";
		cout<<"NIP: " << temp->nip << "\n"; 
		cout<<"Alamat: " << temp->alamat << "\n\n";
        temp = temp->next;
    }
}

void tampilDariBelakang() {
    Node *temp = tail;
    cout << "Data dari belakang:\n";
    while (temp != NULL) {
        cout <<"Nama: " << temp->nama << "\n";
		cout<<"NIP: " << temp->nip << "\n"; 
		cout<<"Alamat: " << temp->alamat << "\n\n";
        temp = temp->prev;
    }
}

int main() {
    int pilihan, tambah, hapus, tampil;
    string nama, nip, alamat, after_nip;

    do {
        system("clear");
        cout << "Program Daftar Dosen Umi\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Dosen\n";
        cout << "3. Hapus Dosen\n";
        cout << "4. Tampilkan List Data Dosen\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Pilihan [1...5]: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
            	system("clear");
                if (head != NULL) {
                    cout << "Node Awal Sudah dibuat!" << endl;
                    system("sleep 2"); 
					break; 
                }
            	system("clear");
                cout << "Masukkan nama: "; getline(cin, nama);
                cout << "Masukkan NIP: "; getline(cin, nip);
                cout << "Masukkan alamat: "; getline(cin, alamat);
                buatNodeBaru(nama, nip, alamat);
                system("sleep 2");
                break;
            case 2:
                system("clear");
                if (head == NULL) {
                    cout << "Node Awal Belum ada, tolong dibuat terlebih dahulu!" << endl;
                    system("sleep 2");  
                    break;
                }
                do{
				system("clear");
                cout << "Tambah Data Dosen" << endl;
                cout << "1. Tambah depan" << endl;
                cout << "2. Tambah tengah" << endl;
                cout << "3. Tambah belakang" << endl;
                cout << "4. Batal" << endl;
                cout << "Pilih [1..4]: ";
				cin>>tambah;
				cin.ignore();
        
                switch (tambah) {
                    case 1:
                    	system("clear");
                        cout << "Masukkan nama: "; getline(cin, nama);
                		cout << "Masukkan NIP: "; getline(cin, nip);
                		cout << "Masukkan alamat: "; getline(cin, alamat);
                        tambahDiDepan(nama, nip, alamat);
                        system("sleep 2");
						  
                        break;
                    case 2:
                    	if(head == tail){
				        system("clear");
						cout<<"Masukkan node minimal 2 dan node tidak boleh di posisi belakang.\n";
						system("sleep 2");
						break;
						}
                    	system("clear");
                    	cout << "Masukkan NIP setelah dosen yang akan ditambahkan: ";
						getline(cin, after_nip);
						
						if(tail->nip == after_nip){
						system("clear");
						cout<<"Node tidak boleh ditambahkan setelah node dengan NIP terakhir (tail).\n";
						system("sleep 2");
						break;
						}
						
                        cout << "Masukkan nama: "; getline(cin, nama);
		                cout << "Masukkan NIP: "; getline(cin, nip);
		                cout << "Masukkan alamat: "; getline(cin, alamat);
		                tambahDiTengah(nama, nip, alamat, after_nip);
                        system("sleep 2");
                    	
                        break;
                    case 3:
                    	system("clear");
                        cout << "Masukkan nama: "; getline(cin, nama);
		                cout << "Masukkan NIP: "; getline(cin, nip);
		                cout << "Masukkan alamat: "; getline(cin, alamat);
		                tambahDiBelakang(nama, nip, alamat);
		                system("sleep 2"); 
                        break;
                    case 4:
                    	system("clear");
                        cout << "Batal, kembali ke menu utama." << endl;
                        system("sleep 2");
                        break;
                    default:
                      cout<<"Masukkan tidak valid"<<endl;
                   	system("sleep 2");
                	}
                }while(tambah != 4);
                break;
            case 3:
                system("clear");
                if (head == NULL) {
                    cout << "Node Awal Belum ada, tolong dibuat terlebih dahulu!" << endl;
                    system("sleep 2"); 
                    break;
                }
                do{
				system("clear");
                cout << "Hapus Data Dosen\n";
                cout << "1. Hapus depan\n";
                cout << "2. Hapus tengah\n";
                cout << "3. Hapus belakang\n";
                cout << "4. Batal" << endl;
                cout << "Pilihan [1..4]: ";
				cin>>hapus;
				cin.ignore();
                switch (hapus) {
                    case 1:
                    	system("clear");
                        hapusDiDepan();
                        system("sleep 2"); 
                        break;
                    case 2:
                    	system("clear");
                        cout << "Masukkan NIP dosen dihapus: "; 
						getline(cin, nip);
                		hapusDiTengah(nip);
                        system("sleep 2");
                        break;
                    case 3:
                    	system("clear");
                        hapusDiBelakang();
                        system("sleep 2");
                        break;
                    case 4:
                    	system("clear");
                        cout << "Batal, kembali ke menu utama." << endl;
                        system("sleep 2");
                        break;
                    default:
                    	system("clear");
                    cout<<"Masukkan tidak valid"<<endl;
                    system("sleep 2");
                	}
                }while(hapus != 4);
                break;
            case 4:
            	system("clear");
                if (head == NULL) {
                    cout << "Linked List kosong, tekan Enter untuk kembali ke menu..." << endl;
                    system("sleep 2"); 
                    break;
                }
                do{
                system("clear");
                cout << "Tampil data Dosen: \n";
                cout<<"1. Tampil dari depan\n";
                cout<<"2. Tampil dari belakang\n";
                cout<<"3. Batal\n";
                cout<<"Masukkan pilihan [1..3]: ";
                cin>>tampil;
                switch(tampil){
                	case 1:
                		system("clear");
                		cout<<"Tampil dari depan\n\n";
                		tampilDariDepan();
                		system("sleep 2");
                		break;
                	case 2:
                		system("clear");
                		cout<<"Tampil dari Belakang\n\n";
                		tampilDariBelakang();
                		system("sleep 2");
                		break;
                	case 3:
                		system("clear");
                		cout << "Batal, kembali ke menu utama." << endl;
                        system("sleep 2");
                        break;
                    default:
                    	system("clear");
                   	cout<<"Masukkan tidak valid"<<endl;
                   	system("sleep 2");
					}
				}while(tampil != 3);	
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
