#include <iostream>
using namespace std;

const int eur = 30;
const int bacs = 27;
const double BacsInEur = 1.09;
const double EurInBack = 0.92;

class Bank {
private:
    int number;
    double sum;
    char value;
public:
    Bank() {
        cout << "Enter number" << endl;
        cin >> this->number;

        cout << "Enter sum" << endl;
        cin >> this->sum;

        cout << "Enter value" << endl;
        cin >> this->value;

        cout << endl;
    }

    Bank(int number, double sum, char value) {
        this->number = number;
        this->sum = sum;
        this->value = value;
    }

    void minusMoney() {
        int resForMinusMonej;

        cout << "Enter skilki you hozete sniati" << endl;
        cin >> resForMinusMonej;

        if (this->sum >= resForMinusMonej) {
            this->sum -= resForMinusMonej;
            cout << "Успішно переведено" << endl;
        }
        else {
            cout << "No monej" << endl;
        }
    }

    void plusMonej() {
        int resForPlusMonej;

        cout << "Enter na skiko you hozete popovniti" << endl;
        cin >> resForPlusMonej;

        this->sum += resForPlusMonej;
    }

    void show() {
        cout << "-------------------------------------\n";
        cout << "Number: \t" << number << endl;
        cout << "Sum: \t" << this->sum;
        cout << this->value;
        cout << endl;
    }

    void perekaz(Bank& b) {
        int zminnaForPerekaz, karta1, karta2;

        cout << "Введіть номер карточки з якої ви хочете переказати" << endl;
        cin >> karta1;

        cout << "Введіть номер карточки на яку ви хочете переказати" << endl;
        cin >> karta2;

        if (b.value != 'G') {
            if (b.value == 'E') {
                b.value = 'G';
                b.sum *= eur;
            }
            else if (b.value == '$') {
                b.value = 'G';
                b.sum *= bacs;
            }
        }

        if (this->value != 'G') {
            if (this->value == 'E') {
                this->value = 'G';
                this->sum *= eur;
            }
            else if (b.value == '$') {
                this->sum *= bacs;
                this->value = 'G';
            }
        }

        if (this->number == karta1 && b.number == karta2) {
            cout << "Ввведіть скільки ви хочете переказати" << endl;
            cin >> zminnaForPerekaz;

            if (this->sum < zminnaForPerekaz) {
                cout << "Error" << endl;
            }
            else {
                b.sum += zminnaForPerekaz;
                this->sum -= zminnaForPerekaz;
                cout << "Успiшно переведено" << endl;
            }
        }
        else if (b.number == karta1 && this->number == karta2) {
            cout << "Ввведіть скiльки ви хочете переказати" << endl;
            cin >> zminnaForPerekaz;

            if (b.sum < zminnaForPerekaz) {
                cout << "No money" << endl;
            }
            else {
                this->sum += zminnaForPerekaz;
                b.sum -= zminnaForPerekaz;
                cout << "Успішно переведено" << endl;
            }
        }
        else {
            cout << "Eror" << endl;
        }
    }

    void showMyBalance() {
        if (this->value == 'G') {
            cout << "My balanse: 1)" << this->sum << "G" << "\t2)" << this->sum / eur << "E" << "\t3)" << this->sum / bacs << "$" << endl;
        }
        else if (this->value == 'E') {
            cout << "My balanse: 1)" << this->sum * eur << "G" << "\t2)" << this->sum << "E" << "\t3)" << this->sum * BacsInEur << "$" << endl;
        }
        else if (this->value == '$') {
            cout << "My balanse: 1)" << this->sum * bacs << "G" << "\t2)" << this->sum * EurInBack << "E" << "\t3)" << this->sum << "$" << endl;
        }
    }

};

void menu(Bank& a, Bank& b);

int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "Russian");
    Bank a;//(1, 200, '$');
    Bank b;//(2, 100, 'E');
    menu(a, b);

    return 0;
}

void menu(Bank& a, Bank& b) {
    int resForMenu;
    while (true) {
        cout << "-------------------------------------";
        cout << "\n1.Зняти" << endl;
        cout << "2.Додати" << endl;
        cout << "3.Передати" << endl;
        a.showMyBalance();
        cout << "-->_";
        cin >> resForMenu;

        switch (resForMenu) {
        case 1:
            a.minusMoney();
            a.show();
            break;
        case 2:
            a.plusMonej();
            a.show();
            break;
        case 3:
            a.perekaz(b);
            a.show();
            b.show();
            break;

        default:
            break;
        }
    }
}