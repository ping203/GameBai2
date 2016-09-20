/**
 * Created by Quyet Nguyen on 7/6/2016.
 */

String.prototype.insertAt=function(index, string) {
    return this.substr(0, index) + string + this.substr(index);
}

cc.Global = cc.Global || {};
cc.Global.NumberFormat1 = function (number) {
    var pret = Math.abs(number).toString();
    if(pret.length > 3){
        for(var i=pret.length-3; i>0;i-=3){
            pret = pret.insertAt(i,".");
        }
    }
    if(number < 0){
        return "-"+pret;
    }
    return pret;
};

cc.Global.NumberFormat2 = function (number) {
    return number.toString();
};

//cc.winSize.screenScale = cc.winSize.width / 1280.0;
cc.res = cc.res || {};
cc.res.font = cc.res.font || {};
cc.res.font.Roboto_Condensed = "res/fonts/Roboto-Condensed.ttf";
cc.res.font.Roboto_CondensedBold = "res/fonts/Roboto-BoldCondensed.ttf";
cc.res.font.UTM_AvoBold = "res/fonts/UTM-AvoBold.ttf";

cc.res.font.Roboto_Condensed_40 = "res/fonts/RobotoCondensed_40.fnt";
cc.res.font.Roboto_CondensedBold_40 = "res/fonts/RobotoBoldCondensed_40.fnt";
cc.res.font.UTM_AvoBold_40 = "res/fonts/UTMAvoBold_40.fnt";

cc.res.font.Roboto_Condensed_30 = "res/fonts/RobotoCondensed_30.fnt";
cc.res.font.Roboto_CondensedBold_30 = "res/fonts/RobotoBoldCondensed_30.fnt";
cc.res.font.UTM_AvoBold_30 = "res/fonts/UTMAvoBold_30.fnt";

cc.res.font.Roboto_Condensed_25 = "res/fonts/RobotoCondensed_25.fnt";
cc.res.font.Roboto_CondensedBold_25 = "res/fonts/RobotoBoldCondensed_25.fnt";
cc.res.font.UTM_AvoBold_25 = "res/fonts/UTMAvoBold_25.fnt";

var GameType = GameType || {};
GameType.GAME_MauBinh = 0;
GameType.GAME_TienLenMN = 1;
GameType.GAME_Phom = 2;
GameType.GAME_Sam = 3;
GameType.GAME_BaCay = 4;
GameType.GAME_XocDia = 5;
GameType.GAME_TaiXiu = 6;
GameType.GAME_VongQuayMayMan = 7;
GameType.GAME_TLMN_Solo = 8;
GameType.GAME_Sam_Solo = 9;
GameType.GAME_Lieng = 10;
GameType.GAME_BaCayChuong = 11;
GameType.MiniGame_ChanLe = 12;
GameType.MiniGame_CaoThap = 13;
GameType.MiniGame_Pocker = 14;

var s_game_id = s_game_id || [
    [
        GameType.GAME_TLMN_Solo, GameType.GAME_TienLenMN,
        GameType.MiniGame_CaoThap, GameType.MiniGame_Pocker,
        GameType.GAME_XocDia, GameType.GAME_TaiXiu,
        GameType.GAME_Sam_Solo, GameType.GAME_Sam,
        GameType.GAME_Phom, GameType.GAME_BaCay,
        GameType.GAME_VongQuayMayMan, GameType.MiniGame_ChanLe,
        GameType.GAME_MauBinh
    ],
    [
        GameType.GAME_TLMN_Solo, GameType.GAME_TienLenMN,
        GameType.GAME_Sam_Solo, GameType.GAME_Sam,
        GameType.GAME_Phom, GameType.GAME_BaCay,
        GameType.GAME_MauBinh
    ],
    [
        GameType.MiniGame_CaoThap, GameType.MiniGame_Pocker,
        GameType.MiniGame_ChanLe
    ],
    [
        GameType.GAME_VongQuayMayMan
    ],
    [
        GameType.GAME_TLMN_Solo, GameType.GAME_TienLenMN,
        GameType.MiniGame_CaoThap, GameType.MiniGame_Pocker
    ]
];

var s_mini_game_id = [GameType.MiniGame_CaoThap, GameType.MiniGame_Pocker, GameType.MiniGame_ChanLe];
var s_games_display_name = s_games_display_name || [];
s_games_display_name[GameType.GAME_TLMN_Solo] = "TIẾN LÊN MIỀN NAM ĐẾM LÁ SOLO";
s_games_display_name[GameType.GAME_TienLenMN] = "TIẾN LÊN MIỀN NAM";
s_games_display_name[GameType.GAME_Sam] = "SÂM LỐC";
s_games_display_name[GameType.GAME_Sam_Solo] = "SÂM SOLO";
s_games_display_name[GameType.GAME_XocDia] = "XÓC ĐĨA";
s_games_display_name[GameType.GAME_TaiXiu] = "TÀI XỈU";
s_games_display_name[GameType.GAME_MauBinh] = "MẬU BINH";
s_games_display_name[GameType.GAME_Phom] = "PHỎM";
s_games_display_name[GameType.GAME_BaCay] = "BA CÂY NHẤT ĂN TẤT";
s_games_display_name[GameType.GAME_Lieng] = "LIÊNG";
s_games_display_name[GameType.GAME_BaCayChuong] = "BA CÂY CHƯƠNG";

