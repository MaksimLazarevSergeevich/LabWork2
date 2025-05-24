/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

# Testing Plan

## Unit Testing

### 1. **Hero Class**
   - **Test Case 1**: Verify that a hero's health is correctly reduced when taking damage.  
   - **Test Case 2**: Verify that a hero's energy is correctly reduced when using a weapon attack.  
   - **Test Case 3**: Verify that a hero's special ability works as expected.  

### 2. **Weapon Class**
   - **Test case 1**: Verify that all characteristics are correctly incremented. 

### 3. **Item Class**
   - **Test Case 1**: Verify that a Health Potion restores the correct amount of health.  
   - **Test Case 2**: Verify that an Energy Potion restores the correct amount of energy.  
   - **Test Case 3**: Verify that a Debuff Bomb reduces the target's stats correctly. 

### 4. **Bot Class**
   - **Test case 1**: Verify that the bot is created correctly.

---

## System Testing

### 1. **Game Flow**
   - **Test Case 1**: Verify that the game transitions correctly from the main menu to the battle phase.  
   - **Test Case 2**: Check that the battle ends when one of the heroes has 0 health.

### 2. **User Input Handling**
   - **Test Case 1**: Verify that the system handles invalid input gracefully (e.g., entering text instead of numbers).  
   - **Test Case 2**: Verify that the system provides appropriate feedback for invalid selections.  

---

## Memory Testing with Valgrind

### 1. **Memory Leak Detection**
   - **Test Case 1**: Run the game with Valgrind to ensure there are no memory leaks.  
     ```bash
     valgrind --leak-check=full ./game
     ```
   - **Expected Result**: No memory leaks should be reported.

### 2. **Invalid Memory Access Detection**
   - **Test Case 1**: Use Valgrind to check for invalid memory access (e.g., use of uninitialized memory, out-of-bounds access).  
     ```bash
     valgrind --tool=memcheck ./game
     ```
   - **Expected Result**: No invalid memory access should be reported.

### 3. **Memory Corruption Detection**
   - **Test Case 1**: Use Valgrind to detect memory corruption (e.g., double free, invalid free).  
     ```bash
     valgrind --tool=memcheck ./game
     ```
   - **Expected Result**: No memory corruption should be reported.

---