/*
 * NewTableView.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: QuyetNguyen
 */

#include "NewTableView.h"
namespace quyetnd{

TableView* TableView::create(const Size& size, int columnSize){
	auto tab = new TableView();
	tab->initWithSize(size, columnSize);
	tab->autorelease();
	return tab;
}

TableView::TableView() {
	// TODO Auto-generated constructor stub
	columnSize = 1;
	marginTop = 0.0f;
	marginBottom = 0.0f;
	marginLeft = 0.0f;
	marginRight = 0.0f;
	padding = 0.0f;
	_isUpdateView = false;

	_runningEffect = false;
	_updateEffect = false;
	_checkParentPageView = false;

	effectMoveSpeed = 4000.0f;
	effectTimeDelayPerColumn = 0.05f;
	effectTimeDelayPerRow = 0.1f;
    
    _handler = nullptr;

	_checkParentPageView = false;
	_parentIsPageView = false;
	_moveThis = false;
	_moveParent = false;
}

TableView::~TableView() {
	// TODO Auto-generated destructor stub
	this->removeAllItems();
}

void TableView::setAnimationHandler(const ItemAnimationHandler& handler){
    _handler = handler;
}
    
void TableView::setDirection(Direction dir){
	if (dir != this->getDirection()){
		auto d = rowSize;
		rowSize = columnSize;
		columnSize = d;
	}
	ui::ScrollView::setDirection(dir);
}
    
void TableView::initWithSize(const Size& size, int columnSize){
	ui::ScrollView::init();
	_direction = ui::ScrollView::Direction::VERTICAL;
	if (columnSize < 1){
		columnSize = 1;
	}
	this->setContentSize(size);
	this->columnSize = columnSize;
	this->setBounceEnabled(true);
}

void TableView::refreshViewVertical(){
	//float width = (this->getContentSize().width - marginLeft - marginRight) / columnSize;
	float allItemWidth = 0.0f;
	float spaceStep, height, itemHeight;
	float defaultItemWidth;
	int zorder = 0;
	Node* item;

	float containerHeight = marginTop + marginBottom;
	for (int i = 0; i < _items.size(); i += columnSize){
		//find max height
//		item = _items[i];
//		itemHeight = item->getContentSize().height * item->getScaleY();
		height = 0.0f;

		for (int j = 0; j < columnSize && (i + j) < _items.size(); j++){
			item = _items[i + j];
			itemHeight = item->getContentSize().height * item->getScaleY();
			if (itemHeight > height){
				height = itemHeight;
			}
		}
		//add height
		containerHeight += (height + padding);
	}
	containerHeight -= padding;
	if (containerHeight < this->getContentSize().height){
		containerHeight = this->getContentSize().height;
	}
    
    spaceStep = 0.0f;
    bool flag = true;
	float y = containerHeight - marginTop;
	for (int i = 0; i < _items.size(); i += columnSize){
		//
		allItemWidth = 0.0f;
//		item = _items[i];
//		itemHeight = item->getContentSize().height * item->getScaleY();
		height = 0.0f;
		for (int j = 0; j < columnSize && (i + j) < _items.size(); j++){
			item = _items[i + j];
			itemHeight = item->getContentSize().height * item->getScaleY();
			if (itemHeight > height){
				height = itemHeight;
			}
			allItemWidth += item->getContentSize().width * item->getScaleX();
		}
//		if (_items.size() - i >= columnSize){
//			spaceStep = (this->getContentSize().width - marginLeft - marginRight - allItemWidth) / (columnSize + 1);
//		}

		if (_items.size() - i < columnSize){
			if(flag){
				item = _items[i];
				defaultItemWidth = item->getContentSize().width * item->getScaleX();
				allItemWidth = defaultItemWidth*columnSize;
				spaceStep = (this->getContentSize().width - marginLeft - marginRight - allItemWidth) / (columnSize + 1);
			}
			//spaceStep = (this->getContentSize().width - marginLeft - marginRight - allItemWidth) / (columnSize + 1);
		}
		else{
			spaceStep = (this->getContentSize().width - marginLeft - marginRight - allItemWidth) / (columnSize + 1);
		}

		flag = false;
		float a = spaceStep;

		for (int j = 0; j < columnSize && (i + j) < _items.size(); j++){
			item = _items[i + j];
			//item->setPosition(width*(0.5f + j) + marginLeft, y - height / 2);
			item->setPosition(Point(a + item->getContentSize().width*item->getScaleX() / 2 + marginLeft, y - height / 2));
			//item->setLocalZOrder(zorder);
			
			zorder++;
			a += item->getContentSize().width*item->getScaleX() + spaceStep;
		}

		y -= (height + padding);
	}

	this->setInnerContainerSize(Size(this->getContentSize().width, containerHeight));
}

void TableView::refreshViewHorizontal(){
	float itemHeight = (this->getContentSize().height - marginTop - marginBottom) / rowSize;
	float containerWidth = marginLeft + marginRight;
	float columnWidth = 0.0f;
	float itemWidth, spaceStep, allItemHeight;
	Node* item;

	for (int i = 0; i < _items.size(); i += rowSize){
		//find max height
		item = _items[i];
		itemWidth = item->getContentSize().width * item->getScaleX();
		columnWidth = itemWidth;
		for (int j = 0; j < rowSize && (i + j) < _items.size(); j++){
			item = _items[i+j];
			itemWidth = item->getContentSize().width * item->getScaleX();
			columnWidth = itemWidth;
			if (itemWidth > columnWidth){
				columnWidth = itemWidth;
			}
		}
		containerWidth += columnWidth + padding;
	}
	containerWidth -= padding;
	if (containerWidth < this->getContentSize().width){
		containerWidth = this->getContentSize().width;
	}

	float x = marginLeft;
	int zorder = 0;
	spaceStep = 0.0f;
	bool flag = true;
	for (int i = 0; i < _items.size(); i += rowSize){
		//find max height
		allItemHeight = 0.0f;
		item = _items[i];
		itemWidth = item->getContentSize().width * item->getScaleX();
		columnWidth = itemWidth;
		int j =0;
		for (j = 0; j < rowSize && (i + j) < _items.size(); j++){
			item = _items[i + j];
			itemWidth = item->getContentSize().width * item->getScaleX();
			if (itemWidth > columnWidth){
				columnWidth = itemWidth;
			}
			allItemHeight += item->getContentSize().height * item->getScaleY();
		}

//		if (_items.size() - i >= rowSize){
//			spaceStep = (this->getContentSize().height - marginTop - marginBottom - allItemHeight) / (rowSize + 1);
//		}

		if (_items.size() - i < rowSize){
			//log("1234zzzz");
			if(flag){
				item = _items[i];
				float defaultItemHeight = item->getContentSize().height * item->getScaleY();
				allItemHeight = defaultItemHeight*rowSize;
				//log("zzzz");
				spaceStep = (this->getContentSize().height - marginTop - marginBottom - allItemHeight) / (rowSize + 1);
			}
			//spaceStep = (this->getContentSize().height - marginTop - marginBottom - allItemHeight) / (rowSize + 1);
		}
		else{
			spaceStep = (this->getContentSize().height - marginTop - marginBottom - allItemHeight) / (rowSize + 1);
		}

		flag = false;
		//spaceStep = (this->getContentSize().height - marginTop - marginBottom - allItemHeight) / (rowSize + 1);
		float a = this->getContentSize().height - spaceStep - marginTop;
		
		for (int j = 0; j < rowSize && (i + j) < _items.size(); j++){
			item = _items[i + j];
			//item->setPosition(a + item->getContentSize().width*item->getScaleX() / 2 + marginLeft, y - height / 2);
			item->setPosition(Point(x + columnWidth / 2, a - item->getContentSize().height*item->getScaleY()/2));
			//item->setLocalZOrder(zorder);
			zorder++;
			a -= item->getContentSize().height*item->getScaleY() + spaceStep;
		}

		x += (columnWidth + padding);
	}

	this->setInnerContainerSize(Size(containerWidth, this->getContentSize().height));
}

void TableView::setPadding(float padding){
	this->padding = padding;
	_isUpdateView = true;
}

void TableView::setMargin(float top, float bot, float left, float right){
	marginTop = top;
	marginBottom = bot;
	marginLeft = left;
	marginRight = right;
	_isUpdateView = true;
}

void TableView::runMoveEffect(float moveSpeed, float delayPerColumn, float delayPerRow){
	_autoScrolling = false;
	_runningEffect = true;
	_updateEffect = true;
	_isUpdateView = true;

	effectMoveSpeed = moveSpeed;
	effectTimeDelayPerColumn = delayPerColumn;
	effectTimeDelayPerRow = delayPerRow;
}
    
void TableView::onItemStartAnimation(Node* item){
    if(_handler){
        _handler(TableViewItemAction::ItemStartAnimation, item);
    }
}
    
void TableView::onItemFinishedAnimation(Node* item){
    if(_handler){
        _handler(TableViewItemAction::ItemFinishedAnimation, item);
    }
}

bool TableView::getItemsRow(std::vector<Node*> &items, int index){
	Rect mrect(0, 0, this->getContentSize().width, this->getContentSize().height);
	Rect itemRect;

	if (_direction == ui::ScrollView::Direction::HORIZONTAL){
		for (int i = 0; i < columnSize; i++){
			int itemIndex = rowSize*i + index;
			if (itemIndex < _items.size()){
				auto item = _items[itemIndex];
				itemRect.setRect(-item->getContentSize().width / 2, -item->getContentSize().height / 2, item->getContentSize().width / 2, item->getContentSize().height / 2);
				if (itemRect.intersectsRect(mrect)){
					items.push_back(item);
				}
				
			}
		}
	}
	else if (_direction == ui::ScrollView::Direction::VERTICAL){
		for (int i = 0; i<columnSize; i++){
			int itemIndex = index*columnSize + i;

			if (itemIndex < _items.size()){
				auto item = _items[itemIndex];
				itemRect.setRect(-item->getContentSize().width / 2, -item->getContentSize().height / 2, item->getContentSize().width / 2, item->getContentSize().height / 2);
				if (itemRect.intersectsRect(mrect)){
					items.push_back(item);
				};
			}
		}
	}

	return true;
}

bool TableView::getItemsColumn(std::vector<Node*> &items, int index){
	if (_direction == ui::ScrollView::Direction::HORIZONTAL){
		for (int i = 0; i < rowSize; i++){
			int itemIndex = rowSize*index + i;
			if (itemIndex < _items.size()){
				items.push_back(_items[itemIndex]);
			}
		}
	}
	else if (_direction == ui::ScrollView::Direction::VERTICAL){
		for (int i = 0; i<rowSize; i++){
			int itemIndex = i*columnSize + index;

			if (itemIndex < _items.size()){
				items.push_back(_items[itemIndex]);
			}
		}
	}

	return true;
}

void TableView::updateRunMoveEffect(){
	forceRefreshView();
    _isUpdateView = false;

	if (_direction == ui::ScrollView::Direction::VERTICAL){
		rowSize = 0;
		for (int i = 0; i < _items.size(); i += columnSize){
			rowSize++;
		}
	}
	else if (_direction == ui::ScrollView::Direction::HORIZONTAL){
		columnSize = 0;
		for (int i = 0; i < _items.size(); i += rowSize){
			columnSize++;
		}
	}


    this->setEnabled(false);
    
	bool fromLeft = true;
	if (effectMoveSpeed > 0){
		fromLeft = false;
	}
    
	float x = 0;
	if(fromLeft){
		x = -(this->getContentSize().width + this->getContentSize().width / columnSize);
	}
	else{
		x = this->getContentSize().width + this->getContentSize().width / columnSize;
	}

    float y = 0.0f;
    float delayPerColumn = 0.0f;
    float delayPerRow = 0.0f;
    float duration = Point(x, y).length() / fabs(effectMoveSpeed);
    std::vector<Node*> items;
    float itemLine = marginTop;
    itemsEffect = 0;
    for (int i = 0; i < rowSize; i++){
        items.clear();
        getItemsRow(items, i);
        //delayTime = 0.0f;
        if (itemLine <  this->getContentSize().height){
            float rowHeight = 0.0f;
            delayPerColumn = 0.0f;

			int j = 0;
			if(fromLeft){
				j = items.size() - 1;
			}
			while (true){
				itemsEffect++;
				auto item = items.at(j);
				auto itemHeight = item->getContentSize().height* item->getScaleY();
				if (itemHeight > rowHeight){
					rowHeight = itemHeight;
				}

				auto currentPoint = item->getPosition();
				item->stopAllActions();
				item->setPosition(Point(item->getPosition() + Point(x, y)));
				item->setVisible(true);
				auto moveAction = Sequence::create(
					DelayTime::create(delayPerColumn + delayPerRow),
					EaseCircleActionOut::create(MoveBy::create(duration, Point(-x, -y))),
					CallFuncN::create(CC_CALLBACK_0(TableView::runMoveEffectFinished, this)),
					NULL);

				this->onItemStartAnimation(item);
				item->runAction(Sequence::create(moveAction,
					CallFunc::create(CC_CALLBACK_0(TableView::onItemFinishedAnimation, this, item)),
					NULL));// MoveBy::create(duration, Point(-x, -y))));

				delayPerColumn += effectTimeDelayPerColumn;

				if(fromLeft){
					j--;
					if (j < 0){
						break;
					}
				}
				else{
					j++;
					if (j >= items.size()){
						break;
					}
				}

			}

            itemLine += rowHeight + padding;
            delayPerRow += effectTimeDelayPerRow;
        }
    }

    if(itemsEffect == 0){
        _runningEffect = false;
        this->setEnabled(true);
    }
}

void TableView::runMoveEffectFinished(){
    itemsEffect--;
    if(itemsEffect <= 0){
        _runningEffect = false;
        this->setEnabled(true);
    }
}

float TableView::getMarginTop(){
	return marginTop;
}

float TableView::getMarginBottom(){
	return marginBottom;
}

float TableView::getMarginLeft(){
	return marginLeft;
}

float TableView::getMarginRight(){
//	this->setSwallowTouches
	return marginRight;
}

Node* TableView::getItem(int index){
	return _items[index];
}

int TableView::size(){
	return _items.size();
}

void TableView::removeAllItems(){
	for (int i = 0; i < _items.size(); i++){
		_items[i]->removeFromParentAndCleanup(true);
	}

	_items.clear();
	_isUpdateView = true;
}

void TableView::removeItem(Node* item){
	_items.erase(std::remove(_items.begin(), _items.end(), item));
	item->removeFromParentAndCleanup(true);
	_isUpdateView = true;
}

void TableView::removeItem(int index){
	auto item = _items[index];
	_items.erase(_items.begin() + index);
	item->removeAllChildrenWithCleanup(true);
	_isUpdateView = true;
}

void TableView::refreshView(){
	_isUpdateView = true;
}

void TableView::forceRefreshView(){
	if (_direction == ui::ScrollView::Direction::VERTICAL){
		refreshViewVertical();
	}
	else if (_direction == ui::ScrollView::Direction::HORIZONTAL){
		refreshViewHorizontal();
	}
	_isUpdateView = false;
}

void TableView::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags){
	Node* node = this;
	while (node) {
		if (!node->isVisible()){
            return;
        }
		node = node->getParent();
    }
    

	if (_updateEffect){
		updateRunMoveEffect();
		_updateEffect = false;
	}

	if (!_runningEffect){
		if (_isUpdateView){
			this->forceRefreshView();
			_isUpdateView = false;
		}
	}
    
	ui::ScrollView::visit(renderer, parentTransform, parentFlags);
}

