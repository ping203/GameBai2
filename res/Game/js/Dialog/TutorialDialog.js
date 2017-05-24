/**
 * Created by VGA10 on 1/9/2017.
 */

var TutorialDialog = Dialog.extend({
    ctor: function (gameType) {
        this._super();

        this.bouldingWidth = 800;
        // var board_bg = new ccui.Scale9Sprite("board_bg.png", cc.rect(105, 105, 147, 147));
        // board_bg.setAnchorPoint(cc.p(0, 0));
        // this.addChild(board_bg);
        // this.board_bg = board_bg;

        this.initWithSize(cc.size(880, 580));
        this.okButton.visible = false;
        this.cancelButton.visible = false;
        this.title.setString("HƯỚNG DẪN CHƠI");
        // var title = cc.Label.createWithBMFont(cc.res.font.Roboto_CondensedBold_30, "HƯỚNG DẪN CHƠI");
        // title.setPosition(this.getContentSize().width / 2, this.getContentSize().height - 138);
        // title.setColor(cc.color("#ffde00"));
        // this.addChild(title);

        // var clippingLayout = new ccui.Layout();
        // clippingLayout.setContentSize(this.getContentSize().width, this.getContentSize().height - 275);
        // clippingLayout.setAnchorPoint(cc.p(0.5, 0.5));
        // clippingLayout.setPosition(this.getContentSize().width / 2, this.getContentSize().height / 2 - 25);
        // clippingLayout.setClippingEnabled(true);
        // clippingLayout.setClippingType(ccui.Layout.CLIPPING_SCISSOR);
        // this.addChild(clippingLayout);

        var contentTable = new newui.TableView(cc.size(this.bouldingWidth, 470), 1);
        contentTable.setDirection(ccui.ScrollView.DIR_VERTICAL);
        contentTable.setScrollBarEnabled(false);
        contentTable.setPadding(0);
        contentTable.setMargin(10, 10, 0, 0);
        contentTable.setAnchorPoint(cc.p(0.5, 0.5));
        contentTable.setPosition(this.getContentSize().width / 2, this.getContentSize().height / 2 - 25);
        this.addChild(contentTable);
        // contentTable.setPosition(clippingLayout.getContentSize().width / 2,
        //     clippingLayout.getContentSize().height / 2);
        // clippingLayout.addChild(contentTable);
        this.contentTable = contentTable;
        if(cc.sys.isNative){
            this.HDList = jsb.fileUtils.getValueMapFromFile("res/data/HDList.plist");
        }
        else{
            this.HDList = cc.loader.getRes("res/data/HDList.plist");
        }


        switch (gameType) {
            case GameType.MiniGame_CaoThap:
                this.initCaoThapTutorial();
                break;

            case GameType.MiniGame_Poker:
                this.initMiniPokerTutorial();
                break;

            case GameType.MiniGame_VideoPoker:
                this.initVideoPokerTutorial();
                break;
            case GameType.MiniGame_ChanLe:
                this.initChanLeTutorial();
                break;
            case GameType.GAME_VongQuayMayMan:
                this.initVongQuayTutorial();
                break;
        }
    },

    // initWithSize: function (mSize) {
    //     this.board_bg.setPreferredSize(cc.size(mSize.width, mSize.height));
    //     this.setContentSize(this.board_bg.getContentSize());
    // },

    initCaoThapTutorial: function () {
        var tutorialLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, this.HDList["CaoThap"]);
        tutorialLabel.setBoundingWidth(this.bouldingWidth);
        this.contentTable.pushItem(tutorialLabel);
    },

    initMiniPokerTutorial: function () {
        this.initPokerTutorial("MiniPoker");
    },

    initVideoPokerTutorial: function () {
        this.initPokerTutorial("VideoPoker");
    },
    initChanLeTutorial:function () {
        var tutorialLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, this.HDList["MINITAIXIU"]);
        var icon1 = new cc.Sprite("#mntx_btn_bxh.png");
        icon1.setScale(0.7);
        icon1.setPosition(570, 83);
        this.contentTable.addChild(icon1);
        var icon2 = new cc.Sprite("#caothap_historyBt.png");
        icon2.setScale(0.7);
        icon2.setPosition(620, 83);
        this.contentTable.addChild(icon2);
        tutorialLabel.setBoundingWidth(this.bouldingWidth);
        this.contentTable.pushItem(tutorialLabel);
    },
    initVongQuayTutorial:function () {
        var tutorialLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, this.HDList["VQGD"]);
        tutorialLabel.setBoundingWidth(this.bouldingWidth);
        this.contentTable.pushItem(tutorialLabel);
    },
    initPokerTutorial: function (dataField) {
        var miniLabel1 = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, this.HDList[dataField]["text1"]
            , cc.TEXT_ALIGNMENT_LEFT);
        miniLabel1.setBoundingWidth(this.bouldingWidth);
        this.contentTable.pushItem(miniLabel1);

        // result table
        for (var i = 0; i < this.HDList[dataField]["Result"].length; i++) {
            var container = new ccui.Widget();
            var contentSize = cc.size(this.contentTable.getContentSize().width, 60);
            container.setContentSize(contentSize);
            var data = this.HDList[dataField]["Result"][i];

            var rowBg = new cc.LayerColor(cc.color(74,142,211,i%2 ? 128 : 255),contentSize.width,contentSize.height);
            container.addChild(rowBg);

            var titleLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, data["Title"]);
            titleLabel.setPosition(i == 0 ? contentSize.width / 4 : contentSize.width / 8, contentSize.height / 2);
            container.addChild(titleLabel,1);
            //
            if (i != 0) {
                var cardList = new CardList(cc.size(contentSize.width / 4, contentSize.height - 20));
                cardList.setPosition(contentSize.width * 3 / 8, contentSize.height / 2);
                var cards = data["cards"];
                cards = cards.split(',');
                for (var j = 0; j < cards.length; j++) {
                    var cardObj = cardList.getCardWithId(parseInt(cards[j]));
                    cardList.addCard(new Card(cardObj.rank, cardObj.suit));
                }
                cardList.reOrderWithoutAnimation();
                container.addChild(cardList);
            }

            //
            var rewardLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, data["Reward"]);
            rewardLabel.setPosition(contentSize.width * 3 / 4, contentSize.height / 2);
            container.addChild(rewardLabel);
            this.contentTable.pushItem(container);
        }

        var miniLabel2 = new cc.LabelBMFont(this.HDList[dataField]["text2"], cc.res.font.Roboto_Condensed_25, this.bouldingWidth, cc.TEXT_ALIGNMENT_LEFT);
        this.contentTable.pushItem(miniLabel2);
    }
});

