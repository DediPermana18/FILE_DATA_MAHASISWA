#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double nilairataUAS(double Mtk, double BIn, double Big, double IPA) {
    return (Mtk * 0.4) + (IPA * 0.3) + (BIn * 0.2) + (Big * 0.2);
}
double nilairataUTS(double Mtk, double BIn, double Big, double IPA) {
    return (Mtk * 0.4) + (IPA * 0.3) + (BIn * 0.2) + (Big * 0.2);
}
double nilairataTUGAS(double Mtk, double BIn, double Big, double IPA) {
    return (Mtk * 0.4) + (IPA * 0.3) + (BIn * 0.2) + (Big * 0.2);
}

double nilairataTOTAL(double nilairataUTS, double nilairataUAS, double nilairataTUGAS) {
    return (nilairataUAS * 0.4) + (nilairataUTS * 0.35) + (nilairataTUGAS * 0.25);
}

struct tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct nilai_mapel {
    double Mtk;
    double BIn;
    double Big;
    double IPA;
};

struct nilai_mahasiswa {
    nilai_mapel uas;
    nilai_mapel uts;
    nilai_mapel tugas;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    int NISN;
    tanggal lahir;
    nilai_mahasiswa nilaiMhs;
    double nilaiAkhir;
};

int jumlahMahasiswa() {
    int jumlahMhs;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMhs;
    cout << endl;
    return jumlahMhs;
}

void tambahDataSiswa(Mahasiswa &mhs) {
    cin.ignore();
    cout << "Masukkan nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan umur: ";
    cin >> mhs.umur;
    cin.ignore();
    cout << "Masukkan jurusan: ";
    getline(cin, mhs.jurusan);
    cout << "Masukkan NISN: ";
    cin >> mhs.NISN;
    cout << endl;
}

void TambahTanggalLahirSiswa(tanggal &tgl) {
    cout << "Masukkan tanggal lahir: " << endl;  
    cout << "Tanggal: ";
    cin >> tgl.hari;
    cout << "Bulan: ";
    cin >> tgl.bulan;
    cout << "Tahun: ";
    cin >> tgl.tahun;
    cout << endl;
}

void TambahNilaiSiswa(Mahasiswa &mhs) {
    cout << "--- Input Nilai UAS ---" << endl;
    cout << "MTK: "; cin >> mhs.nilaiMhs.uas.Mtk;
    cout << "IPA: "; cin >> mhs.nilaiMhs.uas.IPA;
    cout << "B.Indonesia: "; cin >> mhs.nilaiMhs.uas.BIn;
    cout << "B.Inggris: "; cin >> mhs.nilaiMhs.uas.Big;
    
    cout << "--- Input Nilai UTS ---" << endl;
    cout << "MTK: "; cin >> mhs.nilaiMhs.uts.Mtk;
    cout << "IPA: "; cin >> mhs.nilaiMhs.uts.IPA;
    cout << "B.Indonesia: "; cin >> mhs.nilaiMhs.uts.BIn;
    cout << "B.Inggris: "; cin >> mhs.nilaiMhs.uts.Big;

    cout << "--- Input Nilai Tugas ---" << endl;
    cout << "MTK: "; cin >> mhs.nilaiMhs.tugas.Mtk;
    cout << "IPA: "; cin >> mhs.nilaiMhs.tugas.IPA;
    cout << "B.Indonesia: "; cin >> mhs.nilaiMhs.tugas.BIn;
    cout << "B.Inggris: "; cin >> mhs.nilaiMhs.tugas.Big;
    cout << endl;

}

void nilaimapel(const Mahasiswa &mhs, ostream &file = cout) {  
    file << "| --- UAS ---" << endl;
    file << "| MTK        : " << mhs.nilaiMhs.uas.Mtk << " * 40% --> " << mhs.nilaiMhs.uas.Mtk * 0.4 << endl;
    file << "| IPA        : " << mhs.nilaiMhs.uas.IPA << " * 30% --> " << mhs.nilaiMhs.uas.IPA * 0.3 << endl;
    file << "| B.Indonesia: " << mhs.nilaiMhs.uas.BIn << " * 20% --> " << mhs.nilaiMhs.uas.BIn * 0.2 << endl;
    file << "| B.Inggris  : " << mhs.nilaiMhs.uas.Big << " * 20% --> " << mhs.nilaiMhs.uas.Big * 0.2 << endl;
    file << "|" << endl;

    file << "| --- UTS ---" << endl;
    file << "| MTK        : " << mhs.nilaiMhs.uts.Mtk << " * 40% --> " << mhs.nilaiMhs.uts.Mtk * 0.4 << endl;
    file << "| IPA        : " << mhs.nilaiMhs.uts.IPA << " * 30% --> " << mhs.nilaiMhs.uts.IPA * 0.3 << endl;
    file << "| B.Indonesia: " << mhs.nilaiMhs.uts.BIn << " * 20% --> " << mhs.nilaiMhs.uts.BIn * 0.2 << endl;
    file << "| B.Inggris  : " << mhs.nilaiMhs.uts.Big << " * 20% --> " << mhs.nilaiMhs.uts.Big * 0.2 << endl;
    file << "|" << endl;

    file << "| --- TUGAS ---" << endl;
    file << "| MTK        : " << mhs.nilaiMhs.tugas.Mtk << " * 40% --> " << mhs.nilaiMhs.tugas.Mtk * 0.4 << endl;
    file << "| IPA        : " << mhs.nilaiMhs.tugas.IPA << " * 30% --> " << mhs.nilaiMhs.tugas.IPA * 0.3 << endl;
    file << "| B.Indonesia: " << mhs.nilaiMhs.tugas.BIn << " * 20% --> " << mhs.nilaiMhs.tugas.BIn * 0.2 << endl;
    file << "| B.Inggris  : " << mhs.nilaiMhs.tugas.Big << " * 20% --> " << mhs.nilaiMhs.tugas.Big * 0.2 << endl;
    file << "|" << endl;
}

