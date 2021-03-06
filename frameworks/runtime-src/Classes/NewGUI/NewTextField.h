/*
 *
 *
 *  Created on: Jun 28, 2016
 *      Author: Quyet Nguyen
 */

#ifndef NEWGUI_TEXT_FIELD_H_
#define NEWGUI_TEXT_FIELD_H_

#include "cocos2d.h"
USING_NS_CC;

//TextFieldTTF

namespace quyetnd {
enum TextFieldAlignment{
	CENTER = 0,
	LEFT = 1
};

enum TextChangeType{
	INSERT = 1,
	DELETE = 2
};

class TextField;
typedef std::function<bool(TextField*)> TextFieldReturnCallback;

class TextField : public Node, public IMEDelegate{
	bool _isEnable;
	bool _keyboardMe;
	bool _keyboardShowMe;
	bool _autoDetachWithIME;
	bool _TextFieldTTF;
	int _alignment;
	int maxLength;

	TextFieldReturnCallback _returnCallback;
	std::function<void(bool)> _focusCallback;
	std::function<bool(int, const std::string&)> _textChangeCallback;
protected:
	Label* _textLabel;
	Label* _placeHolderLabel;
	ClippingRectangleNode* clippingNode;
	Node* _cursorSprite;

	std::string inputText;

	Rect _touchRect;
	EventListener* _touchListener;
	bool isAttachWithIME;
	bool isPassword;

	virtual bool canAttachWithIME();
	virtual bool canDetachWithIME();

	virtual void didAttachWithIME();
	virtual void didDetachWithIME();
	virtual void insertText(const char * text, size_t len);
	virtual void deleteBackward();
	virtual const std::string& getContentText();

	virtual void keyboardWillShow(IMEKeyboardNotificationInfo& info);
	virtual void keyboardDidShow(IMEKeyboardNotificationInfo& info);
	virtual void keyboardWillHide(IMEKeyboardNotificationInfo& info);
	virtual void keyboardDidHide(IMEKeyboardNotificationInfo& info);

	virtual void updateText();
	virtual void updateTextSize();
	virtual void updateTextSizeCenter();
	virtual void updateTextSizeLeft();
	bool checkVisible();
public:
	TextField();
	virtual ~TextField();
	void initWithSize(const Size& size);
	void initWithTTFFont(const Size& size, const std::string& textFont, float textFontSize, const std::string& placeHolderFont = "", float placeHolderFontSize = -1);
	void initWithBMFont(const Size& size, const std::string& textFont, const std::string& placeHolderFont = "");

	void setPlaceHolder(const std::string& placeHolder);
	void setText(const std::string& text);
	const std::string& getText();
	
	void setTextColor(const Color3B& color);
	void setPlaceHolderColor(const Color3B& color);

	void setTextColor(const Color4B& color);
	void setPlaceHolderColor(const Color4B& color);

	void setPasswordEnable(bool isPassword);
	void setMaxLength(int maxLength);

	void setReturnCallback(const TextFieldReturnCallback& callback);
	void setFocusListener(std::function<void(bool)>& callback);
	void setTextChangeListener(std::function<bool(int, const std::string&)>& callback);

	void setAlignment(int alignment);

	void showKeyboard();
	void hideKeyboard();

	void setEnable(bool isEnable);

	void onEnter();
	void onExit();

	virtual bool attachWithIME() override;
	virtual bool detachWithIME() override;

	static TextField* createWithTTFFont(const Size& size, const std::string& textFont, float textFontSize, const std::string& placeHolderFont = "", float placeHolderFontSize = -1);
	static TextField* createWithBMFont(const Size& size, const std::string& textFont, const std::string& placeHolderFont = "");
};

} /* namespace quyetnd */

#endif /* NEWGUI_TEXT_FIELD_H_ */
