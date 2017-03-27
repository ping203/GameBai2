/**
 * Created by Quyet Nguyen on 7/11/2016.
 */

var RankSubLayer = cc.Node.extend({
    ctor: function () {
        this._super();
        this.initItemList();

        var _left = 60.0 * cc.winSize.screenScale;
        var _padding = 2.0;
        this.width1 = 150.0 * cc.winSize.screenScale;
        this.width3 = 200.0;
        this.width2 = this.itemList.getContentSize().width - this.width1 - this.width3 - _padding * 2 - _left * 2;

        this.x1 = _left + this.width1 / 2;
        this.x2 = this.x1 + this.width1 / 2 + this.width2 / 2;
        this.x3 = this.x2 + this.width2 / 2 + this.width3 / 2;

        var rankLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "Cấp");
        rankLabel.setPosition(this.x1, 576);
        rankLabel.setOpacity(0.2 * 255);
        this.addChild(rankLabel);
        this.rankLabel = rankLabel;

        var userLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "Người chơi");
        userLabel.setPosition(this.x2, 576);
        userLabel.setOpacity(0.2 * 255);
        this.addChild(userLabel);
        this.userLabel = userLabel;

        var scoreLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "Điểm");
        scoreLabel.setPosition(this.x3, 576);
        scoreLabel.setOpacity(0.2 * 255);
        this.addChild(scoreLabel);
        this.scoreLabel = scoreLabel;
    },

    initItemList : function () {
        var _top = 554.0;
        var _bottom = 82.0 * cc.winSize.screenScale;

        var itemList = new newui.TableView(cc.size(cc.winSize.width, _top - _bottom), 1);
        itemList.setDirection(ccui.ScrollView.DIR_VERTICAL);
        itemList.setScrollBarEnabled(false);
        itemList.setPadding(10);
        itemList.setMargin(10, 30, 0, 0);
        itemList.setPosition(cc.p(0, _bottom));
        this.addChild(itemList, 1);
        this.itemList = itemList;
    },

    addItem: function (rank, username, score) {
        var container = new ccui.Widget();
        container.setContentSize(cc.size(this.itemList.getContentSize().width, 80));
        this.itemList.pushItem(container);


        var bg1 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg1.setPreferredSize(cc.size(this.width1, container.getContentSize().height));
        bg1.setPosition(this.x1, container.getContentSize().height / 2);
        container.addChild(bg1);

        var bg2 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg2.setPreferredSize(cc.size(this.width2, container.getContentSize().height));
        bg2.setPosition(this.x2, container.getContentSize().height / 2);
        container.addChild(bg2);

        var bg3 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg3.setPreferredSize(cc.size(this.width3, container.getContentSize().height));
        bg3.setPosition(this.x3, container.getContentSize().height / 2);
        container.addChild(bg3);

        var rankLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, rank);
        rankLabel.setPosition(bg1.getPosition());
        container.addChild(rankLabel);

        if (username.length > 3 && (username != PlayerMe.username)) {
            username = username.substring(0, username.length - 3) + "***";
        }

        var userLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, username, cc.TEXT_ALIGNMENT_CENTER);
        userLabel.setLineBreakWithoutSpace(true);
        userLabel.setDimensions(bg2.getContentSize().width - 10, userLabel.getLineHeight());
        userLabel.setPosition(bg2.getPosition());
        container.addChild(userLabel);

        var scoreLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, score);
        scoreLabel.setPosition(bg3.getPosition());
        container.addChild(scoreLabel);
    }
});

var RankGoldLayer = RankSubLayer.extend({
    ctor: function () {
        this._super();
        this.scoreLabel.setString("Vàng");
        LobbyClient.getInstance().addListener("getTop", this.onGetTop, this);
        LobbyClient.getInstance().send({command: "getTop", type: 2, limit: 10});
    },
    onGetTop: function (command, data) {
        data = data["data"]["2"];
        if (this.itemList.length > 0 || (!data))
            return;
        for (var i = 0; i < data.length; i++) {
            this.addItem(i + 1, data[i]["username"], data[i]["value"]);
        }
    },
    onExit: function () {
        this._super();
        LobbyClient.getInstance().removeListener(this);
    }
});