void TableView::pushItem(Node* item){
	this->addChild(item, 0);

	_items.push_back(item);
	_isUpdateView = true;
}

void TableView::insertItem(Node* item, int index){
	this->addChild(item, 0);

	_items.insert(_items.begin() + index, item);
	_isUpdateView = true;
}

void TableView::removeAllChildren(){
	this->removeAllChildrenWithCleanup(true);
}

void TableView::removeAllChildrenWithCleanup(bool cleanup){
	ScrollView::removeAllChildrenWithCleanup(cleanup);
	_items.clear();
	_isUpdateView = true;
}

void TableView::removeChild(Node* child, bool cleaup){
	_items.erase(std::remove(_items.begin(), _items.end(), child));
	ScrollView::removeChild(child, cleaup);
	_isUpdateView = true;
}

void TableView::jumpToBottom(){
	_autoScrolling = false;
	ui::ScrollView::jumpToBottom();
}

void TableView::jumpToTop(){
	_autoScrolling = false;
	ui::ScrollView::jumpToTop();
}

void TableView::jumpToLeft(){
	_autoScrolling = false;
	ui::ScrollView::jumpToLeft();
}

void TableView::jumpToRight(){
	_autoScrolling = false;
	ui::ScrollView::jumpToRight();
}

bool TableView::onTouchBegan(Touch *touch, Event *unusedEvent){
	if (!_checkParentPageView){
		if (_direction == ui::ScrollView::Direction::VERTICAL){
			auto parent = this->getParent();
			if (dynamic_cast<ui::Layout*>(parent)){
				parent = parent->getParent();
				if (dynamic_cast<ui::PageView*>(parent)){
					_parentIsPageView = true;
				}
			}
		}	
		_checkParentPageView = true;
	}

	if (!_parentIsPageView){
		return ui::ScrollView::onTouchBegan(touch, unusedEvent);
	}

	_propagateTouchEvents = true;
	bool bret = ui::ScrollView::onTouchBegan(touch, unusedEvent);
	_propagateTouchEvents = false;
	if (bret){
		_startPoint = touch->getLocation();
		_moveThis = false;
		_moveParent = false;
	}
	return bret;
}

