#include <string>
class Item
{
public:
    Item();
    Item( std::string NAME, std::string DESC, int TYPE, int ATK, int DEF, int MATK, int MDEF, bool OWN, int FUNC);

    std::string NAME();
    std::string DESC();
    int TYPE();
    int ATK();
    int DEF();
    int MATK();
    int MDEF();
    int FUNC();
    bool OWN();

private:
     std::string ItemName;
     std::string ItemDesc;
     int ItemType;
     int ItemAtk;
     int ItemDef;
     int ItemMatk;
     int ItemMdef;
     int ItemFunc;
     bool ItemOwned;
};

