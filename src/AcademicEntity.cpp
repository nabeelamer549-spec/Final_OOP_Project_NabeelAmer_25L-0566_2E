#include "AcademicEntity.h"

AcademicEntity::AcademicEntity(string nid, string nname, string nemail)
{
    id = nid;
    name = nname;
    email = nemail;
}

AcademicEntity::~AcademicEntity()
{
}

string AcademicEntity::getId() const
{
    return id;
}

string AcademicEntity::getName() const
{
    return name;
}