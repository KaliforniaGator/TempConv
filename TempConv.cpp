#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <sstream>

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void drawbox(std::string text, bool solid=true, std::string bg_color="bg_blue", std::string text_color="bold_white") {
    std::string command = "drawbox \"" + text + "\" ";
    command += (solid ? "solid " : " ");
    command += (solid ? bg_color + " " + text_color : " " + text_color);

    int drawingResult = system(command.c_str());
}

std::string convFC(double tempF) {
    double tempC = (tempF - 32) / 1.8;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << tempF << "F is " << tempC << "C";
    return oss.str();
}

std::string convCF(double tempC) {
    double tempF = (1.8 * tempC) + 32;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << tempC << "C is " << tempF << "F";
    return oss.str();
}

void printHelp() {
    std::cout << "Usage: tempconv [OPTION] [TEMPERATURE]\n";
    std::cout << "Options:\n";
    std::cout << "  -cF <temperature>  Convert Celsius to Fahrenheit\n";
    std::cout << "  -fC <temperature>  Convert Fahrenheit to Celsius\n";
    std::cout << "  --help             Display this help message\n";
    std::cout << "Example:\n";
    std::cout << "  tempconv -cF 25    Convert 25°C to Fahrenheit\n";
    std::cout << "  tempconv -fC 77    Convert 77°F to Celsius\n";
}

void printHeader() {
    //clearConsole();
    drawbox("Temperature Converter", false);
    std::cout << "+----------------------------------+\n";
    std::cout << "| 1. Convert Fahrenheit to Celsius |\n";
    std::cout << "| 2. Convert Celsius to Fahrenheit |\n";
    std::cout << "|                                  |\n";
    std::cout << "| 3. Exit                          |\n";
    std::cout << "+----------------------------------+\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Command-line mode
        std::string option = argv[1];

        if (option == "--help") {
            printHelp();
            return 0;
        }

        // Check if the required temperature argument is missing
        if (argc < 3) {
            std::cerr << "Error: Missing temperature value!\n";
            printHelp();
            return 1;
        }

        double temperature;
        std::istringstream iss(argv[2]);

        if (!(iss >> temperature)) {
            std::cerr << "Error: Invalid temperature value! Please use only numbers.\n";
            return 1;
        }

        if (option == "-cF") {
            std::string result = convCF(temperature);
            drawbox(result, false); // Use drawbox or ASCII box
        } else if (option == "-fC") {
            std::string result = convFC(temperature);
            drawbox(result, false); // Use drawbox or ASCII box
        } else {
            std::cerr << "Error: Invalid option!\n";
            printHelp();
            return 1;
        }
        
    } else {
        // Interactive mode
        int choice;
        bool validChoice = false;

        printHeader();
        while (!validChoice) {
            std::cout << "\nSelect an action: ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                drawbox("Invalid input! Please enter a number.", true, "bg_red", "bold_white");
                continue;
            }

            switch (choice) {
                case 1: {
                    double tempF;
                    std::cout << "Enter the temperature in Fahrenheit: ";
                    while (!(std::cin >> tempF)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        drawbox("Invalid temperature! Please use only numbers.", true, "bg_red", "bold_white");
                        std::cout << "Enter the temperature in Fahrenheit: ";
                    }
                    std::string FCresult = convFC(tempF);
                    drawbox(FCresult, false);
                    validChoice = true;
                    break;
                }
                case 2: {
                    double tempC;
                    std::cout << "Enter the temperature in Celsius: ";
                    while (!(std::cin >> tempC)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        drawbox("Invalid temperature! Please use only numbers.", true, "bg_red", "bold_white");
                        std::cout << "Enter the temperature in Celsius: ";
                    }
                    std::string CFresult = convCF(tempC);
                    drawbox(CFresult, false);
                    validChoice = true;
                    break;
                }
                case 3:
                    validChoice = true;
                    break;
                default:
                    drawbox("Invalid choice! Please try again.", true, "bg_red", "bold_white");
                    break;
            }

        }
    }

    return 0;
}
