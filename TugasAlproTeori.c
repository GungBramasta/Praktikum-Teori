#include <stdio.h>


void tampilkartu(char *kartu, int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        printf("%c ", kartu[i]);
    }
    printf("\n");
}


int JQK(char kartu)
{
    if (kartu == 'J')
    {
        return 11;
    }
    else if (kartu == 'Q')
    {
        return 12;
    }
    else if (kartu == 'K')
    {
        return 13;
    }
    else if (kartu == '1')
    {
        return 10;
    }
    else
        return kartu - '0';
}



int bubblesort(char *kartu, int panjang)
{
    int swaps = 0;
    for (int i = 0; i < panjang - 1; i++)
    {
        int save = i;
        for (int j = i + 1; j < panjang; j++)
        {
            if (JQK(kartu[j]) < JQK(kartu[save]))
            {
                save = j;
            }
        }
        if (save != i)
        {
            char temp = kartu[i];
            kartu[i] = kartu[save];
            kartu[save] = temp;
            swaps++;

            printf("Pertukaran %d : ", swaps);
            tampilkartu(kartu, panjang);
        }
    }
    return swaps;
}

int main()
{
    int jumlah;
    printf("Masukan Jumlah Kartu : ");
    scanf("%d", &jumlah);

    char kartu[jumlah];

    printf("Masukan isi kartu : ");
    for (int i = 0; i < jumlah; i++){
        scanf(" %c", &kartu[i]);
    }


    int tukar = bubblesort(kartu, jumlah);
    printf("Jumlah Pertukaran : %d", tukar);
    return 0;
}