var RankVipLayer = RankSubLayer.extend({
    ctor: function () {
        this._super();
        this.scoreLabel.setString("VIP");
        LobbyClient.getInstance().addListener("getTop", this.onGetTop, this);
        LobbyClient.getInstance().send({command: "getTop", type: 3, limit: 10});
    },
    onGetTop: function (command, data) {
        data = data["data"]["3"];
        if (this.itemList.length > 0 || (!data))
            return;
        for (var i = 0; i < data.length; i++) {
            this.addItem(i + 1, data[i]["username"], data[i]["value"]);
        }
    },
    onExit: function () {
        this._super();
        LobbyClient.getInstance().removeListener(this);
    }
});

var s_game_rank_id = s_game_rank_id || [
        GameType.GAME_MauBinh,
        GameType.GAME_TienLenMN,
        GameType.GAME_TLMN_Solo,
        GameType.GAME_Sam,
        GameType.GAME_Sam_Solo,
        GameType.GAME_Phom,
        GameType.GAME_BaCay,
        GameType.GAME_XocDia,
        GameType.GAME_TaiXiu,
        //GameType.GAME_Lieng
        //GameType.GAME_BaCayChuong
];

var RankLevelLayer = RankSubLayer.extend({
    ctor: function () {
        this._super();
        this.scoreLabel.removeFromParent(true);
        this.userLabel.setPositionX(this.x2 - 88);

        //override
        var _left = 60.0 * cc.winSize.screenScale;
        var _padding = 2.0;
        this.width1 = 150.0 * cc.winSize.screenScale;
        this.width3 = 200.0;
        this.width2 = this.itemList.getContentSize().width - this.width1 - this.width3;

        this.x1 = _left + this.width1 / 2;
        this.x2 = this.x1 + this.width1 / 2 + this.width2 / 2;
        this.x3 = this.x2 + this.width2 / 2 + this.width3 / 2;
        /**/

        var winLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "Thắng");
        winLabel.setPosition(this.x3 - 200, 576);
        winLabel.setOpacity(0.2 * 255);
        this.addChild(winLabel);

        var loseLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "Thua");
        loseLabel.setPosition(this.x3 - 50, 576);
        loseLabel.setOpacity(0.2 * 255);
        this.addChild(loseLabel);

        LobbyClient.getInstance().addListener("getTop", this.onGetTop, this);

        var typeToggle = new ToggleNodeGroup();
        //this.addChild(typeToggle, 1);

        var itemCount = 0;
        for (var i = 0; i < s_game_rank_id.length; i++) {
            var gameId = s_game_rank_id[i];
            if(s_game_available[gameId]) {
                itemCount++;
            }
        }

        var dy = 80.0;
        var width = 200.0;
        var height = dy * itemCount;
        var x = width/2 - 18.0;
        var y = height - dy/2;

        typeToggle.setAnchorPoint(cc.p(0.0,0.0));
        typeToggle.setContentSize(cc.size(width, height));

        var scrollView = new newui.TableView(cc.size(width, dy* 5), 1);
        scrollView.setPosition(cc.winSize.width - width, 140);
        scrollView.pushItem(typeToggle);
        this.addChild(scrollView, 1);

        var selectBg = new cc.Sprite("#rank_label_selected_1.png");
        selectBg.setPosition(x, y);
        typeToggle.addChild(selectBg);

        var selectIcon = new cc.Sprite("#rank_label_selected_2.png");
        selectIcon.setPosition(width - selectIcon.getContentSize().width/2, y);
        typeToggle.addChild(selectIcon);

        var thiz = this;
        for (var i = 0; i < s_game_rank_id.length; i++) {
            (function () {
                var gameId = s_game_rank_id[i];
                if(s_game_available[gameId]){
                    var icon1 = new cc.Sprite("#rank_label_" + gameId + "_1.png");
                    var icon2 = new cc.Sprite("#rank_label_" + gameId + "_2.png");

                    icon1.setPosition(x, y);
                    icon2.setPosition(icon1.getPosition());

                    typeToggle.addChild(icon1);
                    typeToggle.addChild(icon2);

                    var toggleItem = new ToggleNodeItem(icon1.getContentSize());
                    toggleItem.setPosition(icon1.getPosition());
                    typeToggle.addItem(toggleItem);
                    toggleItem.onSelect = function (isForce) {
                        icon1.setVisible(false);
                        icon2.setVisible(true);
                        selectBg.y = icon1.y;
                        selectIcon.y = icon1.y;

                        thiz.requestGetTop(gameId);
                    };
                    toggleItem.onUnSelect = function () {
                        icon1.setVisible(true);
                        icon2.setVisible(false);
                    };

                    y -= dy;
                }
            })();
        }

     //   typeToggle.selectItem(0);
        this.typeToggle = typeToggle;
    },

    requestGetTop : function (gameId) {
        this.itemList.removeAllItems();
        LobbyClient.getInstance().send({command: "getTop", type: 1, gameType: s_games_chanel[gameId], limit: 10});
    },

    onEnter : function () {
        this._super();
        this.typeToggle.selectItem(0);
    },

    initItemList : function () {
        var _top = 554.0;
        var _bottom = 82.0 * cc.winSize.screenScale;

        var itemList = new newui.TableView(cc.size(cc.winSize.width - 220 , _top - _bottom), 1);
        itemList.setDirection(ccui.ScrollView.DIR_VERTICAL);
        itemList.setScrollBarEnabled(false);
        itemList.setPadding(10);
        itemList.setMargin(10, 30, 0, 0);
        itemList.setPosition(cc.p(0, _bottom));
        this.addChild(itemList, 1);
        this.itemList = itemList;
    },

    onGetTop: function (command, data) {
        cc.log(JSON.stringify(data));
        data = data["data"]["1"];
        if (!data)
            return;
        this.itemList.removeAllItems();
        for (var i = 0; i < data.length; i++) {
            this.addItem(i + 1, data[i]["username"], data[i]["winGold"], data[i]["looseGold"]);
        }
    },
    addItem: function (rank, username, win, lose) {
        var container = new ccui.Widget();
        container.setContentSize(cc.size(this.itemList.getContentSize().width, 80));
        this.itemList.pushItem(container);


        var bg1 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg1.setPreferredSize(cc.size(this.width1, container.getContentSize().height));
        bg1.setPosition(this.x1, container.getContentSize().height / 2);
        container.addChild(bg1);

        var bg2 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg2.setPreferredSize(cc.size(this.width2 - 180, container.getContentSize().height));
        bg2.setPosition(this.x2 - 88, container.getContentSize().height / 2);
        container.addChild(bg2);

        var bg3 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg3.setPreferredSize(cc.size(150, container.getContentSize().height));
        bg3.setPosition(this.x3 - 200, container.getContentSize().height / 2);
        container.addChild(bg3);

        var bg4 = new ccui.Scale9Sprite("sublobby-cell-bg.png", cc.rect(10, 0, 4, 78));
        bg4.setPreferredSize(cc.size(150, container.getContentSize().height));
        bg4.setPosition(this.x3 - 50, container.getContentSize().height / 2);
        container.addChild(bg4);

        var rankLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, rank);
        rankLabel.setPosition(bg1.getPosition());
        container.addChild(rankLabel);

        if (username.length > 3 && (username != PlayerMe.username)) {
            username = username.substring(0, username.length - 3) + "***";
        }

        var userLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, username, cc.TEXT_ALIGNMENT_CENTER);
        userLabel.setLineBreakWithoutSpace(true);
        userLabel.setDimensions(bg2.getContentSize().width - 10, userLabel.getLineHeight());
        userLabel.setPosition(bg2.getPosition());
        container.addChild(userLabel);

        var winLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, win);
        winLabel.setPosition(bg3.getPosition());
        container.addChild(winLabel);

        var loseLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, lose);
        loseLabel.setPosition(bg4.getPosition());
        container.addChild(loseLabel);
    },
    onExit: function () {
        this._super();
        LobbyClient.getInstance().removeListener(this);
    }
});

var rank_tab_1 = rank_tab_1 || [
    "#rank-tab-1.png",
    "#rank-tab-2.png",
    "#rank-tab-3.png"
];

var rank_tab_2 = rank_tab_2 || [
    "#rank-tab-selected-1.png",
    "#rank-tab-selected-2.png",
    "#rank-tab-selected-3.png"
];

var RankLayer = LobbySubLayer.extend({
    ctor: function () {
        this._super("#lobby-title-rank.png");

        var allLayer = [new RankGoldLayer(), new RankVipLayer(), new RankLevelLayer()];
        for (var i = 0; i < allLayer.length; i++) {
            this.addChild(allLayer[i]);
        }
        this._initTab(rank_tab_1, rank_tab_2, allLayer);
    },

    onEnter: function () {
        this._super();
        this.mToggle.selectItem(0);
    }
});