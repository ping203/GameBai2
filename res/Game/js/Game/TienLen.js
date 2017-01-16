/**
 * Created by Quyet Nguyen on 7/21/2016.
 */

var CardRemaining = cc.Node.extend({
    ctor: function () {
        this._super()
        this.setAnchorPoint(cc.p(0.5, 0.5));

        var bg = new cc.Sprite("#card_remain_bg_1.png");
        this.setContentSize(bg.getContentSize());
        bg.setPosition(this.getContentSize().width / 2, this.getContentSize().height / 2);
        this.addChild(bg);
        this.bg = bg;

        var label = new cc.LabelBMFont("99", cc.res.font.Roboto_Condensed_25);
        label.setPosition(bg.x, bg.y);
        this.addChild(label);
        this.label = label;
    },

    setCardRemain: function (card) {
        if (card <= 0) {
            this.setVisible(false);
        }
        else {
            this.setVisible(true);
            this.label.setString(card);
            if (card > 1) {
                this.bg.setSpriteFrame("card_remain_bg_2.png");
            }
            else {
                this.bg.setSpriteFrame("card_remain_bg_1.png");
            }
        }
    }
});

var TienLen = IGameScene.extend({
    ctor: function () {
        this._super();

        var table_bg = new cc.Sprite("res/gp_table.png");
        table_bg.setPosition(cc.winSize.width / 2, cc.winSize.height / 2);
        table_bg.setScale(cc.winSize.screenScale);
        this.sceneLayer.addChild(table_bg);

        //initview
        var chatBt = new ccui.Button("ingame-chatBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        chatBt.setPosition(1120, 653);
        this.gameTopBar.addChild(chatBt);
        var thiz = this;
        chatBt.addClickEventListener(function () {
            var dialog = new ChatDialog();
            dialog.onTouchMessage = function (message) {
                thiz.sendChatMessage(message);
            };
            dialog.show();
        });

        //
        this.initPlayer();
        this.initButton();

        //initCardxd
        var cardList = new CardList(cc.size(cc.winSize.width - 10, 100));
        cardList.setAnchorPoint(cc.p(0.5, 0.0));
        cardList.setPosition(cc.winSize.width / 2, 100.0);
        this.sceneLayer.addChild(cardList);
        this.cardList = cardList;

        var cardOnTable = new CardOnTable();
        cardOnTable.setPosition(cc.p(0, 0));
        this.sceneLayer.addChild(cardOnTable);
        this.cardOnTable = cardOnTable;

        //test
    },
    initController: function () {
        this._controller = new TLMNGameController(this);
    },
    initButton: function () {
        var danhbaiBt = new ccui.Button("game-danhbaiBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        danhbaiBt.setPosition(cc.winSize.width - 110, 50);
        this.sceneLayer.addChild(danhbaiBt);

        var xepBaiBt = new ccui.Button("game-xepbaiBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        xepBaiBt.setPosition(cc.winSize.width - 510, danhbaiBt.y);
        this.sceneLayer.addChild(xepBaiBt);

        var boluotBt = new ccui.Button("game-boluotBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        boluotBt.setPosition(cc.winSize.width - 310, danhbaiBt.y);
        this.sceneLayer.addChild(boluotBt);

        var startBt = new ccui.Button("game-startBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        startBt.setPosition(boluotBt.getPosition());
        this.sceneLayer.addChild(startBt);

        var thiz = this;
        startBt.addClickEventListener(function () {
            thiz.sendStartRequest();
        });
        boluotBt.addClickEventListener(function () {
            thiz.sendBoluotRequest();
        });
        danhbaiBt.addClickEventListener(function () {
            thiz.sendDanhBai();
        });
        xepBaiBt.addClickEventListener(function () {
            thiz.onXepBaiBtClick();
        });

        //danhbaiBt.visible = false;
        xepBaiBt.visible = false;
        boluotBt.visible = false;
        startBt.visible = false;

        this.danhbaiBt = danhbaiBt;
        this.xepBaiBt = xepBaiBt;
        this.boluotBt = boluotBt;
        this.startBt = startBt;
    },

    onXepBaiBtClick: function () {
        this.cardList.reArrangeCards(function (a, b) {
            var operatorA = a.rank, operatorB = b.rank;
            if (operatorA < 3) {
                operatorA += 13;
            }
            if (operatorB < 3) {
                operatorB += 13;
            }
            return operatorA - operatorB;
        });
    },

    initPlayer: function () {
        var playerMe = new GamePlayerMe();
        playerMe.setPosition(150, 50.0);
        this.sceneLayer.addChild(playerMe, 1);

        var player1 = new GamePlayer();
        player1.setPosition(cc.winSize.width - 120.0 / cc.winSize.screenScale, 360.0);
        this.sceneLayer.addChild(player1, 1);
        player1.chatView.setAnchorPoint(cc.p(1.0, 0.0));
        player1.chatView.y += 20;

        var player2 = new GamePlayer();
        player2.setPosition(cc.winSize.width / 2, 650.0 * cc.winSize.screenScale);
        this.sceneLayer.addChild(player2, 1);
        player2.chatView.setAnchorPoint(cc.p(1.0, 1.0));

        var player3 = new GamePlayer();
        player3.setPosition(120.0 / cc.winSize.screenScale, 360.0);
        this.sceneLayer.addChild(player3, 1);
        player3.chatView.setAnchorPoint(cc.p(0.0, 0.0));
        player3.chatView.y += 20;

        this.playerView = [playerMe, player1, player2, player3];

        var cardRemaining1 = new CardRemaining();
        cardRemaining1.setPosition(30, 100);
        player1.infoLayer.addChild(cardRemaining1);
        player1.cardRemaining = cardRemaining1;

        var cardRemaining2 = new CardRemaining();
        cardRemaining2.setPosition(130, 100);
        player2.infoLayer.addChild(cardRemaining2);
        player2.cardRemaining = cardRemaining2;

        var cardRemaining3 = new CardRemaining();
        cardRemaining3.setPosition(130, 100);
        player3.infoLayer.addChild(cardRemaining3);
        player3.cardRemaining = cardRemaining3;
    },

    onBoLuot: function (username) {
        if (PlayerMe.username == username) {
            return;
        }
        for (var i = 0; i < this.allSlot.length; i++) {
            if (this.allSlot[i].username == username) {
                var slot = this.allSlot[i];

                var labelEffect = cc.Label.createWithBMFont(cc.res.font.Roboto_CondensedBold_30, "Bỏ lượt");
                labelEffect.setColor(cc.color("#ff0000"));
                labelEffect.setPosition(slot.avt.getPosition());
                slot.addChild(labelEffect, 10);
                labelEffect.runAction(new cc.Sequence(new cc.DelayTime(1.0), new cc.CallFunc(function () {
                    labelEffect.removeFromParent(true);
                })));

                return;
            }
        }
    },

    showFinishedDialog: function (player) {
        var dialog = new ResultDialog(player.length);
        for (var i = 0; i < player.length; i++) {
            var username = player[i].username;
            if (username.length > 3 && (username != PlayerMe.username)) {
                username = username.substring(0, username.length - 3) + "***";
            }
            dialog.userLabel[i].setString(player[i].username);
            if (player[i].username == PlayerMe.username) {
                SoundPlayer.playSound(player[i].isWinner ? "winning" : "losing");
            }
            dialog.contentLabel[i].setString(player[i].title);

            this.setCardList(dialog.cardList[i], player[i].cardList)
            dialog.cardList[i].reOrderWithoutAnimation();

            var gold = player[i].gold;
            var goldStr = cc.Global.NumberFormat1(Math.abs(gold)) + " V";
            if (gold >= 0) {
                goldStr = "+" + goldStr;
            }
            else {
                goldStr = "-" + goldStr;
            }
            dialog.goldLabel[i].setString(goldStr);

            if (gold >= 0) {
                dialog.goldLabel[i].setColor(cc.color("#ffde00"));
            }
            else {
                dialog.goldLabel[i].setColor(cc.color("#ff0000"));
            }
        }
        dialog.showWithAnimationMove();
    },

    onChatChem: function (params) {
        var player1 = params["7"];
        var gold1 = params["3"];
        var changeGold1 = params["2"];

        var player2 = params["8"];
        var gold2 = params["6"];
        var changeGold2 = params["5"];

        for (var i = 0; i < this.allSlot.length; i++) {
            if (this.allSlot[i].username == player1) {
                this.allSlot[i].runChangeGoldEffect(changeGold1);
                //+ tien changeGold1
            }
            if (this.allSlot[i].username == player2) {
                this.allSlot[i].runChangeGoldEffect("-" + changeGold2);
                //- tien changeGold2
            }
        }

        this.updateGold(player1, gold1);
        this.updateGold(player2, gold2);
    },

    setCardMe: function (cardList) {
        this.setCardList(this.cardList, cardList);
    },

    setCardList: function (list, data) {
        list.removeAll();
        for (var i = 0; i < data.length; i++) {
            var cardNew = new Card(data[i].rank, data[i].suit);
            list.addCard(cardNew);
        }
        list.reOrderWithoutAnimation();
    },

    setCardOnTable: function (cardList) {
        this.cardOnTable.addCardReconnect(cardList);
    },

    dealCards: function (cardList) {
        this.cardList.dealCards(cardList, true);
    },

    removeCardList: function () {
        this.cardList.removeAll();
    },

    removeCardOnTable: function () {
        this.cardOnTable.removeAll();
    },

    setDanhBaiBtVisible: function (visible) {
        this.danhbaiBt.setVisible(visible);
    },

    setXepBaiBtVisible: function (visible) {
        this.xepBaiBt.setVisible(visible);
    },

    setBoLuotBtVisible: function (visible) {
        this.boluotBt.setVisible(visible);
    },

    setStartBtVisible: function (visible) {
        this.startBt.setVisible(visible);
    },

    // updateOwner: function (username) {
    //     this._super(username);
    //     if (this._controller.gameStatus == 1 && this.isOwnerMe) {
    //         this.startBt.visible = true;
    //     }
    // },

    onDanhbaiMe: function (username, cards) {
        var slot = this.getSlotByUsername(username);
        var arr = this.cardList.removeCard(cards);
        this.cardOnTable.moveOldCard();
        this.cardOnTable.addCard(arr);
        this.cardList.reOrder();
        for (var i = 0; i < arr.length; i++) {
            arr[i].release();
        }
        SoundPlayer.playSound("danh_bai");
    },

    onDanhbaiOther: function (username, cards) {
        var slot = this.getSlotByUsername(username);
        this.cardOnTable.moveOldCard();
        this.cardOnTable.addNewCardList(cards, slot.getPosition());
        SoundPlayer.playSound("danh_bai");
    },

    onUpdateTurn: function (username, currentTime, maxTime) {
        cc.log("updateTurn: " + currentTime + ":" + maxTime + " - " + Date.now());
        for (var i = 0; i < this.allSlot.length; i++) {
            if (this.allSlot[i].username == username) {
                this.allSlot[i].showTimeRemain(currentTime, maxTime);
            }
            else {
                this.allSlot[i].stopTimeRemain();
            }
        }
    },

    updateCardRemaining: function (username, card) {
        cc.log("updateCardRemaining: " + username);
        for (var i = 0; i < this.allSlot.length; i++) {
            if (this.allSlot[i].username == "") {
                continue;
            }
            if (this.allSlot[i].username == username) {
                if (this.allSlot[i].cardRemaining) {
                    this.allSlot[i].cardRemaining.setCardRemain(card);
                }
                break;
            }
        }
    },

    /* send request */
    sendStartRequest: function () {
        this._controller.sendStartRequest();
    },
    sendBoluotRequest: function () {
        this._controller.sendBoluotRequest();
    },
    sendDanhBai: function () {
        var cards = this.cardList.getCardSelected();
        this._controller.sendDanhBai(cards);
    }
});