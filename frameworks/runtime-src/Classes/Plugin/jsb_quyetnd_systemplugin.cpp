#include "jsb_quyetnd_systemplugin.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "SystemPlugin.h"

JSClass  *jsb_quyetnd_systemplugin_class;
JSObject *jsb_quyetnd_systemplugin_prototype;
JSObject *jsb_quyetnd_systemplugin_ns_object;
JSObject *jsb_quyetnd_systemplugin_target;

bool jsb_quyetnd_systemplugin_setJSTarget(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		jsb_quyetnd_systemplugin_target = args.get(0).toObjectOrNull(); 
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_getVersionName(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		auto versionName = quyetnd::SystemPlugin::getInstance()->getVersionName();
		args.rval().set(std_string_to_jsval(cx, versionName));
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_downloadFile(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 2){
		std::string url;
		std::string path;
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);

		bool ok = jsval_to_std_string(cx, args[0], &url);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_downloadFile : Error processing arguments");

		ok = jsval_to_std_string(cx, args[1], &path);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_downloadFile : Error processing arguments");

		quyetnd::SystemPlugin::getInstance()->downloadFileAsync(url, path);
		args.rval().setUndefined();
		return true;
	}
	else if (argc == 3){
		std::string url;
		std::string path;
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);

		bool ok = jsval_to_std_string(cx, args[0], &url);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_downloadFile : Error processing arguments");

		ok = jsval_to_std_string(cx, args[1], &path);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_downloadFile : Error processing arguments");

		std::function<void(int)> arg3 = nullptr;
		if (JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION){
			JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
			std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(2), args.thisv()));
			auto lambda = [=](int returnCode) -> void {
				JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
				jsval largv[1];
				largv[0] = INT_TO_JSVAL(returnCode);
				JS::RootedValue rval(cx);
				bool succeed = func->invoke(1, &largv[0], &rval);
				if (!succeed && JS_IsExceptionPending(cx)) {
					JS_ReportPendingException(cx);
				}
			};
			arg3 = lambda;
		}

		quyetnd::SystemPlugin::getInstance()->downloadFileAsync(url, path, arg3);
		args.rval().setUndefined();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_androidRequestPermission(JSContext *cx, uint32_t argc, jsval *vp){
  	if (argc == 2){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::vector<std::string> permission;
		int requestCode;

		bool ok = true;
		ok = jsval_to_std_vector_string(cx, args.get(0), &permission);
		ok = jsval_to_int(cx, args.get(1), &requestCode);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_androidRequestPermission : Error processing arguments");
		if (ok){
			quyetnd::SystemPlugin::getInstance()->androidRequestPermission(permission, requestCode);
		}
		args.rval().setUndefined();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_androiCheckPermission(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::string permission;
		bool ok = true;
		ok = jsval_to_std_string(cx, args.get(0), &permission);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_androiCheckPermission : Error processing arguments");
		if (ok){
			bool pret = quyetnd::SystemPlugin::getInstance()->androidCheckPermission(permission);
			args.rval().setBoolean(pret);
		}
		else{
			args.rval().setBoolean(false);
		}
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_md5(JSContext *cx, uint32_t argc, jsval *vp){
	/*if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::string permission;
		bool ok = true;
		ok = jsval_to_std_string(cx, args.get(0), &permission);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_androiCheckPermission : Error processing arguments");
		if (ok){
			bool pret = quyetnd::SystemPlugin::getInstance()->androidCheckPermission(permission);
			args.rval().setBoolean(pret);
		}
		else{
			args.rval().setBoolean(false);
		}
		return true;
	}
	return false;*/
	return false;
}

bool jsb_quyetnd_systemplugin_sha1(JSContext *cx, uint32_t argc, jsval *vp){
	/*if (argc == 1){
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	std::string permission;
	bool ok = true;
	ok = jsval_to_std_string(cx, args.get(0), &permission);
	JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_androiCheckPermission : Error processing arguments");
	if (ok){
	bool pret = quyetnd::SystemPlugin::getInstance()->androidCheckPermission(permission);
	args.rval().setBoolean(pret);
	}
	else{
	args.rval().setBoolean(false);
	}
	return true;
	}
	return false;*/
	return false;
}

bool jsb_quyetnd_systemplugin_showCallPhone(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::string phoneNumber;
		bool ok = true;
		ok = jsval_to_std_string(cx, args.get(0), &phoneNumber);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_showCallPhone : Error processing arguments");
		if (ok){
			quyetnd::SystemPlugin::getInstance()->callSupport(phoneNumber);			
		}
		args.rval().setUndefined();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_checkFileValidate(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::string filename;
		bool ok = true;
		ok = jsval_to_std_string(cx, args.get(0), &filename);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_checkFileValidate : Error processing arguments");
		if (ok){
			bool ret = quyetnd::SystemPlugin::getInstance()->checkFileValidate(filename);
			args.rval().setBoolean(ret);
		}
		args.rval().setBoolean(false);
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_showSMS(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 2){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		bool ok = true;

		std::string smsNumber;	
		ok = jsval_to_std_string(cx, args.get(0), &smsNumber);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_showSMS : Error processing arguments");

		std::string smsContent;
		ok = jsval_to_std_string(cx, args.get(1), &smsContent);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_showSMS : Error processing arguments");

		if (ok){
			quyetnd::SystemPlugin::getInstance()->showSMS(smsNumber, smsContent);
		}
		args.rval().setUndefined();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_getSystemPushNotification(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		auto token = quyetnd::SystemPlugin::getInstance()->getSystemPushNotification();
		args.rval().set(std_string_to_jsval(cx, token));
		return true;
	}
	return false;
}



bool jsb_quyetnd_systemplugin_getCarrierName(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		auto carrier = quyetnd::SystemPlugin::getInstance()->getCarrierName();
		jsval ret = std_vector_string_to_jsval(cx, carrier);
		args.rval().set(ret);
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_enableMipmapTexture(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::string textureName;
		bool ok = true;
		ok = jsval_to_std_string(cx, args.get(0), &textureName);
		JSB_PRECONDITION2(ok, cx, false, "jsb_quyetnd_systemplugin_enableMipmapTexture : Error processing arguments");
		if (ok){
			quyetnd::SystemPlugin::getInstance()->enableMipmapTexture(textureName);
		}	
		args.rval().setUndefined();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_exitApp(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		quyetnd::SystemPlugin::getInstance()->exitApp();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_startLaucher(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		quyetnd::SystemPlugin::getInstance()->startLaucher();
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_getPackageName(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 0){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		auto packageName = quyetnd::SystemPlugin::getInstance()->getPackageName();
		args.rval().set(std_string_to_jsval(cx, packageName));
		return true;
	}
	
	return false;
}

bool jsb_quyetnd_systemplugin_buyIAPItem(JSContext *cx, uint32_t argc, jsval *vp){
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	auto packageName = quyetnd::SystemPlugin::getInstance()->getPackageName();
	args.rval().set(std_string_to_jsval(cx, packageName));
	if (argc == 1){
		std::string itemBundle;
		jsval_to_std_string(cx, args.get(0), &itemBundle);
		quyetnd::SystemPlugin::getInstance()->buyItem(itemBundle);
		return true;
	}
	return false;
}

bool jsb_quyetnd_systemplugin_getDeviceUUID(JSContext *cx, uint32_t argc, jsval *vp){
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	std::string deviceUUID = "";
	if (argc == 0){
		deviceUUID = quyetnd::SystemPlugin::getInstance()->getDeviceUUID();
	}
	else if(argc == 1){
		std::string key;
		jsval_to_std_string(cx, args.get(0), &key);
		deviceUUID = quyetnd::SystemPlugin::getInstance()->getDeviceUUID(key);
	}
	args.rval().set(std_string_to_jsval(cx, deviceUUID));
	return true;
}

bool jsb_quyetnd_systemplugin_IOS_InitStore(JSContext *cx, uint32_t argc, jsval *vp){
	if (argc == 1){
		JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
		std::vector<std::string> itemList;
		jsval_to_std_vector_string(cx, args.get(0), &itemList);
		quyetnd::SystemPlugin::getInstance()->initStore(itemList);
		return true;
	}
	return false;
}

void jsb_quyetnd_onBuyItemFinished_Android(int returnCode, const std::string& signature, const std::string& json){
	if (jsb_quyetnd_systemplugin_target){
		ScriptingCore* sc = ScriptingCore::getInstance();
		if (sc){
			jsval dataVal[] = {
				dataVal[0] = INT_TO_JSVAL(returnCode),
				dataVal[1] = std_string_to_jsval(sc->getGlobalContext(), signature),
				dataVal[2] = std_string_to_jsval(sc->getGlobalContext(), json)
			};
			sc->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsb_quyetnd_systemplugin_target), "onBuyItemFinishAndroid", 3, dataVal);
		}
	}
}

void jsb_quyetnd_onBuyItemFinished_iOS(int returnCode, const std::string& signature){
	if (jsb_quyetnd_systemplugin_target){
		ScriptingCore* sc = ScriptingCore::getInstance();
		if (sc){
			jsval dataVal[] = {
				dataVal[0] = INT_TO_JSVAL(returnCode),
				dataVal[1] = std_string_to_jsval(sc->getGlobalContext(), signature),
			};
			sc->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsb_quyetnd_systemplugin_target), "onBuyItemFinishIOS", 2, dataVal);
		}
	}
}

void jsb_quyetnd_onRegisterNotificationSuccess(const std::string& deviceId, const std::string& token){
	if (jsb_quyetnd_systemplugin_target){
		ScriptingCore* sc = ScriptingCore::getInstance();
		if (sc){
			jsval dataVal[] = {
				dataVal[0] = std_string_to_jsval(sc->getGlobalContext(), deviceId),
				dataVal[1] = std_string_to_jsval(sc->getGlobalContext(), token)
			};
			sc->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsb_quyetnd_systemplugin_target), "onRegisterNotificationSuccess", 2, dataVal);
		}
	}
}

bool js_quyetnd_systemplugin_constructor(JSContext *cx, uint32_t argc, jsval *vp){
	JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	JS::RootedObject parent(cx, jsb_quyetnd_systemplugin_ns_object);
	JS::RootedObject proto(cx, jsb_quyetnd_systemplugin_prototype);
	JS::RootedObject jsObj(cx, JS_NewObject(cx, jsb_quyetnd_systemplugin_class, proto, parent));
	args.rval().set(OBJECT_TO_JSVAL(jsObj));
	return true;
}

void js_quyetnd_systemplugin_finalize(JSFreeOp *fop, JSObject *obj){

}

void js_register_quyetnd_systemplugin(JSContext *cx, JS::HandleObject global) {
	jsb_quyetnd_systemplugin_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_quyetnd_systemplugin_class->name = "SystemPlugin";
	jsb_quyetnd_systemplugin_class->addProperty = JS_PropertyStub;
	jsb_quyetnd_systemplugin_class->delProperty = JS_DeletePropertyStub;
	jsb_quyetnd_systemplugin_class->getProperty = JS_PropertyStub;
    jsb_quyetnd_systemplugin_class->setProperty = JS_StrictPropertyStub;
    jsb_quyetnd_systemplugin_class->enumerate = JS_EnumerateStub;
    jsb_quyetnd_systemplugin_class->resolve = JS_ResolveStub;
    jsb_quyetnd_systemplugin_class->convert = JS_ConvertStub;
    jsb_quyetnd_systemplugin_class->finalize = js_quyetnd_systemplugin_finalize;
    jsb_quyetnd_systemplugin_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
		JS_FN("getVersionName", jsb_quyetnd_systemplugin_getVersionName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPackageName", jsb_quyetnd_systemplugin_getPackageName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDeviceUUID", jsb_quyetnd_systemplugin_getDeviceUUID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDeviceUUIDWithKey", jsb_quyetnd_systemplugin_getDeviceUUID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("buyIAPItem", jsb_quyetnd_systemplugin_buyIAPItem, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("iOSInitStore", jsb_quyetnd_systemplugin_IOS_InitStore, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTarget", jsb_quyetnd_systemplugin_setJSTarget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("enableMipmapTexture", jsb_quyetnd_systemplugin_enableMipmapTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("androidRequestPermission", jsb_quyetnd_systemplugin_androidRequestPermission, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("androidCheckPermission", jsb_quyetnd_systemplugin_androiCheckPermission, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("showCallPhone", jsb_quyetnd_systemplugin_showCallPhone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("exitApp", jsb_quyetnd_systemplugin_exitApp, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),	
		JS_FN("startLaucher", jsb_quyetnd_systemplugin_startLaucher, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("checkFileValidate", jsb_quyetnd_systemplugin_checkFileValidate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("showSMS", jsb_quyetnd_systemplugin_showSMS, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCarrierName", jsb_quyetnd_systemplugin_getCarrierName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPushNotificationToken", jsb_quyetnd_systemplugin_getSystemPushNotification, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("downloadFile", jsb_quyetnd_systemplugin_downloadFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };
	
    JSFunctionSpec *st_funcs = NULL;
    jsb_quyetnd_systemplugin_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_quyetnd_systemplugin_class,
		js_quyetnd_systemplugin_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
}

void register_all_quyetnd_systemplugin(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "quyetnd", &ns);
	jsb_quyetnd_systemplugin_ns_object = ns;
	js_register_quyetnd_systemplugin(cx, ns);
}

