if (self.CavalryLogger) { CavalryLogger.start_js(["SXFBI"]); }

__d("PresenceViewerCapabilities",["ArbiterMixin","Bootloader","CurrentUser","PresenceConfig","debounceAcrossTransitions"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g=null,h=Object.assign({},b("ArbiterMixin")),i=b("debounceAcrossTransitions")(function(){return h.inform("viewerChange")},0);function j(a){try{a=JSON.parse(a.payload);a.capabilityBitMask!==g&&i();a.capabilityBitMask!=null&&(g=a.capabilityBitMask)}catch(a){}}Object.assign(h,{get:function(){if(g!=null)return g;b("Bootloader").loadModules(["SkywalkerManager"],function(a){return a.subscribe("presence/fb/"+b("CurrentUser").getID(),j)},"PresenceViewerCapabilities");g=b("PresenceConfig").get("viewer_presence_capabilities");return g}});e.exports=h}),null);
__d("WorkplaceChatHelper",["ChannelConstants","CurrentUser","PresenceViewerCapabilities"],(function(a,b,c,d,e,f){"use strict";a={isDesktopChatApp:function(){return window.workchat!==void 0},getAppID:function(){return window.workchat.appId},showWindow:function(){window.workchat.showWindow()},getScreenSharingSourceID:function(){return window.workchat.getScreenSharingSourceID()},stopScreenSharing:function(){return window.workchat.stopScreenSharing()},suppressChatIfActiveOnDesktop:function(){return b("CurrentUser").isWorkUser()&&(b("PresenceViewerCapabilities").get()&b("ChannelConstants").CAPABILITY_ACTIVE_ON_DESKTOP_APP)==b("ChannelConstants").CAPABILITY_ACTIVE_ON_DESKTOP_APP}};e.exports=a}),null);
__d("ChatOpenTab",["csx","Bootloader","ContextualThing","CurrentUser","Event","MercuryIDs","MercuryParticipantTypes","Parent","WorkGalahadSettings","WorkplaceChatHelper","gkx","requireWeak"],(function(a,b,c,d,e,f,g){"use strict";__p&&__p();var h=null;b("requireWeak")("FantaTabsReactApp",function(a){return h=a});b("requireWeak")("FantaTabsSlimApp",function(a){return h=a});function i(a,c,d,e){b("Event").listen(a,"click",function(f){(b("WorkGalahadSettings").isGalahadEnabled||l.canOpenTab()||b("CurrentUser").isWorkUser()&&b("WorkplaceChatHelper").suppressChatIfActiveOnDesktop()&&b("gkx")("678256"))&&(e(c,d),a.removeAttribute("ajaxify"),a.removeAttribute("rel"),f.preventDefault())})}function j(a,c,d,e){b("Event").listen(a,"click",function(a){l.canOpenTab()&&e(c,d)})}function k(a){a=b("ContextualThing").getContext(a);return a&&b("Parent").bySelector(a,"._3qw")!==null}var l={canOpenTab:function(){return h&&!h.isHidden()},listenOpenEmptyTabDEPRECATED:function(a,b){i(a,null,b,this._loadAndOpenEmptyFantaTab)},listenOpenThreadDEPRECATED:function(a,b,c){i(a,b,c,function(a,b){return this.loadAndOpenFantaTab(a,b,c)}.bind(this))},listenOpenUserTabDEPRECATED:function(a,c,d){k(a)||i(a,c,d,function(a){return this.loadAndOpenFantaTab(a,b("MercuryParticipantTypes").USER,d)}.bind(this))},listenOpenUserTabPersistentEventDEPRECATED:function(a,c,d){k(a)||j(a,c,d,function(a){return this.loadAndOpenFantaTab(a,b("MercuryParticipantTypes").USER,d)}.bind(this))},listenOpenPageTabDEPRECATED:function(a,c,d,e){k(a)||i(a,c,e,function(a){return this.loadAndOpenFantaTab(a,b("MercuryParticipantTypes").PAGE,e)}.bind(this))},listenOpenPageTabPersistentEventDEPRECATED:function(a,c,d,e){k(a)||j(a,c,e,function(a){return this.loadAndOpenFantaTab(a,b("MercuryParticipantTypes").PAGE,e)}.bind(this))},loadAndOpenFantaTab:function(a,c,d){b("Bootloader").loadModules(["ChatOpenTabEventLogger","FantaTabActions"],function(e,f){if(c===b("MercuryParticipantTypes").USER||c===b("MercuryParticipantTypes").PAGE){var g=b("MercuryIDs").getThreadIDFromUserID(a);f.openTab(g,[d]);e.logUserClickOpen(d,a)}else f.openTab(a,[d]),e.logClickOpen(d,a)},"ChatOpenTab")},_loadAndOpenEmptyFantaTab:function(){b("Bootloader").loadModules(["ChatOpenTabEventLogger","FantaTabActions","MessengerState.bs"],function(a,c,d){d=d.createNewLocalThreadGenerateID(b("CurrentUser").getID());c.openNewMessageTab(d,"jewel_new_message");a.logClickOpen("EmptyTab")},"ChatOpenTab")}};e.exports=l}),null);
__d("HovercardLink",["URI"],(function(a,b,c,d,e,f){__p&&__p();var g={getBaseURI:function(){return new(b("URI"))("/ajax/hovercard/hovercard.php")},constructEndpoint:function(a,b){return g.constructEndpointWithGroupAndLocation(a,b,null)},constructEndpointWithLocation:function(a,b){return g.constructEndpointWithGroupAndLocation(a,null,b)},constructEndpointWithGroupAndLocation:function(a,b,c,d){return g.constructEndpointWithGroupLocationAndExtraParams(a,b,c,d)},constructEndpointWithGroupLocationAndExtraParams:function(a,c,d,e,f){__p&&__p();f===void 0&&(f=null);var h=new(b("URI"))(g.getBaseURI()).setQueryData({id:a.id}),i={};if(f!==null)for(var j in f)i[j]=f[j];(a.weakreference||e)&&c&&(i.group_id=c);d&&(i.hc_location=d);c&&(i.directed_target_id=c);h.addQueryData({extragetparams:JSON.stringify(i)});return h}};e.exports=g}),null);
__d("Dock",["csx","Arbiter","ArbiterMixin","BlueBar","ChatQuietLinks","CSS","DataStore","DOM","Event","Parent","Scroll","Style","Toggler","Vector","emptyFunction","isKeyActivation","shield"],(function(a,b,c,d,e,f,g){__p&&__p();function c(){}Object.assign(c,b("ArbiterMixin"),{MIN_HEIGHT:140,INITIAL_FLYOUT_HEIGHT_OFFSET:10,init:function(a){__p&&__p();this.init=b("emptyFunction");this.rootEl=a;this.calculateViewportDimensions();b("ChatQuietLinks").removeEmptyHrefs(this.rootEl);b("Event").listen(a,"click",this._onClick.bind(this));var c=a.querySelector(".fbNubButton");c&&b("Event").listen(c,"keypress",this._onKeyPress.bind(this));b("Event").listen(window,"resize",this._onWindowResize.bind(this));b("Toggler").subscribe(["show","hide"],function(c,d){d=d.getActive();if(!b("DOM").contains(a,d))return;if(b("CSS").hasClass(d,"fbNub"))this.notifyNub(d,c),c==="show"&&this._resizeNubFlyout(d);else{d=b("Parent").byClass(d,"fbNubFlyout");d&&b("CSS").conditionClass(d,"menuOpened",c==="show")}}.bind(this));this.inform("init",{},"persistent")},calculateViewportDimensions:function(){return this.viewportDimensions=b("Vector").getViewportDimensions()},getFlyoutHeightOffset:function(){if(this.flyoutHeightOffset)return this.flyoutHeightOffset;this.flyoutHeightOffset=this.INITIAL_FLYOUT_HEIGHT_OFFSET+b("Vector").getElementDimensions(this.rootEl).y;var a=b("BlueBar").getBar();if(a){var c=b("Style").isFixed(a)?"viewport":"document";this.flyoutHeightOffset+=b("Vector").getElementPosition(a,c).y+b("Vector").getElementDimensions(a).y}return this.flyoutHeightOffset},toggle:function(a){var c=this._findFlyout(a);if(!c)return;this.subscribe("init",function(){b("Toggler").toggle(a)})},show:function(a){this.subscribe("init",function(){b("Toggler").show(a)})},showNub:function(a){b("CSS").show(a)},hide:function(a){this.subscribe("init",function(){var c=b("Toggler").getInstance(a);b("DOM").contains(a,c.getActive())&&c.hide()})},hideNub:function(a){b("CSS").hide(a),this.hide(a)},setUseMaxHeight:function(a,c){b("CSS").conditionClass(a,"maxHeight",c!==!1),this._resizeNubFlyout(a)},_resizeNubFlyout:function(a){__p&&__p();var c=this._findFlyout(a);if(!c||b("CSS").hasClass(a,"placeholder")||!(b("CSS").hasClass(a,"openToggler")||b("CSS").hasClass(a,"opened")))return;var d=b("DOM").find(c,"div.fbNubFlyoutOuter"),e=b("DOM").find(d,"div.fbNubFlyoutInner"),f=b("DOM").find(e,"div.fbNubFlyoutBody"),g=b("CSS").hasClass(a,"canBeCompactTab"),h=b("Scroll").getTop(f),i=f.offsetHeight;b("Style").set(f,"height","auto");var j=b("Vector").getElementDimensions(c),k=b("Vector").getElementDimensions(f),l=this.getMaxFlyoutHeight(a);b("Style").set(c,"max-height",l+"px");b("Style").set(d,"max-height",l+"px");j=b("Vector").getElementDimensions(c);d=b("Vector").getElementDimensions(e);l=d.y-k.y;e=j.y-l;d=parseInt(f.style.height||f.clientHeight,10);d=e!==d;j.y>l&&d&&!g&&b("Style").set(f,"height",e+"px");b("CSS").removeClass(c,"swapDirection");var m=b("Vector").getElementPosition(c).x;b("CSS").conditionClass(c,"swapDirection",function(){if(m<0)return!0;return!j||!this.viewportDimensions?!1:m+j.x>this.viewportDimensions.x}.bind(this)());d&&h+i>=k.y?b("Scroll").setTop(f,f.scrollHeight):b("Scroll").setTop(f,h);this.notifyNub(a,"resize")},getMaxFlyoutHeight:function(a){a=this._findFlyout(a);var c=b("Vector").getElementPosition(a,"viewport");a=b("Vector").getElementDimensions(a);if(!this.viewportDimensions||!c)return 0;c=Math.max(this.MIN_HEIGHT,this.viewportDimensions.y-this.getFlyoutHeightOffset())-(this.viewportDimensions.y-c.y-a.y);return Math.max(c,0)},resizeAllFlyouts:function(){var a=this._getAllNubs(),b=a.length;while(b--)this._resizeNubFlyout(a[b])},_getAllNubs:function(){if(!this.rootEl)return[];var a=b("DOM").scry(this.rootEl,"div._50-v.openToggler:not(._s0f)");return a.concat(b("DOM").scry(this.rootEl,"div._50-v.opened:not(._s0f)"))},_onKeyPress:function(a){var c=a.getTarget();c=b("Parent").byClass(c,"fbNub");b("isKeyActivation")(a)&&c&&this.toggle(c)},_onClick:function(a){__p&&__p();a=a.getTarget();var c=b("Parent").byClass(a,"fbNub");if(c){if(b("Parent").byClass(a,"fbNubFlyoutTitlebar")){var d=b("Parent").byTag(a,"a");a=a.nodeName=="INPUT"&&a.getAttribute("type")=="submit";if(!d&&!a){this.hide(c);return!1}}this.notifyNub(c,"click")}},_onWindowResize:function(a){this.calculateViewportDimensions(),this.resizeAllFlyouts()},_findFlyout:function(a){return b("CSS").hasClass(a,"fbNubFlyout")?a:b("DOM").scry(a,"div.fbNubFlyout")[0]||null},registerNubController:function(a,c){b("DataStore").set(a,"dock:nub:controller",c),c.subscribe("nub/button/content-changed",b("shield")(this.inform,this,"resize",a)),c.subscribe("nub/flyout/content-changed",b("shield")(this._resizeNubFlyout,this,a))},unregisterNubController:function(a){b("DataStore").remove(a,"dock:nub:controller")},notifyNub:function(a,c,d){a=b("DataStore").get(a,"dock:nub:controller");a&&a.inform(c,d)}});e.exports=a.Dock||c}),null);
__d("MercuryTypingAnimation_DEPRECATED.react",["cx","React","joinClasses"],(function(a,b,c,d,e,f,g){"use strict";var h;h=babelHelpers.inherits(a,b("React").PureComponent);h&&h.prototype;a.prototype.render=function(){return b("React").createElement("div",{className:b("joinClasses")("_4a0v _1x3z",this.props.className)},b("React").createElement("div",{className:"_4b0g"},b("React").createElement("div",{className:"_5pd7"}),b("React").createElement("div",{className:"_5pd7"}),b("React").createElement("div",{className:"_5pd7"})))};function a(){h.apply(this,arguments)}e.exports=a}),null);
__d("MessengerMQTTGating",["gkx"],(function(a,b,c,d,e,f){"use strict";var g={_forcedOff:!1,isEnabled:function(){return b("gkx")("678651")&&!g._forcedOff},turnOff:function(){g._forcedOff=!0}};e.exports=g}),null);
__d("DocumentTitle",["Arbiter"],(function(a,b,c,d,e,f){__p&&__p();var g=1500,h=null,i=!1,j=0,k=[],l=null,m=document.title;function n(){k.length>0?!i?(o(k[j].title),j=++j%k.length):p():(clearInterval(h),h=null,p())}function o(a){document.title=a,i=!0}function p(){q.set(l||m,!0),i=!1}function q(a){"use strict";this.$1=a}q.get=function(){"use strict";return m};q.set=function(a,c){"use strict";var d=a.toString();document.title=d;!c?(m=d,l=null,b("Arbiter").inform("update_title",a)):l=d};q.blink=function(a){"use strict";a={title:a.toString()};k.push(a);h===null&&(h=setInterval(n,g));return new q(a)};q.prototype.stop=function(){"use strict";var a=k.indexOf(this.$1);a>=0&&(k.splice(a,1),j>a?j--:j==a&&j==k.length&&(j=0))};q.badge=function(a){"use strict";var b=q.get();a=a?"("+a+") "+b:b;q.set(a,!0)};e.exports=q}),null);
__d("SystemEvents",["ArbiterMixin","Cookie","ErrorGuard","ErrorUtils","SystemEventsInitialData","TimeSlice","UserActivity","UserAgent_DEPRECATED","gkx","mixin","setIntervalAcrossTransitions","setTimeoutAcrossTransitions"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g,h=1e3;c=babelHelpers.inherits(a,b("mixin")(b("ArbiterMixin")));g=c&&c.prototype;function a(){g.constructor.call(this),this.$SystemEvents12=function(){var a=this.$SystemEvents7();this.$SystemEvents2!=a&&(this.$SystemEvents2=a,this.inform(this.USER,a));this.$SystemEvents13()}.bind(this),this.USER="SystemEvents/USER",this.ONLINE="SystemEvents/ONLINE",this.TIME_TRAVEL="SystemEvents/TIME_TRAVEL",this.$SystemEvents1=b("SystemEventsInitialData").ORIGINAL_USER_ID,this.$SystemEvents2=this.$SystemEvents1,this.$SystemEvents3=navigator.onLine,this.$SystemEvents4=Date.now(),this.$SystemEvents6()}a.prototype.isPageOwner=function(a){return(a||this.$SystemEvents7())==this.$SystemEvents1};a.prototype.isOnline=function(){return!!(b("UserAgent_DEPRECATED").chrome()||this.$SystemEvents3)};a.prototype.checkTimeTravel=function(){var a=Date.now(),b=a-this.$SystemEvents4;this.$SystemEvents4=a;(b<0||b>1e4)&&this.inform(this.TIME_TRAVEL,b)};a.prototype.$SystemEvents6=function(){this.$SystemEvents8(),this.$SystemEvents9(),this.$SystemEvents10(),this.$SystemEvents11()};a.prototype.$SystemEvents8=function(){var a=b("TimeSlice").guard(function(){this.$SystemEvents3||(this.$SystemEvents3=!0,this.inform(this.ONLINE,this.$SystemEvents3))}.bind(this),"SystemEvents onOnline"),c=b("TimeSlice").guard(function(){this.$SystemEvents3&&(this.$SystemEvents3=!1,this.inform(this.ONLINE,this.$SystemEvents3))}.bind(this),"SystemEvents onOffline");b("UserAgent_DEPRECATED").ie()?b("UserAgent_DEPRECATED").ie()>=11?(window.addEventListener("online",a,!1),window.addEventListener("offline",c,!1)):b("UserAgent_DEPRECATED").ie()>=8?window.attachEvent("onload",function(){document.body.ononline=a,document.body.onoffline=c}):b("setIntervalAcrossTransitions")(function(){(navigator.onLine?a:c)()},h):window.addEventListener&&(window.addEventListener("online",a,!1),window.addEventListener("offline",c,!1))};a.prototype.$SystemEvents13=function(){clearTimeout(this.$SystemEvents5),this.$SystemEvents5=b("setTimeoutAcrossTransitions")(this.$SystemEvents12,h)};a.prototype.$SystemEvents9=function(){if(self!==top&&b("gkx")("678677"))return;b("gkx")("678678")&&b("UserActivity").subscribe(function(){this.$SystemEvents13()}.bind(this));this.$SystemEvents13()};a.prototype.$SystemEvents10=function(){b("setIntervalAcrossTransitions")(this.checkTimeTravel.bind(this),h)};a.prototype.$SystemEvents11=function(){b("setIntervalAcrossTransitions")(function(){window.onerror!=b("ErrorUtils").onerror&&window.onerror!=b("ErrorGuard").onerror&&(window.onerror=b("ErrorUtils").onerror)},h)};a.prototype.$SystemEvents7=function(){return b("Cookie").get("c_user")||"0"};e.exports=new a()}),3);
__d("ContextualLayerUpdateOnScroll",["Event"],(function(a,b,c,d,e,f){__p&&__p();function a(a){"use strict";this._layer=a}a.prototype.enable=function(){"use strict";this._subscriptions=[this._layer.subscribe("show",this._attachScrollListener.bind(this)),this._layer.subscribe("hide",this._removeScrollListener.bind(this))]};a.prototype.disable=function(){"use strict";while(this._subscriptions.length)this._subscriptions.pop().unsubscribe()};a.prototype._attachScrollListener=function(){"use strict";if(this._listener)return;var a=this._layer.getContextScrollParent();this._listener=b("Event").listen(a,"scroll",this._layer.updatePosition.bind(this._layer))};a.prototype._removeScrollListener=function(){"use strict";this._listener&&this._listener.remove(),this._listener=null};Object.assign(a.prototype,{_subscriptions:[]});e.exports=a}),null);
__d("FantailLogger",["FantailConfig"],(function(a,b,c,d,e,f){__p&&__p();var g=b("FantailConfig").FantailLogQueue;a={debug:function(a,b){var c;for(var d=arguments.length,e=new Array(d>2?d-2:0),f=2;f<d;f++)e[f-2]=arguments[f];g&&(c=g.get(a)).debug.apply(c,[b].concat(e))},info:function(a,b){var c;for(var d=arguments.length,e=new Array(d>2?d-2:0),f=2;f<d;f++)e[f-2]=arguments[f];g&&(c=g.get(a)).info.apply(c,[b].concat(e))},warn:function(a,b){var c;for(var d=arguments.length,e=new Array(d>2?d-2:0),f=2;f<d;f++)e[f-2]=arguments[f];g&&(c=g.get(a)).warn.apply(c,[b].concat(e))},error:function(a,b){var c;for(var d=arguments.length,e=new Array(d>2?d-2:0),f=2;f<d;f++)e[f-2]=arguments[f];g&&(c=g.get(a)).error.apply(c,[b].concat(e))}};e.exports=a}),null);
__d("codedError",["fbt","invariant"],(function(a,b,c,d,e,f,g,h){"use strict";__p&&__p();function a(a){h(0,2095)}a.withParams=function(a,b){h(0,2095)};a._=function(a,b,c,d){b=b(g);c=c(g,d);d=b+": "+c;d=new Error(d);Object.assign(d,{framesToPop:1,code:a,description:c,summary:b});return d};e.exports=a}),null);
__d("Log",[],(function(a,b,c,d,e,f){"use strict";__p&&__p();a={DEBUG:3,INFO:2,WARNING:1,ERROR:0};b=function(a,b,c){for(var d=arguments.length,e=new Array(d>3?d-3:0),f=3;f<d;f++)e[f-3]=arguments[f];var h=0,i=c.replace(/%s/g,function(){return String(e[h++])}),j=window.console;j&&g.level>=b&&j[a in j?a:"log"](i)};var g={level:-1,Level:a,debug:b.bind(null,"debug",a.DEBUG),info:b.bind(null,"info",a.INFO),warn:b.bind(null,"warn",a.WARNING),error:b.bind(null,"error",a.ERROR),log:b};e.exports=g}),null);
__d("PerfXSharedFields",[],(function(a,b,c,d,e,f){var g={addCommonValues:function(a){navigator&&navigator.hardwareConcurrency!==void 0&&(a.num_cores=navigator.hardwareConcurrency);navigator&&navigator.deviceMemory&&(a.ram_gb=navigator.deviceMemory);navigator&&navigator.connection&&(typeof navigator.connection.downlink==="number"&&(a.downlink_megabits=navigator.connection.downlink),typeof navigator.connection.effectiveType==="string"&&(a.effective_connection_type=navigator.connection.effectiveType),typeof navigator.connection.rtt==="number"&&(a.rtt_ms=navigator.connection.rtt));return a},getCommonData:function(){var a={};g.addCommonValues(a);return a}};e.exports=g}),null);
__d("QuickLogConfigHelper",["QuickLogConfig"],(function(a,b,c,d,e,f){a.prototype.getEventDetails=function(a){"use strict";var c=null;b("QuickLogConfig").qpl_events?c=b("QuickLogConfig").qpl_events[a]:b("QuickLogConfig").qpl_events_static&&(c=b("QuickLogConfig").qpl_events_static[a]);return c};function a(){"use strict"}e.exports=new a()}),null);
__d("QuickPerformanceLogger",["requireCond","cr:684019"],(function(a,b,c,d,e,f){"use strict";e.exports=b("cr:684019")}),null);
__d("QuickPerformanceLoggerBase",["Arbiter","Banzai","Bootloader","Env","PerfXSharedFields","QuickLogConfig","QuickLogConfigHelper","Random","gkx","performanceAbsoluteNow","performanceNavigationStart","requireCond","cr:682175"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g=b("performanceAbsoluteNow")();function a(a){a===void 0&&(a={}),this.$1={},this.$2={},this.$3=100,this.loomProviderId="QPL",this.$4=a,b("cr:682175")&&b("cr:682175").addProvider(this)}a.prototype.$7=function(a,c){if(b("QuickLogConfig").killswitch)return null;a=this.$1[a];if(!a)return null;a=a[c];return!a?null:a};a.prototype.markerStart=function(a,c,d){__p&&__p();c===void 0&&(c=0);d===void 0&&(d=this.currentTimestamp());if(b("QuickLogConfig").killswitch)return;var e=b("QuickLogConfigHelper").getEventDetails(a);if(!e)return;if(b("cr:682175")&&!this.$5){var f=a+"_"+c,g=new Set(["QPL","AsyncProfiler"]);b("cr:682175").startTrace(f,"QPL",g)}this.$5&&this.$5.buffer.addEvent({type:"QPL_START",action:"START",markerId:a,instanceKey:c},d);f=this.$6===a?1:this.$2[a]||e.sampleRate||this.$3;g=b("Env").enable_qplinspector||b("Random").coinflip(f);e=this.$1[a];e||(this.$1[a]={});this.$1[a][c]={passesSampling:g,timestamp:d,sampleRate:f,points:{}};if(g){e=this.$4.onMarkerStart;e&&e(a,c,d)}};a.prototype.markerStartFromNavStart=function(a,c){c===void 0&&(c=0);var d=b("performanceNavigationStart")();this.markerStart(a,c,d);if(b("performanceNavigationStart").isPolyfilled){d=this.$7(a,c);d&&(d.timestampIsApproximate=!0)}};a.prototype.annotateMarkerString=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotations||{};f[b]=c;e.annotations=f};a.prototype.annotateMarkerStringArray=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotationsStringArray||{};f[b]=c;e.annotationsStringArray=f};a.prototype.annotateMarkerInt=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotationsInt||{};f[b]=c;e.annotationsInt=f};a.prototype.annotateMarkerIntArray=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotationsIntArray||{};f[b]=c;e.annotationsIntArray=f};a.prototype.annotateMarkerDouble=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotationsDouble||{};f[b]=c;e.annotationsDouble=f};a.prototype.annotateMarkerDoubleArray=function(a,b,c,d){d===void 0&&(d=0);var e=this.$7(a,d);if(!e)return;var f=this.$5;f&&f.buffer.addEvent({type:"QPL_ANNOTATION",markerId:a,instanceKey:d,annotationKey:b,annotationValue:c},e.timestamp);f=e.annotationsDoubleArray||{};f[b]=c;e.annotationsDoubleArray=f};a.prototype.markerPoint=function(a,b,c,d,e){d===void 0&&(d=0);e===void 0&&(e=this.currentTimestamp());var f=this.$7(a,d);if(!f)return;f.points[b]={data:c,timeSinceStart:e-f.timestamp};f=this.$5;f&&f.buffer.addEvent({type:"QPL_POINT",markerId:a,instanceKey:d,name:b,data:c},e)};a.prototype.markerEnd=function(a,c,d,e){__p&&__p();d===void 0&&(d=0);e===void 0&&(e=this.currentTimestamp());var f=Date.now(),h=b("QuickLogConfigHelper").getEventDetails(a);if(!h)return;var i=this.$5;if(i){i.buffer.addEvent({type:"QPL_END",action:c,markerId:a,instanceKey:d},e);var j=a+"_"+d;b("cr:682175")&&i.triggerId===j&&b("cr:682175").endTraceWithTimeout(j,3e4)}i=this.$7(a,d);if(!i)return;if(i.passesSampling){j=this.$4.onMarkerEnd;j&&j(a,d,e);j=e-i.timestamp;f=f-j;var k=i.points;this.$8({event_is_intermediate_marker:"false",instance_id:d,quicklog_module:h.moduleName,quicklog_event:h.name,quicklog_action:c,sample_rate:i.sampleRate,trace_tags:"",value:i.timestampIsApproximate?null:j,annotations:i.annotations,annotations_double:i.annotationsDouble,annotations_double_array:i.annotationsDoubleArray,annotations_int:i.annotationsInt,annotations_int_array:i.annotationsIntArray,annotations_string_array:i.annotationsStringArray,points:Object.keys(k).map(function(a){return{data:k[a].data,name:a,timeSinceStart:k[a].timeSinceStart}}),metadata:{application_analytics:{time_since_qpl_module_init:e-g}}},f);this.$6===a&&(console.timeStamp("QPLDebug MarkerEnd, "+this.currentTimestamp()+", "+f+", "+j),b("Arbiter").inform("qpl_debugger_finished"))}delete this.$1[a][d]};a.prototype.markerDrop=function(a,b){b===void 0&&(b=0);a=this.$1[a];a&&delete a[b]};a.prototype.dropAllMarkers=function(){this.$1={}};a.prototype.setAlwaysOnSampleRate=function(a,b){this.$2[a]=b};a.prototype.setSampleRateForInstance=function(a,b,c){c===void 0&&(c=0);a=this.$1[a][c];a&&(a.sampleRate=b)};a.prototype.currentTimestamp=function(){return b("performanceAbsoluteNow")()};a.prototype.$8=function(a,c){a=this.$9(a);var d=this.$10(a,c);b("Env").enable_qplinspector&&b("Bootloader").loadModules(["QPLInspector"],function(a){a.appendLog(d)},"QuickPerformanceLoggerBase");b("gkx")("708253")?b("Banzai").post("perf",d,b("Banzai").VITAL):b("Banzai").post("perf",d)};a.prototype.$9=function(a){var c=b("PerfXSharedFields").getCommonData();a.metadata=babelHelpers["extends"]({},a.metadata,{memory_stats:{total_mem:c.ram_gb?c.ram_gb*1073741824:null},network_stats:{downlink_megabits:c.downlink_megabits,network_subtype:c.effective_connection_type,rtt_ms:c.rtt_ms}});return a};a.prototype.$10=function(a,b){b=Math.floor(b/1e3);return{appversion:"0 (web)",clienttime:b,rawclienttime:b,deviceid:"0",extra:a}};a.prototype.loomTraceDidBegin=function(a){this.$5=a};a.prototype.loomTraceWillEnd=function(){this.$5=null};a.prototype.enableDebug=function(a){this.$6=parseInt(a,10)};a.prototype.disableDebug=function(){this.$6=null};e.exports=a}),null);
__d("QuickPerformanceLoggerImpl",["EventProfiler","QuickLogConfig","QuickPerformanceLoggerBase"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g,h={},i={onMarkerStart:function(a,c,d){var e=b("QuickLogConfig").qpl_to_interaction[a];if(e){a=a+" : "+c;h[a]=b("EventProfiler").markManualStart([e.name],e.eventType,d)}},onMarkerEnd:function(a,b,c){a=a+" : "+b;h[a]&&h[a].markManualEnd(c)}};c=babelHelpers.inherits(a,b("QuickPerformanceLoggerBase"));g=c&&c.prototype;function a(){g.constructor.call(this,i)}e.exports=new a()}),null);
__d("getVendorPrefixedEventName",["fbjs/lib/ExecutionEnvironment"],(function(a,b,c,d,e,f){"use strict";__p&&__p();function a(a,b){var c={};c[a.toLowerCase()]=b.toLowerCase();c["Webkit"+a]="webkit"+b;c["Moz"+a]="moz"+b;c["ms"+a]="MS"+b;c["O"+a]="o"+b.toLowerCase();return c}var g={animationend:a("Animation","AnimationEnd"),animationiteration:a("Animation","AnimationIteration"),animationstart:a("Animation","AnimationStart"),transitionend:a("Transition","TransitionEnd")},h={},i={};b("fbjs/lib/ExecutionEnvironment").canUseDOM&&(i=document.createElement("div").style,"AnimationEvent"in window||(delete g.animationend.animation,delete g.animationiteration.animation,delete g.animationstart.animation),"TransitionEvent"in window||delete g.transitionend.transition);function c(a){if(h[a])return h[a];else if(!g[a])return a;var b=g[a];for(var c in b)if(Object.prototype.hasOwnProperty.call(b,c)&&c in i)return h[a]=b[c];return""}e.exports=c}),null);