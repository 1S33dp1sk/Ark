if (self.CavalryLogger) { CavalryLogger.start_js(["rHlOh"]); }

__d("createRelayFBBaseNetwork",["RelayAPIConfig","withLive","RelayRuntime","RelayFBNetworkLogger","createRelayFBGraphiQLPrinter"],(function(a,b,c,d,e,f){"use strict";var g=b("RelayRuntime").Network;function a(a,c){var d=g.create(a,c);return{execute:function(a,c,e,f){return d.execute(a,c,b("withLive")(a,e),f)}}}e.exports=a}),null);