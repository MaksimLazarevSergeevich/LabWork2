#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
class GameController
{
public:
    void startGame();
    void setPointChanger(int);
    int getPointChanger();
private:
    int _pointChanger = 0;
};
#endif