var s_MiniPockerTutorialDialog = null;
var s_VideoPockerTutorialDialog = null;
var s_CaoThapTutorialDialog = null;
var s_ChanLeTutorialDialog = null;
var s_VongQuayTutorialDialog = null;

TutorialDialog.getTutorial = function (gameType) {
    switch (gameType) {
        case GameType.MiniGame_CaoThap:{
            if(!s_CaoThapTutorialDialog){
                s_CaoThapTutorialDialog = new TutorialDialog(gameType);
                s_CaoThapTutorialDialog.retain();
            }
            return s_CaoThapTutorialDialog;
           // return new TutorialDialog(gameType)
            break;
        }

        case GameType.MiniGame_Poker:{
            if(!s_MiniPockerTutorialDialog){
                s_MiniPockerTutorialDialog = new TutorialDialog(gameType);
                s_MiniPockerTutorialDialog.retain();
            }
            return s_MiniPockerTutorialDialog;
            //return new TutorialDialog(gameType);
            break;
        }

        case GameType.MiniGame_VideoPoker:{
            if(!s_VideoPockerTutorialDialog){
                s_VideoPockerTutorialDialog = new TutorialDialog(gameType);
                s_VideoPockerTutorialDialog.retain();
            }
            return s_VideoPockerTutorialDialog;
           // return new TutorialDialog(gameType);
            break;
        }
        case GameType.MiniGame_ChanLe:{
            // if(!s_ChanLeTutorialDialog){
            //     s_ChanLeTutorialDialog = new TutorialDialog(gameType);
            //     s_ChanLeTutorialDialog.retain();
            // }
            // return s_ChanLeTutorialDialog;
            return new TutorialDialog(gameType);
            break;
        }
        case GameType.GAME_VongQuayMayMan:{
            // if(!s_VongQuayTutorialDialog){
            //     s_VongQuayTutorialDialog = new TutorialDialog(gameType);
            //     s_VongQuayTutorialDialog.retain();
            // }
            // return s_VongQuayTutorialDialog;
            return new TutorialDialog(gameType);
            break;
        }
    }
};