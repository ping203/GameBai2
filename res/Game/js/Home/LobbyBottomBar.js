/**
 * Created by Quyet Nguyen on 7/1/2016.
 */

var LobbyBottomBar = cc.Node.extend({
    ctor : function () {
        this._super();

        var thiz = this;

        this.setAnchorPoint(cc.p(0,0));

        var logo = new cc.Sprite("#bot_bar_logo.png");
        logo.setAnchorPoint(cc.p(0.5, 0.0));
        logo.setPosition(640, 0);
        logo.setVisible(false);
        this.addChild(logo);
        this.logo = logo;



        var effectPlayNow = new cc.Sprite("bot_bar_effect_playBg.png");
        effectPlayNow.setAnchorPoint(cc.p(0.5, 0.0));
        effectPlayNow.setPosition(640, -50);
        effectPlayNow.setVisible(false);
        this.addChild(effectPlayNow);
        this.effectPlayNow = effectPlayNow;

        var playnowBt = new ccui.Button("bot_bar_playBg.png", "", "", ccui.Widget.PLIST_TEXTURE);
        playnowBt.setAnchorPoint(cc.p(0.5, 0.0));
        playnowBt.setPosition(640, 0);
        playnowBt.setVisible(false);
        this.addChild(playnowBt);
        playnowBt.addClickEventListener(function(){
            thiz.playNowButtonHandler();

        });
        this.playnowBt = playnowBt;


        var avt = UserAvatar.createMe();
        avt.setPosition(63, 56);
        this.addChild(avt, 0);
        this.avatar = avt;

        var nameLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_18, "Name2221231312313213212312312332132");
        nameLabel.setAnchorPoint(0.0, 0.5);
        nameLabel.setColor(cc.color("#bff2ff"));
        nameLabel.setPosition(109, 66);
        this.addChild(nameLabel,1);
        this.nameLabel = nameLabel;

        var goldLabel = cc.Label.createWithBMFont(cc.res.font.Roboto_CondensedBold_18, "100,1111V");
        goldLabel.setAnchorPoint(0.0, 0.5);
        goldLabel.setColor(cc.color("#ffde00"));
        goldLabel.setPosition(109, 45);
        this.addChild(goldLabel,1);
        this.goldLabel = goldLabel;

        var level = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "6");
        level.setScale(25/24);
        level.setPosition(328, 57);
        level.setColor(cc.color("#36c9ff"));
        this.addChild(level, 1);
        this.levelLabel = level;

        var vip = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_25, "6");
        vip.setScale(25/24);
        vip.setPosition(421, 57);
        vip.setColor(cc.color("#ffde00"));
        this.addChild(vip, 1);
        this.vipLabel = vip;

        var _levelText = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_16, "Level");
        _levelText.setColor(cc.color("#36c9ff"));
        _levelText.setPosition(level.x, 16);
        this.addChild(_levelText, 1);

        var _vipText = cc.Label.createWithBMFont(cc.res.font.Roboto_Condensed_16, "V.I.P");
        _vipText.setColor(cc.color("#ffde00"));
        _vipText.setPosition(vip.x, 16);
        this.addChild(_vipText, 1);

        var levelBar = new cc.ProgressTimer(new cc.Sprite("#bot_bar_levelBar_1.png"));
        levelBar.setType(cc.ProgressTimer.TYPE_RADIAL);
        levelBar.setReverseDirection(true);
        levelBar.setPosition(level.getPosition());
        levelBar.setPercentage(25.0);
        var levelBarBg = new cc.Sprite("#bot_bar_levelBar_bg.png");
        levelBarBg.setPosition(levelBar.getContentSize().width/2, levelBar.getContentSize().height/2);
        levelBar.addChild(levelBarBg, -1);
        this.addChild(levelBar);
        this.levelBar = levelBar;

        var vipBar = new cc.ProgressTimer(new cc.Sprite("#bot_bar_levelBar_2.png"));
        vipBar.setType(cc.ProgressTimer.TYPE_RADIAL);
        vipBar.setReverseDirection(true);
        vipBar.setPosition(vip.getPosition());
        vipBar.setPercentage(75.0);
        var vipBarBg = new cc.Sprite("#bot_bar_levelBar_bg.png");
        vipBarBg.setPosition(vipBar.getContentSize().width/2, vipBar.getContentSize().height/2);
        vipBar.addChild(vipBarBg, -1);
        this.addChild(vipBar);
        this.vipBar = vipBar;

        if(!cc.sys.isNative && cc._renderType === cc.game.RENDER_TYPE_WEBGL){
            vipBar._alwaysRefreshVertext = true;
            levelBar._alwaysRefreshVertext = true;
        }

        var paymentBt = new ccui.Button("bot_bar_paymentBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        paymentBt.setAnchorPoint(cc.p(0.0, 0.0));
        paymentBt.setPosition(853, 26);
        this.addChild(paymentBt);

        var rewardBt = new ccui.Button("bot_bar_rewardBt.png", "", "", ccui.Widget.PLIST_TEXTURE);
        rewardBt.setAnchorPoint(cc.p(0.0, 0.0));
        rewardBt.setPosition(1065, 26);
        this.addChild(rewardBt);

        var userinfoBt = new ccui.Widget();
        userinfoBt.setContentSize(cc.size(200, 80));
        userinfoBt.setAnchorPoint(cc.p(0,0));
        userinfoBt.setTouchEnabled(true);
        userinfoBt.setPosition(0, 0);
        this.addChild(userinfoBt);

        this.setScale(cc.winSize.screenScale);

        this.paymentBt = paymentBt;
        this.rewardBt = rewardBt;
        this.userinfoBt = userinfoBt;

        this.refreshView();


    },

    refreshView : function () {
        //this.avatar.setAvatarMe();

        var myName = PlayerMe.username;
        if(myName.length > 15){
            myName = PlayerMe.username.substr(0, 15);
        }

        this.nameLabel.setString(myName);
        this.goldLabel.setString(cc.Global.NumberFormat1(PlayerMe.gold) +" V");

        var level = cc.Global.GetLevelMe();
        this.levelLabel.setString(level.level.toString());
        this.levelBar.setPercentage(level.expPer);

        var vip = cc.Global.GetVipMe();
        this.vipLabel.setString(vip.level.toString());
        this.vipBar.setPercentage(vip.expPer);
    },

    startGame : function () {
        this.logo.setVisible(true);
        this.playnowBt.setVisible(false);
        this.effectPlayNow.setVisible(false);
    },

    startLobby : function () {
        this.logo.setVisible(false);
        this.playnowBt.setVisible(true);
        this.effectPlayNow.setVisible(true);
        // this.runEffectPlayNow(true);
    },

    playNowButtonHandler : function () {

    },

    runEffectPlayNow : function(isRun)
    {
        // this.effectPlayNow.stopAllActions();
        this.effectPlayNow.setVisible(true);
        // if(isRun)
        // {
            var moveup = new cc.MoveTo(0.5, cc.p(this.effectPlayNow.x, 100));
            var movedown = new cc.MoveTo(0.5, cc.p(this.effectPlayNow.x, 0));

            var actions = new cc.Sequence(moveup, movedown);
            this.effectPlayNow.runAction(new cc.RepeatForever(actions));
        // }
        // else
        // {
        //     this.effectPlayNow.setVisible(false);
        // }
    }



});