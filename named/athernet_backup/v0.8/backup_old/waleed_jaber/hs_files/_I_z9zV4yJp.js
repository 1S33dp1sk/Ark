if (self.CavalryLogger) { CavalryLogger.start_js(["DzOuy"]); }

__d("rebound",["ExecutionEnvironment","setImmediate"],(function(a,b,c,d,e,f){__p&&__p();(function(){__p&&__p();var a={},c=a.util={},d=Array.prototype.concat,f=Array.prototype.slice;c.bind=function(a,b){var c=f.call(arguments,2);return function(){a.apply(b,d.call(c,f.call(arguments)))}};c.extend=function(a,b){for(var c in b)Object.prototype.hasOwnProperty.call(b,c)&&(a[c]=b[c])};var g=a.SpringSystem=function(a){this._springRegistry={},this._activeSprings=[],this.listeners=[],this._idleSpringIndices=[],this.looper=a||new k(),this.looper.springSystem=this};c.extend(g.prototype,{_springRegistry:null,_isIdle:!0,_lastTimeMillis:-1,_activeSprings:null,listeners:null,_idleSpringIndices:null,setLooper:function(a){this.looper=a,a.springSystem=this},createSpring:function(a,b){var c=new h(this);this.registerSpring(c);if(a===void 0||b===void 0)c.setSpringConfig(j.DEFAULT_ORIGAMI_SPRING_CONFIG);else{a=j.fromOrigamiTensionAndFriction(a,b);c.setSpringConfig(a)}return c},getIsIdle:function(){return this._isIdle},getSpringById:function(a){return this._springRegistry[a]},getAllSprings:function(){var a=[];for(var b in this._springRegistry)Object.prototype.hasOwnProperty.call(this._springRegistry,b)&&a.push(this._springRegistry[b]);return a},registerSpring:function(a){this._springRegistry[a.getId()]=a},deregisterSpring:function(a){n(this._activeSprings,a),delete this._springRegistry[a.getId()]},advance:function(a,b){__p&&__p();while(this._idleSpringIndices.length>0)this._idleSpringIndices.pop();for(var c=0,d=this._activeSprings.length;c<d;c++){var e=this._activeSprings[c];e.systemShouldAdvance()?e.advance(a/1e3,b/1e3):this._idleSpringIndices.push(this._activeSprings.indexOf(e))}while(this._idleSpringIndices.length>0){e=this._idleSpringIndices.pop();e>=0&&this._activeSprings.splice(e,1)}},loop:function(a){__p&&__p();var b;this._lastTimeMillis===-1&&(this._lastTimeMillis=a-1);var c=a-this._lastTimeMillis;this._lastTimeMillis=a;var d=0,e=this.listeners.length;for(d=0;d<e;d++)b=this.listeners[d],b.onBeforeIntegrate&&b.onBeforeIntegrate(this);this.advance(a,c);this._activeSprings.length===0&&(this._isIdle=!0,this._lastTimeMillis=-1);for(d=0;d<e;d++)b=this.listeners[d],b.onAfterIntegrate&&b.onAfterIntegrate(this);this._isIdle||this.looper.run()},activateSpring:function(a){a=this._springRegistry[a];this._activeSprings.indexOf(a)==-1&&this._activeSprings.push(a);this.getIsIdle()&&(this._isIdle=!1,this.looper.run())},addListener:function(a){this.listeners.push(a)},removeListener:function(a){n(this.listeners,a)},removeAllListeners:function(){this.listeners=[]}});var h=a.Spring=function a(b){this._id="s"+a._ID++,this._springSystem=b,this.listeners=[],this._currentState=new i(),this._previousState=new i(),this._tempState=new i()};c.extend(h,{_ID:0,MAX_DELTA_TIME_SEC:.064,SOLVER_TIMESTEP_SEC:.001});c.extend(h.prototype,{_id:0,_springConfig:null,_overshootClampingEnabled:!1,_currentState:null,_previousState:null,_tempState:null,_startValue:0,_endValue:0,_wasAtRest:!0,_restSpeedThreshold:.001,_displacementFromRestThreshold:.001,listeners:null,_timeAccumulator:0,_springSystem:null,destroy:function(){this.listeners=[],this.frames=[],this._springSystem.deregisterSpring(this)},getId:function(){return this._id},setSpringConfig:function(a){this._springConfig=a;return this},getSpringConfig:function(){return this._springConfig},setCurrentValue:function(a,b){this._startValue=a;this._currentState.position=a;b||this.setAtRest();this.notifyPositionUpdated(!1,!1);return this},getStartValue:function(){return this._startValue},getCurrentValue:function(){return this._currentState.position},getCurrentDisplacementDistance:function(){return this.getDisplacementDistanceForState(this._currentState)},getDisplacementDistanceForState:function(a){return Math.abs(this._endValue-a.position)},setEndValue:function(a){__p&&__p();if(this._endValue==a&&this.isAtRest())return this;this._startValue=this.getCurrentValue();this._endValue=a;this._springSystem.activateSpring(this.getId());for(var a=0,b=this.listeners.length;a<b;a++){var c=this.listeners[a];c=c.onSpringEndStateChange;c&&c(this)}return this},getEndValue:function(){return this._endValue},setVelocity:function(a){if(a===this._currentState.velocity)return this;this._currentState.velocity=a;this._springSystem.activateSpring(this.getId());return this},getVelocity:function(){return this._currentState.velocity},setRestSpeedThreshold:function(a){this._restSpeedThreshold=a;return this},getRestSpeedThreshold:function(){return this._restSpeedThreshold},setRestDisplacementThreshold:function(a){this._displacementFromRestThreshold=a},getRestDisplacementThreshold:function(){return this._displacementFromRestThreshold},setOvershootClampingEnabled:function(a){this._overshootClampingEnabled=a;return this},isOvershootClampingEnabled:function(){return this._overshootClampingEnabled},isOvershooting:function(){var a=this._startValue,b=this._endValue;return this._springConfig.tension>0&&(a<b&&this.getCurrentValue()>b||a>b&&this.getCurrentValue()<b)},advance:function(a,b){__p&&__p();a=this.isAtRest();if(a&&this._wasAtRest)return;var c=b;b>h.MAX_DELTA_TIME_SEC&&(c=h.MAX_DELTA_TIME_SEC);this._timeAccumulator+=c;b=this._springConfig.tension;c=this._springConfig.friction;var d=this._currentState.position,e=this._currentState.velocity,f=this._tempState.position,g=this._tempState.velocity,i,j,k,l,m,n,o,p;while(this._timeAccumulator>=h.SOLVER_TIMESTEP_SEC)this._timeAccumulator-=h.SOLVER_TIMESTEP_SEC,this._timeAccumulator<h.SOLVER_TIMESTEP_SEC&&(this._previousState.position=d,this._previousState.velocity=e),i=e,j=b*(this._endValue-f)-c*e,f=d+i*h.SOLVER_TIMESTEP_SEC*.5,g=e+j*h.SOLVER_TIMESTEP_SEC*.5,k=g,l=b*(this._endValue-f)-c*g,f=d+k*h.SOLVER_TIMESTEP_SEC*.5,g=e+l*h.SOLVER_TIMESTEP_SEC*.5,m=g,n=b*(this._endValue-f)-c*g,f=d+m*h.SOLVER_TIMESTEP_SEC*.5,g=e+n*h.SOLVER_TIMESTEP_SEC*.5,o=g,p=b*(this._endValue-f)-c*g,i=1/6*(i+2*(k+m)+o),k=1/6*(j+2*(l+n)+p),d+=i*h.SOLVER_TIMESTEP_SEC,e+=k*h.SOLVER_TIMESTEP_SEC;this._tempState.position=f;this._tempState.velocity=g;this._currentState.position=d;this._currentState.velocity=e;this._timeAccumulator>0&&this.interpolate(this._timeAccumulator/h.SOLVER_TIMESTEP_SEC);(this.isAtRest()||this._overshootClampingEnabled&&this.isOvershooting())&&(this._springConfig.tension>0?(this._startValue=this._endValue,this._currentState.position=this._endValue):(this._endValue=this._currentState.position,this._startValue=this._endValue),this.setVelocity(0),a=!0);m=!1;this._wasAtRest&&(this._wasAtRest=!1,m=!0);o=!1;a&&(this._wasAtRest=!0,o=!0);this.notifyPositionUpdated(m,o)},notifyPositionUpdated:function(a,b){for(var c=0,d=this.listeners.length;c<d;c++){var e=this.listeners[c];a&&e.onSpringActivate&&e.onSpringActivate(this);e.onSpringUpdate&&e.onSpringUpdate(this);b&&e.onSpringAtRest&&e.onSpringAtRest(this)}},systemShouldAdvance:function(){return!this.isAtRest()||!this.wasAtRest()},wasAtRest:function(){return this._wasAtRest},isAtRest:function(){return Math.abs(this._currentState.velocity)<this._restSpeedThreshold&&(this.getDisplacementDistanceForState(this._currentState)<=this._displacementFromRestThreshold||this._springConfig.tension===0)},setAtRest:function(){this._endValue=this._currentState.position;this._tempState.position=this._currentState.position;this._currentState.velocity=0;return this},interpolate:function(a){this._currentState.position=this._currentState.position*a+this._previousState.position*(1-a),this._currentState.velocity=this._currentState.velocity*a+this._previousState.velocity*(1-a)},getListeners:function(){return this.listeners},addListener:function(a){this.listeners.push(a);return this},removeListener:function(a){n(this.listeners,a);return this},removeAllListeners:function(){this.listeners=[];return this},currentValueIsApproximately:function(a){return Math.abs(this.getCurrentValue()-a)<=this.getRestDisplacementThreshold()}});var i=function(){};c.extend(i.prototype,{position:0,velocity:0});var j=a.SpringConfig=function(a,b){this.tension=a,this.friction=b},k=a.AnimationLooper=function(){this.springSystem=null;var a=this,b=function(){a.springSystem.loop(Date.now())};this.run=function(){c.onFrame(b)}};a.SimulationLooper=function(a){__p&&__p();this.springSystem=null;var b=0,c=!1;a=a||16.667;this.run=function(){if(c)return;c=!0;while(!this.springSystem.getIsIdle())this.springSystem.loop(b+=a);c=!1}};a.SteppingSimulationLooper=function(a){this.springSystem=null;var b=0;this.run=function(){};this.step=function(a){this.springSystem.loop(b+=a)}};var l=a.OrigamiValueConverter={tensionFromOrigamiValue:function(a){return(a-30)*3.62+194},origamiValueFromTension:function(a){return(a-194)/3.62+30},frictionFromOrigamiValue:function(a){return(a-8)*3+25},origamiFromFriction:function(a){return(a-25)/3+8}};c.extend(j,{fromOrigamiTensionAndFriction:function(a,b){return new j(l.tensionFromOrigamiValue(a),l.frictionFromOrigamiValue(b))},coastingConfigWithOrigamiFriction:function(a){return new j(0,l.frictionFromOrigamiValue(a))}});j.DEFAULT_ORIGAMI_SPRING_CONFIG=j.fromOrigamiTensionAndFriction(40,7);c.extend(j.prototype,{friction:0,tension:0});var m={};c.hexToRGB=function(a){if(m[a])return m[a];a=a.replace("#","");a.length===3&&(a=a[0]+a[0]+a[1]+a[1]+a[2]+a[2]);var b=a.match(/.{2}/g);b={r:parseInt(b[0],16),g:parseInt(b[1],16),b:parseInt(b[2],16)};m[a]=b;return b};c.rgbToHex=function(a,b,c){a=a.toString(16);b=b.toString(16);c=c.toString(16);a=a.length<2?"0"+a:a;b=b.length<2?"0"+b:b;c=c.length<2?"0"+c:c;return"#"+a+b+c};g=a.MathUtil={mapValueInRange:function(a,b,c,d,e){c=c-b;e=e-d;a=(a-b)/c;return d+a*e},interpolateColor:function(a,b,d,e,f,g){e=e===void 0?0:e;f=f===void 0?1:f;b=c.hexToRGB(b);d=c.hexToRGB(d);var h=Math.floor(c.mapValueInRange(a,e,f,b.r,d.r)),i=Math.floor(c.mapValueInRange(a,e,f,b.g,d.g));a=Math.floor(c.mapValueInRange(a,e,f,b.b,d.b));if(g)return"rgb("+h+","+i+","+a+")";else return c.rgbToHex(h,i,a)},degreesToRadians:function(a){return a*Math.PI/180},radiansToDegrees:function(a){return a*180/Math.PI}};c.extend(c,g);function n(a,b){b=a.indexOf(b);b!=-1&&a.splice(b,1)}var o;g=b("ExecutionEnvironment");g.canUseDOM&&(o=window.requestAnimationFrame||window.webkitRequestAnimationFrame||window.mozRequestAnimationFrame||window.msRequestAnimationFrame||window.oRequestAnimationFrame);o||(o=b("setImmediate"));c.onFrame=function(a){return o(a)};e.exports=a})()}),null);
__d("LiveAudioAnimation",["cx","AudioContextSingleton","CSS","CSSAnimationBuilder","DOM","LiveAudioAnimationConfig","Random","Run","SubscriptionsHandler","queryThenMutateDOM","requestAnimationFrame"],(function(a,b,c,d,e,f,g){__p&&__p();function h(a,c){"use strict";this.$9=!1,this.$10=!1,this.$11=[],this.$12=!1,this.$13=[],this.$14=[],this.$15=0,this.$6=a,this.$2=c,this.$3=new(b("SubscriptionsHandler"))(),this.$16(),b("Run").onLeave(function(){return this.$17()}.bind(this))}h.prototype.$16=function(){"use strict";__p&&__p();var a=this.$2.getVideoNode(),c=b("AudioContextSingleton").get();if(!c)return;a=c.createMediaElementSource(a);this.$7=c.createAnalyser();a.connect(this.$7);this.$7.connect(c.destination);this.$7.fftSize=h.FFT_SIZE;a=this.$7.frequencyBinCount;this.$8=new Uint8Array(a);this.$3.addSubscriptions(this.$2.addListener("unmuteVideo",function(){this.$12=!1,this.$18()}.bind(this)),this.$2.addListener("muteVideo",function(){this.$12=!0}.bind(this)),this.$2.addListener("pausePlayback",function(){return this.$19()}.bind(this)),this.$2.addListener("beginPlayback",function(){return this.$18()}.bind(this)),this.$2.addListener("streamInterrupted",function(){return this.$19()}.bind(this)),this.$2.addListener("streamResumed",function(){return this.$18()}.bind(this)),this.$2.addListener("finishPlayback",function(){return this.$19()}.bind(this)),this.$2.addListener("VideoControls/visibilityUpdate",function(a){a=a.areControlsVisible;return this.$20(a)}.bind(this)));for(var c=0;c<h.HUMP_COUNT;c++){a=document.createElement("canvas");b("CSS").setClass(a,"_39px");b("DOM").appendContent(this.$6,a);a=new i(!1,a);this.$13.push(a)}this.$12=this.$2.isMuted();this.$18()};h.prototype.$17=function(){"use strict";this.$19(),this.$3.release()};h.prototype.$21=function(a){"use strict";__p&&__p();if(!this.$9){a.isAnimating=!1;b("CSS").addClass(a.canvas,"hidden_elem");return}a.isAnimating=!0;var c=a.canvas;this.$22(c);var d=h.MIN_SPEED+b("Random").random()*(h.MAX_SPEED-h.MIN_SPEED);d/=1e3;d/=2;var e=b("CSSAnimationBuilder").keyframeAnimation(c);e.defineKeyframes({"0%":{transform:"scaleY(0)"},"100%":{transform:"scaleY(1)"}});e.setDuration(d).setDirection("alternate").setMemoize(!1).setTimingFunction("ease-in-out").setIterationCount(2);e.setFinishedCallback(function(){b("CSS").setClass(c,"_39px"),this.$21(a)}.bind(this));e.start()};h.prototype.$22=function(a){"use strict";__p&&__p();a=a.getContext("2d");var c=this.$4,d=this.$5;if(!a||!c||!d)return;a.clearRect(0,0,c,d);var e=0;this.$12?e=h.RANDOM_MIN_AMPLITUDE+b("Random").random()*(h.RANDOM_MAX_AMPLITUDE-h.RANDOM_MIN_AMPLITUDE):e=this.getNextAudioLevel();var f=b("Random").random(),g=h.MINIMUM_WIDTH_FACTOR+h.WIDTH_FACTOR_MULTIPLIER*b("Random").random();f=c/4+f*c/2;var i=[];for(var j=h.ANCHOR_POINT_X_VALUES,k=Array.isArray(j),l=0,j=k?j:j[typeof Symbol==="function"?Symbol.iterator:"@@iterator"]();;){var m;if(k){if(l>=j.length)break;m=j[l++]}else{l=j.next();if(l.done)break;m=l.value}m=m;i.push([f+m*c/4,d-this.$23(m,d,e,g)])}this.$24(a,i)};h.prototype.$23=function(a,b,c,d){"use strict";c=c*b;b=Math.pow(1/(1+Math.pow(d*a,2)),2);return c*b};h.prototype.$24=function(a,b){"use strict";__p&&__p();a.fillStyle=h.FILL_COLOR;a.beginPath();a.moveTo.apply(a,b[0]);var c=1;for(;c<b.length-2;c++){var d=(b[c][0]+b[c+1][0])/2,e=(b[c][1]+b[c+1][1])/2;a.quadraticCurveTo(b[c][0],b[c][1],d,e)}a.quadraticCurveTo(b[c][0],b[c][1],b[c+1][0],b[c+1][1]);a.lineTo.apply(a,b[0]);a.fill()};h.prototype.$18=function(){"use strict";__p&&__p();if(!this.$2.isState("playing"))return;this.$9=!0;for(var a=this.$13,c=Array.isArray(a),d=0,a=c?a:a[typeof Symbol==="function"?Symbol.iterator:"@@iterator"]();;){var e;if(c){if(d>=a.length)break;e=a[d++]}else{d=a.next();if(d.done)break;e=d.value}e=e;e.isAnimating||(b("CSS").removeClass(e.canvas,"hidden_elem"),this.$21(e))}this.$25()};h.prototype.$19=function(){"use strict";this.$9=!1};h.prototype.$20=function(a){"use strict";a?this.$19():this.$18()};h.prototype.$25=function(){"use strict";if(!this.$9)return;b("requestAnimationFrame")(function(){b("queryThenMutateDOM")(function(){return this.$26()}.bind(this),function(){this.$27(),this.$25()}.bind(this))}.bind(this))};h.prototype.getNextAudioLevel=function(){"use strict";var a=this.$28(this.$11);this.$11=[];a-=h.NOISE_FLOOR;a=Math.max(a,0);a*=1/(1-h.NOISE_FLOOR);a<h.MINIMUM_ANIMATION_LEVEL&&(a=0);return a};h.prototype.$27=function(){"use strict";if(!this.$7)return;if(this.$12)return;this.$7.getByteFrequencyData(this.$8);var a=this.$28(this.$8,h.BINS_TO_USE_FOR_DB_AVERAGE)/h.MAX_BYTE_VALUE;a=this.$29(a);this.$11.push(a)};h.prototype.$29=function(a){"use strict";var b=this.$15++%h.NORMALIZATION_HISTORY_LENGTH;this.$14[b]=a;if(this.$15<h.NORMALIZATION_HISTORY_LENGTH)return a;b=this.$28(this.$14);b=.5/b;b=Math.min(a*b,1);return b*h.NORMALIZATION_FACTOR+a*(1-h.NORMALIZATION_FACTOR)};h.prototype.$28=function(a,b){"use strict";__p&&__p();var c=0,d=0;for(var a=a,e=Array.isArray(a),f=0,a=e?a:a[typeof Symbol==="function"?Symbol.iterator:"@@iterator"]();;){var g;if(e){if(f>=a.length)break;g=a[f++]}else{f=a.next();if(f.done)break;g=f.value}g=g;c+=g;d++;if(b&&d==b)break}return d===0?0:c/d};h.prototype.$26=function(){"use strict";if(this.$13.length<1)return;var a=this.$13[0].canvas;this.$4=a.width;this.$5=a.height};h.FFT_SIZE=32;h.MAX_BYTE_VALUE=255;h.BINS_TO_USE_FOR_DB_AVERAGE=10;h.NORMALIZATION_HISTORY_LENGTH=b("LiveAudioAnimationConfig").NORMALIZATION_CONFIG.NORMALIZATION_HISTORY_LENGTH;h.NORMALIZATION_FACTOR=b("LiveAudioAnimationConfig").NORMALIZATION_CONFIG.NORMALIZATION_FACTOR;h.HUMP_COUNT=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.HUMP_COUNT;h.MIN_SPEED=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.MIN_SPEED;h.MAX_SPEED=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.MAX_SPEED;h.NOISE_FLOOR=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.NOISE_FLOOR;h.MINIMUM_ANIMATION_LEVEL=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.MINIMUM_ANIMATION_LEVEL;h.FILL_COLOR=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.FILL_COLOR;h.MINIMUM_WIDTH_FACTOR=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.MINIMUM_WIDTH_FACTOR;h.WIDTH_FACTOR_MULTIPLIER=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.WIDTH_FACTOR_MULTIPLIER;h.REFRESH_THRESHOLD_PIXELS=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.REFRESH_THRESHOLD_PIXELS;h.RANDOM_MIN_AMPLITUDE=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.RANDOM_MIN_AMPLITUDE;h.RANDOM_MAX_AMPLITUDE=b("LiveAudioAnimationConfig").ANIMATION_CONFIG.RANDOM_MAX_AMPLITUDE;h.ANCHOR_POINT_X_VALUES=[-3,-2,-1,-.5,-.25,-.1,-.05,0,.05,.1,.25,.5,1,2,3];function i(a,b){"use strict";this.isAnimating=a,this.canvas=b}e.exports=h}),null);
__d("VideoComponentAutoPlayControl.react",["FeedVideoPlayerController","React","VideoAutoplayControllerX","VideoComponent"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g;g=babelHelpers.inherits(a,b("React").Component);g&&g.prototype;a.prototype.enable=function(a){var c={controller:a,startsMuted:this.props.startMuted,viewport_autoplay:!0,video_ids:[a.getVideoID()]};a={video_container:a.getVideoNode()};this.$2=new(b("FeedVideoPlayerController"))(a,c);this.$3=b("VideoAutoplayControllerX").registerVideoUnit(this.$2)};a.prototype.disable=function(){this.$3()};a.prototype.shouldComponentUpdate=function(){return!1};a.prototype.render=function(){return null};function a(){g.apply(this,arguments)}a.defaultProps={startMuted:!0};e.exports=b("VideoComponent").createContainer(a)}),null);
__d("getSquiggleImgURL",[],(function(a,b,c,d,e,f){"use strict";function g(a){return'<svg fill="'+a+'" opacity="0.8" preserveAspectRatio="none" xmlns="http://www.w3.org/2000/svg" x="0" y="0" viewBox="0 0 10 2.8"><path d="M10,0.7L9.7,1C8.4,2,6.6,2,5.3,1C3.8-0.3,1.6-0.3,0,0.8V2l0.3-0.2c1.3-1,3.1-1,4.4,0c0.8,0.7,1.8,1,2.8,1C8.4,2.8,9.2,2.5,10,2V0.7z"/></svg>'}function h(a){return'<svg fill="'+a+'" opacity="0.8" preserveAspectRatio="none" xmlns="http://www.w3.org/2000/svg" x="0" y="0" viewBox="0 0 10 3.8"><path d="M10,0.6L9.4,1.1C8.3,2,6.7,2,5.6,1.1C4-0.2,1.8-0.3,0,0.7v2.5l0.6-0.5c1.1-0.9,2.6-0.9,3.8,0c0.9,0.7,2,1.1,3.1,1.1c0.9,0,1.7-0.2,2.5-0.7V0.6z"/></svg>'}function a(a,b){return"'data:image/svg+xml;utf8,"+(b?h(a):g(a))+"'"}e.exports=a}),null);
__d("Autosize",["cx","CSS","DOM","Style"],(function(a,b,c,d,e,f,g){__p&&__p();["fontFamily","fontStyle","fontVariant","fontWeight","letterSpacing","textDecoration","textIndent","textTransform","whiteSpace","wordSpacing","wordWrap"];var h=/^[0-9]+$/;function i(a){var c=a.cloneNode(!0);b("CSS").addClass(c,"_4g");var d=a.clientWidth-b("Style").getFloat(a,"paddingLeft")-b("Style").getFloat(a,"paddingRight");b("Style").set(c,"width",d+"px");d=a.clientHeight-b("Style").getFloat(a,"paddingTop")-b("Style").getFloat(a,"paddingBottom");b("Style").set(c,"height",d+"px");b("DOM").insertAfter(a,c);return c}function j(a,c,d,e,f){__p&&__p();var g=a.style.fontSize,h=a.style.height;b("Style").set(a,"height","auto");if(c!==null){var i=a.style.width;b("Style").set(a,"width","auto")}var j=0,k=f.length-1;while(j<k){var l=Math.ceil((j+k)/2);b("Style").set(a,"font-size",f[l]+e);d!==null&&a.scrollHeight>d||c!==null&&a.scrollWidth>c?k=l-1:j=l}a.style.fontSize=g;a.style.height=h;c!==null&&(a.style.width=i);return f[j]+e}function k(a,c,d,e,f,g){__p&&__p();var h=a.style.fontSize,i=a.style.height;b("Style").set(a,"height","auto");if(c!==null){var j=a.style.width;b("Style").set(a,"width","auto")}b("Style").set(a,"font-size",g+e);if((d===null||a.scrollHeight<=d)&&(c===null||a.scrollWidth<=c)){a.style.fontSize=h;a.style.height=i;c!==null&&(a.style.width=j);return g+e}b("Style").set(a,"font-size",f+e);if(d!==null&&a.scrollHeight>d||c!==null&&a.scrollWidth>c){a.style.fontSize=h;a.style.height=i;c!==null&&(a.style.width=j);return f+e}while(f+1<g){var k=Math.ceil((f+g)/2);b("Style").set(a,"font-size",k+e);d!==null&&a.scrollHeight>d||c!==null&&a.scrollWidth>c?g=k:f=k}a.style.fontSize=h;a.style.height=i;c!==null&&(a.style.width=j);return f+e}function a(a,b){__p&&__p();this._wrap=a;this._attr=b;if(this._attr.sizes){a=this._attr.sizes;for(var c=1,d=a.length;c<d;c++){if(a[c-1]<=a[c])continue;a.sort(function(a,b){return a-b});break}}else if(b.min>b.max){c=b.min;b.min=b.max;b.max=c}this.fit()}a.prototype.fit=function(a,c){__p&&__p();var d=this._wrap;if(!d.clientWidth){l.push(this);return}var e=i(d);typeof a==="undefined"&&(a=this._attr.width);h.test(a)?e.style.width=a+"px":a!==null&&a!=="auto"&&(e.style.width=a);typeof c==="undefined"&&(c=this._attr.height);h.test(c)?e.style.height=c+"px":c!==null&&c!=="auto"&&(e.style.height=c);a=null;this._attr.wrap||(a=e.clientWidth);var f=null;(this._attr.wrap||c!==null)&&(f=e.clientHeight);this._attr.sizes?c=j(e,a,f,"px",this._attr.sizes):c=k(e,a,f,"px",this._attr.min,this._attr.max);b("DOM").remove(e);b("Style").set(d,"font-size",c);b("CSS").removeClass(d,"invisible_elem")};var l=[];a.onNodeInserted=function(){var a=l;l=[];a.forEach(function(a){a.fit()})};e.exports=a}),null);
__d("FBKeyframesProject",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({ADS_ANIMATOR:"ads_animator",AWESOME_TEXT_POSTS:"awesome_text_posts",AWESOME_TEXT_STORIES:"awesome_text_stories",BALLOT:"ballot",CIVIC_PROPOSAL:"civic_proposal",CMS:"cms",CULTURAL_MOMENTS_QP:"cultural_moments_qp",CULTURAL_MOMENTS_QP_TOOL:"cultural_moments_qp_tool",DIGITAL_LITERACY:"digital_literacy",ELECTION_PHOTO_FORWARD:"election_photo_forward",FACEBOOK_STORIES:"facebook_stories",FEEDBACK_REACTIONS:"feedback_reactions",FUN_FACTS:"fun_facts",FUNDRAISER:"fundraiser",GOODWILL_AR_BIRTHDAY:"goodwill_ar_birthday",GOODWILL_MC:"goodwill_mc",ILLUSTRATION_KIT_TEMPLATE:"illustration_kit_template",KEYFRAMES_UICE:"keyframes_uice",KEYFRAMES_UNIT_TEST:"keyframes_unit_test",LIFE_EVENTS:"life_events",MENTORSHIP:"mentorship",MESSAGING_REACTIONS:"messaging_reactions",MLE_REACTIONS:"mle_reactions",NT_EXAMPLES:"nt_examples",PAGE_SURFACE:"page_surface",PIXELCLOUD:"pixelcloud",PRIVACY_BASICS:"privacy_basics",RECRUITING_DELIGHT:"recruiting_delight",SOCIAL_PLAYER:"social_player",TEXT_DELIGHTS:"text_delights",TIME_IN_APP:"time_in_app",VIDEO_HOME_SOCIAL_GLYPH:"video_home_social_glyph",VOTER_REGISTRATION_DRIVE:"voter_registration_drive",YOUTH_PORTAL:"youth_portal",ONCALL_DASHBOARD:"oncall_dashboard",ACTIONABLE_INSIGHTS:"actionable_insights"})}),null);
__d("StoriesTestID",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({FEEDBACK_TEXT_REPLY_BAR:"viewer_feedback_text_reply_bar",FEEDBACK_DRAFT_EDITOR:"viewer_feedback_draft_editor",FEEDBACK_TEXT_REPLY_BAR_SEND_BUTTON:"viewer_feedback_text_reply_bar_SEND_BUTTON",LWR_MENU:"UFIReactionsMenu",NAV_LIST:"nav_list",NAV_LIST_ITEM:"nav_list_item",OVERLAY_RESHARED_POST:"overlay_reshared_post",PHOTO_MEDIA:"photo_media",PHOTO_MEDIA_IMAGE:"photo_media_image",PROFILE_PICTURE:"profile_pic",TRAY:"tray",TRAY_ITEM:"tray_item",VIEWER_DIALOG:"viewer_dialog",VIEWER_DELETE_CONFIRMATION_DIALOG:"viewer_delete_confirmation_dialog",VIEWER_CLOSE_BUTTON:"viewer_option_close_button",VIEWER_OPTION_MENU_BUTTON:"viewer_option_menu_button",VIEWER_OPTION_MENU:"viewer_option_menu",VIEWER_OPTION_MENU_DELETE_BUTTON:"viewer_option_menu_delete_button",VIEWER_OPTION_MENU_DELETE_CONFIRM_BUTTON:"viewer_option_menu_delete_confirm_button",VIEWER_PAUSE_BUTTON:"viewer_pause_button",VIEWER_LEFT_BUTTON:"viewer_left_button",VIEWER_RIGHT_BUTTON:"viewer_right_button",VIEWER_SHEET:"viewer_sheet",STORY_TRAY:"story_tray",KEYBOARD_LAYER:"keyboard_layer"})}),null);
__d("StoryOwnerType",[],(function(a,b,c,d,e,f){e.exports=Object.freeze({NUX:"nux",SELF:"self",FRIEND:"friend",FOLLOWEE:"followee",NULL:"null",PAGE:"page",EVENT:"event",GROUP:"group",PROMOTION:"promotion"})}),null);
__d("XBusinessSettingsController",["XController"],(function(a,b,c,d,e,f){e.exports=b("XController").create("/settings/{?tab}/{?asset_id}/",{business_id:{type:"FBID"},tab:{type:"String"},asset_id:{type:"Int"}})}),null);