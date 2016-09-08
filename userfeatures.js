export default {
    getAppUser : function() {
        var Wsh = Server.CreateObject("WScript.Shell");

        if(Wsh !== null || Wsh !== "undefined") {
            var userName = Wsh.Environment.item("USERNAME")
        }
        var objNet = Server.CreateObject("WScript.Network");
        userName = objNet.UserName;
        return userName;

    },
    getWindowsAuthUser : function() {
        return Request.ServerVariables("AUTH_USER");
    }
}