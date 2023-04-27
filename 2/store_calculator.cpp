#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

std::stringstream open_file(std::string path) {
    std::ifstream file(path);
    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer;
    }
    
}

int calculate_score(std::map<std::string, int> scores) { 
    int score = 0;

    std::stringstream input = open_file("./input.txt");
    std::string line;
    getline(input, line, '\n');

    while (line.std::string::compare("") != 0) {

        int p1_choice = scores[line.substr(0, 1)];
        int p2_choice = scores[line.substr(2, 3)];

        /* Part 1 
        score += scores[line.substr(2)];
        if (p1_choice == p2_choice) {
            score += scores["draw"];
        }
        else if ((p1_choice == 1 && p2_choice == 3) ||
                 (p1_choice == 2 && p2_choice == 1) ||
                 (p1_choice == 3 && p2_choice == 2) ) {

                 
           score += scores["defeat"];
        }
        
        else {
            score += scores["victory"];
        } 
        */

       // Part 2
       if (p2_choice == 2) {
        score += p1_choice + scores["draw"];
       }
       else if (p2_choice == 1) {
        if (p1_choice == 1) {
            score += 3;
        }
        else if (p1_choice == 2) {
            score += 1;
        }
        else if (p1_choice == 3) {
            score += 2;
        }
       }
       else if (p2_choice == 3) {
        if (p1_choice == 1) {
            score += 2;
        }
        else if (p1_choice == 2) {
            score += 3;
        }
        else if (p1_choice == 3) {
            score += 1;
        }
        score += scores["victory"];

       }

        getline(input, line, '\n');
    }
    return score;

}

int main() {
    std::map<std::string, int> scores;
    
    scores["A"] = 1; // Rock
    scores["X"] = 1;
    scores["B"] = 2; // Paper
    scores["Y"] = 2;
    scores["C"] = 3; // Scissor
    scores["Z"] = 3;
    scores["defeat"] = 0;
    scores["draw"] = 3;
    scores["victory"] = 6;

    std::cout << "The final score is \n" << calculate_score(scores) << '\n';
}
