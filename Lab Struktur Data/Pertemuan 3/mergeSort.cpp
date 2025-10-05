#include <iostream>
#include <vector>
using namespace std;

// Fungsi merge untuk menggabungkan dua bagian array yg sudah terurut sebelumnya
void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  // Jumlah elemen bagian kiri
    int n2 = right - mid;    // Jumlah elemen bagian kanan


    vector<int> L(n1), R(n2); // Array sementara untuk kiri dan kanan

    // Menyalin isi array dari parameter ke array sementaranya
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    // Inisialisasi indeksnya
    int i = 0;    
    int j = 0;      
    int k = left;

    // Proses penggabungan array-nya
    while (i < n1 && j < n2) { // akan terus jalan selama masih ada elemen dalam 2 array ini
        if (L[i] <= R[j]) { // akan jalan kalau elemen di array kiri lebih kecil atau sama dnegan yg di array kanan
            arr[k] = L[i]; // elemen array kiri akan dimasukkan ke array kiri
            i++;
        } else { // akan jalan kalau elemen array kanan lebih kecil
            arr[k] = R[j]; // elemen array kanan akan dimasukkan ke array kiri
            j++;
        }
        k++; // tiap masukkan nilai, maka lanjut ke indeks berikutnya
    }


    while (i < n1) { // akan jalan selama masih ada elemen di array kiri
        arr[k] = L[i]; // masukkan elemen di array kiri, ke array yg udah digabung tadi
        i++;
        k++;
    }


    while (j < n2) { // akan jalan selama masih ada elemen di array kanan
        arr[k] = R[j]; // masukkan elemen di array kanan ke array yg udah digabung tadi juga
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right) // akan jalan kalau indeks awal sama atau melewati indeks akhir
        return; // kalau iya, fungsi mergeSort akan langsung selesai, dan gak jalanin blok kode dibawahnya lagi karena udah dianggap terurut


    int mid = left + (right - left) / 2; // nyari titik tengah untuk bagi array jadi 2 bagian, kanan dan kiri


    mergeSort(arr, left, mid); // lakuin rekursi untuk ngurutin bagian array sebelah kiri dulu
    mergeSort(arr, mid + 1, right); // rekursi juga untuk ngurutin sebelah kanan array-nya
   
    // setelah kanan dan kiri udah diurutin, maka digabungin deh jadi 1 array yg udah berurut
    merge(arr, left, mid, right);
}

// Fungsi untuk nampilin tiap elemen array-nya
void printArray(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: "; // masukin jumlah elemen yg diinginkan user
    cin >> n;
   
    vector<int> data(n); // buat vektor atau array yg namanya 'data' dengan panjang 'n'
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    // nampilin array pas belum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data); 
   
    // ngurutin array-nya
    mergeSort(data, 0, n - 1);
   
    // nampilin array yg udah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}