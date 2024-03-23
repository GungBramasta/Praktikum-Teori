#include <stdio.h>

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

int kabisat(int tahun) {
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0))
        return 1; 
    else
        return 0; 
}

int cekhari(int bulan, int tahun) {
    switch(bulan) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (kabisat(tahun))
                return 29;
            else
                return 28;
        default:
            return -1; 
    }
}

struct Tanggal besok(struct Tanggal tgl) {
    struct Tanggal besok;
    besok.hari = tgl.hari;
    besok.bulan = tgl.bulan;
    besok.tahun = tgl.tahun;
    
    if (besok.hari == 28 && besok.bulan == 2 && kabisat(besok.tahun)) {
        besok.hari = 29;
    } else if (besok.hari == 29 && besok.bulan == 2 && !kabisat(besok.tahun)) {
        besok.hari = 1;
        besok.bulan = 3;
    } else if (besok.hari == 31 && besok.bulan == 12) {
        besok.hari = 1;
        besok.bulan = 1;
        besok.tahun++;
    } else if (besok.hari == cekhari(besok.bulan, besok.tahun)) {
        besok.hari = 1;
        besok.bulan++;
    } else {
        besok.hari++;
    }
    
    return besok;
}

int main() {
    struct Tanggal tgl, besok1;
    
    printf("Masukkan tanggal \ndd/mm/yyyy\n");
    scanf("%d/%d/%d", &tgl.hari, &tgl.bulan, &tgl.tahun);

    if (tgl.hari < 1 || tgl.hari > 31 || tgl.bulan < 1 || tgl.bulan > 12 || tgl.tahun < 1) {
        printf("Input tidak valid!\n");
        return 1;
    }
    
    if (tgl.hari > cekhari(tgl.bulan, tgl.tahun)) {
        printf("Input tanggal tidak valid!\n");
        return 1;
    }
    
    besok1 = besok(tgl);
    
    printf("\nTanggal besoknya adalah: %d/%d/%d\n", besok1.hari, besok1.bulan, besok1.tahun);
    
    return 0;
}