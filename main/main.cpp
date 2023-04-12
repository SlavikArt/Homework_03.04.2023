#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction() : numerator(1), denominator(1) {}

    Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw exception("Can't divide by Zero.");
        }
        else
        {
            this->numerator = numerator;
            this->denominator = denominator;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

ostream& operator<<(ostream& o, const Fraction& f)
{
    o << f.numerator << "/" << f.denominator;
    return o;
}

void task1()
{
    ifstream inputFile("input/1.txt");
    ofstream outputFile("output/1.txt");

    if (inputFile && outputFile)
    {
        string word;
        while (inputFile >> word)
        {
            if (word.size() >= 8)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    if (ispunct(word[i]))
                    {
                        word.erase(i, 1);
                        i--;
                    }
                }
                outputFile << word << "\n";
            }
        }
        inputFile.close();
        outputFile.close();

        cout << "Задание 1: Успешно выполнено.\n\n";
    }
    else
    {
        cout << "Не удалось открыть файлы :(" << "\n";
    }
}

void task2()
{
    ifstream inputFile("input/2.txt");
    ofstream outputFile("output/2.txt");

    if (inputFile && outputFile)
    {
        string line;
        while (getline(inputFile, line))
        {
            outputFile << line << "\n";
        }
        inputFile.close();
        outputFile.close();

        cout << "Задание 2: Успешно выполнено.\n\n";
    }
    else
    {
        cout << "Не удалось открыть файлы :(" << "\n";
    }
}

void task3()
{
    Fraction fractions[4] = { Fraction(1,2), Fraction(1,8), Fraction(2,3), Fraction(3,5) };
    Fraction fractions2[4];

    ofstream outputFile("output/3.bin", ios::binary);

    if (outputFile)
    {
        outputFile.write((char*)fractions, sizeof(fractions));
        outputFile.close();

        ifstream inputFile("output/3.bin", ios::binary);

        if (inputFile)
        {
            inputFile.read((char*)fractions2, sizeof(fractions2));

            for (int i = 0; i < 4; i++)
            {
                cout << fractions2[i] << ", ";
            }
            cout << "\n";
            inputFile.close();

            cout << "Задание 3: Успешно выполнено.\n\n";
        }
        else
        {
            cout << "Не удалось открыть файл :(" << "\n";
        }
    }
    else
    {
        cout << "Не удалось открыть файл :(" << "\n";
    }
}

void task4()
{
    Fraction fractions[4] = { Fraction(1,2), Fraction(1,8), Fraction(2,3), Fraction(3,5) };
    Fraction fraction;

    ofstream outputFile("output/4.bin", ios::binary);

    if (outputFile)
    {
        outputFile.write((char*)fractions, sizeof(fractions));
        outputFile.close();

        ifstream inputFile("output/4.bin", ios::binary);

        if (inputFile)
        {
            inputFile.seekg(-2 * sizeof(Fraction), ios::end);

            inputFile.read((char*)&fraction, sizeof(Fraction));

            inputFile.close();

            cout << fraction << "\n";

            cout << "Задание 4: Успешно выполнено.\n\n";
        }
        else
        {
            cout << "Не удалось открыть файл :(" << "\n";
        }
    }
    else
    {
        cout << "Не удалось открыть файл :(" << "\n";
    }
}

int main()
{
    setlocale(0, "ukr");

    task1();

    task2();

    task3();

    task4();
}
