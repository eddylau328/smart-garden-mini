#include "BaseComponent.h"


void BaseComponent::setLinkage(PageContent *pageContent) {
  this->connectContent = pageContent; 
}

void BaseComponent::updateContent() {}