/*
** Project Name mysteryWord
** File: main.cpp
** Created by VASSEUR Maxence, on 2019-04-29
** Copyright (c), VASSEUR Maxence
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string randomPos(std::string word)
{
    std::string ret;
    int position(0);

    while ((int)word.size()) {
        position = rand() % (int)word.size();
        ret += word[position];
        word.erase((unsigned long)position, 1);
    }
    return (ret);
}

std::string getWordFromDico(std::string path)
{
    std::ifstream dico(path);
    std::vector <std::string> tblWord;
    std::string word;
    int random(0);

    if (!dico)
        exit(84);
    while (getline(dico, word))
        tblWord.push_back(word);
    random = rand() % 200 + 1;
    return (tblWord[random]);
}


void playGame(void)
{
    std::string word, newWord, proposal, rematch;
    int nbTry(5);

    word = getWordFromDico("../dico.txt");
    if (word.empty())
        exit(84);
    newWord = randomPos(word);
    do {
        std::cout << std::endl << "You got " << nbTry << " try!" << std::endl << "What is this word:  " << std::endl;
        std::cout << newWord << std::endl;
        std::cin >> proposal;
        if (proposal == word)
            std::cout << "GG WP !" << std::endl;
        else
            std::cout << "False, retry..." << std::endl;
        nbTry--;
    } while (proposal != word && nbTry);
    if (!nbTry)
        std::cout << "You Loose" << std::endl << std::endl;
    std::cout << "Do you want to play again? (o/N) ";
    if ((std::cin >> rematch) && rematch == "o")
        playGame();
}

int main(int ac, char **av) {
    playGame();
    return (0);
}