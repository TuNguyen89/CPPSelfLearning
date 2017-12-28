/**
* @ingroup 
*/


#include "ArgsParserLib.h"

using namespace UTILITY;

BoolArgumentMarshaler::BoolArgumentMarshaler()
    : boolValue(false)
{

}

void BoolArgumentMarshaler::set(string args)
{
    boolValue = true;
}

bool BoolArgumentMarshaler::get()
{
    return boolValue;
}