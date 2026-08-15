#pragma once
#include "COLstring.h"
#include "COLstream.h"

class COLstreamString : public COLstream{
public:
   COLstreamString();
   ~COLstreamString();

   COLstring m_String;
private:
};
