#ifndef Page_h
#define Page_h

#include <Arduino.h>
#include "../../Config/Config.h"
#include "../Components/PageContent/PageContent.h"
#include "../Components/PageLayoutPosition/PageLayoutPosition.h"

class Page {
  public:
    virtual void mountPage();
    virtual void getContents(PageContent **contents, int *length) = 0;
    virtual void updateContents();
    virtual void interactiveUpdate(int counter, bool isPress);
    virtual void dismountPage();
    void setNextPageCallback(uint8_t key, void (*callback)(uint8_t));
  protected:
    uint8_t pageKey;
    void (*nextPageCallback)(uint8_t);
};

#endif