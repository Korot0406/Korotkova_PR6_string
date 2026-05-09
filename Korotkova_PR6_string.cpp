#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <algorithm>
using namespace std;

// Функция проверки корректности ввода целого числа 
bool IntUserInput(string input) {
    if (input.empty())return false;

    try {
        size_t pos;
        stoi(input, &pos);
        return input.length() == pos;
    }
    catch (...) {
        return false;
    }
}

// Функция ввода целого числа с повторением запроса до корректного ввода
int IntEnterNumber(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!IntUserInput(raw_input)) {
        cout << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}

// Функция проверки корректности ввода вещественного числа
bool DoubleUserInput(string input) {
    if (input.empty())return false;

    try {
        size_t pos;
        stod(input, &pos);
        return pos == input.length();
    }
    catch (...) {
        return false;
    }


}

// Функция ввода вещественного числа с повторением запроса до корректного ввода
double DoubleEnterNumber(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!DoubleUserInput(raw_input)) {
        cout << label;
        getline(cin, raw_input);
    }
    return stod(raw_input);
}

// Функция проверки корректности ввода непустой строки типа string
bool UserInputStr(string input) {
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    return !input.empty();
}

// Функция ввода строки с повторением запроса до корректного ввода
string EnterString(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInputStr(raw_input)) {
        cout << label;
        getline(cin, raw_input);
    }
    return raw_input;
}

// Функция проверки корректности ввода непустой строки char[]
bool UserInputArrChar(const char str[]) {
    const char* p = str;
    while (*p != '\0')
        if (*p++ != ' ') return true;
    return false;
}

// Функция ввода строки с повторением запроса до корректного ввода
void EnterArrChar(const char label[], char output[], size_t size) {
    cout << label;
    cin.getline(output, size);

    while (!UserInputArrChar(output)) {
        cout << label;
        cin.getline(output, size);
    }
}

// Задание 1. Вводится строка произвольного текста. Вывести на экран все символы, не являющиеся буквами и цифрами. 
// Если таких символов нет, вывести -1.
void problem1(){
    char s[1000];
    EnterArrChar("Введите строку текста: ", s, 1000);
    char number[] = "0123456789";
    char letters[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int count = 0;
    
    int len = 0;
    char* p = s;
    char* p_n = number;
    char* p_l = letters;
    while (*p++ != '\0'){
        len++;
    }

    p = s;
    cout << "Результат задания:\n";
    for (int i = 0; i <= len; i++){
        int k = 0;
        for (int j1 = 0; j1 < 53; j1++){
            if (*(p + i) == *(p_l + j1)){
                ++k;
                break;
            }
        }   

        for (int j1 = 0; j1 < 10; j1++){
            if (*(p + i) == *(p_n + j1)){
                ++k;
                break;
            }
        }
        
        if (*(p + i) == ' ')++k;

        if (k == 0){
            ++count;
            cout << "Символы, не являющиеся буквами и цифрами:\n" << *(p + i) << "\n" ;
        }
    }

    if (count == 0){
        cout << "-1\n";
    }
}


// Задание 2. Вводится строка произвольного текста. Заменить все цифры на соответствующие им символы *. 
// Вывести преобразованную таким образом строку.
void problem2(){
    string s = EnterString("Введите текст:\n");
    cout << "Исходная строка:\n" << s << "\n";
    int len = s.length();
    string numbers = "0123456789";

    for (int i = 0; i < len; i++) {
        if (numbers.find(s[i]) != -1) {
            s[i] = '*';
        }
    }
    cout << "Преобразованная строка:\n" << s << "\n";
}

// Задание 3. Вводится строка символов.Определить, сколько слов начинается с заглавной
// буквы. Слова разделяются пробелами, в начале и конце строки пробелы допускаются.
void problem3(){

}

// Задание 4. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются. 
// Вывести на экран все слова, содержащие хотя бы одну цифру.
void problem4(){
    string s = EnterString("Введите строку:\n");
    int len = s.length();
    string numbers = "0123456789";

    for (int i = 0; i < len - 1;) {
        int k = 0;
        int ind_end = 0;
        for (int j = i; j < len; j++) {
            ind_end = j;
            if (s[j] == ' ') {
                break;
            }
            if (numbers.find(s[j] != -1)) {
                ++k;
            }
        }
        if (k > 0) {
            string ans = s.substr(i, ind_end - i);
            cout << ans << "\n";
        }
        i = ind_end;
    }
}

// Задание 5. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.
// Удалить все слова, длина которых равна заданному числу k(k вводится с клавиатуры), сохраняя пробелы до и после
// слов.Вывести преобразованную строку.
void problem5(){}

// Задание 6. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами.В первом слове отсортировать символы по возрастанию
// ASCII - кодов.Вывести преобразованную строку.
void problem6(){
    string s = EnterString("Введите строку символов: ");


}


struct MenuItem {
    string title;
    void (*action)();
};



int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    map<int, MenuItem> menu = {
        {1, {"Вводится строка произвольного текста. Вывести на экран все символы, не являющиеся буквами и цифрами.\nЕсли таких символов нет, вывести -1.", problem1}},
        {2, {"Вводится строка произвольного текста. Заменить все цифры на соответствующие им символы *.\nВывести преобразованную таким образом строку.", problem2}},
        {3, {"Вводится строка символов.Определить, сколько слов начинается с заглавной буквы.\n Слова разделяются пробелами, в начале и конце строки пробелы допускаются.", problem3}},
        {4, {"Вводится строка символов, которые разделены на слова.\nПробелы являются разделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.\nВывести на экран все слова,содержащие хотя бы одну цифру.", problem4}},
        {5, {"Вводится строка символов, которые разделены на слова. Пробелы являются\nразделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.\nУдалить все слова, длина которых равна заданному числу k(k вводится с клавиатуры), сохраняя пробелы до и послеслов.\nВывести преобразованную строку.", problem5}},
        {6, {"Вводится строка символов, которые разделены на слова. Пробелы являются\nразделителями между словами.В первом слове отсортировать символы по возрастанию\nASCII - кодов.Вывести преобразованную строку.", problem6}}
    };

    int choice = 0;

    while (true) {
        cout << "Меню:\n";

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << "\n";
        }

        cout << "0. Выход\n";

        choice = IntEnterNumber("Введите номер пункта: ");

        if (choice == 0) {
            cout << "© 2026 Korotkova I.S.\n";
            break;
        }

        cout << "\n";

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else {
            cout << "Некорректный ввод.\n";
        }
    }

    return 0;
}

