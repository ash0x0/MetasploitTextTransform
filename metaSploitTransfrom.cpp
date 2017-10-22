#include <iostream>
#include <string>
#include <cstdio>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    string line;
    string option;
    char character;

    printf("Please input the script to transform: ");
    getline (cin, line);
    printf("Please input the number of times: ");
    getline (cin, option);

    int number = stoi (option, nullptr);

    for (int k = 0; k < number; k++) {
        cout << "\033[2J\033[1;1H";
        for (int i = 0; i < line.length(); i++) {
            character = line[i];
            if (character < 91 && character > 64) {
                line[i] = character + 32;
            } else if (character < 123 && character > 96) {
                line[i] = character - 32;
            } else continue;
            printf("%s\n", line.c_str());
            line[i] = character;
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            cout << "\033[2J\033[1;1H";
        }
    }
    return 0;
}
