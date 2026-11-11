#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

// Membuat node baru
Node* buatNode(int data) {
    Node* baru = new Node;

    baru->data = data;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

// TODO : Memasukkan data ke Binary Search Tree
Node* insert(Node* akar, int data) {

    // Jika posisi kosong, maka akan buat node baru
    if(akar == NULL){
        return buatNode(data);
    }

    if(data < akar->data){
        akar->kiri = insert(akar->kiri, data);
    }

    else if(data > akar->data){
        akar->kanan = insert(akar->kanan, data);
    }
    return akar;
}

// TODO : In-order (Kiri - Root - Kanan)
void inOrder(Node* akar) {
    if(akar != NULL){
        inOrder(akar->kiri);
        cout << akar->data << " ";
        inOrder(akar->kanan);
    }
}

// Nilai terkecil
int nilaiTerkecil(Node* akar) {
    Node* cur = akar;
    while (cur->kiri != NULL) {
        cur = cur->kiri;
    }
    return cur->data;
}

// Nilai terbesar
int nilaiTerbesar(Node* akar) {
    Node* cur = akar;
    while (cur->kanan != NULL) {
        cur = cur->kanan;
    }
    return cur->data;
}

int main() {

    Node* akar = NULL;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti):\n";

    while (true) {

        cout << "Input: ";
        cin >> angka;

        if(angka == 0){
            break;
        }

        akar = insert(akar, angka);
    }

    cout << "\nHasil Traversal:\n";

    cout << "\nData (In-order)   : ";
    inOrder(akar);

    cout << "\nNilai Terkecil    : " << nilaiTerkecil(akar);
    cout << "\nNilai Terbesar    : " << nilaiTerbesar(akar);
    cout << endl;

    return 0;
}