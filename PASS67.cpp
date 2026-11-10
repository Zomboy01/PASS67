#include <iostream>
#include <cstdlib>
using namespace std;

// Deklarasi Variabel
string password[100];
string username[100];
string kategori[100];

string cari;
char yakin;
bool ditemukan = false;
int jumlahAkun = 0;
string pwutama;
int nomor;
string menu = "";


// fungsi pertama : bersihkan layar
void bersihkanLayar() {
    system("clear");
}

// fungsi kedua : pencet enter untuk kembali
void tungguEnter() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

// fungsi ketiga : tampilan menu
void tampilkanMenu (){
    cout << "1. Tambah Akun"
        "\n2. Lihat  Akun"
        "\n3. Cari Akun"
        "\n4. Edit Akun"
        "\n5. Hapus Akun"
        "\n6. Statistik Akun"
        "\n7. Keluar"
        "\n=================================\n"
        "Pilih menu (1-7) : ";
}

// fungsi keempat : tampilan judul
void tampilkanJudul(string judul) {
    cout << "=================================\n";
    cout << "             " << judul << "\n";
    cout << "=================================\n";
}


//fungsi kelima : cancel
bool cekcancel(string input){
    if (input == "0") {
        cout << "\nProses dibatalkan!\n";
        return true;
    }
    return false;
}
// fungsi keenam : verifikasi master password
bool verifPassword(string pwutama) {
    string input;
    cout << "Masukkan Password Utama : ";
    getline(cin >> ws, input);

    if (cekcancel(input)) {
        return false;
    }
    else if (input == pwutama) {
        return true;
    } else {
        cout << "\nMaster Password Salah! Akses Ditolak.\n";
        return false;
    }
}