void bobotNilai(double nilairataUTS, double nilairataUAS, double nilairataTUGAS, ostream &file = cout) {
    file << "| UAS   : " << nilairataUAS << " * 40% --> " << nilairataUAS * 0.4 << endl;
    file << "| UTS   : " << nilairataUTS << " * 35% --> " << nilairataUTS * 0.35 << endl;
    file << "| Tugas : " << nilairataTUGAS << " * 25% --> " << nilairataTUGAS * 0.25 << endl;
    file << "|" << endl;
}

void tampilDataSiswa(const Mahasiswa &mhs, ostream &file = cout) {
    file << "\n|======== DATA MAHASISWA ========" << endl;
    file << "| --- identitas ---" << endl;
    file << "| Nama   : " << mhs.nama << endl;
    file << "| Umur   : " << mhs.umur << endl;
    file << "| Jurusan: " << mhs.jurusan << endl;
    file << "| NISN   : " << mhs.NISN << endl;
    file << "|" << endl;
    file << "| --- Tanggal Lahir ---" << endl;
    file << "| tanggal " << mhs.lahir.hari << " /bulan " << mhs.lahir.bulan << " /tahun " << mhs.lahir.tahun << endl;
    file << "|" << endl;
    file << "|============ Nilai ============" << endl;

    nilaimapel(mhs, file);
    
    double rataUAS = nilairataUAS(mhs.nilaiMhs.uas.Mtk, mhs.nilaiMhs.uas.BIn, mhs.nilaiMhs.uas.Big, mhs.nilaiMhs.uas.IPA);
    double rataUTS = nilairataUTS(mhs.nilaiMhs.uts.Mtk, mhs.nilaiMhs.uts.BIn, mhs.nilaiMhs.uts.Big, mhs.nilaiMhs.uts.IPA);
    double rataTugas = nilairataTUGAS(mhs.nilaiMhs.tugas.Mtk, mhs.nilaiMhs.tugas.BIn, mhs.nilaiMhs.tugas.Big, mhs.nilaiMhs.tugas.IPA);
    file << "| --- Bobot Nilai ---" << endl;
    bobotNilai(rataUTS, rataUAS, rataTugas, file);
    file << "| --- Rata-rata ---" << endl;
    file << "| Nilai Rata-rata Akhir: " << nilairataTOTAL(rataUTS, rataUAS, rataTugas) << endl;
    file << "|================================" << endl;
}

void simpanKeFile(const Mahasiswa &mhs, int index) {
    string namaFile = "mahasiswa_" + to_string(index + 1) + ".txt";
    ofstream file(namaFile);
    if (file.is_open()) {
        tampilDataSiswa(mhs, file);
        file.close();
        cout << " Data mahasiswa ke-" << index + 1 << " disimpan di file: " << namaFile << endl;
    } else {
        cout << " Gagal menyimpan data ke file." << endl;
    }
}

