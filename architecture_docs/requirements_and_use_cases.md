/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

# Requirements and Use Cases

## System Requirements

The project has been tested and developed under the following environment:

### Compiler

- **g++** version: `11.4.0`  
- Compilation flag: `-std=c++17`

### Libraries

- Standard C++ libraries, including:
  - `<vector>`
  - `<random>`
  - `<iostream>`
- Unit testing is implemented using **Google Test**:
  - Header: `<gtest/gtest.h>`

### Functional Requirements

1. **Hero Selection**  
   - The system must allow the player to choose a hero from the following options:  
     - Berserk  
     - Mage  
     - Archer  
   - The selected hero must have unique attributes (health, energy, damage).

2. **Weapon Selection**  
   - The system must allow the player to choose a weapon from the following options:  
     - Sword  
     - Magic Staff  
     - Bow  
   - Each weapon must have unique damage and energy cost attributes.

3. **Item Selection**  
   - The system must allow the player to select up to 3 items from the following options:  
     - Health Potion  
     - Energy Potion  
     - Debuff Bomb  
   - Items must provide specific effects when used during battle.

4. **Battle System**  
   - The system must implement a turn-based battle system where the player and the bot take turns to perform actions.  
   - The player must be able to:  
     - Perform a default attack.  
     - Perform a weapon attack (consumes energy).  
     - Use a special ability (hero-specific).  
     - Use items from the inventory.  
   - The bot must automatically select actions based on predefined logic.

5. **Inventory Management**  
   - The system must allow the player to view and use items during battle.  
   - Used items must be removed from the inventory.

6. **Win/Loss Conditions**  
   - The system must determine the winner based on the health of the player and the bot.  
   - The game must end when either the player or the bot reaches 0 health.

---

### Non-Functional Requirements

1. **Performance**  
   - The game must respond to user input within 1 second.  
   - The battle system must process turns without noticeable delays.

2. **Usability**  
   - The game must provide clear instructions and feedback to the player.  
   - The menu system must be intuitive and easy to navigate.

3. **Error Handling**  
   - The system must handle invalid user input gracefully and provide appropriate error messages.

---

## Use Cases

### Use Case 1: Select Hero

**Actor**: Player  
**Precondition**: The game is in the main menu.  
**Main Flow**:  
1. The player selects the "Choose a hero" option.  
2. The system displays available heroes: Berserk, Mage, Archer.  
3. The player selects a hero.  
4. The system confirms the selection and updates the player's hero.  
**Postcondition**: The player has a selected hero.

---

### Use Case 2: Select Weapon

**Actor**: Player  
**Precondition**: The game is in the main menu.  
**Main Flow**:  
1. The player selects the "Choose a weapon" option.  
2. The system displays available weapons: Sword, Magic Staff, Bow.  
3. The player selects a weapon.  
4. The system confirms the selection and updates the player's weapon.  
**Postcondition**: The player has a selected weapon.

---

### Use Case 3: Select Items

**Actor**: Player  
**Precondition**: The game is in the main menu.  
**Main Flow**:  
1. The player selects the "Choose items" option.  
2. The system displays available items: Health Potion, Energy Potion, Debuff Bomb.  
3. The player selects up to 3 items.  
4. The system confirms the selection and updates the player's inventory.  
**Postcondition**: The player has selected items in their inventory.

---

### Use Case 4: Start Battle

**Actor**: Player  
**Precondition**: The player has selected a hero and a weapon.  
**Main Flow**:  
1. The player selects the "Start a game" option.  
2. The system initializes the battle with the player's selected hero, weapon, and items.  
3. The system creates a bot with a random hero, weapon, and items.  
4. The battle begins, and the player and bot take turns performing actions.  
**Postcondition**: The battle is ongoing.

---

### Use Case 5: Perform Attack

**Actor**: Player  
**Precondition**: The battle is ongoing, and it is the player's turn.  
**Main Flow**:  
1. The player selects the "Default attack" or "Attack with a weapon" option.  
2. The system calculates the damage and applies it to the bot.  
3. The system updates the bot's health and displays the result.  
**Postcondition**: The bot's health is reduced, and the turn ends.

---

### Use Case 6: Use Item

**Actor**: Player  
**Precondition**: The battle is ongoing, and it is the player's turn.  
**Main Flow**:  
1. The player selects the "Open inventory" option.  
2. The system displays the player's items.  
3. The player selects an item to use.  
4. The system applies the item's effect (e.g., healing, energy restoration, debuff).  
5. The used item is removed from the inventory.  
**Postcondition**: The item's effect is applied, and the turn ends.

---

### Use Case 7: End Battle

**Actor**: System  
**Precondition**: The battle is ongoing.  
**Main Flow**:  
1. The system checks the health of the player and the bot.  
2. If either the player or the bot reaches 0 health, the system declares the winner.  
3. The system displays the result and returns to the main menu.  
**Postcondition**: The battle ends, and the game returns to the main menu.

---

### Use Case 8: Quit Game

**Actor**: Player  
**Precondition**: The game is in the main menu.  
**Main Flow**:  
1. The player selects the "Quit" option.  
2. The system terminates the game.  
**Postcondition**: The game is closed.