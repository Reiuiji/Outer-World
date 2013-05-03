#include <string>
class Item
{
public:
    Item();
    Item(std::string NAME, std::string DESC, int TYPE, int ATK, int DEF, int MATK, int MDEF, int FUNC, int PRICE, bool BUYABLE, int NUM_OWNED, int BOUGHT, int DISCARD);

    std::string NAME();
    std::string DESC();
    int TYPE();
    int ATK();
    int DEF();
    int MATK();
    int MDEF();
    int FUNC();
    int PRICE();

    bool BUYABLE();
    int NUM_OWNED();
    int BOUGHT();
    int DISCARD();

private:
     std::string ItemName;
     std::string ItemDesc;
     int ItemType;
     int ItemAtk;
     int ItemDef;
     int ItemMatk;
     int ItemMdef;
     int ItemFunc;
     int ItemPrice;

     bool Buyable;
     int ItemOwned;
};

