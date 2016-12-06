/**
 * Created by Quyet Nguyen on 7/25/2016.
 */

var s_xocdia_slot_id = s_xocdia_slot_id || [0,1,2,3,4,5,6];
var s_xocdia_slot_position = s_xocdia_slot_position || [
        {x : 271, y : 407},
        {x : 1011, y : 407},
        {x : 150, y : 215},
        {x : 395, y : 215},
        {x : 640, y : 215},
        {x : 885, y : 215},
        {x : 1130, y : 215}
];

var s_xocdia_result_position= s_xocdia_result_position ||
[
    {x : 218, y : 194},
    {x : 161, y : 219},
    {x : 175, y : 152},
    {x : 235, y : 144},
    {x : 276, y : 178},
    {x : 291, y : 231},
    {x : 190, y : 270},
    {x : 242, y : 248},
    {x : 278, y : 302},
    {x : 333, y : 262},
    {x : 342, y : 200},
    {x : 342, y : 146},
    {x : 289, y : 125},
    {x : 282, y : 82},
    {x : 231, y : 86},
    {x : 175, y : 95},
    {x : 125, y : 129},
    {x : 117, y : 177},
    {x : 99, y : 223},
    {x : 116, y : 279},
    {x : 180, y : 318},
    {x : 232, y : 332}

];

var _get_random_array = function(take, maxSize){
    var arr = [];
    var min = 0;
    var max = maxSize - take;
    for(var i=0; i<take; i++){
        var number = min + Math.floor(Math.random() * (max - min));
        min = number + 1;
        max++;
        arr.push(number);
    }
    return arr;
};

var XocDiaBettingSlot = cc.Node.extend({
    ctor : function (idx, parentNode) {
        this._super();
        this._chipNode = new cc.Node();
        this.addChild(this._chipNode);
        this._slotGold = 0;
        this._userGold = 0;

        this.setAnchorPoint(cc.p(0.5, 0.5));
        this.setPosition(s_xocdia_slot_position[idx]);

        var bg = new cc.Sprite("#xocdia_slot_" + (idx + 1)+".png");
        this.bg = bg;
        this.setContentSize(bg.getContentSize());
        bg.setPosition(this.getContentSize().width/2, this.getContentSize().height/2);
        this.addChild(bg);

        if(idx < 2){
            var slotGoldLabel = new cc.LabelBMFont("10.00.000", cc.res.font.Roboto_Condensed_25);
            slotGoldLabel.setColor(cc.color("#392d2e"));
            slotGoldLabel.setPosition(this.x - this.getContentSize().width/4, this.y - this.getContentSize().height/2 + 25);
            parentNode.addChild(slotGoldLabel,1);
            this.slotGoldLabel = slotGoldLabel;

            var userGoldLabel = new cc.LabelBMFont("1.00.000", cc.res.font.Roboto_CondensedBold_25 );
            userGoldLabel.setColor(cc.color("#392d2e"));
            userGoldLabel.setPosition(this.x + this.getContentSize().width/4, slotGoldLabel.y);
            parentNode.addChild(userGoldLabel,1);
            this.userGoldLabel = userGoldLabel;
        }
        else{
            var slotGoldLabel = new cc.LabelBMFont("100.000", cc.res.font.Roboto_Condensed_25);
            slotGoldLabel.setColor(cc.color("#767eb6"));
            slotGoldLabel.setPosition(this.x - this.getContentSize().width/4, this.y - this.getContentSize().height/2 + 20);
            slotGoldLabel.setScale(20.0/25.0);
            parentNode.addChild(slotGoldLabel,1);
            this.slotGoldLabel = slotGoldLabel;

            var userGoldLabel = new cc.LabelBMFont("100.000", cc.res.font.Roboto_CondensedBold_25);
            userGoldLabel.setColor(cc.color("#ffde00"));
            userGoldLabel.setPosition(this.x + this.getContentSize().width/4, slotGoldLabel.y);
            userGoldLabel.setScale(20.0/25.0);
            parentNode.addChild(userGoldLabel,1);
            this.userGoldLabel = userGoldLabel
        }

        this.reset();
        //
        //add Touch
        // var rectTouch = cc.rect(0,0, this.getContentSize().width, this.getContentSize().height);
        // var thiz = this;
        // cc.eventManager.addListener({
        //     event: cc.EventListener.TOUCH_ONE_BY_ONE,
        //     swallowTouches:true,
        //     onTouchBegan : function (touch, event) {
        //         var p = thiz.convertToNodeSpace(touch.getLocation());
        //         if(cc.rectContainsPoint(rectTouch, p)){
        //             if(thiz.onTouchSlot){
        //                 thiz.onTouchSlot(s_xocdia_slot_id[slotIndex]);
        //             }
        //             return true;
        //         }
        //         return false;
        //     },
        // }, this);
    },
    setOpacity : function (opacity) {
        this._super();
        this.bg.setOpacity(opacity);
        this.slotGoldLabel.setOpacity(opacity);
        this.userGoldLabel.setOpacity(opacity);
    },
    reset : function () {
        this._chipNode.removeAllChildren(true);
        this.removeChip();
        this.setOpacity(255);

         this.setSlotGold(0);
         this.setUserGold(0);
    },
    setSlotGold : function (gold) {
        this._slotGold = gold;

        this.slotGoldLabel.stopAllActions();
        if(gold>0){
            this.slotGoldLabel.visible = true;
            var action = new quyetnd.ActionNumber(1.0, gold);
            this.slotGoldLabel.runAction(action);
        }
        else{
            this.slotGoldLabel.setString("0");
            this.slotGoldLabel.visible = false;
        }
    },
    setUserGold : function (gold) {
        this._userGold = gold;

        this.userGoldLabel.visible = true;
        if(gold>0){
            var action = new quyetnd.ActionNumber(1.0, gold);
            this.userGoldLabel.runAction(action);
        }
        else{
            this.userGoldLabel.setString("0");
            this.userGoldLabel.visible = false;
        }
    },
    getSlotPosition : function () {
        var padding =50.0;

        var w = Math.random() * (this.getContentSize().width - padding*2) + padding;
        var h = Math.random() * (this.getContentSize().height - padding*2) + padding;
        var x = this.x - this.getContentSize().width/2 + w;
        var y = this.y - this.getContentSize().height/2 + h;

        return cc.p(x,y);
    },
    addChip : function (chipSprite) {
        this._chips.push(chipSprite);
    },
    removeChip : function () {
        this._chips = [];
    }
});

