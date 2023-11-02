#include <iostream>
#define BUNGA 0.01
#include <windows.h>
#include <iomanip>

using namespace std;
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int main()
{
	int kode, kode2, setor, saldo;
	saldo = 0;
	char lagi;
	string pass;
	int tarik[2] = { 50000,100000 };

	cout << "SIAPKAN PIN ANDA . . . . .\n\n\n";
	for (int i = 1; i <= 12; i++) {//untuk memberi waktu loading menyiapkan pin
		Sleep(100);
	}
	SetColor(6);
	cout << " ----------------------------------------\n";
	cout << "|         SIMULASI ATM BANK KITA         | " << endl;
	cout << " ----------------------------------------\n\n\n";

	do {
		cout << "Masukkan Pin: ";
		cin >> pass;
		system("cls");

		while (pass == "123456")//NOMOR PIN ATM: 123456
		{
			if (lagi == 'T' || lagi == 't')//ctt: Jika ditemukan 'lagi' bermasalah saat debug, ignore/abaikan saja
				goto keluar;

			SetColor(14);
			//MENU UTAMA PILIHAN TRANSAKSI PADA ATM
			cout << "                  ATM BANK   " << endl;
			cout << "============================================" << endl;
			cout << endl;
			cout << "____________________________________________" << endl;
			cout << "                    MENU" << endl;
			cout << endl;
			cout << "1. Cek Saldo                3. Setoran Tunai" << endl;
			cout << endl;
			cout << "2. Penarikan Saldo          4. Exit" << endl;
			cout << "____________________________________________" << endl;
			cout << endl;
			cout << "MASUKKAN PILIHAN ANDA : ";
			cin >> kode;
			system("cls");


			switch (kode)

			{

			case 1://CEK SALDO
				cout << endl;
				cout << " _______________________________" << endl;
				cout << "|        Informasi Saldo        |" << endl;
				cout << "|_______________________________|" << endl;
				cout << "						          " << endl;
				cout << " Jumlah Saldo Anda: Rp. " << saldo << endl;
				cout << " _______________________________ " << endl;
				cout << "APAKAH INGIN MELAKUKAN TRANSAKSI LAGI Y/T ; ";
				cin >> lagi;
				system("cls");
				break;

			case 2://MENU PENARIKAN SALDO
				cout << "             Penarikan Saldo " << endl;
				cout << "============================================" << endl;
				cout << "\tSaldo anda saat ini: Rp. " << saldo << endl;
				cout << "____________________________________________" << endl;
				cout << "      PILIH JUMLAH PENARIKAN TUNAI" << endl;
				cout << endl;
				cout << "1. Rp. 50.000             2. Rp. 100.000" << endl;
				cout << "\n\n\n";


				cout << "____________________________________________" << endl;
				cout << endl;
				cout << "MASUKKAN PILIHAN ANDA : ";
				cin >> kode2;
				system("cls");

				switch (kode2)
				{

				case 1://PENARIKAN SALDO SENILAI 50.000
					if ((saldo - tarik[0]) >= 0) {   //Jika saldo cukup, maka penarikan saldo berhasil
						cout << "\t\tPenarikan Berhasil";
						cout << "\n\n\n";


						cout << "Anda melakukan penarikan tunai senilai : Rp. 50.000,-" << endl;
						saldo = saldo - tarik[0];
						cout << endl;
						cout << "Sisa Saldo          : Rp. " << saldo << ",-";
						cout << endl;
						cout << endl;
						cout << "APAKAH INGIN MELAKUKAN TRANSAKSI LAGI Y/T ; ";
						cin >> lagi;
						system("cls");
						break;
					}
					else {   //Jika saldo tidak cukup, maka penarikan saldo gagal
						cout << "Saldo anda tidak mencukupi" << endl;
						cout << "\n\n";
						cout << "APAKAH ANDA MASIH INGIN MELAKUKAN TRANSAKSI Y/T ; ";
						cin >> lagi;
						system("cls");
						break;
					}

				case 2://PENARIKAN SALDO SENILAI 100.000
					if ((saldo - tarik[1]) >= 0) {   //Jika saldo cukup, maka penarikan saldo berhasil
						cout << "\t\tPenarikan Berhasil";
						cout << "\n\n\n";


						cout << "Anda melakukan penarikan tunai senilai : Rp. 100.000,-" << endl;
						saldo = saldo - tarik[1];
						cout << endl;
						cout << "Sisa Saldo          : Rp. " << saldo << ",-";
						cout << endl;
						cout << "APAKAH INGIN MELAKUKAN TRANSAKSI LAGI Y/T ; ";
						cin >> lagi;
						system("cls");
						break;
					}
					else {   //Jika saldo tidak cukup, maka penarikan saldo gagal
						cout << "Saldo anda tidak mencukupi" << endl;
						cout << "\n\n";
						cout << "APAKAH ANDA MASIH INGIN MELAKUKAN TRANSAKSI Y/T ; ";
						cin >> lagi;
						system("cls");
						break;
					}

				default:
					cout << "KODE YANG ANDA MASUKKAN TIDAK TERSEDIA";
					system("cls");
				}
				break;

			case 3://MENU SETORAN TUNAI
				cout << "Setoran Tunai" << endl;
				cout << "\n\n\n";


				cout << "Masukkan Jumlah yang anda ingin setorkan : "; cin >> setor;
				saldo = setor * BUNGA + setor + saldo;
				cout << endl;
				cout << "Jumlah Saldo Anda Sekarang : " << saldo << endl;
				cout << "APAKAH ANDA INGIN MELAKUKAN TRANSAKSI LAGI Y/T ; ";
				cin >> lagi;
				system("cls");
				break;

			case 4://EXIT
				goto keluar;
				break;

			default:
				cout << "KODE YANG ANDA MASUKKAN TIDAK TERSEDIA";
				system("cls");

			}


		}
		//JIKA PIN YANG DIMASUKKAN SALAH
		cout << "Nomor Pin Yang Anda Masukkan Salah!" << endl;
		cout << endl;
		cout << "Silahkan Coba Lagi Y/T ; ";
		cin >> lagi;
		cout << endl;
		system("cls");




	} while (lagi == 'Y' || lagi == 'y');
keluar://AKHIR DARI TRANSAKSI ATM
	SetColor(6);
	cout << "\n\nTERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
	cout << "\n\n\n";

	system("pause");

	return 0;

}