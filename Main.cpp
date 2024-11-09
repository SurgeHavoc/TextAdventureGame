#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

constexpr int buffer_size = 100;

void StartAdventure();

void DarkForest();
void MonsterFight1();
void GrasslandPlains();
void DesertDunes();
void GameOver();
void VictoryCondition1();
void ClearBuffer();

int main()
{
	std::string buffer;
	int choice;

	std::cout << "Hello World!" << std::endl;

	while (true)
	{
		std::cout << "Main Menu\n";
		std::cout << "--------------------\n";
		std::cout << "1. Play\n";
		std::cout << "2. Quit\n";
		std::cout << "Enter choice: ";
		getline(std::cin, buffer);
		if (buffer.empty())
		{
			ClearBuffer();
			continue;
		}

		try
		{
			choice = stoi(buffer);
		}

		catch (const std::invalid_argument&)
		{
			std::cout << "Please enter a number (1 or 2): ";
			continue;
		}

		switch (choice)
		{
			case 1:
				std::cout << "Option 1 selected.\n";
				StartAdventure();
				ClearBuffer();
				break;
			case 2:
				std::cout << "Option 2 selected.\n";
				return 0;
			default:
				std::cout << "Invalid choice, please enter a 1 or 2.\n";
		}
	}

	return 0;
}

void StartAdventure()
{
	int choice;
	std::cout << "You start on bridge in between the Dark Forest and the Grassland Plains\n";
	std::cout << "1. Enter the Dark Forest\n";
	std::cout << "2. Enter the Grassland Plains\n";
	std::cin >> choice;
	if (choice == 1)
	{
		DarkForest();
	}
	else
	{
		GrasslandPlains();
	}
}

void DarkForest()
{
	std::cout << "The forest is dense, dark, and seemingly hostile.\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Suddenly, you are attacked by an evil monster!\n";
	std::cout << "1. Fight\n";
	std::cout << "2. Try to reason with the monster.\n";
	std::cout << "3. Flee in the other direction.\n";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		MonsterFight1();
	}
	else if (choice == 2)
	{
		std::cout << "The monster did not want to reason with you...\n";
		GameOver();
	}
	else
	{
		std::cout << "You get lost, you turn, finding yourself still lost you turn again and again.\n";
		GrasslandPlains();
	}
}

void MonsterFight1()
{
	std::cout << "You pull out a sword and parry the monster.\n";
	std::cout << "1. Attack the monster directly.\n";
	std::cout << "2. Parry the monster.\n";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << "You defeat the monster with ease.\n";
		GrasslandPlains();
	}
	else
	{
		std::cout << "The monster was aware of your second parry attempted and dodge attacked, dealing a fatal blow.\n";
		GameOver();
	}
}

void GrasslandPlains()
{
	std::cout << "You find yourself in the grassland plains near the dark forest.\n";
	std::cout << "1. Open the treasure chest by a pile of rocks.\n";
	std::cout << "2. Move on to the desert dunes.\n";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << "The treasure chest has gold, congrats! Time for the desert dunes.\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		DesertDunes();
	}
	else
	{
		DesertDunes();
	}
}

void DesertDunes()
{
	std::cout << "You made it to the desert dunes!\n";
	std::cout << "1. Celebrate in the city.\n";
	std::cout << "2. Fight the giant snake.\n";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		VictoryCondition1();
	}
	else
	{
		std::cout << "The snake turns to you and eats you.\n";
		GameOver();
	}
}

void GameOver()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Game over.\n";
}

void VictoryCondition1()
{
	std::cout << "You made it to the city in the dunes! Time to celebrate!\n";
	main();
}

void ClearBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}