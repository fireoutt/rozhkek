#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Developer {
protected:
    string name;
    string level;
    int experience;
    vector<string> technologies;

public:
    Developer(string name, string level, int experience, vector<string> technologies)
        : name(name), level(level), experience(experience), technologies(technologies) {}

    virtual void writeCode() = 0;
};

class JavaDeveloper : public Developer {
public:
    JavaDeveloper(string name, string level, int experience, vector<string> technologies)
        : Developer(name, level, experience, technologies) {}

    void writeCode() override {
        cout << "Java developer " << name << " starts writing code." << endl;
        cout << "Technologies used: ";
        for (auto tech : technologies) {
            cout << tech << " ";
        }
        cout << endl;
    }
};

class PythonDeveloper : public Developer {
public:
    PythonDeveloper(string name, string level, int experience, vector<string> technologies)
        : Developer(name, level, experience, technologies) {}

    void writeCode() override {
        cout << "Python developer " << name << " starts writing code." << endl;
        cout << "Technologies used: ";
        for (auto tech : technologies) {
            cout << tech << " ";
        }
        cout << endl;
    }
};

class DeveloperFactory {
public:
    static Developer* createDeveloper(string name, string level, int experience, vector<string> technologies, string type) {
        if (type == "Java") {
            return new JavaDeveloper(name, level, experience, technologies);
        }
        else if (type == "Python") {
            return new PythonDeveloper(name, level, experience, technologies);
        }
        return nullptr;
    }
};

int main() {
    vector<string> technologies = { "Java", "Spring", "Hibernate" };
    Developer* dev = DeveloperFactory::createDeveloper("John", "Senior", 5, technologies, "Java");
    dev->writeCode();
    return 0;
}
