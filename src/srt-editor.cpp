#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#include "srt-editor.h"
#include "utils.h"
#include "offsetter.h"
#include "check-id.h"
#include "save-changes.h"

const std::vector<std::string> menuOptions = {
    "1 - Add Offset\n",
    "2 - Check sub IDs\n",
    "3 - Save Changes\n",
    "0 - Quit the application\n"
};

int main(int argc, char *argv[]){
    if(argc != 2){   //eventually I'll allow editing multiple files
        printUsage();
        return 1;
    }

    std::string fileName = "";
    
    //TODO catch error returnal
    fileName.append(argv[1]);

    bool loop = true;
    while(loop){
        unsigned int option = cli();
        switch(option){
            case 0:
                loop = false;
                break;
            case 1:
                addOffset(fileName);
                break;
            case 2:
                checkIDs(fileName);
                break;
            case 3:
                saveChanges(fileName);
                break;
        }
    }
    
    return 0;
}

unsigned int cli(){
    printMenu();

    unsigned int option = 255;

    while(true){
        std::cout << "\nPlease input your desired option: ";
        std::string input = "";
        std::getline(std::cin, input);

        try{
            option = std::stoi(input);
        } catch (std::invalid_argument const&) {
            std::cout << "Please input an integer.\n";
            continue;
        }
        if(!(option < menuOptions.size())){
            std::cout << "That is not a valid option.\n";
        }
        else break;
    }
    return option;
}

void printMenu(){
    std::cout << std::endl;
    for(auto &option : menuOptions){
        std::cout << option;
    }
}

// void tests(){
//     int s1[4] = {0, 0, 0, 0};
//     int t1[4] = {0, 0, 0, 0};
//     int e1[4] = {59, 59, 59, 999};
    
//     int s2[4] = {0, 0, 0, 0};
//     int t2[4] = {0, 3, 31, 123};
//     int e2[4] = {59, 59, 59, 999};
    
//     int s3[4] = {1, 0, 0, 0};
//     int t3[4] = {2, 0, 0, 0};
//     int e3[4] = {4, 0, 0, 0};
    
//     int s4[4] = {1, 0, 0, 0};
//     int t4[4] = {1, 0, 0, 0};
//     int e4[4] = {4, 0, 0, 0};
    
//     int s5[4] = {1, 0, 0, 0};
//     int t5[4] = {4, 0, 0, 0};
//     int e5[4] = {4, 0, 0, 0};
    
//     int s6[4] = {2, 31, 10, 23};
//     int t6[4] = {2, 30, 23, 9};
//     int e6[4] = {4, 10, 10, 24};

//     int s7[4] = {0, 30, 0, 0};
//     int t7[4] = {1, 10, 0, 0};
//     int e7[4] = {1, 40, 0, 0};
    
//     int s8[4] = {0, 30, 30, 0};
//     int t8[4] = {1, 30, 10, 0};
//     int e8[4] = {1, 40, 40, 0};
    
//     int s9[4] = {0, 30, 30, 30};
//     int t9[4] = {1, 30, 30, 10};
//     int e9[4] = {1, 40, 40, 40};
    
//     int s10[4] = {1, 30, 24, 30};
//     int t10[4] = {1, 30, 24, 10};
//     int e10[4] = {4, 0, 0, 0};
    
//     int s11[4] = {1, 30, 24, 30};
//     int t11[4] = {1, 30, 24, 30};
//     int e11[4] = {4, 0, 0, 0};
    
//     int s12[4] = {1, 30, 24, 30};
//     int t12[4] = {1, 30, 23, 10};
//     int e12[4] = {4, 0, 0, 0};
    
//     int s13[4] = {0, 0, 25, 0};
//     int t13[4] = {0, 0, 30, 982};
//     int e13[4] = {0, 0, 30, 982};
    
//     int s14[4] = {0, 0, 25, 0};
//     int t14[4] = {0, 0, 30, 983};
//     int e14[4] = {0, 0, 30, 982};
    
//     std::cout << "t exp|res\n";
//     std::cout << "t1 " << true << " |" << canEdit(t1, s1, e1) << "\n";
//     std::cout << "t2 " << true << " |" << canEdit(t2, s2, e2) << "\n";
//     std::cout << "t3 " << true << " |" << canEdit(t3, s3, e3) << "\n";
//     std::cout << "t4 " << true << " |" << canEdit(t4, s4, e4) << "\n";
//     std::cout << "t5 " << true << " |" << canEdit(t5, s5, e5) << "\n";
//     std::cout << "t6 " << false << " |" << canEdit(t6, s6, e6) << "\n";
//     std::cout << "t7 " << true << " |" << canEdit(t7, s7, e7) << "\n";
//     std::cout << "t8 " << true << " |" << canEdit(t8, s8, e8) << "\n";
//     std::cout << "t9 " << true << " |" << canEdit(t9, s9, e9) << "\n";
//     std::cout << "t10 " << false << " |" << canEdit(t10, s10, e10) << "\n";
//     std::cout << "t11 " << true << " |" << canEdit(t11, s11, e11) << "\n";
//     std::cout << "t12 " << false << " |" << canEdit(t12, s12, e12) << "\n";
//     std::cout << "t13 " << true << " |" << canEdit(t13, s13, e13) << "\n";
//     std::cout << "t14 " << false << " |" << canEdit(t14, s14, e14) << "\n";
// }
