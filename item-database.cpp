#include "item-database.h"
#include <string>

Item::Item(std::string NAME, std::string DESC, int TYPE, int ATK, int DEF, int MATK, int MDEF, int FUNC, int PRICE, bool BUYABLE, int NUM_OWNED, int BOUGHT)

{
        ItemName  = NAME;
        ItemDesc  = DESC;
        ItemType  = TYPE;
        ItemAtk   = ATK;
        ItemDef   = DEF;
        ItemMatk  = MATK;
        ItemMdef  = MDEF;
        ItemFunc  = FUNC;
        ItemPrice = PRICE;
        Buyable   = BUYABLE;
        ItemOwned = NUM_OWNED;
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
int Item::PRICE()
{
    return ItemPrice;
};
bool Item::BUYABLE()
{
    return Buyable;
};
int Item::NUM_OWNED()
{
    return ItemOwned;
};

int Item::BOUGHT()
{
  ItemOwned++;
  return 1;
};




