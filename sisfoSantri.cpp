#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Santri
{

public:
    string nama;
    int umur;
    string tempat_tinggal;
    string kitab;
    int syahriah;

    Santri *prev;
    Santri *next;
};

class doubleLL
{
public:
    Santri *head;
    Santri *tail;
    doubleLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(string namaSan, int umurSan, string asalSan, string kitabSan, int syahriahSan)
    {
        Santri *newSantri = new Santri;

        newSantri->nama = namaSan;
        newSantri->umur = umurSan;
        newSantri->tempat_tinggal = asalSan;
        newSantri->kitab = kitabSan;
        newSantri->syahriah = syahriahSan;
        newSantri->prev = nullptr;
        newSantri->next = head;

        if (head != NULL)
        {
            head->prev = newSantri;
        }
        else
        {
            tail = newSantri;
        }
        head = newSantri;
    }
    
    bool update(string namaOld, string namaSan, int umurSan, string asalSan, string kitabSan, int syahriahSan, int opsi)
    {
        Santri *now = head;
        while (now != nullptr)
        {
            if (now->nama == namaOld)
            {   
                string namaNow = now->nama;
                int umurNow = now->umur;
                string tempatNow = now->tempat_tinggal;
                string kitabNow = now->kitab;
                int syahriahNow = now->syahriah;

                switch (opsi)
                {
                case 1:
                    now->nama = namaSan;
                    now->umur = umurNow;
                    now->tempat_tinggal = tempatNow;
                    now->kitab = kitabNow;
                    now->syahriah = syahriahNow;
                    break;
                case 2:
                    now->nama = namaNow;
                    now->umur = umurSan;
                    now->tempat_tinggal = tempatNow;
                    now->kitab = kitabNow;
                    now->syahriah = syahriahNow;
                    break;
                case 3:
                    now->nama = namaNow;
                    now->umur = umurNow;
                    now->tempat_tinggal = asalSan;
                    now->kitab = kitabNow;
                    now->syahriah = syahriahNow;
                    break;
                case 4:
                    now->nama = namaNow;
                    now->umur = umurNow;
                    now->tempat_tinggal = tempatNow;
                    now->kitab = kitabSan;
                    now->syahriah = syahriahNow;
                    break;
                case 5:
                    now->nama = namaNow;
                    now->umur = umurNow;
                    now->tempat_tinggal = tempatNow;
                    now->kitab = kitabNow;
                    now->syahriah = syahriahSan;
                    break;
                default:
                    break;
                }
                return true;
            }
            now = now->next;
        }
        return false;
    }
    void deleteData(int posisi)
    {
        if (head == nullptr)
        {
            return;
        }
        Santri *now = head;
        int i = 1;

        while (i < posisi - 1 && now->next != nullptr)
        {
            now = now->next;
            i++;
        }
        if (now->next == nullptr)
        {
            return;
        }

        Santri *temp = now->next;
        now->next = temp->next;
        if (temp->next != nullptr)
        {
            temp->next->prev = now;
        }
        delete temp;
    }