void TableView::onTouchMoved(Touch *touch, Event *unusedEvent){	
	if (_parentIsPageView){
		if (!_moveThis && !_moveParent){
			Point p = touch->getLocation() - _startPoint;
			if (p.length() > 10.0){
				if (abs(p.x) > abs(p.y)){
					_moveParent = true;
				}
				else{
					_moveThis = true;
				}
			}
		}

		if (_moveThis){
			ui::ScrollView::onTouchMoved(touch, unusedEvent);
		}
		else if (_moveParent){
			_propagateTouchEvents = true;
			Layout::onTouchMoved(touch, unusedEvent);
			_propagateTouchEvents = false;
		}
	}
	else{
		ui::ScrollView::onTouchMoved(touch, unusedEvent);
	}
}

void TableView::onTouchEnded(Touch *touch, Event *unusedEvent){	
	if (_parentIsPageView){
		_propagateTouchEvents = true;
		ui::ScrollView::onTouchEnded(touch, unusedEvent);
		_propagateTouchEvents = false;
	}
	else{
		ui::ScrollView::onTouchEnded(touch, unusedEvent);
	}
}

void TableView::onTouchCancelled(Touch *touch, Event *unusedEvent){
	if (_parentIsPageView){
		_propagateTouchEvents = true;
		ui::ScrollView::onTouchCancelled(touch, unusedEvent);
		_propagateTouchEvents = false;
	}
	else{
		ui::ScrollView::onTouchCancelled(touch, unusedEvent);
	}
}

}