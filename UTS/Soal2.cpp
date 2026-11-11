#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int skor;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(string nama, int skor) {
    Node *newNode = new Node();
    newNode->nama = nama;
    newNode->skor = skor;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(string nama, int skor) {
    Node *newNode = new Node();
    newNode->nama = nama;
    newNode->skor = skor;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    delete temp;
}

void printLolos() {
    cout << "Daftar Peserta Lolos (Skor >= 75):\n";
    Node *temp = head;
    while (temp != NULL) {
        if (temp->skor >= 75) {
            cout << "- " << temp->nama << " (Skor: " << temp->skor << ")\n";
        }
        temp = temp->next;
    }
}

int main() {
    int pilihan, skor;
    string nama;

    do {
        cout << "1. Tambah data di awal (Insert Head)\n";
        cout << "2. Tambah data di akhir (Insert Tail)\n";
        cout << "3. Hapus data di awal (Delete Head)\n";
        cout << "4. Tampilkan Peserta Lolos (Skor >= 75)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu [1-5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Skor: ";
                cin >> skor;
                insertFirst(nama, skor);
                break;

            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Skor: ";
                cin >> skor;
                insertLast(nama, skor);
                break;

            case 3:
                deleteFirst();
                break;

            case 4:
                printLolos();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}