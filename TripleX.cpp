#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
  // Print Game Instructions
  if (Difficulty == 1)
  {
    std::cout << "   .____.\n   |BTC |\n __|____|__\n|  ______  |\n  /.::::.|\n /.::::::.|";
    std::cout << "\n\nTi si haker koji je pronasao BTC wallet sa level " << Difficulty;
    std::cout << " security zastitom!\nTvoj zadatak je da pogodis lozinku...\n\n";
  }
  else
  {
    std::cout << " BTC wallet je sa level " << Difficulty;
    std::cout << " security zastitom!\nPogodi lozinku...\n\n";
  }
  
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  // Declare 3 number codes
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  // Print CodeSum and CodeProduct
  std::cout << "- Postoje tri broja u delicu lozinke\n";
  std::cout << "+ Zbir cifara je: " << CodeSum;
  std::cout << "\n+ Proizvod cifara je: " << CodeProduct;

  // Player Guess
  int GuessA, GuessB, GuessC;

  std::cout << "\n\n- Pogodi cifre koje daju zbir i proizvod: \n";
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if correct guess
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    std::cout << "\n\n+ Lozinka je tacna!";
    if (Difficulty <= 4)
    {
      std::cout << "\nUspesno si otkljucao BTC wallet!\n";
      std::cout << "Sledeci";
    }

    return true;
  }
  else 
  {
    std::cout << "\n\n- Lozinka nije tacna!";
    std::cout << "\n+ Pokusaj ponovo!\n";
    std::cout << "Trenutni";

    return false;
  }
}

int main()
{
  srand(time(NULL)); // random seed based on computer time

  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;

  while (LevelDifficulty <= MaxDifficulty) // Loop game until complete
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //Clears Errors
    std::cin.ignore(); //Discards Buffer

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
    
  }

  std::cout << "\n\n++Otkljucao si sve BTC wallete!";
  std::cout << "\n++Cestitam!";

  return 0;
}