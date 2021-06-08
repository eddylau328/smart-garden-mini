#include "InputCharacter.h"

InputCharacter::~InputCharacter() {
    destroy();
}

void InputCharacter::init(int8_t displayRange, int8_t bufferSize) {
    destroy();
    this->bufferSize = bufferSize;
    buffer = new char[bufferSize + 1];
    valueIndex = 0;
    showIndex = 0;
    this->displayRange = displayRange;
    for (int i = 0 ; i < bufferSize; i++)
        *(buffer + i) = ' ';
    *(buffer + bufferSize) = '\0';
    connectContent->updateContent(buffer, displayRange, showIndex); 
}

void InputCharacter::destroy() {
    if (buffer != NULL) {
        delete[] buffer;
        buffer = NULL;
    }
}

void InputCharacter::set(const char* defaultValue, int8_t stringLength) {
    // copy the default to the buffer
    Helper::copyString(buffer, defaultValue, stringLength);
    for (int i = 0 ; i < stringLength ; i++)
        if (!(Helper::isInRange((int) *(buffer+i), 32, 126)))
            *(buffer + i) = ' ';
    connectContent->updateContent(buffer, stringLength, showIndex);
}

void InputCharacter::blinkUpdate() {
    if (isBlink && connectContent && inputTriggerDelay.justFinished()) {
        if (isBlinking) {
            Helper::copyString(copyBuffer, connectContent->getContent(), displayRange);
            *(copyBuffer + valueIndex - showIndex) = '_';
            connectContent->updateContent(copyBuffer, displayRange, 0);
        }
        else {
            char blinkChar = *(buffer + valueIndex);
            if (isSpecialCharValue(blinkChar)) {
                int8_t customCharacterIndex = getSpecialCharIndex(blinkChar);
                connectContent->setCustomCharacterIndex(customCharacterIndex, valueIndex - showIndex, true);
            }
            else
                connectContent->updateContent(buffer, displayRange, showIndex);
        }
        isBlinking = !isBlinking;
        inputTriggerDelay.repeat();
    }
}

bool InputCharacter::interactiveUpdate(int counter, bool isPress) {
    char currentValue = *(buffer + valueIndex);
    if (isPress && isSpecialCharValue(currentValue)) {
        int8_t specialCharIndex = getSpecialCharIndex(currentValue);
        *(buffer + valueIndex) = ' ';
        if (specialCharIndex == CUSTOM_BACKSPACE)
            valueIndex--;
        showIndex = valueIndex - displayRange < 0 ? 0 : valueIndex - displayRange + 1;
        connectContent->updateContent(buffer, displayRange, showIndex);
        if (specialCharIndex == CUSTOM_ENTER) {
            resetInput();
            return true;
        }
        return false;
    }

    if (isPress) {
        valueIndex++;
        if (valueIndex >= bufferSize) {
            resetInput();
            return true;
        }
        showIndex = valueIndex - displayRange < 0 ? 0 : valueIndex - displayRange + 1;
        connectContent->updateContent(buffer, displayRange, showIndex);
        return false;
    }

    if (!connectContent)
        return true;

    char value = *(buffer + valueIndex) + counter;
    char newValue = isCircleLoop? validateCircleLoopCharValue(value) : validateCharValue(value);
    *(buffer + valueIndex) = newValue;
    if (isSpecialCharValue(newValue)) {
        int8_t customCharacterIndex = getSpecialCharIndex(newValue);
        connectContent->setCustomCharacterIndex(customCharacterIndex, valueIndex - showIndex, true);
    }
    else
        connectContent->updateContent(buffer, displayRange, showIndex);
    inputTriggerDelay.repeat();
    return false;
}

bool InputCharacter::isSpecialCharValue(char value) {
    return value == 31 || value == 30;
}

int8_t InputCharacter::getSpecialCharIndex(char value) {
    return value == 31 ? CUSTOM_BACKSPACE : CUSTOM_ENTER;
}

char InputCharacter::validateCircleLoopCharValue(char value) {
    if (value < 30)
        value = 127 - (30 - value);
    else if (value > 126)
        value = 29 + (value - 126);
    return value;
}

char InputCharacter::validateCharValue(char value) {
    if (value < 32)
        value = 32;
    else if (value > 128)
        value = 128;
    return value;
}

void InputCharacter::getInputValue(char **ptr, int *length) {
    for (int i = bufferSize - 1; i > 0; i--)
        if (*(buffer + i) != ' ') {
            *(buffer + i + 1) = '\0';
            *length = i + 1;
            break;
        }
    *ptr = buffer;
}

void InputCharacter::resetInput() {
    this->valueIndex = 0;
    this->isBlink = false;
    this->isBlinking = false;
    inputTriggerDelay.stop();
}