// fungsi utama
int main() {
    // buat pw utama
    tampilkanJudul("Password Utama");
    cout << "Buat Master Password Pertama Anda : ";
    getline(cin >> ws, pwutama);
    cout << "Master Password Berhasil Dibuat!\n";
    tungguEnter();
    bersihkanLayar();

    // Menu Utama
    while (menu != "7") {
        tampilkanJudul("PASS67");
        tampilkanMenu();
        cin >> menu;
        bersihkanLayar();

        // Fitur Tambah Akun : Moh. Rizki
        if (menu == "1") {
            tampilkanJudul("Akun Baru");
            cout << "Ketik '0' untuk membatalkan\n";
            cout << "Masukan Username : "; getline(cin >> ws, username[jumlahAkun]);
            if (cekcancel(username[jumlahAkun])) {
                tungguEnter();
                bersihkanLayar();
                continue;
            }
            cout << "Masukan Password : "; getline(cin >> ws, password[jumlahAkun]);
            cout << "Masukan Kategori : "; getline(cin >> ws, kategori[jumlahAkun]);

            jumlahAkun++;
            cout << "Berhasil Menambahkan Akun!\n";
            tungguEnter();
            bersihkanLayar();

        }

        // Fitur Lihat Daftar Akun : Ahmad Dani
        else if (menu == "2") {
            tampilkanJudul("Daftar Akun");
            if (verifPassword(pwutama)) {
                if (jumlahAkun==0){
                    cout << "Tidak ada akun";
                }
                else{
                    for (int no = 0; no < jumlahAkun; no++){
                        cout << "No." << no + 1 
                            << "\nUsername : " << username[no]
                            << "\nPassword : " << password[no]
                            << "\nKategori : " << kategori[no]
                            << "\n==============================\n";
                    }
                }
                tungguEnter();
                bersihkanLayar();
            }
            else {
            tungguEnter();
            bersihkanLayar();
            }
        }

        // Fitur Cari Akun : Gadafi
        else if (menu == "3") {
            tampilkanJudul("Cari Akun");
            if (verifPassword(pwutama)) {
                bool ditemukan = false;

                cout << "Masukkan Username yang dicari : ";
                getline(cin >> ws, cari);

                for (int posisi = 0; posisi < jumlahAkun; posisi++) {
                    if (username[posisi] == cari) {
                        cout << "\nAkun Ditemukan!\n";
                        cout << "Username : " << username[posisi] << endl;
                        cout << "Password : " << password[posisi] << endl;
                        cout << "Kategori : " << kategori[posisi] << endl;

                        ditemukan = true;
                        break;
                    }
                }

                if (ditemukan == false) {
                    cout << "\nAkun tidak ditemukan!\n";
                }
                tungguEnter();
                bersihkanLayar();
            }
            else {
            tungguEnter();
            bersihkanLayar();
            }
        }

        // Fitur Edit Akun  : Chalista
        else if (menu == "4") {
            tampilkanJudul("Edit Akun");
            if (verifPassword(pwutama)) {
                // Cek jumlahAkun
                if (jumlahAkun == 0) {
                    cout << "Tidak ada akun\n";
                    tungguEnter();
                    bersihkanLayar();
                }

                else {
                    // Tampilkan list akun
                    for (int list = 0; list < jumlahAkun; list++) {
                        cout << "Nomor : " << list + 1 << "\n"
                             << "Username : " << username[list] << "\n"
                             << "===========================\n";
                    }

                    // Input Nomor Akun yang ingin di edit
                    cout << "Masukan nomor akun yang ingin di edit (ketik '0' untuk membatalkan) : ";
                    cin >> nomor;

                    // cek apakah user ingin membatalkan
                    if (cekcancel(to_string(nomor))) {
                        tungguEnter();
                        bersihkanLayar();
                    }
                    // Input Data Akun yang baru
                    else if (nomor > 0 && nomor <= jumlahAkun) {
                        cout << "Masukan username baru : "; getline(cin >> ws, username[nomor-1]);
                        cout << "Masukan password baru : "; getline(cin >> ws, password[nomor-1]);
                        cout << "Masukan kategori baru : "; getline(cin >> ws, kategori[nomor-1]);
                        cout << "Akun berhasil di edit!\n";
                        tungguEnter();
                        bersihkanLayar();
                    }
                    else {
                        cout << "nomor akun tidak di temukan!\n ";
                        tungguEnter();
                        bersihkanLayar();
                    }
                }
            }
            else {
            tungguEnter();
            bersihkanLayar();
            }
        }

        // Fitur Hapus Akun : Bilal Adi Jani
        else if (menu == "5") {
            tampilkanJudul("Hapus Akun");
            if (verifPassword(pwutama)) {
                if (jumlahAkun == 0) {
                    cout << "Tidak ada akun\n";
                    tungguEnter();
                    bersihkanLayar();
                }

                else {
                    for (int list = 0; list < jumlahAkun; list++) {
                        cout << "Nomor : " << list + 1 << "\n"
                             << "Username : " << username[list] << "\n"
                             << "===========================\n";
                    }
                    cout << "Masukan nomor akun yang ingin dihapus (ketik '0' untuk membatalkan) : ";
                    cin >> nomor;

                    if (cekcancel(to_string(nomor))) {
                        tungguEnter();
                        bersihkanLayar();
                    }

                    // ini untuk geser
                    else if (nomor >= 1 && nomor <= jumlahAkun) {
                        for (int posisi = nomor - 1; posisi < jumlahAkun - 1; posisi++) {
                            password[posisi] = password[posisi + 1];
                            username[posisi] = username[posisi + 1];
                            kategori[posisi] = kategori[posisi + 1];
                        }

                        jumlahAkun--;
                        cout << "Berhasil menghapus akun!\n";
                        tungguEnter();
                        bersihkanLayar();

                    } 

                    else {
                        cout << "Nomor akun tidak ditemukan!\n";
                        tungguEnter();
                        bersihkanLayar();
                    }
                }
            }
            else {
            tungguEnter();
            bersihkanLayar();
            }
        }

        // Fitur Statistik Akun : Jihan
        else if (menu == "6") {
            tampilkanJudul("Statistik Akun");
            cout << "Total Akun : " << jumlahAkun << " akun\n\n";

            if (jumlahAkun == 0) {
                cout << "Belum ada akun.\n";
            } else {
                for (int nomor = 0; nomor < jumlahAkun; nomor++) {
                    bool pernahDihitung = false;
                    for (int sebelumnya = 0; sebelumnya < nomor; sebelumnya++) {
                        if (kategori[nomor] == kategori[sebelumnya]) {
                            pernahDihitung = true;
                            break;
                        }
                    }

                    if (pernahDihitung == false) {
                        int total = 0;
                        for (int posisi = 0; posisi < jumlahAkun; posisi++) {
                            if (kategori[nomor] == kategori[posisi]) {
                                total = total + 1;
                            }
                        }
                        cout << kategori[nomor] << " : " << total << " akun\n";
                    }
                }
            }
            tungguEnter();
            bersihkanLayar();
        }
        else if (menu == "7") {
            tampilkanJudul("YAKIN?");
            cout << "Apakah yakin ingin Keluar!? Y/N : "; cin >> yakin;
            if (yakin == 'Y' || yakin == 'y') {
                bersihkanLayar();
                cout << 
                    "⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠉⠉⠀⠀⠉⠙⢿⣿⣿⣿⣿⣿⡿⠛⠉⠁⢀⣀⠈⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⠋⠀⢀⣤⣶⣶⣶⣦⡀⠀⢹⣿⣿⣿⠋⠀⣠⣶⣿⣿⣿⣿⣷⣆⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⡇⠀⢰⣿⣿⣿⣿⣿⣿⣇⠀⢸⣿⣿⠁⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⡄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⠁⠀⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⢿⡇⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⡄⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠈⠃⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣇⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣄⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣧⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⡿⠷⠄⠀⠹⣿⣿⣿⣿⣿⣿⣿⣧⢸⣿⣿⣿⣿⣿⣿⣿⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⡿⠋⠀⣀⣤⣦⣄⡀⠘⢿⣿⣿⠟⢉⣠⣴⣶⣤⣈⠉⠻⣿⣿⣿⣆⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⠁⢀⣾⣿⣿⣿⣿⣿⣦⡀⠛⢁⣴⣿⣿⣿⣿⣿⣿⣿⣦⡈⣿⣿⣿⡀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⠿⢋⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠈⣿⣿⣇⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣇⠀⢸⣿⣿⣿⣿⠁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⡄⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⡄⠀⢿⣿⣿⣿⠀⢿⣿⣿⣿⣿⣿⣿⣿⡿⠟⢡⣾⠿⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣆⠀⠹⢿⣿⣷⣤⣉⡛⠛⠛⣛⣛⣩⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⡇⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⣉⠛⠛⢋⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⣈⡛⠿⠿⣿⣍⠻⠿⣿⣿⣿⣿⣿⡿⠿⠛⣁⣴⡏⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠈⢿⣿⣷⣶⣿⣿⣷⣶⣶⣶⣶⣶⣶⣾⣿⣿⠏⠀⣰⣿⠟⠉⠉⢻⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⡟⠉⠈⠛⢿⣿⣿⣿⣦⣀⠈⠛⠿⢿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠉⠀⣠⠾⠋⠀⠀⠀⢾⠟⠛⢿⣿⣿⣿\n"
                    "⣿⣿⡿⠋⠀⢀⡄⠀⢠⡟⠛⠛⡿⠻⣿⣶⣤⣤⣀⣀⣀⣀⣀⣀⠀⠤⣤⡆⠉⠻⡆⠀⢰⣦⡀⠀⠀⠠⣶⡟⠉⠙\n"
                    "⡿⠋⠀⢀⡀⠀⠀⣠⣾⡆⠀⠸⠃⠀⡀⠀⠀⠉⠉⢹⣿⣿⡇⠀⠀⡀⠈⢳⣤⡀⠀⠀⠈⢿⣿⣦⡀⠀⠀⠀⢀⣴\n"
                    "⡀⠀⠀⠛⠃⠀⢀⣿⣿⠇⠀⠀⣠⣾⡇⠀⠰⠷⢶⣾⠿⠿⢷⠀⠀⠋⠀⠀⠿⣿⣷⣄⠀⠈⢻⣿⣿⣦⣤⣶⣿⣿\n"
                    "⣿⣷⣦⣤⣤⣴⣾⣿⠟⠀⠀⣼⣿⣿⠀⠀⣀⣀⣸⣇⣀⣀⣴⡄⠀⠰⣦⠀⠀⢸⣿⣿⣆⠀⢀⣹⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣀⠀⣸⣿⣿⡏⠀⠀⠙⠛⠈⢻⣿⣿⣿⡇⠀⠀⠉⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
                    "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣤⣤⣿⣿⣿⣿⣷⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
                return 0;
            }
            else {
                menu = "0";
                tungguEnter();
                bersihkanLayar();
            }
        }
        else {
            cout << "Pilihan menu tidak valid!\n";
            tungguEnter();
            bersihkanLayar();
        }

    }
}