    void display()
    {
        Santri *now = head;
        cout
            << left
            << setw(30)
            << "Nama"
            << left
            << setw(10)
            << "Umur"
            << left
            << setw(15)
            << "Asal"
            << left
            << setw(20)
            << "Nama Kitab"
            << left
            << setw(20)
            << "Tunggakan Syahriah"
            << endl;

        while (now != nullptr)
        {
            cout
                << left
                << setw(30)
                << now->nama
                << left
                << setw(10)
                << now->umur
                << left
                << setw(15)
                << now->tempat_tinggal
                << left
                << setw(20)
                << now->kitab
                << left
                << setw(20)
                << now->syahriah
                << endl;

            now = now->next;
        }
        cout << endl;
    }
};
int main()
{
    string namaSan, nama, kitab, tempat_tinggal;
    int umur, syahriah;
    int pilihan, length, counter = 0, iterate;
    char confirm = 'y';
    doubleLL list;
        list.add("Naila", 17, "sokaraja", "imrithi", 10000);
        list.add("Fajar", 14, "sokaraja", "jurumiyah", 5000);
        list.add("Ridho", 15, "sokaraja", "jurumiyah", 30000);
        list.add("Aisyah", 18, "sokaraja", "imrithi", 0);
        list.display();
    do
    {   

        cout << "\tSISTEM INFORMASI SANTRI PONPES AL BAROKAH WAL KHOER\t" << endl;
        cout << "1. Masukkan data santri" << endl;
        cout << "2. Melihat data santri" << endl;
        cout << "3. Hapus data santri" << endl;
        cout << "4. update data santri" << endl;
        cout << "5. Exit" << endl;
        cout << "Menu apa yang anda pilih ? :  ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            // masukkanData(sntr);
            cout << "Berapa data Santri yang ingin anda masukkan : ";
            cin >> iterate;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = counter; i < iterate; i++)
            {
                cout << "Masukkan Nama Santri-" << i + 1 << " : ";
                getline(cin, nama);
                cout << "Masukkan Umur Santri-" << i + 1 << " : ";
                cin >> umur;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Masukkan Tempat Asal Santri-" << i + 1 << " : ";

                getline(cin, tempat_tinggal);
                cout << "Masukkan Nama Kitab yang dipelajari Santri-" << i + 1 << " : ";

                getline(cin, kitab);
                cout << "Masukkan jumlah tunggakan syahriah bulan ini Santri-" << i + 1 << " : ";

                cin >> syahriah;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                list.add(nama, umur, tempat_tinggal, kitab, syahriah);
            }
            break;
        }
        case 2:
        {
            list.display();
            break;
        }
        case 3:
        {
            int posisi;
            cout << "Masukkan posisi data yang mau dihapus: ";
            cin >> posisi;
            list.deleteData(posisi);
            break;
        }
        case 4:
        {
            int opsiUpdate;

            cin.ignore();

            cout << "Masukkan data nama santri data yang mau diupdate: ";
            getline(cin, namaSan);
            cout << "\tdata apa yang mau diganti?\t" << endl;
            cout << "1. Nama" << endl;
            cout << "2. Umur" << endl;
            cout << "3. Asal Alamat" << endl;
            cout << "4. Kitab" << endl;
            cout << "5. Tunggakan Syahriah" << endl;
            // cin.ignore();
            cout << "pilih opsi : ";
            cin >> opsiUpdate;

            switch (opsiUpdate)
            {
            case 1:
                cout << "Masukkan nama Santri : ";
                cin >> nama;
                list.update(namaSan, nama, umur, tempat_tinggal, kitab, syahriah, 1);
                break;
            case 2:
                cout << "Masukkan Umur Santri : ";
                cin >> umur;
                list.update(namaSan, nama, umur, tempat_tinggal, kitab, syahriah, 2);
                break;
            case 3:
                cout << "Masukkan tempat tinggal Santri : ";
                cin >> tempat_tinggal;
                list.update(namaSan, nama, umur, tempat_tinggal, kitab, syahriah, 3);
                break;
            case 4:
                cout << "Masukkan kitab Santri : ";
                cin >> kitab;
                list.update(namaSan, nama, umur, tempat_tinggal, kitab, syahriah, 4);
                break;
            case 5:
                cout << "Masukkan syahriah Santri : ";
                cin >> syahriah;
                list.update(namaSan, nama, umur, tempat_tinggal, kitab, syahriah, 5);
                break;

            default:
                break;
            }
            break;
        }
        case 5:
        {
            confirm = 'y';
            return 0;
            break;
        }
        default:
            cout << "Pilihan yang anda pilih tidak ada di menu!" << endl;

            break;
        }
        // if (confirm == 'y')
        //     return 0;
        cout << endl;
        cout << "Apakah anda ingin kembali ke menu?(y/n)";
        cin >> confirm;
    } while (confirm == 'y');
}