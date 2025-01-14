// request.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>
//cделать функцию для редактирования записи
void InitializeConsole() 
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

}

void show() {
    std::ifstream out;
    out.open("D:/request/request/request/Diary.txt",std::ios::app);
    if (!out.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return;
    }
    std::string strInput;
    if (out.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "File is empty." << std::endl;
    }
    else {
        while (std::getline(out, strInput))
        {
            std::cout << strInput << std::endl;
        }

    }
    out.close();
}

void request() 
{
   
    std::fstream out;
    std::string date;
    std::string text;
    out.open("D:/request/request/request/Diary.txt", std::ios::app);

    if (!out.is_open()) {
        std::cerr <<"Error.File is not open for request." << std::endl;
        return;
    }

    std::cout << "Enter data:";
    std::cin >> date;
    std::cout << "Enter text:";
    std::cin.ignore();
    std::getline(std::cin , text);

    out << "Enter data:" << date;
    out << std::endl;
    out << "Enter text:" << text << std::endl;
    out << std::endl;

    std::cout << "Request save." << std::endl;
    out.close();
}
void clear() {
    std::ofstream out("D:/request/request/request/Diary.txt", std::ios::trunc);
    if (!out.is_open()) 
    {
        std::cerr << "Error.File is not open for request."<<std::endl;
        return;
    }
    std::cout << "Diary cleared." << std::endl;
    out.close();
}


int main() {
    InitializeConsole();
    std::string command;
   
    
    while (true) {
        std::cout << "Enter command(show,request,exit,clear): ";
        
        if (!std::getline(std::cin, command)) {
            std::cerr << "Error command." << std::endl;
        }
        if (command == "show") {
            show();

        }
        else if (command == "request") {
            request();
            
        }
        else if (command == "exit"){
            break;
        }
        else if(command == "clear"){
            clear();
        }
        else {
            std::cout << "Error command." << std::endl;
        }
       
    }

    return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
