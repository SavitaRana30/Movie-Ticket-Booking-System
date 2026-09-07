#include <string>
#include <vector>
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens; // OOP: Composition - Cinema owns Screens

public:
    Cinema(string name) {
        this->name = name;
    }

    string getName() const { return name; }

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    vector<Screen>& getScreens() { return screens; }
    const vector<Screen>& getScreens() const { return screens; }
};
