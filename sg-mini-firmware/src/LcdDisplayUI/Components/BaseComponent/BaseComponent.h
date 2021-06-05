#ifndef BaseComponent_h
#define BaseComponent_h

#include "../PageContent/PageContent.h"

class BaseComponent {
    public:
        /**
         * @brief Set the Linkage between the PageContent object and the BaseComponent object
         * 
         * @param pageContent - PageContent object pointer 
         */
        void setLinkage(PageContent *pageContent);
        virtual void updateContent();
    
    protected:
        PageContent *connectContent;
};

#endif