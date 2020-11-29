#ifndef Page_h
#define Page_h

#include "../UI/Components/PageContent/PageContent.h"
#include "../UI/Components/PageLayoutPosition/PageLayoutPosition.h"

class Page {
  public:
    virtual void getContents(PageContent **contents, int *length) = 0;
};

#endif