var s_games_chanel = s_games_chanel || [];
s_games_chanel[GameType.GAME_TLMN_Solo] = "";
s_games_chanel[GameType.GAME_TienLenMN] = "tlmn_tudo";
s_games_chanel[GameType.GAME_Sam] = "";
s_games_chanel[GameType.GAME_Sam_Solo] = "";
s_games_chanel[GameType.GAME_XocDia] = "";
s_games_chanel[GameType.GAME_TaiXiu] = "";
s_games_chanel[GameType.GAME_MauBinh] = "";
s_games_chanel[GameType.GAME_Phom] = "";
s_games_chanel[GameType.GAME_BaCay] = "";
s_games_chanel[GameType.GAME_Lieng] = "";
s_games_chanel[GameType.GAME_BaCayChuong] = "";

var s_games_chanel_id = s_games_chanel_id || {};
s_games_chanel_id["1"] = GameType.GAME_TLMN_Solo;
s_games_chanel_id["tlmn_tudo"] = GameType.GAME_TienLenMN;
s_games_chanel_id["2"] = GameType.GAME_Sam;
s_games_chanel_id["3"] = GameType.GAME_Sam_Solo;
s_games_chanel_id["4"] = GameType.GAME_XocDia;
s_games_chanel_id["5"] = GameType.GAME_TaiXiu;
s_games_chanel_id["6"] = GameType.GAME_MauBinh;
s_games_chanel_id["7"] = GameType.GAME_Phom;
s_games_chanel_id["8"] = GameType.GAME_BaCay;
s_games_chanel_id["9"] = GameType.GAME_Lieng;
s_games_chanel_id["10"] = GameType.GAME_BaCayChuong;

var PlayerMe = PlayerMe || {};
PlayerMe.username = "quyetnd";
PlayerMe.password = "1234567";
PlayerMe.phoneNumber = "0123456789";
PlayerMe.gameType = "";
PlayerMe.gold = 1000;
PlayerMe.exp = 11000;
PlayerMe.vipExp = 1000;
PlayerMe.spin = 0;
PlayerMe.messageCount = 100;
PlayerMe.SFS = PlayerMe.SFS || {};

var GameConfig = GameConfig || {};
GameConfig.email = "gamebaivip@gmail.com";
GameConfig.hotline = "09000123";
GameConfig.broadcastMessage = "Thông báo";
GameConfig.DeviceIDKey = "";

var LevelData = JSON.parse(jsb.fileUtils.getStringFromFile("res/data/LevelData.json"));
var VipData = JSON.parse(jsb.fileUtils.getStringFromFile("res/data/VipData.json"));
cc.Global.GetLevel = function (exp) {
    var preLevel = LevelData[0];
    for(var i=1;i<LevelData.length;i++){
        var obj = LevelData[i];
        if(exp >= preLevel.exp && exp < obj.exp){
            var expPer = 100.0 * (exp - preLevel.exp) / (obj.exp - preLevel.exp);
            return {
                level : i-1,
                expPer : expPer,
                content : preLevel.content
            };
        }
        preLevel = obj;
    }
    return {
        level : LevelData.length-1,
        expPer : 100.0,
        content : preLevel.content
    };
};
cc.Global.GetVip = function (exp) {
    var preLevel = VipData[0];
    for(var i=1;i<VipData.length;i++){
        var obj = VipData[i];
        if(exp >= preLevel.exp && exp < obj.exp){
            var expPer = 100.0 * (exp - preLevel.exp) / (obj.exp - preLevel.exp);
            return {
                level : i-1,
                expPer : expPer,
                content : preLevel.content
            };
        }
        preLevel = obj;
    }
    return {
        level : VipData.length-1,
        expPer : 100.0,
        content : preLevel.content
    };
};

cc.Global.GetLevelMe = function () {
    return cc.Global.GetLevel(PlayerMe.exp);
};
cc.Global.GetVipMe = function () {
    return cc.Global.GetVip(PlayerMe.vipExp);
};

cc.Global.GetSetting = function (setting, defaultValue) {
    var value = cc.sys.localStorage.getItem(JSON.stringify(setting));
    if(value){
        return JSON.parse(value);
    }
    return defaultValue;
};
cc.Global.SetSetting = function (setting, value) {
    cc.sys.localStorage.setItem(JSON.stringify(setting), JSON.stringify(value));
};

var ApplicationConfig = ApplicationConfig || {};
ApplicationConfig.VERSION = "1.0.0";
ApplicationConfig.BUNBLE = "com.gamebai.vip";
(function () {
    if(cc.sys.os === cc.sys.OS_IOS){
        ApplicationConfig.PLATFORM = 1;
    }
    else if(cc.sys.os === cc.sys.OS_ANDROID){
        ApplicationConfig.PLATFORM = 2;
    }
    else if(cc.sys.os === cc.sys.OS_WINRT){
        ApplicationConfig.PLATFORM = 3;
    }
    else if(cc.sys.os === cc.sys.OS_WINDOWS){
        ApplicationConfig.PLATFORM = 3;
    }
    else{
        ApplicationConfig.PLATFORM = 3;
    }
})();

cc.Global.NodeIsVisible = function (node) {
    while(node){
        if(!node.visible){
            return false;
        }
        node = node.getParent();
    }
    return true;
};