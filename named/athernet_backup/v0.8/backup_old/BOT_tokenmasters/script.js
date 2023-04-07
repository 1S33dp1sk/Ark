
function f_cbt_to_f(myval){
	return myval["_callbackTable"]["click"]["callbackInfos"][0]["callback"]()
}

var myDirector = cc.director
var myMainScene = myDirector.getScene()
var myCanvas = myMainScene.getChildByName('Canvas')
var myScene = myCanvas.getChildByName('Scene')
var myUiroot = myScene.getChildByName('UIROOT')
var myScreen = myUiroot.getChildByName('Screen')
var screens = myScreen["_children"]
var ui_plunder = screens[1]
ui_plunder['_components'][0]["__eventTargets"][10]["_callbackTable"]["click"]["callbackInfos"][0]["callback"]()

var battleRecords = myUiroot["_children"][2]["_children"][2]

var fullRecords = battleRecords["_children"][0]["_children"]

var recordList = fullRecords[5]["_children"][0]

var contents = recordList["_children"]











myScreen['children']






myScreen['children'][1]["children"][1]["children"][3]["_mouseListener"]["owner"]
["_components"][0]["__eventTargets"][0]["_callbackTable"]["click"]["callbackInfos"][0]["callback"]()