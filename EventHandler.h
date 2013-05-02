#include <string>
class EventHandler
{
public:
    EventHandler();
    EventHandler(int Event);

    int Get_Event();
    int Set_Event();

private:
    int EventsFlagged;
};
