#include "include/game_menu.h"

void GameMenu::showMainMenu()
{
    std::string choice;
    while(true)
    {
        std::cout << "\n--- Главное меню ---\n";
        std::cout << "1. Выбрать персонажа\n";
        std::cout << "2. Выбрать оружие\n";
        std::cout << "3. Выбрать предметы\n";
        std::cout << "4. Начать игру\n";
        std::cout << "5. Выйти\n";
        std::cout << "Введите номер действия: ";
        std::cin >> choice;
        if (choice == "5")
        {
            setPointChanger(-1);
            break;
        }
        else if (choice == "4")
        {
            checkReady();
            if (getPointChanger() == 1)
            {
                break;
            }
        }
        else if (choice == "3")
        {
            chooseItem();
        }
        else if (choice == "2")
        {
            chooseWeapon();
        }
        else if (choice == "1")
        {
            chooseHero();
        }
        else
        {
            std::cout << "Неверный ввод" << "\n";
        }
    }
}

void GameMenu::chooseHero()
{
    std::cout << "\nВыбор персонажа:\n";
    std::cout << "1. Воин\n2. Маг\n3. Лучник\n4. Назад\n";
    std::string choice;
    while(true)
    {
        std::cin >> choice;
        if (choice == "1")
        {
            currentHero = "Воин";
            break;
        }
        else if (choice == "2")
        {
            currentHero = "Маг";
            break;
        }
        else if (choice == "3")
        {
            currentHero = "Лучник";
            break;
        }
        else if (choice == "4")
        {
            return;
        }
        else
        {
            std::cout << "Неверный ввод\n"; 
        }
    }
    std::cout << "Теперь ваш герой " << currentHero << "\n";
}

void GameMenu::chooseItem()
{
    currentItems.clear();
    std::cout << "\nВыбор предметов (до 3):\n";
    std::cout << "1. Зелье здоровья\n2. Свиток огня\n3. Зелье энергии\n4. Выход\n";
    std::string choice;
    while (currentItems.size() < 3)
    {
        std::cin >> choice;
        if (choice == "1")
        {
            currentItems.push_back("Зелье здоровья");
        }
        else if (choice == "2")
        {
            currentItems.push_back("Свиток огня");
        }
        else if (choice == "3")
        {
            currentItems.push_back("Зелье энергии");
        }
        else if (choice == "4")
        {
            break;
        }
        else
        {
            std::cout << "Неверный ввод\n";
        }
    }
    if (!currentItems.empty())
    {
        std::cout << "Теперь ваши предметы - это:\n";
        for (size_t i = 0; i < currentItems.size(); i++)
        {
            std::cout << currentItems[i] << "\n";
        }
    }
    else
    {
        std::cout << "Ваш инвентарь пуст\n";
    }
}

void GameMenu::chooseWeapon()
{
    std::cout << "\nВыбор оружия:\n";
    std::cout << "1. Меч\n2. Посох\n3. Лук\n4. Back\n";
    std::string choice;
    while(true)
    {
        std::cin >> choice;
        if (choice == "1")
        {
            currentWeapon = "Меч";
            break;
        }
        else if (choice == "2")
        {
            currentWeapon = "Посох";
            break;
        }
        else if (choice == "3")
        {
            currentWeapon = "Лук";
            break;
        }
        else if (choice == "4")
        {
            return;
        }
        else
        {
            std::cout << "Неверный ввод\n";
        }
    }
    std::cout << "Теперь ваше оружие: " << currentWeapon << "\n";
}

void GameMenu::checkReady()
{
    if (currentHero.empty() || currentWeapon.empty())
    {
        std::cout << "Вам нужен герой и оружие\n";
    }
    else
    {
        std::cout << "Начать с " << currentHero << " и " << currentWeapon << "\n";
        if (!currentItems.empty())
        {
            std::cout << "Ваши предметы: ";
            for (auto &item: currentItems)
            {
                std::cout << item << " ";
            }
            std::cout << "\n";
        }
        setPointChanger(1);
    }
}

std::string GameMenu::getCurrentHero()
{
    return currentHero;
}