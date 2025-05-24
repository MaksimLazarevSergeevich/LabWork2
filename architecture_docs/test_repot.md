/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

# Test report

## Unit Testing

#### Unit tests were added for classes: Weapon, Hero, Bot, Item, GameMenu.

![Passed tests](diagrams/passed_test.png)

## System Testing

#### The game transitions correctly from the main menu to battle

![Main menu to battle](diagrams/correct_start.png)

#### When a hero dies, the winner is displayed correctly

![Show winner](diagrams/output_win.png)

#### If the user enters something incomprehensible, an invalid input is displayed

![incorrect input](diagrams/incorrect_input.png)

## Memory Testing with Valgrind

#### No memory leaks and other memory related errors

![memory chaeck](diagrams/memory_check.png)