void bukaFile(int index) {
    string namaFile = "mahasiswa_" + to_string(index + 1) + ".txt";
    ifstream file(namaFile);
    if (file.is_open()) {
        cout << "=-- ISI FILE " << namaFile << " --=" << endl;
        string baris;
        while (getline(file, baris)) {
            cout << baris << endl;
        }
        file.close();
    } else {
        cout << "File tidak ditemukan." << endl;
    }
}
void simpanRanking(Mahasiswa mhs[], int jumlah) {
    double nilaiAkhir[jumlah];
    for (int i = 0; i < jumlah; i++) {
        double rataUTS = nilairataUTS(mhs[i].nilaiMhs.uts.Mtk, mhs[i].nilaiMhs.uts.BIn, mhs[i].nilaiMhs.uts.Big, mhs[i].nilaiMhs.uts.IPA);
        double rataUAS = nilairataUAS(mhs[i].nilaiMhs.uas.Mtk, mhs[i].nilaiMhs.uas.BIn, mhs[i].nilaiMhs.uas.Big, mhs[i].nilaiMhs.uas.IPA);
        double rataTugas = nilairataTUGAS(mhs[i].nilaiMhs.tugas.Mtk, mhs[i].nilaiMhs.tugas.BIn, mhs[i].nilaiMhs.tugas.Big, mhs[i].nilaiMhs.tugas.IPA);
        nilaiAkhir[i] = nilairataTOTAL(rataUTS, rataUAS, rataTugas);
        mhs[i].nilaiAkhir = nilaiAkhir[i];
    }

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (nilaiAkhir[j] > nilaiAkhir[i]) {
                swap(nilaiAkhir[i], nilaiAkhir[j]);
                swap(mhs[i], mhs[j]);
            }
        }
    }

    ofstream file("ranking_mahasiswa.txt");
    if (file.is_open()) {
        file << "==============================\n";
        file << "   DAFTAR RANKING MAHASISWA\n";
        file << "==============================\n";

        for (int i = 0; i < jumlah; i++) {
            file << "Ranking ke-" << i + 1 << endl;
            file << "Nama        : " << mhs[i].nama << endl;
            file << "NISN        : " << mhs[i].NISN << endl;
            file << "Umur        : " << mhs[i].umur << endl;
            file << "Jurusan     : " << mhs[i].jurusan << endl;
            file << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
            file << "----------------------------------" << endl;
        }

        file.close();
        cout << "\nFile ranking disimpan ke: ranking_mahasiswa.txt" << endl;
    } else {
        cout << "Gagal membuat file ranking.";
    }
}
void tampilkanSemua(Mahasiswa mhs[], int jumlah) {
    cout << "\nData Mahasiswa:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << mhs[i].nama << endl;
    }
    cout << jumlah + 1 << ". Keluar" << endl;
}

void cariSiswa(Mahasiswa mhs[], int jumlah) {
    int cari;
    cout << "Masukkan NISN yang dicari: ";
    cin >> cari;
    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].NISN == cari) {
            cout << "Data ditemukan!";
            tampilDataSiswa(mhs[i]);
            ketemu = true;
            break;
        }
    }
    if (!ketemu) cout << "NISN tidak ditemukan.";
}

void ranking(Mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        double rataUTS = nilairataUTS(mhs[i].nilaiMhs.uts.Mtk, mhs[i].nilaiMhs.uts.BIn, mhs[i].nilaiMhs.uts.Big, mhs[i].nilaiMhs.uts.IPA);
        double rataUAS = nilairataUAS(mhs[i].nilaiMhs.uas.Mtk, mhs[i].nilaiMhs.uas.BIn, mhs[i].nilaiMhs.uas.Big, mhs[i].nilaiMhs.uas.IPA);
        double rataTugas = nilairataTUGAS(mhs[i].nilaiMhs.tugas.Mtk, mhs[i].nilaiMhs.tugas.BIn, mhs[i].nilaiMhs.tugas.Big, mhs[i].nilaiMhs.tugas.IPA);
        mhs[i].nilaiAkhir = nilairataTOTAL(rataUTS, rataUAS, rataTugas);
    }

    Mahasiswa *copy = new Mahasiswa[jumlah];
    for (int i = 0; i < jumlah; ++i) copy[i] = mhs[i];

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (copy[j].nilaiAkhir < copy[j + 1].nilaiAkhir)
                swap(copy[j], copy[j + 1]);
        }
    }

    cout << "\n=== RANKING MAHASISWA ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << copy[i].nama
             << " (NISN: " << copy[i].NISN
             << ", Nilai Akhir: "
             << copy[i].nilaiAkhir << ")" << endl;
    }

    delete[] copy;
}

int main() {
    int jumlahMhs = jumlahMahasiswa();
    Mahasiswa mhs[jumlahMhs];

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "##===== Input Mahasiswa ke-" << i + 1 << " =====##" << endl;
        tambahDataSiswa(mhs[i]);
        TambahTanggalLahirSiswa(mhs[i].lahir);
        TambahNilaiSiswa(mhs[i]);
        simpanKeFile(mhs[i], i);
    }

    int pilihan;
    do {
        cout << "\n|====================|" << endl;
        cout << "|--- MENU PILIHAN ---|" << endl;
        cout << "|====================|" << endl;
        cout << "1. Lihat data dari file" << endl;
        cout << "2. Cari siswa berdasarkan NISN" << endl;
        cout << "3. Lihat ranking siswa" << endl;
        cout << "4. Simpan ranking ke file" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                tampilkanSemua(mhs, jumlahMhs);
                int pilih;
                cout << "Pilih file mahasiswa yang ingin dibuka: ";
                cin >> pilih;
                if (pilih >= 1 && pilih <= jumlahMhs) bukaFile(pilih);
                else cout << "Pilihan tidak valid.";
                break;
            }
            case 2:
                cariSiswa(mhs, jumlahMhs);
                break;
            case 3:
                ranking(mhs, jumlahMhs);
                break;
            case 4:
                simpanRanking(mhs, jumlahMhs);
                break;
            case 5:
                cout << "Keluar dari program.";
                break;
            default:
                cout << "Pilihan tidak valid!";
        }
    } while (pilihan != 5);

    return 0;
}