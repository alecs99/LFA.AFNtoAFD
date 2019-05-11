#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AFNtoAFD {
    int nr_litere, nr_stari_afn, nr_stari_fin_afn, nr_tranz_afn, stare_start;
    int nr_stari_adaugate;
    int stari_fin_afn[20];
    int stari_fin_afd[20][20];
    int matrice_afn[20][20][20];
    int matrice_afd[20][20][20];
    int nr_stari_fin_afd;
public:
    AFNtoAFD() {
        ifstream f("afntoafd.txt");
        int i, j;

        f >> stare_start;
        f >> nr_litere;
        f >> nr_stari_afn;
        f >> nr_stari_fin_afn;

        for (i = 0; i < nr_stari_fin_afn; i++)
            f >> stari_fin_afn[i];

        f >> nr_tranz_afn;

        int in, out;
        char litera;

        for (i = 0; i < nr_stari_afn; i++)
            for (j = 0; j < nr_litere; j++)
                matrice_afn[i][j][0] = -1;

        for (i = 0; i < nr_tranz_afn; i++) {
            f >> in >> litera >> out;
            j = 0;
            while (matrice_afn[in][litera - 'a'][j] != -1)
                j++;
            matrice_afn[in][litera - 'a'][j] = out;
            matrice_afn[in][litera - 'a'][j + 1] = -1;
        }
    }

    void afisare_afn() {
        int i, j, k;
        cout << "Afisare AFN initial" << endl;
        for (i = 0; i < nr_stari_afn; i++) {
            cout << "Pleaca din:" << i << ' ';
            for (j = 0; j < nr_litere; j++) {
                if (matrice_afn[i][j][0] != -1) {
                    cout << " cu " << char(j + 'a') << " la ";
                    for (k = 0; matrice_afn[i][j][k] != -1; k++)
                        cout << matrice_afn[i][j][k] << ' ';
                }

            }
            cout << endl;
        }
    }

    int verif_stare(int stare[20]) {
        int i, k;
        for (i = 0; i < nr_stari_adaugate; i++) {
            k = 0;
            while (matrice_afd[i][nr_litere][k] != -1 && stare[k] != -1 && matrice_afd[i][nr_litere][k] == stare[k])
                k++;

            if (stare[k] == -1 && matrice_afd[i][nr_litere][k] == -1)
                return 1;
        }
        return 0;
    }

    void sortare_stergere(int v[20], int n) {
        int i, j, aux;

        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++)
                if (v[i] > v[j]) {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
        }

        for (i = 0; i < n - 1; i++)
            if (v[i] == v[i + 1]) {
                for (j = i + 1; j < n; j++)
                    v[j] = v[j + 1];

                n--;
            }
    }

    void adaug_stare(int stare_adaugata[10]) {
        int i, j, k, m;
        if (verif_stare(stare_adaugata) == 0) {
            for (i = 0; stare_adaugata[i] != -1; i++)
                matrice_afd[nr_stari_adaugate][nr_litere][i] = stare_adaugata[i];
            matrice_afd[nr_stari_adaugate][nr_litere][i] = -1;
            for (i = 0; i < nr_litere; i++) {
                m = 0;
                for (j = 0; stare_adaugata[j] != -1; j++) {
                    for (k = 0; matrice_afn[stare_adaugata[j]][i][k] != -1; k++)
                        matrice_afd[nr_stari_adaugate][i][m++] = matrice_afn[stare_adaugata[j]][i][k];
                }
                matrice_afd[nr_stari_adaugate][i][m] = -1;
                sortare_stergere(matrice_afd[nr_stari_adaugate][i], m);
            }
            nr_stari_adaugate++;
        }
    }

    void creare_matrice_afd() {
        int v[2];
        v[0] = stare_start;
        v[1] = -1;
        nr_stari_adaugate = 0;
        adaug_stare(v);

        int i = 0;

        while (i < nr_stari_adaugate) {
            for (int j = 0; j < nr_litere; j++)
                if (matrice_afd[i][j][0] != -1)
                    adaug_stare(matrice_afd[i][j]);

            i++;
        }

        int k, l, q;
        nr_stari_fin_afd = 0;

        for (i = 0; i < nr_stari_adaugate; i++) {
            for (k = 0; matrice_afd[i][nr_litere][k] != -1; k++) {
                for (l = 0; l < nr_stari_fin_afn; l++)
                    if (stari_fin_afn[l] == matrice_afd[i][nr_litere][k]) {
                        for (q = 0; matrice_afd[i][nr_litere][q] != -1; q++)
                            stari_fin_afd[nr_stari_fin_afd][q] = matrice_afd[i][nr_litere][q];
                        stari_fin_afd[nr_stari_fin_afd][q] = -1;
                        nr_stari_fin_afd++;
                    }

            }
        }
    }

    void afisare_afd() {
        int i, j, k;
        cout << "Afisare transformare AFN în AFD" << endl;
        for (i = 0; i < nr_stari_adaugate; i++) {
            cout << "Pleaca din:" << ' ';
            for (k = 0; matrice_afd[i][nr_litere][k] != -1; k++)
                cout << matrice_afd[i][nr_litere][k] << ' ';
            for (j = 0; j < nr_litere; j++) {
                if (matrice_afd[i][j][0] != -1) {
                    cout << " cu " << char(j + 'a') << " la ";
                    for (k = 0; matrice_afd[i][j][k] != -1; k++)
                        cout << matrice_afd[i][j][k] << ' ';
                }

            }
            cout << endl;

        }
        cout << "Stari finale:" << endl;
        for (i = 0; i < nr_stari_fin_afd; i++) {
            for (j = 0; stari_fin_afd[i][j] != -1; j++)
                cout << stari_fin_afd[i][j] << " ";
            cout << endl;
        }
    }

    void transformare() {
        afisare_afn();
        creare_matrice_afd();
        afisare_afd();

    }

};

int main() {
    AFNtoAFD a;
    a.transformare();
}