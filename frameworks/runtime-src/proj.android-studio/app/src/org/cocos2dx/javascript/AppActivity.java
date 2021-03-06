/****************************************************************************
Copyright (c) 2015 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.javascript;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.content.Intent;
import android.os.Bundle;
import android.view.WindowManager;
import quyetnd.plugin.facebook.FacebookPlugin;
import vn.quyetnguyen.android.billing.AndroidBilling;
import vn.quyetnguyen.plugin.system.ExtensionLoader;
import vn.quyetnguyen.plugin.system.SystemPlugin;
import vn.quyetnguyen.plugin.system.UUDIPlugin;

public class AppActivity extends Cocos2dxActivity {
	
    @Override
    public Cocos2dxGLSurfaceView onCreateView() {
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
        // TestCpp should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

        return glSurfaceView;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        this.getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        SystemPlugin.getInstance().init(this);
        UUDIPlugin.getInstance().initWithActivity(this);
        FacebookPlugin.getInstance().init(this, Cocos2dxGLSurfaceView.getInstance());
        AndroidBilling.getInstance().initBilling(this, Cocos2dxGLSurfaceView.getInstance(), PluginConfig.IAP_base64PublicKey);
        ExtensionLoader.getInstance().init(this, Cocos2dxGLSurfaceView.getInstance());
    }

    @Override
    protected void onStart() {
        super.onStart();
        FacebookPlugin.getInstance().onStart();
        ExtensionLoader.getInstance().onStart();
    }

    @Override
    protected void onPostCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onPostCreate(savedInstanceState);
        ExtensionLoader.getInstance().onPostCreate(savedInstanceState);
    }

    @Override
    protected void onPostResume() {
        // TODO Auto-generated method stub
        super.onPostResume();
        ExtensionLoader.getInstance().onPostResume();
    }

    @Override
    protected void onRestart() {
        // TODO Auto-generated method stub
        super.onRestart();
        ExtensionLoader.getInstance().onRestart();
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onRestoreInstanceState(savedInstanceState);
        ExtensionLoader.getInstance().onRestoreInstanceState(savedInstanceState);
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        // TODO Auto-generated method stub
        super.onSaveInstanceState(outState);
        ExtensionLoader.getInstance().onSaveInstanceState(outState);
    }

    @Override
    protected void onPause() {
        super.onPause();
        ExtensionLoader.getInstance().onPause();
        FacebookPlugin.getInstance().onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        ExtensionLoader.getInstance().onPause();
        FacebookPlugin.getInstance().onResume();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(!AndroidBilling.getInstance().onActivityResult(requestCode, resultCode, data)){
            super.onActivityResult(requestCode, resultCode, data);
            FacebookPlugin.getInstance().onActivityResult(requestCode, resultCode, data);
        }
        ExtensionLoader.getInstance().onActivityResult(requestCode, resultCode, data);
        SystemPlugin.getInstance().onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onDestroy() {
        FacebookPlugin.getInstance().onDestroy();
        AndroidBilling.getInstance().onDestroy();
        ExtensionLoader.getInstance().onDestroy();
        super.onDestroy();
    }

    @Override
    protected void onStop() {
        FacebookPlugin.getInstance().onStop();
        ExtensionLoader.getInstance().onStop();
        super.onStop();
    }
}
