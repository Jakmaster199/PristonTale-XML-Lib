include "ItemParser.h"

extern sDEF_ITEMINFO* DefaultItems;
sDEF_ITEMINFO DefItems;
sDEF_ITEMINFO* lpDefItem;
sITEMINFO* lpItem;


ItemParser::ItemParser() {}
ItemParser::~ItemParser() {}

void ItemParser::LoadFile(XMLFilePath) {
    XMLParsedDocument = xml_loaded_document.load_file(XMLFilePath);
}

void ItemParser::LoadItemInfo() {

    DefaultItemCount = 0;
    lpDefItem = &DefaultItems[DefaultItemCount];
    lpItem = &lpDefItem->Item;

    ZeroMemory(lpDefItem, sizeof(sDEF_ITEMINFO));


    xml_node item_tree = XMLDocument.child("Items");

    for (xml_node item = item_tree.child("item"); item; item = item.next_sibling("item")) {

        // Item Name
        lpItem->ItemName = item.attribute("name").value();

        &lpItem->itemType = item.find_child_by_attribute("set", "name", "weapon_type").attribute("value").value();
        &lpItem->Price = item.find_child_by_attribute("set", "name", "price").attribute("value").value();

        // Stats Node
        xml_node ItemStats = item.child("stats");

        // Requirements Node
        xml_node ItemRequirements = item.child("req");

        &lpItem->Level = item.find_child_by_attribute("base", "stat", "level").attribute("value").value();
        &lpItem->Spirit = item.find_child_by_attribute("base", "stat", "spirit").attribute("value").value();
        &lpItem->Dexterity = item.find_child_by_attribute("base", "stat", "agility").attribute("value").value();
        &lpItem->Strength = item.find_child_by_attribute("base", "stat", "strength").attribute("value").value();
        &lpItem->Talent = item.find_child_by_attribute("base", "stat", "talent").attribute("value").value();


    }
}