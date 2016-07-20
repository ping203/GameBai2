/**
 * Created by Quyet Nguyen on 6/30/2016.
 */

var HomeScene = IScene.extend({
    ctor : function () {
        this._super();
        this.homeLocation = 0;

        var bg = new cc.Sprite("res/game-bg.jpg");
        bg.x = cc.winSize.width/2;
        bg.y = cc.winSize.height/2;
        this.sceneLayer.addChild(bg);

        this.mainLayer = new cc.Node();
        this.sceneLayer.addChild(this.mainLayer);

        this.topBar = new LobbyTopBar();
        this.mainLayer.addChild(this.topBar);

        this.userInfo = new LobbyBottomBar();
        this.mainLayer.addChild(this.userInfo);

        this.homeLayer = new HomeLayer();
        this.mainLayer.addChild(this.homeLayer,1);

        this.gameLayer = new GameLayer();
        this.mainLayer.addChild(this.gameLayer);

        this.lobbyLayer = new LobbyLayer();
        this.mainLayer.addChild(this.lobbyLayer);

        this.miniGame = new MiniGameLayer();
        this.mainLayer.addChild(this.miniGame);

        var thiz = this;
        this.topBar.backBt.addClickEventListener(function () {
            thiz.backButtonHandler();
        });
        this.topBar.newsBt.addClickEventListener(function () {
            thiz.newsButtonhandler();
        });
        this.topBar.rankBt.addClickEventListener(function () {
            thiz.rankButtonHandler();
        });
        this.topBar.callBt.addClickEventListener(function () {
            thiz.callButtonHandler();
        });
        this.topBar.settingBt.addClickEventListener(function () {
            thiz.settingButtonHandler();
        });
        this.userInfo.newsBt.addClickEventListener(function () {
            thiz.newsMesasgeButtonHandler();
        });
        this.userInfo.paymentBt.addClickEventListener(function () {
            thiz.paymentButtonHandler();
        });
        this.userInfo.rewardBt.addClickEventListener(function () {
            thiz.rewardButtonHandler();
        });
        this.userInfo.userinfoBt.addClickEventListener(function () {
            thiz.userInfoButtonHandler();
        });

        this.startHome();
    },

    startHome : function () {
        this.homeLocation = 1;
        this.homeLayer.visible = true;
        this.gameLayer.visible = true;
        this.lobbyLayer.visible = false;
        this.userInfo.visible = false;
        if(arguments.length == 1) {
            this.miniGame.startAnimation();
            this.gameLayer.startAnimation();
        }
    },

    startGame : function () {
        this.homeLocation = 2;
        this.homeLayer.visible = false;
        this.gameLayer.visible = true;
        this.lobbyLayer.visible = false;
        this.userInfo.visible = true;
        this.userInfo.refreshView();
        if(arguments.length == 1) {
            this.miniGame.startAnimation();
            this.gameLayer.startAnimation();
        }
    },

    startLobby : function(){
        this.homeLocation = 3;
        this.homeLayer.visible = false;
        this.gameLayer.visible = false;
        this.lobbyLayer.visible = true;
        this.userInfo.visible = true;
        this.userInfo.refreshView();
        if(arguments.length == 1){
            this.lobbyLayer.startGame(arguments[0]);
        }
        else{
            this.lobbyLayer.startGame(-1);
        }
    },

    startGameWithAnimation : function () {
        this.startGame();
    },

    backButtonHandler : function () {
        if(this.popupLayer.getChildren().length > 0){
            this.popupLayer.removeAllChildren();
            return;
        }
        if(this.subLayer){
            this.subLayer.removeFromParent(true);
            this.subLayer = 0;
            this.mainLayer.visible = true;
            if(this.homeLocation == 2){
                this.miniGame.startAnimation();
                this.gameLayer.startAnimation();
            }
            if(this.homeLocation == 3){
                this.lobbyLayer.startAnimation();
                this.miniGame.startAnimation();
            }
            return;
        }
        if(this.homeLocation == 1){
            //exit app
            SystemPlugin.getInstance().exitApp();
        }
        else if(this.homeLocation == 2){
            //logout
            //to home
            var dialog = new MessageConfirmDialog();
            dialog.setMessage("Bạn muốn thoát game ?");
            dialog.okButtonHandler = function () {
                SystemPlugin.getInstance().exitApp();
            };
            dialog.cancelButtonHandler = function () {
                dialog.hide();
            };
            dialog.show();
        }
        else if(this.homeLocation == 3){
            //to game
            this.startGame();
            this.gameLayer.startAnimation();
        }
    },

    addSubLayer : function (subLayer) {
        var thiz = this;
        subLayer.backBt.addClickEventListener(function () {
            thiz.backButtonHandler();
        });
        subLayer.settingBt.addClickEventListener(function () {
            thiz.settingButtonHandler();
        });

        this.subLayer = subLayer;
        this.sceneLayer.addChild(subLayer);
        this.mainLayer.visible = false;
    },

    newsButtonhandler : function () {
        if(this.homeLocation == 1){
            MessageNode.getInstance().show("Bạn phải đăng nhập trước");
            return;
        }
        this.addSubLayer(new NewsLayer());
    },
    
    rankButtonHandler : function () {
        if(this.homeLocation == 1){
            MessageNode.getInstance().show("Bạn phải đăng nhập trước");
            return;
        }
        this.addSubLayer(new RankLayer());
    },

    settingButtonHandler : function () {
        var dialog = new SettingDialog();
        dialog.showWithAnimationMove();
    },

    callButtonHandler : function () {
        // var dialog = new Dialog();
        // dialog.initWithSize(cc.size(700,300));
        // dialog.show();

       // LoadingDialog.getInstance().show();
        //MessageNode.getInstance().show("Test message node");

        var dialog = new RewardDialog();
        dialog.setItem("Apple iPhone 10S 128GB", 1000000);
        dialog.showWithAnimationScale();
    },

    newsMesasgeButtonHandler : function () {
        if(this.homeLocation == 1){
            MessageNode.getInstance().show("Bạn phải đăng nhập trước");
            return;
        }
        this.addSubLayer(new InboxLayer());
    },
    
    rewardButtonHandler : function () {
        this.addSubLayer(new RewardLayer());
    },
    
    paymentButtonHandler : function () {
        this.addSubLayer(new PaymentLayer());
    },
    
    userInfoButtonHandler : function () {
        var dialog = new UserinfoDialog();
        dialog.showWithAnimationMove();
    },

    onEnter : function () {
        this._super();
        var thiz = this;
        cc.eventManager.addListener({
            event: cc.EventListener.KEYBOARD,
            // onKeyPressed:  function(keyCode, event){
            //     cc.log("Key " + parseKeyCode(keyCode) + " was pressed!");
            // },
            onKeyReleased: function(keyCode, event){
                if(parseKeyCode(keyCode) == cc.KEY.back){
                    thiz.backButtonHandler();
                }
            }
        }, this);
    }
});