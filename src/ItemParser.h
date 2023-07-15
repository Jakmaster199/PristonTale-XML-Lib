#include <string>
#include "pugixml.hpp"
using namespace pugi;

class ItemParser
{
private:
    std::string XMLFilePath
    xml_document XMLDocument
    xml_parse_result XMLParsedDocument

public:
    ItemParser();
    ~ItemParser();

    void LoadFile;
    void LoadItemInfo;
};
