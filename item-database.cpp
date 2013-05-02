#include "item-database.h"
#include <string>

Item::Item( std::string NAME, std::string DESC, int TYPE, int ATK, int DEF, int MATK, int MDEF, bool OWN, int FUNC)
{
        ItemName  = NAME;
        ItemDesc  = DESC;
        ItemType  = TYPE;
        ItemAtk   = ATK;
        ItemDef   = DEF;
        ItemMatk  = MATK;
        ItemMdef  = MDEF;
        ItemOwned = OWN;
        ItemFunc  = FUNC;
};

std::string Item::NAME()
{
    return ItemName;
};

std::string Item::DESC()
{
    return ItemDesc;
};

int Item::TYPE()
{
    return ItemType;
};

int Item::ATK()
{
    return ItemAtk;
};

int Item::DEF()
{
    return ItemDef;
};

int Item::MATK()
{
    return ItemMatk;
};

int Item::MDEF()
{
    return ItemMdef;
};

int Item::FUNC()
{
    return ItemFunc;
};

bool Item::OWN()
{
    return ItemOwned;
};
