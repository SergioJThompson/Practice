#include <iostream>
using namespace std;

enum command { go_north, go_south, quit, unparseable };

string get_input() {
    string input;
    getline(cin, input);
    return input;
}

command parse_as_command(string &s) { /* TODO: Consider making this a switch */
    if (s == "go north" || s == "head north" || s == "walk north")
        return go_north;
    else if (s == "go south" || s == "head south" || s == "walk south")
        return go_south;
    else if (s == "quit" || s == "end")
        return quit;
    return unparseable;
}

void obey(command c) {
    switch(c) {
        case go_north:
            cout << "You go north.";
            break;
        case go_south:
            cout << "You go south.";
            break;
        case unparseable:
            cout << "I don't recognize that command.";
            break;
        default:
            throw invalid_argument("Something weird was passed to obey() in main.cpp");
    }
}

int main() {
    while (true) {
        cout << "Enter a command: ";
        string input = get_input();
        command command = parse_as_command(input);
        if (command == quit) {
            cout << "Goodbye!";
            return 0;
        } else {
            obey(command);
            cout << endl;
        }
    }
}
