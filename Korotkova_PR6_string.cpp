// Короткова
#include <iostream>
#include <string>
#include <cstring>
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
    int count = 0;
    
    int len = 0;
    char* p = s;
    while (*p++ != '\0'){
        len++;
    }

    p = s;
    cout << "Результат задания:\n";
    for (int i = 0; i < len; i++){
        int k = 0;
        if ((*(p + i) >= '0' && *(p + i) <= '9') || (*(p + i) >= 'a' && *(p + i) <= 'z') || (*(p + i) >= 'A' && *(p + i) <= 'Z')){
            ++k;
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

    for (int i = 0; i < len; i++) {
        if ( s[i] >= '0' && s[i] <= '9') {
            s[i] = '*';
        }
    }
    cout << "Преобразованная строка:\n" << s << "\n";
}

// Задание 3. Вводится строка символов. Определить, сколько слов начинается с заглавной
// буквы. Слова разделяются пробелами, в начале и конце строки пробелы допускаются.
void problem3(){
    char s[1000];
    EnterArrChar("Введите строку: ", s, 1000);
    int len = strlen(s);

    int i = 0;
    int k = 0;
    while (i < len){
        if (s[i] >= 'A' && s[i] <= 'Z') ++k;

        for (int j = i; j <= len; j++){
            if (s[j] == ' ' || s[j] == '\0'){
                i = j;
                break;
            }
        }
        ++i;
    }
    cout << "Количество слов, начинающихся с заглавной буквы: " << k << "\n";
}

// Задание 4. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются. 
// Вывести на экран все слова, содержащие хотя бы одну цифру.
void problem4(){
    string s = EnterString("Введите строку:\n");
    int len = s.length();

    string word;
    int k = 0;
    cout << "Результат:\n";
    for (int i = 0; i <= len; i++){
        if (i < len && s[i] != ' '){
            word += s[i];

            if (s[i] >= '0' && s[i] <= '9'){
                ++k;
            }
        }else{
            if (word.size() > 0 && k){
                cout << word << "\n";
            }

            word = "";
            k = 0;
        }
    }
}

// Задание 5. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.
// Удалить все слова, длина которых равна заданному числу k (k вводится с клавиатуры), сохраняя пробелы до и после слов.
// Вывести преобразованную строку.
void problem5(){
    char s[1000];
    EnterArrChar("Введите строку: ", s, 1000);
    int len = strlen(s);
    int k = IntEnterNumber("Введите длину слов, которые будут удаляться: ");
    char copy_s[1000];
    
    int j = 0;
    int i = 0;

    while (i < len){
        while (i < len && s[i] == ' '){
            copy_s[j++] = s[i];
            ++i;
        }

        if (i >= len) break;

        int start = i;

        while (i < len && s[i] != ' '){
            ++i;
        }
        int end = i;
        int word_len = end - start;

        if (word_len != k){
            for (int j1 = start; j1 < end; j1++){
                copy_s[j++] = s[j1];
            }
        }
    }
    copy_s[j] = '\0';
    strcpy(s, copy_s);
    cout << "Преобразованная строка: " << s << "\n";

}

// Задание 6. Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами. В первом слове отсортировать символы по возрастанию
// ASCII - кодов. Вывести преобразованную строку.
void problem6(){
    string s = EnterString("Введите строку: ");
    if (s[0] == ' '){
        s = EnterString("Введите строку: ");
    }

    string correct_str;
    int len_word = 0;

    if (s.find(' ') != string::npos){
        len_word = s.find(' ');
    }else{
        len_word = size(s);
    }

    correct_str = s.substr(0, len_word);

    for (int i = 0; i < len_word - 1; i++){
        for (int j = 0; j < len_word - i - 1; j++){
            if (correct_str[j] > correct_str[j + 1]){
                char x = correct_str[j];
                correct_str[j] = correct_str[j + 1];
                correct_str[j + 1] = x;
            }
        }
    }

    s.replace(0, len_word, correct_str);
    cout << "Преобразованная строка: " << s << "\n";

}

// Меню
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
        {3, {"Вводится строка символов.Определить, сколько слов начинается с заглавной буквы.\nСлова разделяются пробелами, в начале и конце строки пробелы допускаются.", problem3}},
        {4, {"Вводится строка символов, которые разделены на слова.\nПробелы являются разделителями между словами,\nпричём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.\nВывести на экран все слова,содержащие хотя бы одну цифру.", problem4}},
        {5, {"Вводится строка символов, которые разделены на слова. Пробелы являются\nразделителями между словами, причём слова могут разделяться более чем одним пробелом, в начале и конце строки пробелы также допускаются.\nУдалить все слова, длина которых равна заданному числу k(k вводится с клавиатуры), сохраняя пробелы до и после слов.\nВывести преобразованную строку.", problem5}},
        {6, {"Вводится строка символов, которые разделены на слова. Пробелы являются разделителями между словами.\nВ первом слове отсортировать символы по возрастанию ASCII - кодов.\nВывести преобразованную строку.", problem6}}
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

