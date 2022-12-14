#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Windows.h>
#include "Language.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Language> vlanguage;
    vlanguage.push_back(Language("Белоруский", "Прывiтанне!", 32, 901, 1));
    vlanguage.push_back(Language("Итальянский", "Ciao!", 26, 1301, 0));
    vlanguage.push_back(Language("Французский", "Salut!", 26, 801, 0));
    vlanguage.push_back(Language("Польский", "Czesc!", 32, 1301, 1));
    vlanguage.push_back(Language("Английский", "Hello!", 26, 522, 1));
    vlanguage.push_back(Language("Латынь", "Ave!", 23, -2000, 0));

    char menu = NULL;
    do{
        cout << "\n1 - добавить новый язык\n"
            << "2 - удалить язык\n"
            << "3 - вывести список добавленных языков\n"
            << "4 - сортировать языки от новейшего к самому древнему\n"
            << "5 - найти самый древний язык из списка\n"
            << "6 - суммарное количество букв в алфавите\n"
            << "7 - поиск языка, на котором может говорить Эрика Мазай :)\n"
            << "8 - сказать \"Привет!\" на выбранном языке\n"
            << "9 - выход" << endl;;

        cin >> menu;
        switch (menu)
        {
        case '1':
        {
            string name,
                sayHello;
            int alphabet,
                year;
            bool canspeak;

            cout << "Опишите язык по следующим параметрам: \n\nНазвание: ";
            cin >> name;
            cout << "\nКак сказать \"Привет\"?: ";
            cin >> sayHello;
            cout << "\nКоличество букв в алфавите: ";
            cin >> alphabet;
            cout << "\nГод первого упоминания (возникновение): ";
            cin >> year;
            cout << "\nМожет ли Эрика говорить на этом языке? (1 - да, 0 - нет/неизвестно): ";
            cin >> canspeak;

            Language new_elem = Language(name, sayHello, alphabet, year, canspeak);
            vlanguage.push_back(new_elem);

            cout << "\nНовый язык добавлен в список." << endl;
            break;
        }
        case '2':
        {
            int del;
            cout << "Введите номер языка для удаления: ";
            
            if (vlanguage.empty())
                cout << "Языки для удаления не обнаружены." << endl;
            else {
                cin >> del;
                if (del > vlanguage.size() || del < 0)
                    cout << "Out of range!";
                else
                    vlanguage.erase(vlanguage.begin() + (del - 1));
            }
            
            break;
        }
        case '3':
        {
            for_each(vlanguage.begin(), vlanguage.end(), [](Language const& lang) {
                cout << lang.toString() << endl; });

            break;
        }
        case '4':
        {
            sort(vlanguage.begin(), vlanguage.end(), [](Language const& first, Language const& second) {
                return first.getYear() > second.getYear();
                });

            for_each(vlanguage.begin(), vlanguage.end(), [](Language const& lang) {
                cout << lang.toString() << endl; });

            break;
        }
        case '5':
        {
            auto theoldest = min_element(vlanguage.begin(), vlanguage.end(), [](Language const& first, Language const& second) {
                return first.getYear() < second.getYear();
                });

            cout << "Самый древний язык из списка - " << (*theoldest).getName() << ", он возник в " << (*theoldest).getYear() << " году!" << endl;

            break;
        }
        case '6':
        {
            vector<int> sum;
            for (Language i : vlanguage)
                sum.push_back(i.getAlphabet());

            int res = accumulate(sum.begin(), sum.end(), 0);

            cout << "Сумма букв алфавитов: " << res << endl;

            break;
        }
        case '7':
        {
            cout << "Из данного списка языков Эрика знает:\n" << endl;

            for_each(vlanguage.begin(), vlanguage.end(), [](Language const& lang) {
                if(lang.getCanSpeak() == 1)
                    cout << lang.getName() << "--"; });

            break;
        }
        case '8': {
            string answ;
            cout << "Введите название языка (с заглавной буквы): ";
            cin >> answ;

            auto it = find_if(vlanguage.begin(), vlanguage.end(), [answ](Language const& l) {return l.getName() == answ; });

            if (it == vlanguage.end())
                cout << "Такого языка не найденно в списке добавленных!" << endl;
            else
                cout << "Привет - " << (*it).getHello() << endl;
            
            break;

        }
        default:
            if (menu == '9')
                continue;
            cout << "Некорректный ввод" << endl;
            break;
        }
    }while (menu != '9');
}
