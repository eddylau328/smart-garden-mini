#ifndef LoadingSpinner_h
#define LoadingSpinner_h

#include <millisDelay.h>

#include "../PageContent/PageContent.h"
#include "../../CustomCharacter/CustomCharacter.h"

class LoadingSpinner {
  
  public:
    /**
     * @brief Set the Linkage between the PageContent object and the InputTool object
     * 
     * @param pageContent - PageContent object pointer for showing the input content
     */
    void setLinkage(PageContent *pageContent);
    void updateSpinner();
    bool isSpinning();
    void spin(bool isSpin);
    void clear();

  private:
    bool isEnableSpin = false;
    int8_t loadingIndex = 0;
    millisDelay loadingUpdateDelay;
    PageContent *connectContent;

};

#endif 