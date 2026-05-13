#include "AcademicEntity.h"

AcademicEntity::AcademicEntity(string id, string n, string e, string fp)
{
    ID = id;
    name = n;
    email = e;
    file_path = fp;
}

AcademicEntity::~AcademicEntity() {}