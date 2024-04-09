#include <iostream>
#include <map>#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct User {
    string fullName;
    string phoneNumber;
};

class PhoneBook {
private:
    vector<User> users;
    string filename = "phonebook.txt";
    
public:
//конструктор загружает данные из файла при инициализации объекта
    PhoneBook() {
        loadFromStorage();
    }

//деструктор сохраняет данные в файл при уничтожении объекта
    ~PhoneBook() {
        saveToStorage();
    }

//добавляет нового пользователя в книгу
    void addUser(const string& fullName, const string& phoneNumber) {
        User newUser;
        newUser.fullName = fullName;
        newUser.phoneNumber = phoneNumber;
        users.push_back(newUser);
    }

//удаляет пользователя из книги по его полному имени
    void deleteUser(const string& fullName) {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->fullName == fullName) {
                users.erase(it);
                break;
            }
        }
    }

//ищет пользователя в книге по полному имени и выводит информацию о нем, если он найден
    void searchUser(const string& fullName) {
        for (const auto& user : users) {
            if (user.fullName == fullName) {
                cout << "Пользователь найден:" << endl;
                cout << "Полное имя: " << user.fullName << endl;
                cout << "Номер телефона: " << user.phoneNumber << endl;
                return;
            }
        }
        cout << "Пользователь не найден." << endl;
    }

//сохраняет данные всех пользователей в файл
    void saveToStorage() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& user : users) {
                file << user.fullName << "," << user.phoneNumber << endl;
            }
            file.close();
        }
    }

//загружает данные из файла и создает объекты пользователей на основе этой информации
    void loadFromStorage() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(",");
                if (pos != string::npos) {
                    User newUser;
                    newUser.fullName = line.substr(0, pos);
                    newUser.phoneNumber = line.substr(pos + 1);
                    users.push_back(newUser);
                }
            }
            file.close();
        }
    }
};

int main() {
    PhoneBook phoneBook;

    phoneBook.addUser("Николай Римский-Корсаков", "8234567890");
    phoneBook.addUser("Шарль д’Артаньян", "8987654321");

    string fullName;
    cout << "Введите ФИО для поиска: ";
    getline(cin, fullName);
    phoneBook.searchUser(fullName);

    phoneBook.saveToStorage();

    return 0;
}
