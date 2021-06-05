#include "ConfirmRestorePage.h"

void ConfirmRestorePage::mountPage() {
    Page::allocateStaticContents(staticContents, 2);
    countDownTimer.setLinkage(&staticContents[ContentIndex::SecondCounter]);
    countDownTimer.setTimer(5000);
    countDownTimer.start();
}

void ConfirmRestorePage::updateContents() {
    countDownTimer.updateContent();
    if (countDownTimer.isFinish())
        ESP.restart();
}