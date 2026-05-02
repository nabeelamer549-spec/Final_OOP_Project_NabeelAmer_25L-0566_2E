#include "AcademicEntity.h"
#include <string>

AcademicEntity::AcademicEntity()
{
    id = " ";
    name = " ";
    email = " ";
}
AcademicEntity::AcademicEntity(string nid = " ", string nname = " ", string nemail = " ")
{
    id = nid;
    name = nname;
    email = nemail;
}