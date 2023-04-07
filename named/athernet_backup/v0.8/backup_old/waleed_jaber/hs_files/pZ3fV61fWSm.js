if (self.CavalryLogger) { CavalryLogger.start_js(["NgABR"]); }

__d("MentionResultsPropTypes",["React","SearchableEntry","SelectionState"],(function(a,b,c,d,e,f){a=b("React").PropTypes;c={viewID:a.string.isRequired,selection:a.instanceOf(b("SelectionState")).isRequired,contextComponent:a.object.isRequired,mentionableEntries:a.array.isRequired,highlightedMentionable:a.instanceOf(b("SearchableEntry")),onMentionSelect:a.func.isRequired,onMentionHighlight:a.func.isRequired,onMentionRenderHighlight:a.func.isRequired};e.exports=c}),null);
__d("MentionsLayer.react",["Bootloader","Locale","MentionResultsPropTypes","React","areEqual"],(function(a,b,c,d,e,f){__p&&__p();a=b("React").PropTypes;var g=!1,h=b("Locale").isRTL(),i,j,k,l,m=5;c=b("React").createClass({displayName:"MentionsLayer",propTypes:babelHelpers["extends"]({},b("MentionResultsPropTypes"),{typeaheadView:a.func.isRequired,typeaheadViewProps:a.object,autoflip:a.bool,position:a.oneOf(["above","below"])}),getInitialState:function(){return{bootloaded:g}},getDefaultProps:function(){return{offset:m}},componentDidMount:function(){this.state.bootloaded||n(function(){this.isMounted()&&this.setState({bootloaded:!0})}.bind(this))},_onMentionSelect:function(a,b){b.preventDefault(),this.props.onMentionSelect(a,b)},shouldComponentUpdate:function(a,c){return this.state.bootloaded!==c.bootloaded||!b("areEqual")(this.props.mentionableEntries,a.mentionableEntries)||this.props.highlightedMentionable!==a.highlightedMentionable||this.props.characterOffset!==a.characterOffset},render:function(){__p&&__p();if(!this.state.bootloaded)return null;var a=this.props.mentionableEntries,c=this.props.selection;c=c.isCollapsed()&&c.getHasFocus()&&a&&a.length;var d=null,e=this.props.typeaheadViewProps,f=!1;e&&e.positionAtContext?f=!0:c&&(d=l(this.props.characterOffset,h));e={};this.props.autoflip&&(e.ContextualLayerAutoFlip=j,e.ContextualLayerUpdateOnScroll=k);var g=this.props.typeaheadView;return b("React").createElement(i,{shown:c,context:this.props.contextComponent,contextBounds:d,containerWidthMatchContext:f,offsetY:this.props.offset,offsetX:this.props.offset,position:this.props.position||"below",behaviors:e,shouldSetARIAProperties:!1},b("React").createElement("div",{"data-testid":"mentions-contextual-layer"},b("React").createElement(g,{id:this.props.viewID,viewProps:this.props.typeaheadViewProps,highlightedEntry:this.props.highlightedMentionable,entries:a||[],onSelect:this._onMentionSelect,onHighlight:this.props.onMentionHighlight,onRenderHighlight:this.props.onMentionRenderHighlight})))}});function n(a){b("Bootloader").loadModules(["ContextualLayer.react","ContextualLayerAutoFlip","ContextualLayerUpdateOnScroll","getMentionableRect"],function(b,c,d,e){i=b,j=c,k=d,l=e,g=!0,a()},"MentionsLayer.react")}e.exports=c}),null);
__d("SUIButtonUniform.fds",["cssVar","createBUITypeStyle"],(function(a,b,c,d,e,f,g){"use strict";a={height:{normal:28,"short":24,tall:36},padding:{normal:{button:"11px",icon:"7px",onlyIcon:"7px"},"short":{button:"7px",icon:"3px",onlyIcon:"3px"},tall:{button:"19px",icon:"7px",onlyIcon:"11px"}},typeStyle:b("createBUITypeStyle")({color:"#444950",fontSize:"12px",fontWeight:"bold"}),use:{"default":{active:{background:"#DADDE1",borderColor:"#DADDE1",color:"#444950"},disabled:{background:"#F5F6F7",borderColor:"#EBEDF0",color:"#BEC3C9"},hover:{background:"#EBEDF0",borderColor:"#DADDE1",color:"#444950"},normal:{background:"#F5F6F7",borderColor:"#DADDE1",color:"#444950"}},confirm:{active:{background:"#1D3C78",borderColor:"#1D3C78",color:"#FFFFFF"},disabled:{background:"#AAC9FF",borderColor:"#AAC9FF",color:"#FFFFFF"},hover:{background:"#2851A3",borderColor:"#2851A3",color:"#FFFFFF"},normal:{background:"#3578E5",borderColor:"#3578E5",color:"#FFFFFF"}},special:{active:{background:"#006900",borderColor:"#006900",color:"#FFFFFF"},disabled:{background:"#86DF81",borderColor:"#86DF81",color:"#FFFFFF"},hover:{background:"#008C00",borderColor:"#008C00",color:"#FFFFFF"},normal:{background:"#00A400",borderColor:"#00A400",color:"#FFFFFF"}},flat:{active:{background:"rgba(0, 0, 0, 0.1)",borderColor:"transparent",color:"#444950"},disabled:{background:"transparent",borderColor:"transparent",color:"#BEC3C9"},hover:{background:"rgba(0, 0, 0, 0.05)",borderColor:"transparent",color:"#444950"},normal:{background:"transparent",borderColor:"transparent",color:"#444950"}},flatWhite:{active:{background:"rgba(255, 255, 255, 0.1)",borderColor:"transparent",color:"#FFFFFF"},disabled:{background:"transparent",borderColor:"transparent",color:"rgba(255, 255, 255, 0.4)"},hover:{background:"rgba(255, 255, 255, 0.05)",borderColor:"transparent",color:"#FFFFFF"},normal:{background:"transparent",borderColor:"transparent",color:"#FFFFFF"}}}};e.exports=a}),null);
__d("FDSPrivateButtonTheme.fds18",["SUIButtonUniform.fds","makeSUIFDSPrivateTheme"],(function(a,b,c,d,e,f){"use strict";a=b("makeSUIFDSPrivateTheme")("FDSButton",{SUIButton:b("SUIButtonUniform.fds")});e.exports=a}),null);
__d("FDSPrivateButtonThemeContext",["FDSPrivateButtonTheme.fds18","React"],(function(a,b,c,d,e,f){"use strict";e.exports=b("React").createContext(b("FDSPrivateButtonTheme.fds18"))}),null);
__d("CornerEnum",[],(function(a,b,c,d,e,f){"use strict";a={topLeft:"topLeft",topRight:"topRight",bottomRight:"bottomRight",bottomLeft:"bottomLeft",values:["topLeft","topRight","bottomRight","bottomLeft"]};e.exports=a}),null);
__d("SideEnum",["prop-types"],(function(a,b,c,d,e,f){"use strict";a={top:"top",right:"right",bottom:"bottom",left:"left",propType:b("prop-types").oneOf(["top","right","bottom","left"]),values:["top","right","bottom","left"]};e.exports=a}),null);
__d("SUIBorderUtils",["CornerEnum","Locale","SideEnum","prop-types"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g=b("CornerEnum").values,h=b("SideEnum").values;a={ALL_CORNERS:g,ALL_SIDES:h,BorderedSidesPropType:b("prop-types").arrayOf(b("prop-types").oneOf(h)),RoundedCornersPropType:b("prop-types").arrayOf(b("prop-types").oneOf(g)),getBorderRadiusStyles:function(a,c){c=c;if(a===g)return c!=null?{borderRadius:c}:null;a=new Set(a);if(a.size===g.length)return c!=null?{borderRadius:c}:null;c==null&&(c="2px");a={borderTopLeftRadius:a.has("topLeft")?c:"0",borderTopRightRadius:a.has("topRight")?c:"0",borderBottomRightRadius:a.has("bottomRight")?c:"0",borderBottomLeftRadius:a.has("bottomLeft")?c:"0"};return b("Locale").isRTL()?{borderTopLeftRadius:a.borderTopRightRadius,borderTopRightRadius:a.borderTopLeftRadius,borderBottomRightRadius:a.borderBottomLeftRadius,borderBottomLeftRadius:a.borderBottomRightRadius}:a},getBorderWidthStyles:function(a){if(a===h)return null;a=new Set(a);if(a.size===h.length)return null;a={borderTopWidth:a.has("top")?"1px":"0",borderRightWidth:a.has("right")?"1px":"0",borderBottomWidth:a.has("bottom")?"1px":"0",borderLeftWidth:a.has("left")?"1px":"0"};return b("Locale").isRTL()?babelHelpers["extends"]({},a,{borderRightWidth:a.borderLeftWidth,borderLeftWidth:a.borderRightWidth}):a}};e.exports=a}),null);
__d("SUIInternalMouseUpListener",["DOMEventListener"],(function(a,b,c,d,e,f){"use strict";var g=null,h=null;a={set:function(a){h||(h=b("DOMEventListener").add(window,"mouseup",i)),g=a},unset:function(a){g===a&&(g=null)}};function i(a){g&&(g(a),g=null)}e.exports=a}),null);
__d("mergeDeepInto",["invariant","mergeHelpers"],(function(a,b,c,d,e,f,g){"use strict";__p&&__p();var h=b("mergeHelpers").ArrayStrategies,i=b("mergeHelpers").checkArrayStrategy,j=b("mergeHelpers").checkMergeArrayArgs,k=b("mergeHelpers").checkMergeLevel,l=b("mergeHelpers").checkMergeObjectArgs,m=b("mergeHelpers").isTerminal,n=b("mergeHelpers").normalizeMergeArg,o=function(a,b,c,d){l(a,b);k(d);var e=b?Object.keys(b):[];for(var f=0;f<e.length;f++){var g=e[f];q(a,b,g,c,d)}},p=function(a,b,c,d){j(a,b);k(d);if(c===h.Concat)a.push.apply(a,b);else{var e=Math.max(a.length,b.length);for(var f=0;f<e;f++)q(a,b,f,c,d)}},q=function(a,b,c,d,e){var f=b[c];b=Object.prototype.hasOwnProperty.call(b,c);var i=b&&m(f),j=b&&Array.isArray(f),k=b&&!j&&!j,l=a[c],n=Object.prototype.hasOwnProperty.call(a,c),q=n&&m(l),r=n&&Array.isArray(l),s=n&&!r&&!r;q?i?a[c]=f:j?(a[c]=[],p(a[c],f,d,e+1)):k?(a[c]={},o(a[c],f,d,e+1)):b||(a[c]=l):r?i?a[c]=f:j?(h[d]||g(0,5117),d===h.Clobber&&(l.length=0),p(l,f,d,e+1)):k?(a[c]={},o(a[c],f,d,e+1)):!b:s?i?a[c]=f:j?(a[c]=[],p(a[c],f,d,e+1)):k?o(l,f,d,e+1):!b:n||(i?a[c]=f:j?(a[c]=[],p(a[c],f,d,e+1)):k?(a[c]={},o(a[c],f,d,e+1)):!b)};a=function(a,b,c){b=n(b);i(c);o(a,b,c,0)};e.exports=a}),null);
__d("mergeDeep",["mergeDeepInto","mergeHelpers"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g=b("mergeHelpers").checkArrayStrategy,h=b("mergeHelpers").checkMergeObjectArgs,i=b("mergeHelpers").normalizeMergeArg;a=function(a,c,d){a=i(a);c=i(c);h(a,c);g(d);var e={};b("mergeDeepInto")(e,a,d);b("mergeDeepInto")(e,c,d);return e};e.exports=a}),null);
__d("SUIThemeContext.react",["React"],(function(a,b,c,d,e,f){"use strict";e.exports=b("React").createContext(null)}),null);
__d("withSUITheme",["invariant","React","SUITheme","SUIThemeContext.react","gkx","hoist-non-react-statics","prop-types","requireWeak"],(function(a,b,c,d,e,f,g){"use strict";__p&&__p();var h=function(a){return a.displayName||a.name||"Component"};function a(a){__p&&__p();var c;if(!b("gkx")("678820"))return a;var d=h(a);c=babelHelpers.inherits(e,b("React").Component);c&&c.prototype;e.prototype.getChildContext=function(){"use strict";return this.props.preserveThemeFromContext===!0?{theme:this.context.theme}:{theme:this.props.theme||this.context.theme}};e.prototype.$1=function(){"use strict";b("requireWeak")("AdsInterfacesComponentsLogger",function(a){return a.logSUIThemeError(new Error("Silvertail component "+d+" was not passed a theme in props or context. See https://fburl.com/silvertail-theme for more details."),d)})};e.prototype.$2=function(a){"use strict";var b=this.props.theme,c=this.context&&this.context.theme;b=b||a||c;b||this.$1();b||g(0,2207,d);return b};e.prototype.render=function(){"use strict";var c=this.props,d=c.theme;return b("React").createElement(b("SUIThemeContext.react").Consumer,null,function(e){var f=b("React").createElement(a,babelHelpers["extends"]({},c,{ref:c.forwardedRef,theme:this.$2(e)}));e=!this.props.preserveThemeFromContext&&d&&d!==e;return e?b("React").createElement(b("SUIThemeContext.react").Provider,{value:d},f):f}.bind(this))};function e(){"use strict";c.apply(this,arguments)}e.defaultProps={preserveThemeFromContext:!1};e.contextTypes={theme:b("prop-types").instanceOf(b("SUITheme"))};e.childContextTypes={theme:b("prop-types").instanceOf(b("SUITheme"))};var f=b("React").forwardRef(function(a,c){return b("React").createElement(e,babelHelpers["extends"]({},a,{forwardedRef:c}))});b("hoist-non-react-statics")(f,a);f.defaultProps=a.defaultProps;f.propTypes=a.propTypes;return f}e.exports=a}),null);
__d("SUIButton.react",["cx","AlignmentEnum","KeyStatus","Link.react","React","RTLKeys","SUIBorderUtils","SUIComponent","SUIGlyphIcon.react","SUIInternalMouseUpListener","SUITheme","TooltipData","VirtualCursorStatus","autoFlipStyleProps","gkx","joinClasses","mergeDeep","withSUITheme"],(function(a,b,c,d,e,f,g){"use strict";__p&&__p();var h,i=b("KeyStatus").isKeyDown,j=b("VirtualCursorStatus").isVirtualCursorTriggered;c=b("React").PropTypes;var k=!1;d="normal";f="center";g="button";var l="default";d={borderedSides:b("SUIBorderUtils").ALL_SIDES,disabled:k,hasHoverState:!0,height:d,labelIsHidden:!1,roundedCorners:b("SUIBorderUtils").ALL_CORNERS,suppressLabelOverflowTooltip:!1,suppressed:!1,textAlign:f,tooltipDelay:0,type:g,use:l};f=b("gkx")("678820")?b("React").PureComponent:b("SUIComponent");g=babelHelpers.inherits(a,f);h=g&&g.prototype;a.getButtonSize=function(a){return"medium"};a.getButtonUse=function(a){return a.use||l};a.getButtonDisabled=function(a){return a.disabled||k};function a(){__p&&__p();h.constructor.call(this),this.$SUIButton2=function(a){this.setState({isActive:!1,showFocusRing:!1}),this.props.onBlur&&this.props.onBlur(a)}.bind(this),this.$SUIButton3=function(a){if(this.props.disabled){a.preventDefault();return}this.props.onClick&&(this.props.onClick(a),this.props.href||a.preventDefault())}.bind(this),this.$SUIButton4=function(a){(i()||j())&&this.setState({showFocusRing:!0}),this.props.onFocus&&this.props.onFocus(a)}.bind(this),this.$SUIButton5=function(a){if(this.props.disabled)return;switch(a.keyCode){case b("RTLKeys").RETURN:case b("RTLKeys").SPACE:this.setState({isActive:!0,showFocusRing:!0});break}this.props.onKeyDown&&this.props.onKeyDown(a)}.bind(this),this.$SUIButton6=function(a){switch(a.keyCode){case b("RTLKeys").RETURN:case b("RTLKeys").SPACE:this.setState({isActive:!1});break}this.props.onKeyUp&&this.props.onKeyUp(a)}.bind(this),this.$SUIButton7=function(a){this.setState({isHovering:!0}),this.props.onMouseEnter&&(this.props.onMouseEnter(a),a.preventDefault())}.bind(this),this.$SUIButton8=function(a){this.setState({isHovering:!1}),this.props.onMouseLeave&&(this.props.onMouseLeave(a),a.preventDefault())}.bind(this),this.$SUIButton9=function(a){if(this.props.disabled)return;b("SUIInternalMouseUpListener").set(this.$SUIButton1);this.setState({isActive:!0,showFocusRing:!1});this.props.onMouseDown&&(this.props.onMouseDown(a),a.preventDefault())}.bind(this),this.$SUIButton1=function(a){if(!this.state.isActive)return;this.setState({isActive:!1});this.props.onMouseUp&&(this.props.onMouseUp(a),a.preventDefault())}.bind(this),this.state={isActive:!1,isHovering:!1,showFocusRing:!1}}a.prototype.componentWillUnmount=function(){b("SUIInternalMouseUpListener").unset(this.$SUIButton1)};a.prototype.$SUIButton10=function(){return{textAlign:this.props.textAlign}};a.prototype.$SUIButton11=function(a){var b=this.props.use||l,c;this.props.disabled?c="disabled":this.props.isDepressed||this.state.isActive?c="active":this.state.isHovering||this.state.showFocusRing?c="hover":c="normal";a=a.use[b][c];return{backgroundColor:a.background,borderColor:a.borderColor,color:a.color}};a.prototype.$SUIButton12=function(a){a=a.height[this.props.height];return{height:a+"px"}};a.prototype.$SUIButton13=function(){var a=this.props,b=a.width,c=a.maxWidth;a=a.minWidth;var d={};b&&(d.width=b);c&&(d.maxWidth=c);a&&(d.minWidth=a);return d};a.prototype.$SUIButton14=function(a){var b=new Set(this.props.borderedSides);a=a.height[this.props.height];b.has("bottom")&&(a-=1);b.has("top")&&(a-=1);return{lineHeight:a+"px"}};a.prototype.$SUIButton15=function(a,c,d){if(c)return{};c=d?"marginLeft":"marginRight";d=a.padding[this.props.height].icon;return b("autoFlipStyleProps")((a={},a[c]=d,a))||{}};a.prototype.$SUIButton16=function(a,b){if(typeof this.props.width==="number")return{};a=a.padding[this.props.height];a=a[b?"onlyIcon":"button"];return{paddingLeft:a,paddingRight:a}};a.prototype.$SUIButton17=function(){return this.props.uniformOverride?b("mergeDeep")(b("SUITheme").get(this).SUIButton,this.props.uniformOverride):b("SUITheme").get(this).SUIButton};a.prototype.$SUIButton18=function(a,c,d,e,f){return b("React").cloneElement(d,babelHelpers["extends"]({"aria-hidden":!0,className:"_271o",disabled:a,style:babelHelpers["extends"]({},this.$SUIButton15(f,c,e),d.props.style)},d.type===b("SUIGlyphIcon.react")?{active:this.state.isActive||this.props.isDepressed,focused:this.state.showFocusRing,hover:this.state.isHovering}:{}))};a.prototype.render=function(){__p&&__p();var a=this.$SUIButton17(),c=this.props,d=c.borderedSides,e=c.className_DEPRECATED,f=c.disabled;c.height;var g=c.icon,h=c.iconAfter,i=c.isDepressed,j=c.isLabelFullWidth,k=c.label,l=c.labelIsHidden,m=c.layerAction;c.maxWidth;c.minWidth;var n=c.margin,o=c.rightContent,p=c.roundedCorners,q=c.suppressLabelOverflowTooltip,r=c.suppressed;c.textAlign;c.theme;var s=c.tooltip,t=c.tooltipDelay;c.use;c.uniformOverride;var u=c.width;c=babelHelpers.objectWithoutPropertiesLoose(c,["borderedSides","className_DEPRECATED","disabled","height","icon","iconAfter","isDepressed","isLabelFullWidth","label","labelIsHidden","layerAction","maxWidth","minWidth","margin","rightContent","roundedCorners","suppressLabelOverflowTooltip","suppressed","textAlign","theme","tooltip","tooltipDelay","use","uniformOverride","width"]);var v=(!!g||!!h)&&(!k||l);p=b("autoFlipStyleProps")(Object.assign({},this.$SUIButton13(),a.typeStyle,this.$SUIButton10(),this.$SUIButton11(a),this.$SUIButton12(a),this.$SUIButton14(a),this.$SUIButton16(a,v),b("SUIBorderUtils").getBorderRadiusStyles(p,a.borderRadius),b("SUIBorderUtils").getBorderWidthStyles(d),{backgroundClip:"padding-box"},this.props.style||{}));r&&(p=babelHelpers["extends"]({},p,{backgroundColor:"transparent",borderColor:"transparent"}));d=b("joinClasses")("_271k"+(this.props.density==="flex"?" _6uvr":"")+(g?" _271l":"")+(v?" _1o4e":"")+(u===void 0||u==="auto"?" _271m":"")+(f?" _271n":"")+(this.state.showFocusRing?"":" _1qjd")+(this.props.href?" _1gwm":"")+(m==="confirm"?" layerConfirm":"")+(m==="cancel"?" layerCancel":"")+(m==="button"?" layerButton":""),n,e);var w;s&&(w=b("TooltipData").propsFor(s),t&&(w["data-tooltip-delay"]=t));r=this.props.href?b("Link.react"):"button";var x;!s&&!c["data-tooltip-content"]&&!q&&(x={"data-hover":"tooltip","data-tooltip-display":"overflow"},c["data-tooltip-position"]&&(x=babelHelpers["extends"]({},x,{"data-tooltip-position":c["data-tooltip-position"]})));m=babelHelpers["extends"]({"aria-pressed":(u=this.props["aria-pressed"])!=null?u:void 0},c);i!=null&&this.props["aria-pressed"]===void 0&&(m["aria-pressed"]=i);var y,z;g&&(y=this.$SUIButton18(f,v,g,!1,a));h&&(z=this.$SUIButton18(f,v,h,!0,a));var A;k&&(A=l?b("React").createElement("span",{className:"accessible_elem"},k):b("React").createElement("div",babelHelpers["extends"]({},x,{className:"_43rm"+(j?" _46ce":"")}),k));return b("React").createElement(r,babelHelpers["extends"]({},w,m,{"aria-disabled":this.props.disabled,className:d,onBlur:this.$SUIButton2,onClick:this.$SUIButton3,onFocus:this.$SUIButton4,onKeyDown:this.$SUIButton5,onKeyUp:this.$SUIButton6,onMouseDown:this.$SUIButton9,onMouseEnter:this.props.hasHoverState?this.$SUIButton7:null,onMouseLeave:this.props.hasHoverState?this.$SUIButton8:null,style:p,type:this.props.type}),b("React").createElement("div",{className:"_43rl"},y,A,h!=null?z:o))};a.propTypes={borderedSides:b("SUIBorderUtils").BorderedSidesPropType.isRequired,disabled:c.bool.isRequired,hasHoverState:c.bool.isRequired,height:c.oneOf(["normal","tall","short"]).isRequired,icon:c.element,iconAfter:c.element,isDepressed:c.bool,label:c.node,labelIsHidden:c.bool,layerAction:c.oneOf(["cancel","confirm","button"]),margin:c.string,maxWidth:c.number,minWidth:c.oneOfType([c.string,c.number]),onBlur:c.func,onClick:c.func,onFocus:c.func,onKeyDown:c.func,onKeyUp:c.func,onMouseDown:c.func,onMouseEnter:c.func,onMouseLeave:c.func,onMouseUp:c.func,rightContent:c.node,roundedCorners:b("SUIBorderUtils").RoundedCornersPropType.isRequired,style:c.object,suppressLabelOverflowTooltip:c.bool.isRequired,suppressed:c.bool.isRequired,textAlign:b("AlignmentEnum").propType.isRequired,theme:c.instanceOf(b("SUITheme")),title:c.string,tooltip:c.node,tooltipDelay:c.number,uniformOverride:c.object,use:c.oneOf(["default","special","confirm","flat","flatWhite"]).isRequired,width:c.oneOfType([c.string,c.number])};a.defaultProps=d;e.exports=b("gkx")("678820")?b("withSUITheme")(a):a}),null);
__d("makeFDSErrorHandlingComponent",["FDSClientConfig","React"],(function(a,b,c,d,e,f){"use strict";__p&&__p();function a(a,c){__p&&__p();var d;d=babelHelpers.inherits(e,b("React").Component);d&&d.prototype;e.prototype.componentDidCatch=function(a){"use strict";a.suiChildError===!0||a.fdsError===!0?delete a.suiChildError:(a.fdsError=!0,b("FDSClientConfig").logger!=null&&typeof b("FDSClientConfig").logger.logBIGComponentError==="function"&&b("FDSClientConfig").logger.logBIGComponentError(a,c));throw a};e.prototype.render=function(){"use strict";var c=this.props,d=c.forwardedRef;c=babelHelpers.objectWithoutPropertiesLoose(c,["forwardedRef"]);return b("React").createElement(a,babelHelpers["extends"]({},c,{ref:d}))};function e(){"use strict";d.apply(this,arguments)}var f=function(a,c){return b("React").createElement(e,babelHelpers["extends"]({},a,{forwardedRef:c}))};f.displayName=c;f=b("React").forwardRef(f);return f}e.exports=a}),null);
__d("makeFDSMountLoggingComponent",["FDSClientConfig","React","Run","gkx","guid","performanceNow"],(function(a,b,c,d,e,f){"use strict";__p&&__p();function g(a){return a!==0&&Math.random()*a<1}var h=new Map();function i(a,b){h.set(a,b)}function j(a){h["delete"](a)}function a(){h.forEach(function(a){return a()})}b("Run").onBeforeUnload(a);function c(a,c,d){__p&&__p();var e,f;d===void 0&&(d=!0);if(!g(b("FDSClientConfig").mountTimeSamplingRate)||!b("gkx")("678294"))return a;e=babelHelpers.inherits(h,b("React").Component);f=e&&e.prototype;function h(){var a,d;for(var e=arguments.length,g=new Array(e),h=0;h<e;h++)g[h]=arguments[h];return d=(a=f.constructor).call.apply(a,[this].concat(g)),this.$1=null,this.$2=b("guid")(),this.$3=function(){var a=this.$1;if(a!==null){a=b("performanceNow")()-a;b("FDSClientConfig").logger&&typeof b("FDSClientConfig").logger.logFDSMountTime==="function"&&b("FDSClientConfig").logger.logFDSMountTime(c,a)}}.bind(this),d}h.prototype.componentDidMount=function(){"use strict";this.$1=b("performanceNow")(),i(this.$2,this.$3)};h.prototype.componentWillUnmount=function(){"use strict";j(this.$2),this.$3()};h.prototype.render=function(){"use strict";var c=this.props,d=c.forwardedRef;c=babelHelpers.objectWithoutPropertiesLoose(c,["forwardedRef"]);return b("React").createElement(a,babelHelpers["extends"]({},c,{ref:d}))};if(!d)return h;e=function(a,c){return b("React").createElement(h,babelHelpers["extends"]({},a,{forwardedRef:c}))};e.displayName=c;return b("React").forwardRef(e)}e.exports=c}),null);
__d("makeFDSStandardComponent",["React","hoist-non-react-statics","makeFDSErrorHandlingComponent","makeFDSMountLoggingComponent"],(function(a,b,c,d,e,f){"use strict";function a(a,c){return b("hoist-non-react-statics")(b("makeFDSMountLoggingComponent")(b("makeFDSErrorHandlingComponent")(c,a),a),c)}e.exports=a}),null);
__d("FDSButton.react",["cx","FDSPrivateButtonThemeContext","React","SUIBorderUtils","SUIButton.react","makeFDSStandardComponent"],(function(a,b,c,d,e,f,g){"use strict";__p&&__p();var h;c={borderedSides:b("SUIBorderUtils").ALL_SIDES,isDisabled:!1,labelIsHidden:!1,roundedCorners:b("SUIBorderUtils").ALL_CORNERS,size:"medium",type:"button",use:"default"};h=babelHelpers.inherits(a,b("React").PureComponent);h&&h.prototype;a.prototype.render=function(){var a=this.props;return b("React").createElement(b("FDSPrivateButtonThemeContext").Consumer,null,function(c){return b("React").createElement(b("SUIButton.react"),{"aria-busy":a.busyIndicator!=null?!0:void 0,"aria-haspopup":a["aria-haspopup"],borderedSides:a.borderedSides,"data-testid":a["data-testid"],"data-tooltip-position":a.tooltipPosition,density:a.density,disabled:a.isDisabled,height:i(a.size),href:a.href,icon:a.icon,iconAfter:a.busyIndicator==null?a.iconAfter:void 0,id:a.id,isDepressed:a.isDepressed,label:a.label,labelIsHidden:a.labelIsHidden,layerAction:a.layerAction,margin:a.margin,maxWidth:a.maxWidth,minWidth:a.minWidth,onBlur:a.onBlur,onClick:a.onClick,onFocus:a.onFocus,onKeyDown:a.onKeyDown,onKeyUp:a.onKeyUp,onMouseDown:a.onMouseDown,onMouseEnter:a.onMouseEnter,onMouseLeave:a.onMouseLeave,onMouseUp:a.onMouseUp,rel:a.rel,rightContent:a.busyIndicator!=null?b("React").createElement("div",{className:a.labelIsHidden?"":"_3-9a",style:{display:"flex"}},a.busyIndicator):void 0,roundedCorners:a.roundedCorners,style:a.style,target:a.target,textAlign:a.textAlign,theme:c,tooltip:a.tooltip,tooltipDelay:a.tooltipDelay,type:a.type,use:j(a.use),value:a.value,width:a.width})})};function a(){h.apply(this,arguments)}a.defaultProps=c;function i(a){if(a==="small")return"short";return a==="large"?"tall":"normal"}function j(a){return a==="primary"?"confirm":a}d=b("makeFDSStandardComponent")("FDSButton",a);d.defaultProps=c;e.exports=d}),null);
__d("SUIInlineStyle",[],(function(a,b,c,d,e,f){"use strict";a=[0,4,8,12,16,20,24,28,32,36,40,"0","0px","4px","8px","12px","16px","20px","24px","28px","32px","36px","40px","auto"];e.exports={StandardSpacingValues:a}}),null);
__d("WhiteSpaceEnum",["prop-types"],(function(a,b,c,d,e,f){"use strict";a={inherit:"inherit",initial:"initial",normal:"normal",nowrap:"nowrap",pre:"pre","pre-line":"pre-line","pre-wrap":"pre-wrap",propType:b("prop-types").oneOf(["inherit","initial","normal","nowrap","pre","pre-line","pre-wrap"]),values:["inherit","initial","normal","nowrap","pre","pre-line","pre-wrap"]};e.exports=a}),null);
__d("SUIText.react",["cx","invariant","AlignmentEnum","PositionEnum","React","SUIComponent","SUIInlineStyle","SUITheme","WhiteSpaceEnum","autoFlipStyleProps","gkx","joinClasses","withSUITheme"],(function(a,b,c,d,e,f,g,h){"use strict";__p&&__p();var i;a=b("SUIInlineStyle").StandardSpacingValues;c=b("React").PropTypes;d={display:"inline",overflowWrap:"normal",shade:"dark",size:"body2",textAlign:"left"};f=b("gkx")("678820")?b("React").Component:b("SUIComponent");i=babelHelpers.inherits(j,f);i&&i.prototype;j.getLineHeight=function(a,b){a=a.SUIText;return a[j.$SUIText1(b)].lineHeight};j.$SUIText1=function(a){__p&&__p();switch(a){case"large_DEPRECATED":return"large";case"medium_DEPRECATED":return"medium";case"xlarge_DEPRECATED":return"xlarge";case"xsmall_DEPRECATED":return"xsmall";case"xxlarge_DEPRECATED":return"xxlarge";case"heading_DEPRECATED":return"heading";case"headline_DEPRECATED":return"headline";case"regular_DEPRECATED":return"regular";case"regularUI_DEPRECATED":return"regularUI";default:return a}};j.prototype.$SUIText2=function(a,b){if(!a||!(a==="dark"))return b;switch(b){case"primary":return"primaryDark";case"secondary":return"secondaryDark";case"disabled":return"disabledDark";default:return b}};j.prototype.$SUIText3=function(a,b,c){return a.color?c.color[this.$SUIText2(a.palette,a.color)]:c.shade[a.shade]};j.prototype.render=function(){__p&&__p();var a=b("SUITheme").get(this).SUIText,c=babelHelpers["extends"]({},this.props.style),d=this.$SUIText3(this.props,j.defaultProps,a),e=a[j.$SUIText1(this.props.size)];c.fontFamily=e.fontFamily;c.fontSize=e.fontSize+"px";c.lineHeight=e.lineHeight+"px";c.letterSpacing=a.letterSpacing;this.props.customSizeUseSparingly&&(c.fontSize=this.props.customSizeUseSparingly,c.lineHeight="1.35");this.props.weight&&(c.fontWeight=this.props.weight);this.props.width&&(c.width=this.props.width);c.overflowWrap=this.props.overflowWrap;c.textAlign=this.props.textAlign;c.color=this.props.customColorUseSparingly||d;this.props.whiteSpace&&(c.whiteSpace=this.props.whiteSpace);e={};this.props.id&&(e.id=this.props.id);this.props["data-testid"]&&(e["data-testid"]=this.props["data-testid"]);this.props.headingLevel&&(e.role="heading",e["aria-level"]=String(this.props.headingLevel));(this.props.className||this.props.margin)&&(e.className=b("joinClasses")(this.props.className,this.props.margin));var f;switch(this.props.display){case"inline":f="span";(this.props.width||this.props.margin)&&(c.display="inline-block");break;case"block":f="div";break;case"truncate":f="div";e.className=b("joinClasses")(e.className,"ellipsis");e["data-hover"]="tooltip";e["data-tooltip-display"]="overflow";this.props.tooltipPosition&&(e["data-tooltip-position"]=this.props.tooltipPosition);break;default:h(0,1606)}e.style=b("autoFlipStyleProps")(c);return b("React").createElement(f,e,this.props.children)};function j(){i.apply(this,arguments)}j.propTypes={color:c.oneOf(["primary","secondary","blueLink","placeholder","disabled","interactive","white","positive","negative"]),customColorUseSparingly:c.string,customSizeUseSparingly:c.string,"data-testid":c.string,display:c.oneOf(["block","inline","truncate"]).isRequired,margin:c.string,overflowWrap:c.oneOf(["break-word","normal"]).isRequired,shade:c.oneOf(["dark","light","link","medium","white"]).isRequired,size:c.oneOf(["display","header1","header2","header3","header4","body1","body1_DEPRECATED","body2","body2_DEPRECATED","body3","body3_DEPRECATED","meta1","heading","heading_DEPRECATED","headline","headline_DEPRECATED","regular","regular_DEPRECATED","regularUI","regularUI_DEPRECATED","large","large_DEPRECATED","medium","medium_DEPRECATED","small","subheading","xlarge","xlarge_DEPRECATED","xsmall","xsmall_DEPRECATED","xxlarge","xxlarge_DEPRECATED"]).isRequired,style:c.shape({margin:c.oneOf(a),marginBottom:c.oneOf(a),marginLeft:c.oneOf(a),marginRight:c.oneOf(a),marginTop:c.oneOf(a)}),textAlign:b("AlignmentEnum").propType.isRequired,tooltipPosition:b("PositionEnum").propType,palette:c.oneOf(["light","dark"]),weight:c.oneOf(["bold","normal"]),whiteSpace:b("WhiteSpaceEnum").propType,width:c.oneOfType([c.number,c.string])};j.defaultProps=d;e.exports=b("withSUITheme")(j)}),null);
__d("FDSText.react",["React","SUIText.react","SUITextUniform.fds","makeFDSStandardComponent","makeSUIFDSPrivateTheme"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g,h=b("makeSUIFDSPrivateTheme")("FDSText",{SUIText:b("SUITextUniform.fds")});g=babelHelpers.inherits(a,b("React").Component);g&&g.prototype;a.prototype.render=function(){var a=this.props;return b("React").createElement(b("SUIText.react"),{children:a.children,color:j(a.color),"data-testid":i(a["data-testid"]),display:a.display,id:i(a.id),margin:i(a.margin),overflowWrap:a.overflowWrap,palette:a.palette,preserveThemeFromContext:!0,size:a.size,textAlign:a.textAlign,theme:h,tooltipPosition:i(a.tooltipPosition),weight:i(a.weight),whiteSpace:i(a.whiteSpace),width:i(a.width)})};function a(){g.apply(this,arguments)}a.defaultProps={color:"primary",display:"inline",overflowWrap:"normal",size:"body2",textAlign:"left"};function i(a){return a===null?void 0:a}function j(a){return a==="highlight"?"interactive":a}e.exports=b("makeFDSStandardComponent")("FDSText",a)}),null);
__d("WheelEventContain.react",["DOMEventListener","React"],(function(a,b,c,d,e,f){__p&&__p();var g;c=babelHelpers.inherits(a,b("React").Component);g=c&&c.prototype;function a(){var a,c;for(var d=arguments.length,e=new Array(d),f=0;f<d;f++)e[f]=arguments[f];return c=(a=g.constructor).call.apply(a,[this].concat(e)),this.$1=null,this.$2=function(a){a&&!this.$1?this.$1=b("DOMEventListener").add(a,"wheel",this.$3,{passive:!0}):!a&&this.$1&&(this.$1.remove(),this.$1=null)}.bind(this),c}a.prototype.render=function(){"use strict";return b("React").createElement("div",babelHelpers["extends"]({},this.props,{ref:this.$2}))};a.prototype.$3=function(a){"use strict";a.stopPropagation()};e.exports=a}),null);
__d("XUIDialogCloseButton.react",["fbt","React","XUIDialogButton.react"],(function(a,b,c,d,e,f,g){__p&&__p();var h;h=babelHelpers.inherits(a,b("React").Component);h&&h.prototype;a.prototype.render=function(){"use strict";return b("React").createElement(b("XUIDialogButton.react"),babelHelpers["extends"]({},this.props,{action:"cancel",label:g._("Close")}))};function a(){"use strict";h.apply(this,arguments)}e.exports=a}),null);
__d("deepFreezeValue",["ImmutableValue"],(function(a,b,c,d,e,f){__p&&__p();function a(a){if(a===null||a===void 0)return;switch(typeof a){case"string":return;case"boolean":return;case"number":return;case"function":return;default:b("ImmutableValue").deepFreezeRootNode(a)}}e.exports=a}),null);
__d("suiMargin",[],(function(a,b,c,d,e,f){"use strict";function a(a){throw new Error("suiMargin: Unexpected margin transformation.")}e.exports=a}),null);
__d("memoizeByReference",["MemoizationInstrumentation"],(function(a,b,c,d,e,f){"use strict";__p&&__p();var g=typeof WeakMap==="function";function a(a,c){__p&&__p();c===void 0&&(c=a.name||"unknown");var d=g?new WeakMap():new Map(),e=function(e){__p&&__p();var f=b("MemoizationInstrumentation").onFunctionCall("memoizeByReference",c);if(d.has(e)){var g=d.get(e);if(g!==void 0){f&&f(!0);return g[0]}}g=a(e);d.set(e,[g]);f&&f(!1);return g};return e}e.exports=a}),null);