var XocDiaScene = IGameScene.extend({
    ctor : function () {
        this._super();
        this._historyData = [];

        this.initView();

        this.initBettingSlot();

        //chip button
        var chipNode = new cc.Node();
        chipNode.setPosition(cc.p(0,0));
        this.sceneLayer.addChild(chipNode);
        this.chipNode = chipNode;
        this.initChipButton();

        //history
        this.initHistory();
        this.initDisk();

        this.setUserCount(0);
    },
    initView : function () {
        var playerMe = new GamePlayerMe();
        playerMe.setPosition(150, 50.0);
        this.sceneLayer.addChild(playerMe,1);
        this.playerView = [playerMe];

        var playerButton = new ccui.Button("ingame-playerBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        playerButton.setPosition(160, 653);
        this.gameTopBar.addChild(playerButton);

        var userLabel = new cc.LabelBMFont("30", cc.res.font.Roboto_CondensedBold_25);
        userLabel.setColor(cc.color("#ffcf00"));
        userLabel.setPosition(playerButton.getContentSize().width/2, 22);
        playerButton.getRendererNormal().addChild(userLabel);
        this.userLabel = userLabel;
    },
    initController : function () {
        this._controller = new XocDiaController(this);
    },
    initBettingSlot : function () {
        this.bettingSlot = [];

        var slotNode = new cc.Node();
        slotNode.setPosition(cc.p(0,0));
        this.sceneLayer.addChild(slotNode);

        for(var i=0;i<7;i++){
            var slot = new XocDiaBettingSlot(i, slotNode);
            slotNode.addChild(slot);
            var slotIndex = s_xocdia_slot_id[i];
            slot.onTouchSlot = function (slotId) {
                //cc.log("touchSlot: "+slotId);
            };
            this.bettingSlot[slotIndex] = slot;
        }

        var timerBg = new cc.Sprite("#xocdia_timer_1.png");
        timerBg.setPosition(640, 420);
        slotNode.addChild(timerBg);

        var timer = new cc.ProgressTimer(new cc.Sprite("#xocdia_timer_2.png"));
        timer.setType(cc.ProgressTimer.TYPE_RADIAL);
        timer.setReverseDirection(true);
        timer.setPosition(timerBg.getPosition());
        timer.setPercentage(30.0);
        slotNode.addChild(timer);
        this.timer = timer;

        var timeLabel = new cc.LabelTTF("100", cc.res.font.Roboto_CondensedBold, 60);
        timeLabel.setPosition(timerBg.getPosition());
        timeLabel.setColor(cc.color("#ffcf00"));
        slotNode.addChild(timeLabel);
        this.timeLabel = timeLabel;
    },
    initChipButton : function () {
        var chipGroup = new ChipGroup();
        this.sceneLayer.addChild(chipGroup);
        this.chipGroup = chipGroup;
        var centerPosition = cc.winSize.width/2;

        var chip1 = new XocDiaChip(1);
        chip1.setPosition(centerPosition - 255.0 * cc.winSize.screenScale , 30.0 * cc.winSize.screenScale);
        chip1.setScale(cc.winSize.screenScale);
        chip1.originPoint = chip1.getPosition();
        chipGroup.addChip(chip1);

        var chip2 = new XocDiaChip(2);
        chip2.setPosition(centerPosition - 85.0 * cc.winSize.screenScale, chip1.y);
        chip2.setScale(cc.winSize.screenScale);
        chip2.originPoint = chip2.getPosition();
        chipGroup.addChip(chip2);

        var chip3 = new XocDiaChip(3);
        chip3.setPosition(centerPosition + 85.0 * cc.winSize.screenScale, chip1.y);
        chip3.setScale(cc.winSize.screenScale);
        chip3.originPoint = chip3.getPosition();
        chipGroup.addChip(chip3);

        var chip4 = new XocDiaChip(4);
        chip4.setPosition(centerPosition + 255.0 *cc.winSize.screenScale, chip1.y);
        chip4.setScale(cc.winSize.screenScale);
        chip4.originPoint = chip4.getPosition();
        chipGroup.addChip(chip4);
    },

    initHistory : function () {
        var padding = 2.0;
        var itemSize = cc.size(46.0, 46.0);
        var row = 4;
        var col = 16;
        var left = 52.0;

        var historyBg = new ccui.Scale9Sprite("xocdia_history_bg1.png", cc.rect(4,4,4,4));
        historyBg.setPreferredSize(cc.size((itemSize.width + padding) * col + left, itemSize.height * row + padding * (row+1)));
        historyBg.setPosition(cc.winSize.width/2, cc.winSize.height - historyBg.getContentSize().height/2);
        this.sceneLayer.addChild(historyBg);

        var historyBt = new ccui.Button("xocdia_history_bt.png","","", ccui.Widget.PLIST_TEXTURE);
        historyBt.setPosition(left/2, historyBg.getContentSize().height/2);
        historyBt.setZoomScale(0.0);
        historyBg.addChild(historyBt);

        for(var i=0; i<col; i++){
            for(var j=0; j<row; j++){
                var x = left + itemSize.width/2 + (itemSize.width + padding) * i;
                var y = padding + itemSize.height/2 + (itemSize.height + padding) *j ;
                var bg = new ccui.Scale9Sprite("xocdia_history_bg2.png", cc.rect(4,4,4,4));
                bg.setPreferredSize(itemSize);
                bg.setPosition(x,y);
                historyBg.addChild(bg);
            }
        }

        this.historyNode = new cc.Node();
        this.historyNode.setContentSize(historyBg.getContentSize());
        this.historyNode.setAnchorPoint(cc.p(0,0));
        historyBg.addChild(this.historyNode);

        this._historyData = [];
    },

    initDisk : function () {
        var diskLayer = new cc.Node();
        this.sceneLayer.addChild(diskLayer);
        this.diskLayer = diskLayer;

        var diskSprite = new cc.Sprite("#xocdia_dia.png");
        diskSprite.setPosition(cc.winSize.width/2, cc.winSize.height/2);
        diskLayer.addChild(diskSprite);
        this.diskSprite = diskSprite;

        var diskNode = new cc.Node();
        diskSprite.addChild(diskNode);
        this.diskNode = diskNode;

        var batSprite = new cc.Sprite("#xocdia_bat.png");
        batSprite.setPosition(diskSprite.getContentSize().width/2, diskSprite.getContentSize().height/2);
        diskSprite.addChild(batSprite);
        this.batSprite = batSprite;
    },

    shakeDisk : function () {
        this.diskLayer.setVisible(true);
        this.diskNode.removeAllChildren(true);
        this.diskSprite.stopAllActions();
        this.batSprite.stopAllActions();
        this.batSprite.setPosition(this.diskSprite.getContentSize().width/2, this.diskSprite.getContentSize().height/2);
        this.diskSprite.setPosition(cc.winSize.width/2, cc.winSize.height + this.diskSprite.getContentSize().height/2);

        var thiz = this;
        this.diskSprite.runAction(new cc.Sequence(
            new cc.EaseSineOut(new cc.MoveTo(1.0, cc.p(cc.winSize.width/2, cc.winSize.height/2))),
            new cc.DelayTime(0.2),
            new quyetnd.ActionShake2D(2.0, cc.p(10.0, 10.0))
        ));
    },

    hideDisk : function () {
        this.diskSprite.stopAllActions();
        this.batSprite.stopAllActions();
        this.diskLayer.setVisible(false);
    },

    openDisk : function (result) {
        this.diskLayer.setVisible(true);
        this.diskNode.removeAllChildren(true);
        this.diskSprite.stopAllActions();
        this.batSprite.stopAllActions();
        this.batSprite.setPosition(this.diskSprite.getContentSize().width/2, this.diskSprite.getContentSize().height/2);
        this.diskSprite.setPosition(cc.winSize.width/2, cc.winSize.height + this.diskSprite.getContentSize().height/2);
        /* add result */
        var arr = _get_random_array(4, s_xocdia_result_position.length);
        for(var i=0; i<arr.length; i++){
            if(i < result){
                var sprite = new cc.Sprite("#xocdia_hat_do.png");
            }
            else{
                var sprite = new cc.Sprite("#xocdia_hat_trang.png");
            }

            sprite.setPosition(s_xocdia_result_position[arr[i]]);
            this.diskNode.addChild(sprite);
        }
        //
        var thiz = this;
        var moveBat = function () {
            thiz.batSprite.runAction(new cc.Sequence(
                new cc.EaseSineIn(new cc.MoveBy(1.0, cc.p(0.0, 450.0))),
                new cc.CallFunc(function () {
                    thiz._addHistory(result);
                    thiz._refreshHistory();
                })
            ));
        };
        this.diskSprite.runAction(new cc.Sequence(
            new cc.EaseSineOut(new cc.MoveTo(1.0, cc.p(cc.winSize.width/2, cc.winSize.height/2))),
            new cc.DelayTime(0.2),
            new cc.CallFunc(moveBat)
        ));
    },

    // _openDisk : function () {
    //     var thiz = this;
    //
    // },

    onEnter : function () {
        this._super();
        this.chipGroup.selectChipAtIndex(0, true);
    },

    addChipToSlot : function (slotIndex, chipIndex, fromMe) {
        if(fromMe){
            var chipPosition = this.chipGroup.getChip(chipIndex).getPosition();
        }
        else{
            //from player button
            var chipPosition = cc.p(0,0);
        }

        var slot = this.bettingSlot[slotIndex];
        var thiz = this;

        var addChipHandler = function () {
            var chip = new cc.Sprite("#xocdia-chipSelected-" + (chipIndex+1) + ".png");
            chip.setPosition(chipPosition);

            thiz.chipNode.addChild(chip);
            slot.addChip(chip);

            //move
            var p = slot.getSlotPosition();
            var duration = cc.pLength(cc.pSub(chip.getPosition(), p)) / 1000.0;
            var moveAction = new cc.Spawn(
                new cc.MoveTo(duration, p),
                new cc.ScaleTo(duration, 0.3)
            );
            chip.runAction(new cc.EaseSineOut(moveAction));
        };

        if(fromMe){
            addChipHandler();
        }
        else{
            var delayTime = 0.5 + Math.random() * 1.0;
            this.chipNode.runAction(new cc.Sequence(
                new cc.DelayTime(delayTime),
                new cc.CallFunc(addChipHandler)
            ));
        }
    },

    updateSlotGold : function (slotId, gold) {
        var slot = this.bettingSlot[slotId];
        slot.setSlotGold(gold);
    },

    updateUserGold : function (slotId, gold) {
        var slot = this.bettingSlot[slotId];
        slot.setUserGold(gold);
    },

    updateUserCount : function (userCount) {

    },

    setTimeRemaining : function (currentTime, maxTime) {
        var timerProgress = 100.0* currentTime / maxTime;
        this.timer.stopAllActions();
        this.timeLabel.stopAllActions();

        this.timer.runAction(new cc.ProgressFromTo(currentTime, timerProgress, 0.0));

        this.timeLabel.setString(currentTime);
        this.timeLabel.runAction(new quyetnd.ActionNumber(currentTime, 0));


        //this.timeLabel.runAction(new cc.RepeatForever(alertAction));

        var thiz = this;
        if(currentTime > 5){
            this.timeLabel.setColor(cc.color("#ffcf00"));
            this.timer.setColor(cc.color("#ffcf00"));

            this.timeLabel.runAction(new cc.Sequence(
                new cc.DelayTime(currentTime - 5),
                new cc.CallFunc(function () {
                    var alertAction = new cc.Sequence(
                        new cc.TintTo(0.2, 255,0,0),
                        new cc.TintTo(0.2, 255,207,0)
                    );
                    thiz.timeLabel.runAction(new cc.RepeatForever(alertAction));
                })
            ));

            this.timer.runAction(new cc.Sequence(
                new cc.DelayTime(currentTime - 5),
                new cc.CallFunc(function () {
                    var alertAction = new cc.Sequence(
                        new cc.TintTo(0.2, 255,0,0),
                        new cc.TintTo(0.2, 255,207,0)
                    );
                    thiz.timer.runAction(new cc.RepeatForever(alertAction));
                })
            ));
        }
        else{
            var alertAction = new cc.Sequence(
                new cc.TintTo(0.2, 255,0,0),
                new cc.TintTo(0.2, 255,207,0)
            );
            this.timeLabel.runAction(new cc.RepeatForever(alertAction.clone()));
            this.timer.runAction(new cc.RepeatForever(alertAction));
        }
    },

    _addHistory : function (history) {
        if(this._historyData.length == 0){
            this._historyData.push(history);
            return;
        }

        var row = 4;
        var col = 16;
        var maxItem = row*col;

        var lastHistory = this._historyData[this._historyData.length-1];
        if((lastHistory%2) != (history%2)){
            //fill empty
            var emptyCount = this._historyData.length % row;
            if(emptyCount > 0){
                emptyCount = row - emptyCount;
                for(var i=0;i<emptyCount;i++){
                    this._historyData.push(-1);
                }
            }
        }
        this._historyData.push(history);

        if(this._historyData.length > maxItem){
            this._historyData.splice(0, row);
        }
    },
    _refreshHistory : function () {
        var padding = 2.0;
        var itemSize = cc.size(46.0, 46.0);
        var row = 4;
        var left = 52.0;

        this.historyNode.removeAllChildren(true);
        for(var i=0; i<this._historyData.length; i++){
            if(this._historyData[i] >= 0){
                var label = new cc.LabelBMFont(this._historyData[i], cc.res.font.Roboto_CondensedBold_25);

                var x = left + itemSize.width/2 + (itemSize.width + padding) * Math.floor(i / row);
                var y =  this.historyNode.getContentSize().height - padding - itemSize.height/2 - (itemSize.height + padding) * (i % row) ;
                if(this._historyData[i] % 2){
                    var historyIcon = new cc.Sprite("#xocdia_history_1.png");
                    label.setColor(cc.color("#ffffff"));
                }
                else{
                    var historyIcon = new cc.Sprite("#xocdia_history_2.png");
                    label.setColor(cc.color("#333333"));
                }
                historyIcon.setPosition(x, y);
                this.historyNode.addChild(historyIcon, 0);

                label.setPosition(x, y);
                this.historyNode.addChild(label, 1);
            }
        }
    },

    setHistory : function (history) {
        this._historyData = [];

        for(var i=0;i<history.length;i++){
            this._addHistory(history[i]);
        }
        //cc.log(this._historyData);
        this._refreshHistory();
    },

    setUserCount : function (count) {
        this.userLabel.setString(count);
    },

    backButtonClickHandler : function () {
        // if(this._controller){
        //     this._controller.requestQuitRoom();
        // }
        // var slot = Math.floor(Math.random()*7);
        // var chip = Math.floor(Math.random()*4);
        //
        // this.addChipToSlot(slot, chip, true);

         var history = Math.floor(Math.random() * 4) + 1;
        // this._addHistory(history);
        // this._refreshHistory();

       // this.setTimeRemaining(15.0, 20.0);
        this.openDisk(history);
    },

    /*ignore*/
    processPlayerPosition : function () {

    },
    updateOwner : function () {

    }
});