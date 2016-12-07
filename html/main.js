/**
 * A brief explanation for "project.json":
 * Here is the content of project.json file, this is the global configuration for your game, you can modify it to customize some behavior.
 * The detail of each field is under it.
 {
    "project_type": "javascript",
    // "project_type" indicate the program language of your project, you can ignore this field

    "debugMode"     : 1,
    // "debugMode" possible values :
    //      0 - No message will be printed.
    //      1 - cc.error, cc.assert, cc.warn, cc.log will print in console.
    //      2 - cc.error, cc.assert, cc.warn will print in console.
    //      3 - cc.error, cc.assert will print in console.
    //      4 - cc.error, cc.assert, cc.warn, cc.log will print on canvas, available only on web.
    //      5 - cc.error, cc.assert, cc.warn will print on canvas, available only on web.
    //      6 - cc.error, cc.assert will print on canvas, available only on web.

    "showFPS"       : true,
    // Left bottom corner fps information will show when "showFPS" equals true, otherwise it will be hide.

    "frameRate"     : 60,
    // "frameRate" set the wanted frame rate for your game, but the real fps depends on your game implementation and the running environment.

    "noCache"       : false,
    // "noCache" set whether your resources will be loaded with a timestamp suffix in the url.
    // In this way, your resources will be force updated even if the browser holds a cache of it.
    // It's very useful for mobile browser debuging.

    "id"            : "gameCanvas",
    // "gameCanvas" sets the id of your canvas element on the web page, it's useful only on web.

    "renderMode"    : 0,
    // "renderMode" sets the renderer type, only useful on web :
    //      0 - Automatically chosen by engine
    //      1 - Forced to use canvas renderer
    //      2 - Forced to use WebGL renderer, but this will be ignored on mobile browsers

    "engineDir"     : "frameworks/cocos2d-html5/",
    // In debug mode, if you use the whole engine to develop your game, you should specify its relative path with "engineDir",
    // but if you are using a single engine file, you can ignore it.

    "modules"       : ["cocos2d"],
    // "modules" defines which modules you will need in your game, it's useful only on web,
    // using this can greatly reduce your game's resource size, and the cocos console tool can package your game with only the modules you set.
    // For details about modules definitions, you can refer to "../../frameworks/cocos2d-html5/modulesConfig.json".

    "jsList"        : [
    ]
    // "jsList" sets the list of js files in your game.
 }
 *
 */

var quyetnd = quyetnd || {};
quyetnd.sys = quyetnd.sys || {};
var _resumeMethod = function () {
    var _listener1 = cc.EventListener.create({
        event: cc.EventListener.CUSTOM,
        eventName: "game_on_hide",
        callback: function(event){
            cc.log("game_on_hide: " + Date.now());
            quyetnd.sys.lastRunningTime = Date.now();
        }
    });

    var _listener2 = cc.EventListener.create({
        event: cc.EventListener.CUSTOM,
        eventName: "game_on_show",
        callback: function(event){
            if(quyetnd.sys.lastRunningTime){
                var dt = (Date.now() - quyetnd.sys.lastRunningTime) / 1000.0;
                cc.log("game_on_show: " + dt);
                var frame_time = 1.0 / 60.0;
                while(dt > 0){
                    if(dt > frame_time){
                        cc.director.getScheduler().update(frame_time);
                    }
                    else{
                        cc.director.getScheduler().update(dt);
                    }
                    dt -= frame_time;
                }
            }
        }
    });

    // cc.eventManager.addListener(_listener1, 1);
    // cc.eventManager.addListener(_listener2, 1);
};


cc.game.onStart = function(){
    if(!cc.sys.isNative && document.getElementById("cocosLoading")) //If referenced loading.js, please remove it
        document.body.removeChild(document.getElementById("cocosLoading"));

 //   cc.view.enableAutoFullScreen(false);

    // Pass true to enable retina display, on Android disabled by default to improve performance

    cc.view.enableRetina(cc.sys.os === cc.sys.OS_IOS ? true : false);
    // Adjust viewport meta
    cc.view.adjustViewPort(true);

    // Setup the resolution policy and design resolution size;
   // cc.view.setFrameSize(cc.size(400,400));
  //  cc.view.setRealPixelResolution(1280,720,cc.ResolutionPolicy.SHOW_ALL);
    var frameSize = cc.view.getFrameSize();
    var designHeight = 720.0;
    var designWidth = 1280.0;//frameSize.width * designHeight / frameSize.height;
    if (designWidth < 960.0) {
        designWidth = 960.0;
    }
    if (designWidth > 1280.0) {
        designWidth = 1280.0;
    }

    // Setup the resolution policy and design resolution size
    var policy = new cc.ResolutionPolicy(cc.ContainerStrategy.PROPORTION_TO_FRAME, cc.ContentStrategy.SHOW_ALL);
    cc.view.setDesignResolutionSize(designWidth, designHeight, policy);

    cc.winSize.screenScale = designWidth / 1280.0;
    // Instead of set design resolution, you can also set the real pixel resolution size
    // Uncomment the following line and delete the previous line.
    // cc.view.setRealPixelResolution(960, 640, cc.ResolutionPolicy.SHOW_ALL);
    // The game will be resized when browser size change
    cc.view.resizeWithBrowserSize(true);


    //load resources
    // cc.LoaderScene.preload(g_resources, function () {
    //     cc.director.runScene(new HelloWorldScene());
    // }, this);
    _resumeMethod();
    cc.director.runScene(new LoadingScene());
};
cc.game.run();