/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

# System Description

### Overview

The system is a turn-based console game developed in **C++**, where the player selects a hero, weapon, and items before engaging in a battle against an bot. The game emphasizes strategic decision-making during hero customization and combat, offering a simple yet engaging gameplay experience.

---

### Key Components

The system is composed of the following main components:

1. **GameController**  
   - Manages the overall flow of the game.  
   - Initializes the game menu and transitions between different states (e.g., selection, battle).  
   - Coordinates interactions between the player and the game logic.

2. **GameMenu**  
   - Handles user interaction in the main menu.  
   - Provides options for selecting a hero, weapon, and items.  
   - Validates player choices and ensures readiness for battle.  
   - Key methods:  
     - `showMainMenu()`: Displays the main menu and processes user input.  
     - `chooseHero()`, `chooseWeapon()`, `chooseItem()`: Handle selection of heroes, weapons, and items.  
     - `checkReady()`: Ensures the player has selected a hero and weapon before starting the battle.

3. **GameFighter**  
   - Manages the battle logic between the player and the bot.  
   - Handles turn-based combat, including attacks, item usage, and special abilities.  
   - Key methods:  
     - `startFight()`: Initiates and manages the battle loop.  
     - `showInventory()`: Displays the player's inventory and allows item usage.  
     - `showStatsInfo()`: Displays the stats of the player and the bot.  
   - Dynamically creates heroes, weapons, and items based on player choices.

4. **Hero**  
   - A base class representing the player's and bot's characters.  
   - Contains attributes such as health, energy, and attack power.  
   - Provides methods for attacking, taking damage, and using special abilities.  
   - Derived classes: `Berserk`, `Mage`, `Archer`, `Vampire`, `Goblin`.

5. **Weapon**  
   - A base class representing weapons.  
   - Defines attributes such as damage output and energy cost per attack.  
   - Derived classes: `Sword`, `MagicStaff`, `Bow`, `Cudgel`, `CrimsonGrail`.
   - After using an attack with a weapon, it will improve its characteristics.

6. **Item**  
   - A base class representing consumable items.  
   - Provides effects such as healing, energy restoration, or debuffs.  
   - Derived classes: `HealthPotion`, `EnergyPotion`, `DebuffBomb`.

7. **Bot**  
   - Represents the AI opponent.  
   - Creates a hero, weapon, and inventory for the bot.  
   - Implements logic for selecting attacks and using items during combat.

---

### System Workflow

1. **Initialization**:  
   - The `GameController` initializes the game and loads the `GameMenu`.

2. **Hero and Equipment Selection**:  
   - The player selects a hero, weapon, and items through the `GameMenu`.  
   - The `GameController` validates the selections and ensures readiness for battle.

3. **Battle Phase**:  
   - The `GameFighter` takes control, managing the turn-based combat between the player and the bot.  
   - The player and bot take turns performing actions such as attacking, using items, or applying special abilities.  
   - The battle continues until either the player or the bot is defeated.

4. **Outcome Determination**:  
   - The `GameFighter` evaluates the battle results and declares a winner.  
   - The game can either end or return to the selection phase for a new round.

---

### Key Features

- **Customizable Heroes**: Players can choose from different heroes (`Berserk`, `Mage`, `Archer`), each with unique attributes and abilities.  
- **Weapon Selection**: Players can equip weapons (`Sword`, `MagicStaff`, `Bow`) to enhance their combat capabilities.  
- **Item Usage**: Players can use items (`Health Potion`, `Energy Potion`, `Debuff Bomb`) strategically during battles.  
- **AI Opponent**: The bot chooses actions randomly, which makes it a bit like a player
- **Turn-Based Combat**: The game emphasizes strategic decision-making during battles.  

---

### Example Interaction

1. The player starts the game and selects a hero (e.g., `Berserk`), a weapon (e.g., `Sword`), and items (e.g., `Health Potion`).  
2. The player enters the battle phase, where they take turns attacking the bot or using items.  
3. The battle continues until one side is defeated, and the winner is declared.  
4. The player can restart the game or exit.

---

### Code Structure

```
/LabWork2
 ├── /include 
 │ ├── archer.h 
 │ ├── berserk.h
 │ ├── bot.h
 │ ├── bow.h
 │ ├── crimson_grail.h
 │ ├── cudgel.h 
 │ ├── debuff_bomb.h 
 │ ├── energy_potion.h 
 │ ├── game_controller.h 
 │ ├── game_fighter.h 
 │ ├── game_menu.h 
 │ ├── goblin.h 
 │ ├── health_potion.h 
 │ ├── hero.h 
 │ ├── item.h 
 │ ├── mage.h 
 │ ├── magic_staff.h 
 │ ├── sword.h 
 │ ├── vampire.h 
 │ └── weapon.h 
 ├── /src 
 │ ├── archer.cpp 
 │ ├── berserk.cpp 
 │ ├── bot.cpp 
 │ ├── bow.cpp 
 │ ├── crimson_grail.cpp 
 │ ├── cudgel.cpp 
 │ ├── debuff_bomb.cpp 
 │ ├── energy_potion.cpp 
 │ ├── game_controller.cpp 
 │ ├── game_fighter.cpp 
 │ ├── game_menu.cpp 
 │ ├── goblin.cpp 
 │ ├── health_potion.cpp 
 │ ├── hero.cpp 
 │ ├── item.cpp 
 │ ├── mage.cpp 
 │ ├── magic_staff.cpp 
 │ ├── sword.cpp 
 │ ├── vampire.cpp 
 │ └── weapon.cpp 
 ├── /tests 
 │ └── ... 
 ├── main.cpp 
 ├── Makefile 
 └── README.md 
 ```